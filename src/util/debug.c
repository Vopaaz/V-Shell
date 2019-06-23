#include "debug.h"
#include <stdio.h>

void print_args(char **args, int count) {
    // Print the first several arguments in the array.
    // Arguments:
    //     - args: the arguments
    //     - count: the number of arguments to print
    for (int i = 0; i < count; i++) {
        printf("%s \n", args[i]);
    }
}
