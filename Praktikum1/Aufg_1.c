#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include "c3includes.h"
int main() {
  pid_t  pid = getpid();
  printf ("Meine PID = %d\n", pid);

  pid = getppid();
  printf ("Meine Eltern-PPID = %d\n", pid);

  uid_t uid = getuid();
  printf ("Meine User-UID = %d\n", uid);

  gid_t gid = getgid();
  printf ("Meine Group-GID = %d\n", gid);
	return 0;
}
