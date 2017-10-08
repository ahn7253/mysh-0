#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!

int count =0;
char *temp = (char*)malloc(sizeof(char)*strlen(command));

strcpy(temp, command);

(*argv) = (char**)malloc(sizeof(char**)*10);
(*argv)[count]= (char*)malloc(sizeof(char*)*10);

char* sttok =  strtok(temp, " \t\n");
if (sttok==NULL)
{
(*argc) = 1;
strcpy((*argv)[0],"");
return;
}

while (sttok !=NULL)
{
	strcpy((*argv)[count],sttok);
	(*argv)[++count] = (char*)malloc(sizeof(char)*25);
	sttok = strtok(NULL," \t\n");
}
*argc = count;
free(sttok);

}

