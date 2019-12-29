CC = gcc
NIM = nim
PY = python3

all: random_list merge_sort

random_list:
	$(PY) $@_generator.py

merge_sort:
	$(CC) $@.c -o $@_c.bin
	$(NIM) c -d:release --verbosity:0 -o:$@_nim.bin $@.nim

clean:
	rm -rf random_list.txt
	rm -rf *.bin

run: merge_sort
	@echo -n "\n\t=== MEMORY LAYOUT ===\n"
	@echo -n "> C to binary:\n"
	size -B $<_c.bin 
	@echo -n "> NIM (to C) to binary:\n"
	size -B $<_nim.bin
	@echo -n "\n\t=== CPU TIME ===\n"
	@echo -n "> C to binary:\n"
	/usr/bin/time ./$<_c.bin 1>/dev/null
	@echo -n "> NIM (to C) to binary:\n"
	/usr/bin/time ./$<_nim.bin 1>/dev/null
