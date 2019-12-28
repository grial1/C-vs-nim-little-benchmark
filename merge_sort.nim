#[

  author:	 Gastón Rial Saibene
  description: 	 This is an example implementation of merge sort testing the NIM lang
		  and compiler against an equivalent C implementation compiled with cc (GNU C compiler).
  date:		 27/12/2019
]#
import strutils

# Function to merge to sequences (lists)
proc merge( l1, l2: seq[int], r: var seq[int]): int =
  var index1, index2 : int = 0 
  for i in 0..<(l1.len+l2.len): # < "i" is a usless index 
    if index1 < l1.len and index2 < l2.len:
      if l1[index1] < l2[index2]:
        r.add( l1[index1] )
        index1 += 1
      else:
        r.add( l2[index2] )
        index2 += 1
    else:
      if index1 < l1.len:
        r.add( l1[index1] )
        index1 += 1
      else:
        r.add( l2[index2] )
        index2 += 1
  result = r.len

# Recursive merge sort implementation
proc merge_sort( l:seq[int], r: var seq[int]): int =
  if l.len < 2:
    r = l
    return r.len
  else:
    let half_len : int = int(l.len/2)
    var le_half,ri_half : seq[int]
    for index, value in l.pairs:
      if index < half_len:
        le_half.add(value)
      else:
        ri_half.add(value)
    var le_sorted, ri_sorted : seq[int]
    assert( merge_sort(le_half, le_sorted) == le_half.len)
    assert( merge_sort(ri_half, ri_sorted) == ri_half.len)
    result = merge( le_sorted, ri_sorted, r)

# MAIN starts here
var input,r : seq[int]

let random_list = readFile("random_list.txt")
for value in random_list.split(","):
  input.add(parseInt(value))

let s = merge_sort(input,r)

echo "sequence: ",r
echo "size: ",s
