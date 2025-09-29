#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  int p = fork();
  if (p == 0) {
    // Proceso hijo
    printf("Soy el hijo, mi padre es: %d\n", getppid());
  } else {
    // Proceso padre
    wait(0);
  }
  exit(0);
}
