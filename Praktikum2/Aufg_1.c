#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "c4includes.h"
int main() {
  char buf[128];
  int fdr, fdw;
  int nr, nw;
    while (1) {
    fdr = fileno((stdin));
    if (fdr == -1) {
      printf("Fehler\n");
    }
    fdw = fileno((stdout));
    if (fdw == -1) {
      printf("Fehler\n");
    }
    nr = read(fdr, buf, sizeof(buf));
    if (nr == 0) {
      printf("EOF - End of file\n");
    }
    else if (nr == -1) {
      printf("Fehler\n");
    }
    buf[nr] = '\0';
    printf("%d %s\n", nr, buf);
    if(strncmp(buf, "eof", 3) == 0){
      break;
    }
    nw = write(fdw, buf, nr);
    if (nw != nr) {
      printf("Fehler\n");
    }

  }
  close(fdr);
  close(fdw);
    return 0;
}
