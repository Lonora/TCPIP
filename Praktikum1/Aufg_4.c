#include <sys/types.h>
#include <signal.h>
#include "c3includes.h"

/**  A funktion that handle the signal
  * When we compile, we are sending this Signal (handle) to the terminal
  *
*/
int zaehler = 0;
void intHandle(int sig) {
  pid_t  pid = fork();
  printf ("Meine PID = %d\n", pid);
  signal(SIGINT, intHandle); //installieren den Signal handler. The type is: SIGINT and attach to the signal(handle)
  printf("Signal %d\n", sig);
  fflush(stdout);
  zaehler++;
  if (zaehler == 5) {
    exit(0);
  }
void userHandle(int usr) {
  signal(SIGUSR1, intHandle);
  kill(SIGUSR1, pid);
  printf("User %d\n", usr);
}
}
int main() {
  //Signal installieren
  signal(SIGINT, intHandle);
  signal(SIGUSR1, intHandle);
  //Dummy schleife. It will keep sending the signal everytime
  while (1) {
    printf("." );
    fflush(stdout); //force the Output
    sleep(1);
  }
  return 0;
}
