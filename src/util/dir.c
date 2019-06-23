#include "dir.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "config.h"

void print_cwd() {
    char cwd[MAX_PATH_LENGTH] = {0};
    getcwd(cwd, MAX_PATH_LENGTH);
    print("%s", cwd);
}

int cd(char **args) {
    if (args[1] != NULL) {
        int cd_result = chdir(args[1]);
        if (cd_result == -1) {
            return __CD_FAILED__;
        } else {
            return __CD_SUCCESS__;
        }
    } else {
        return __CD_FAILED__;
    }
    return 0;
}