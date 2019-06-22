#include <stdio.h>

void print_args(char **args, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s \n", args[i]);
    }
}
