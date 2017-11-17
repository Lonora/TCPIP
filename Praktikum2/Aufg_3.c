#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "c4includes.h"
int main() {
  char buf;
  pid_t pid;
  int pipeD[2];
  pipe(pipeD);
  pid = fork();
  while (1) {
    if (pid == -1 ) {
      perror("Error");
      exit(1);
    }
    if (pid == 0) {
      close(pipeD[1]);
      while (read(pipeD[0], &buf, 1) > 0) {
        write(STDOUT_FILENO, &buf, 1);
        printf("Ich bin dein KIND %d", getid());
      }
      write(STDOUT_FILENO, "\n", 1);
      exit(0);
    } else {
      close(pipeD[0]);
      write(pipeD[1], "Ich Bin Loua", 12);
      wait(NULL);
    }
  }
	return 0;
}
