#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util/config.h"
#include "util/debug.h"
#include "util/execute.h"
#include "util/input.h"
#include "util/space.h"

int main(int argc, char const *argv[]) {
    print(MESSAGE);
    char **args;

    while (true) {
        printf(PROMPT);

        int arg_status = get_args(&args);
        if (arg_status == __NO_ARGS_INPUT__) continue;

        int execute_status = execute(args);
        free_args(args, MAX_COMMAND_NUMBER);

        if (execute_status == __BYE__) return 0;
        if (execute_status == __EXECUTION_FAILED__) {
            printf("Execution failed. Commands may be invalid.\n");
            return 0;
        }
    }

    return 0;
}
