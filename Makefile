# Makefile

CC=gcc
CFLAGS=-Wall -pedantic -std=c89

rcalc: rcalc.c rcalcfunc.c
	$(CC) $(CFLAGS) -o rcalc rcalc.c rcalcfunc.c -I.

.PHONY: clean

clean:
	rm -f rcalc

