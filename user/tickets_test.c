#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int r;

  // Si se pasa un argumento, lo usamos como cantidad de tickets
  if(argc > 1) {
    int n = atoi(argv[1]);
    r = settickets(n);
    if(r < 0)
      printf("Error al asignar tickets\n");
    else
      printf("Tickets asignados a %d\n", n);
  } else {
    // Caso sin argumentos, probamos con un valor fijo
    r = settickets(200);
    if(r < 0)
      printf("Error al asignar tickets\n");
    else
      printf("Tickets asignados por defecto a 200\n");
  }

  exit(0);
}
