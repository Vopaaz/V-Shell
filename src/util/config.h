#pragma once
#define MAX_COMMAND_LENGTH 100
#define MAX_COMMAND_NUMBER 20
#define MAX_PATH_LENGTH 100
#define PROMPTING() \
    print_cwd();    \
    print(" > ");
#define BACKGROUND_EXECUTION_SYNTAX "*"
#define MULTIPLE_COMMAND_SPLIT_SYNTAX "&&"
#define print printf
#define COPYRIGHT_MESSAGE                                                     \
    "--------\n"                                                              \
    "This is a minimum implemented shell coded by Vopaaz (Li YiFan) in June " \
    "2019.\n"                                                                 \
    "It's the course project for Computer System Architechture, Professor "   \
    "Mao.\n"                                                                  \
    "--------\n"
#define EXECUTION_FAILED_MESSAGE "Execution failed. Commands may be invalid.\n"
#define CD_FAILED_MESSAGE \
    "Change working directory failed. Path may be invalid.\n"

#define __NO_ARGS_INPUT__ 0

#define __CD_FAILED__ -2
#define __EXECUTION_FAILED__ -1
#define __SUCCESS__ 0
#define __BYE__ 1
#define __EXECUTION_IN_BACKGROUND__ __SUCCESS__
#define __EXECUTION_SUCCESS__ __SUCCESS__
#define __CD_SUCCESS__ __SUCCESS__
#define __BACKGROUND_PROCESS_ERROR__ __EXECUTION_FAILED__
