#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "c3includes.h"

int main() {
  pid_t pid = fork();
  int status = 25;

  if (pid == -1) {
    printf ("Fehler: fork() ist negativ %d\n", pid);
    exit(0xAA);
  }
  else if (pid == 0) {
    printf ("Kind: PID = %u. Eltern-PPID = %u\n", getpid(), getppid());
    printf ("Kind: status alt = %d\n", status);
    status = 26;
    printf ("Kind: status neu = %d\n", status);
    sleep(2);
    puts ("Kind: Beendet.");
    exit(0xAA);
  } else {
    printf ("Eltern: PPID = %u. Kind-PID = %u\n", getpid(), getppid());
    puts("Eltern:  5 Sekunden Pause.");
    sleep(5);
    puts("Eltern: wieder wach.");
    printf ("Eltern: status = %d\n", status);
    wait(&status);
    printf("%x\n", status);
  }
  return 0;
}
