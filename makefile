all: visual_sorter

visual_sorter: visual_sorter.c
	$(CC) visual_sorter.c -Wall -W -O2 -o visual_sorter -lraylib -lraylib

clean:
	rm -rf visual_sorter
