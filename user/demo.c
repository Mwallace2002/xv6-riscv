#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int N = 10;
  if(argc > 1) N = atoi(argv[1]);

  for(int i = 0; i < N; i++){
    int pid = fork();
    if(pid < 0){
      printf("fork failed\n");
      exit(1);
    }
    if(pid == 0){
      // hijo: asigna tickets distintos
      int t = 50 * (i + 1);      // 50,100,150,...
      settickets(t);

      // carga de CPU para que compitan
      volatile int x = 0;
      for (uint64 k = 0; k < (1ULL<<26); k++) x += k;

      // listo
      exit(0);
    }
  }

  // padre espera a todos; WAIT imprimirá stats (Paso 5)
  for(int i = 0; i < N; i++)
    wait(0);

  exit(0);
}
