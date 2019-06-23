#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util/config.h"
#include "util/debug.h"
#include "util/dir.h"
#include "util/execute.h"
#include "util/input.h"

int main(int argc, char const *argv[]) {
    print(COPYRIGHT_MESSAGE);
    char **args;

    while (true) {
        PROMPTING();

        int arg_status = get_args(&args);
        if (arg_status == __NO_ARGS_INPUT__) continue;

        int execute_status = execute(args);
        free_args(args, MAX_COMMAND_NUMBER);

        switch (execute_status) {
            case __BYE__:
                return 0;
                break;
            case __EXECUTION_FAILED__:
                printf(EXECUTION_FAILED_MESSAGE);
                exit(-1);
                // If execution failed, the child process will not
                // terminate automatically, so terminate it here.
                break;
            case __CD_FAILED__:
                printf(CD_FAILED_MESSAGE);
                break;
            case __EXECUTION_IN_BACKGROUND__:
                break;
            default:
                break;
        }
    }

    return 0;
}
