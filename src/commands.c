#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "commands.h"
#include <unistd.h>


int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  else if (chdir(argv[1]))
 
   return 1;
 
  else
   return 0;
}

int do_pwd(int argc, char** argv) {
 
  if (!validate_pwd_argv(argc, argv))
    return -1;

  else
 {  
    char buf[2048];
    getcwd(buf,8096);
    printf("%s\n", buf);
    return 0;
 }
  
}

int validate_cd_argv(int argc, char** argv) {

  if ((argc==2) && (strcmp(argv[0],"cd")==0))
	return 1;

  else
	return 0;
}

int validate_pwd_argv(int argc, char** argv) {
 
  if (argc >1)
     return 0;

  else if (strcmp(argv[0], "pwd")!=0)
     return 0;
  else 
     return 1;
}
