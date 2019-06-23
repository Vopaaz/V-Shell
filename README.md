# V-Shell

A Very basic Shell.

It's the course project (option 1) for Computer System Architechture, Professor Mao, Tsinghua SEM.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [V-Shell](#V-Shell)
  - [Instruction](#Instruction)
    - [Prerequesites](#Prerequesites)
    - [Build & Run](#Build--Run)
    - [Supported Functions](#Supported-Functions)
  - [Code structure](#Code-structure)
  - [Demonstration Snippets](#Demonstration-Snippets)

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

```text
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
```

- `src/util/config.h`: Define constants, macros, messages, syntax, etc. for the whole project.
- `src/util/debug.c`: Provide print functions for debugging.
- `src/util/dir.c`: Manage the current working directory.
- `src/util/execute.c`: Kernel of v-shell, execute the input commands.
- `src/util/input.c`: Receive user input and split them for further use.
- `src/util/signalHandling.c`: Handling `Ctrl+C` signals.
- `syncDocker.bat`: An auxilary file for syncing the source code to linux docker container and build and test.


## Demonstration Snippets

```text
\\ Entering the v-shell
root@4683062396b4:/usr/vopaaz/v-shell# ./vsh.exe
--------
This is a very basic shell by Vopaaz (Li YiFan) in June 2019.
It's the course project for Computer System Architechture, Professor Mao.
--------

\\ Basic commands supported
/usr/vopaaz/v-shell > ls
Makefile  README.md  src  syncDocker.bat  vsh.exe

\\ Redundant space before the first valid command
/usr/vopaaz/v-shell >      ls
Makefile  README.md  src  syncDocker.bat  vsh.exe

\\ Basic command and parameters
/usr/vopaaz/v-shell > ls -a
.   .git        .vscode   README.md  syncDocker.bat
..  .gitignore  Makefile  src        vsh.exe

\\ Redundant space within the command
/usr/vopaaz/v-shell > ls           -a
.   .git        .vscode   README.md  syncDocker.bat
..  .gitignore  Makefile  src        vsh.exe

\\ Built-in cd function that changes the working directory
/usr/vopaaz/v-shell > cd ..
/usr/vopaaz > cd v-shell

\\ Use '*' to execute command in the background
/usr/vopaaz/v-shell > ls *
Command executing in the background, child process id [3012]
/usr/vopaaz/v-shell > Makefile  README.md  src  syncDocker.bat  vsh.exe
\\ Note that the shell prompts first then comes the output of 'ls'.

\\ Multiple commands in one line, separated by '&&'
/usr/vopaaz/v-shell > ls && ls && ls
Makefile  README.md  src  syncDocker.bat  vsh.exe
Makefile  README.md  src  syncDocker.bat  vsh.exe
Makefile  README.md  src  syncDocker.bat  vsh.exe

\\ Multiple commands executed in the background
/usr/vopaaz/v-shell > ls * && ls * && ls *
Command executing in the background, child process id [3016]
Command executing in the background, child process id [3017]
Command executing in the background, child process id [3018]
/usr/vopaaz/v-shell > Makefile  README.md  src  syncDocker.bat  vsh.exe
Makefile  README.md  src  syncDocker.bat  vsh.exe
Makefile  README.md  src  syncDocker.bat  vsh.exe

\\ Available to handle commands that does not exist
/usr/vopaaz/v-shell > commands-that-not-exist
Execution failed. Commands may be invalid.

\\ If multiple commands are in one line and some of them are invalid,
\\ only those right ones before the invalid one will execute.
/usr/vopaaz/v-shell > ls && commands-that-not-exist
Makefile  README.md  src  syncDocker.bat  vsh.exe
Execution failed. Commands may be invalid.
/usr/vopaaz/v-shell > ls && commands-that-not-exist && ls
Makefile  README.md  src  syncDocker.bat  vsh.exe
Execution failed. Commands may be invalid.

\\ The shell is prevented from being interrupted by 'Ctrl+C'
/usr/vopaaz/v-shell > ^C
Ctrl+C detected, but the shell does not terminate according to the instruction.
To exit the shell, either use 'bye' or press 'Ctrl+Z'

\\ The shell can be terminated using bye
/usr/vopaaz/v-shell > bye
root@4683062396b4:/usr/vopaaz#
```
