#include <stdio.h>
#include <stdlib.h>
#include "diaz.h"

int main()
{
    int numero;
    int todoOk;

    todoOk = getIntRange( &numero, "Ingrese edad ", "Error. Reingrese edad ", 18, 65, 3);

    if( todoOk == 0){
        printf("No ingreso un numero valido");
    }
    else{
        printf("El numero ingresado es %d\n", numero);
    }

    return 0;
}
