.PHONY: all cleanup

CC := gcc
CFLAGS :=

all: a.out

cleanup:
	@-rm a.out

a.out: main.c booking_system.h
	$(CC) $(CFLAGS) $< -o $@

