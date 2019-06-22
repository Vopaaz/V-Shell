#pragma once
#include "config.h"

char *init_buffer(int length);
char **init_args(int number, int length);
void free_args(char** args, int number);
