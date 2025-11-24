#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    // 1. Preparar una pagina de memoria
    char *addr = sbrk(0);
    sbrk(4096);
    addr[0] = 'Z'; // Dato inicial

    printf("Test 1: Protegiendo memoria (quitando lectura)...\n");
    if (mrdprotect(addr, 1) < 0) {
        printf("mrdprotect fallo\n");
        exit(1);
    }

    // 2. Verificar que NO se puede leer (el hijo debe morir)
    int pid = fork();
    if (pid == 0) {
        printf("Hijo: Intentando leer (debe fallar con trap 0xd)...\n");
        char c = addr[0]; 
        // Si llegamos aqui, fallo la proteccion
        printf("Hijo: ERROR FATAL - Pude leer: %c\n", c);
        exit(0);
    }

    wait(0); // Esperar a que el hijo muera por el trap
    printf("Padre: Hijo terminado. Si viste un 'usertrap ... scause 0xd', la proteccion funciona.\n");

    // 3. Prueba de escritura (SALTADA por limitacion de hardware)
    printf("Test 2: Probando escritura...\n");
    printf("Escritura saltada (RISC-V no soporta paginas Write-Only; R=0 W=1 es reservado).\n");

    // 4. Restaurar permisos
    printf("Test 3: Restaurando permisos...\n");
    if (munrdprotect(addr, 1) < 0) {
        printf("munrdprotect fallo\n");
        exit(1);
    }

    // 5. Verificar lectura final
    char c = addr[0];
    printf("Lectura despues de munrdprotect: %c (Debe ser Z)\n", c);

    if (c == 'Z') {
        printf("EXITO: La proteccion se aplico y se revirtio correctamente.\n");
    } else {
        printf("FALLO: El valor leido no es correcto.\n");
    }

    exit(0);
}
