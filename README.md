# ShellProjectOperatingSystems-UnixLike-
Hi there, this is a READ ME text file containing important information about a particular 
program, this text will give insight into the details of the program and will provide
useful information.

Program Name: Shell in C/C ++
Programmer: Justin Winchester
School:	    Cameron University
Class:      Operating Systems
Instructor: Dr. Zhao

This program Shell in C/C++ provides a user interface called a "shell" that gives the user
a platform in which to enter commands and arguments for queries and request generally relating 
to files and computer programs stored in the directories and "paths" of the system.
This program was created to provided the user interface but also show examples of how 
system calls can be used in programming for interprocess communication, interaction, and 
manipulation.
This progams uses POSIX functions fork() and exec() to perform this task. These functions show 
how you can create copies of process, create new processes, and override processes with new
ones. The fork function spawns a process or program based off it's parent, the fork is given
the return value of zero and the parent is returned it's parent id from the child process
fork(). The exec function has 6 familar functions in it's own little family class. These functions
are used to create a new process in place of an existing or currently running process. 
These two functions are typically used together and are much more dynamic that way, fork spawns a
new process and an exec funcion is then called to execute the new process sinch fork is just a 
copy of a previous parent process it is no problem to overwrite it with the exec function program
and let it's parent continue the prior event. 

Functions
Void Parse(){Function used to parse character line commands into argument tokens that 
can be implemented by execvp function!};
Void Execute(){Function that calls the exec function to execute commands afte spawning fork
from parent process}
Arrays
Storage is needed for the arguments and commands 
Line[];
arguments[];
This program can be compiled by typing-
g++ MyNewShell.cpp
then entering in the keyboard subsequently-
./a.out
