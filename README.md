# r24_gamedev

Needs raylib installed(mendatory)
and browse the project files in the raylib installed directory

Copy the VSCode folder from the raylib/raylib/ folder to wherever you want and rename it Game.

Copy all the [source_code].cpp and the [header].h files provided by me, to the vscode folder.

Delete the main.c file from the Game.

Open main.code-workspace file to open vscode.
need to chagne 
CC = gcc to CC = g++
CC = clang to CC = clang++

.vscode/task.json
edit 
"OBJS=${fileBasenameNoExtension}.c" to "OBJS=${fileBasenameNoExtension}.cpp" [Just add 'pp' after '.c'] 
and compile
