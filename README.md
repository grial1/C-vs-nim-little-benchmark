# c_vs_nim_little_benchmark

### Description
This repository contains the source code for an implementation of the *merge sort algorithm* using C and NIM programming languages. The purpose was to compare raw performance (memory size footprint and CPU time consumption) of the resultant binaries under a platform running the GNU/Linux OS.

### System employed for testing
* Linux:          4.4.0-170-generic #199-Ubuntu SMP Thu Nov 14 01:45:04 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
* Distributor ID:	Ubuntu
* Description:	  Ubuntu 16.04.6 LTS
* Release:	      16.04
* Codename:	      xenial
* CPU(s):         4 x Intel(R) Core(TM) i3 CPU M 330 @ 2.13GHz
* MemTotal:       3841960 kB

### How to run tests
```
  $ git clone https://github.com/grial1/c_vs_nim_little_benchmark benchmarks 
  $ cd benchmarks
  $ make
  $ make run
```

### Interesting links
* [NIM lang](https://nim-lang.org/)
* [Merge sort algorithm](https://en.wikipedia.org/wiki/Merge_sort)
* [Another merge sort implementation](https://www.geeksforgeeks.org/merge-sort/)
