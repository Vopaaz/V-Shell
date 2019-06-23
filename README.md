# V-Shell

A Very basic Shell.

It's the course project for Computer System Architechture, Professor Mao, Tsinghua SEM.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [V-Shell](#V-Shell)
  - [Instruction](#Instruction)
    - [Prerequesites](#Prerequesites)
    - [Build & Run](#Build--Run)
    - [Supported Functions](#Supported-Functions)
  - [Code structure](#Code-structure)

<!-- /code_chunk_output -->


## Instruction

### Prerequesites

- System: Linux
- Compiler: gcc

### Build & Run

Building:

```bash
$ make
```

Running:

```Bash
$ ./vsh.exe
```

### Supported Functions

- [x] Display prompt information (current working directory) and accept a command that the user keys in and execute the command
- [x] When the execution is finished, display the prompt again and wait for next command
- [x] Terminate the interpreter with command `bye`
- [x] Allow multiple commands in one line, separated by `&&`
- [x] Execute the command in background when the character `*` is append to the end of one command
- [x] The shell will not terminate from being interrupted by `Ctrl-C`

## Code structure

Note that the cognominal `.h` file is not listed here.

📦V-Shell
 ┣ 📂src
 ┃ ┣ 📂util
 ┃ ┃ ┣ 📜config.h
 ┃ ┃ ┣ 📜debug.c
 ┃ ┃ ┣ 📜dir.c
 ┃ ┃ ┣ 📜execute.c
 ┃ ┃ ┣ 📜input.c
 ┃ ┃ ┣ 📜signalHandling.c
 ┃ ┗ 📜vshell.c
 ┣ 📜.gitignore
 ┣ 📜Makefile
 ┣ 📜README.md
 ┗ 📜syncDocker.bat


`src/util/config.h`: Define constants, macros, messages, syntax, etc. for the whole project.
`src/util/debug.c`: Provide print functions for debugging.
`src/util/dir.c`: Manage the current working directory.
`src/util/execute.c`: Kernel of v-shell, execute the input commands.
`src/util/input.c`: Receive user input and split them for further use.
`src/util/signalHandling.c`: Handling `Ctrl+C` signals.
`syncDocker.bat`: An auxilary file for syncing the source code to linux docker container and build and test.
