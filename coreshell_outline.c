
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
 char command[BUFSIZ];
 int status;
 pid_t pid;

 for(;;) {
  printf("coreline#");
  if(fgets(command, sizeof(command), stdin) == NULL) {
    return 0;
  }

  command[strlen(command) - 1] = '\0';
  if((pid = fork()) == 0)
   execlp(command, command, 0);

  while(wait(&status) != pid)
   continue;

  printf("\n");
 }
}
