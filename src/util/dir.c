#include "dir.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "config.h"

void print_cwd() {
    char cwd[MAX_PATH_LENGTH] = {0};
    getcwd(cwd, MAX_PATH_LENGTH);
    print("%s", cwd);
}