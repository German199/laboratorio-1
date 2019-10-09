#include "diaz.h"

int getIntRange(int* num, char* mensaje, char* mensajeError, int min, int max, int intentos){

   int auxiliar;
   int todoOk =0;


    printf("%s", mensaje);
    scanf("%d", &auxiliar);


    while( auxiliar < min || auxiliar > max){
              intentos--;
        if( intentos == 0){
            break;
        }

        printf("%s", mensajeError);
        scanf("%d", &auxiliar);

    }
    if( intentos != 0){
        *num = auxiliar;
        todoOk = 1;
    }
    return todoOk;
}
