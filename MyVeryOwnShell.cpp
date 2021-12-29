/* ***************************************************************
Programmer:     Justin Winchester
Program Type:   C /C++
Program Name:   My Implementation of Shell That Accepts Commands
Instructor:     Dr. Chao Zhao
Brief Synopsis: This program using C/C++ programming features
and posix functions to generate a "shell". A shell is a user
interface that accepts commands and searching through files
and directories at the users request. This shell uses the POSIX
functions and systems calls to operate the program.
This implementation gives examples how to create processes
using the fork() and exec() system calls to communicatae 
between processes and create them!




******************************************************************   */

/* ***************************************************************** 
        Necessary Librarys For Posix functions and to
        Handle user input
 ***************************************************************** */
#include <iostream>
#include <unistd.h>
#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/* ***************************************************************** 
 PARSING FUNCTION =
    This function takes an input line of characters
        from a user  and parses them into tokens. These
        tokens are then saved as arguments to an array of
        character pointers that will store the user arguments
        input=comamands + arguments    
 ***************************************************************** */

/* ****************************************************************
        EXECUTE FUNCTION = This function will use fork() & execvp()
        to create a new process based on user input commands
        if the command and arguments are known the parent process
        will wait allowing for more input and will fork the requested
        process that is handled by execvp, it recieves first the
        command and then any subsequent arguments!!!
******************************************************************** */



//Implement Parsing Function
 void  parse(char *line, char **args)
{
*args = strtok(line, " ");
       int	i = 0;
	while(*line != '\0')//parsing line into separate args
	{
		*args++  = line;//Point to argument position on line & store location!
		while(*line!= '\0')//Keep Going while chars or until space or null marking end of 1 argument
		line++;
		*args = strtok(NULL, " ");//strtok starts @ next arg keeps going till space 
	}
	}



//Implementation of execute which used fork & execvp
void  execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) {    //* First Fork a child process
          printf("*ALERT: Sorry, Could Not Create FORK process!\n");
          exit(1);
     }
     else if (pid == 0) {         // Child process begining if ZERO:
          if (execvp(*argv, argv) < 0) {    // Execute the command
               printf("*ERROR/ALERT: EXECVP didn't execute!\n");
              exit(1);
          }
     }
     else {                                         
          while (wait(&status) != pid)       // Parent waiting for kid to finish
               ;
     }
}

//Now Call Functions in Main and declare Line array and Pointer Array for args!

int  main()
{
     char  line[1024];             // User Input Line                 
     char  *args[64];              // Arguments,first commmand      

     while (1) {                   //  Infinite Service Loop Until User's is through;       
          printf("Shell Interface >> ");     //  Prompt User             
          fgets(line,1024,stdin);  //  Read Line for Cmmds & ARGS   
          int i = strlen(line)-1;
          if( line[ i ] == '\n') 
              line[i] = '\0';
          parse(line, args);       //  Parse Function is called               
          if (strcmp(args[0], "exit") == 0)  // Do you want to exit?     
               exit(0);            
          execute(args);           //  Execute the arguments(if possible)
     }

return 0; 
}
