CC = gcc
target = vsh.exe

src_main = src/vshell.c
obj_src = $(wildcard ./src/util/*.c)
obj_util = $(obj_src:.c=.o)
config = ./src/util/config.h

$(target): $(src_main) $(obj_util)
	$(CC) -o $@ $^

%.o: %.c $(config)
	$(CC) -c -o $@ $<
