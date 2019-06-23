CC = gcc
target = vsh.exe

src_main = src/vshell.c
src_util = $(wildcard ./src/util/*.c)

$(target): $(src_main) $(src_util)
	$(CC) -o $@ $^

