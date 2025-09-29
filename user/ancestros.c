#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int a0 = getancestor(0);
  int a1 = getancestor(1);
  int a2 = getancestor(2);
  int a3 = getancestor(3); // probablemente -1

  printf("getancestor(0) (yo)        = %d\n", a0);
  printf("getancestor(1) (padre)     = %d\n", a1);
  printf("getancestor(2) (abuelo)    = %d\n", a2);
  printf("getancestor(3) (bisabuelo) = %d\n", a3);

  // chequeos cruzados opcionales:
  // printf("getpid()=%d  getppid()=%d\n", getpid(), getppid());

  exit(0);
}
