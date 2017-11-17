#include <sys/types.h>
#include <signal.h>
#include "c3includes.h"

int main(int argc, char const *argv[]) {
  pid_t pid = fork(); // Kindprozess erzeugen
  if(pid == -1){
    printf("Error");
  }
  else if (pid == 0) {
    printf("Das Kindprozess ist = %d\n", pid);
    sleep(2);
    exit(0);
  } else {
    printf("Das Elternprozess = %d\n", pid);
    sleep(2);
    wait(&pid);
  }
  return 0;
}
