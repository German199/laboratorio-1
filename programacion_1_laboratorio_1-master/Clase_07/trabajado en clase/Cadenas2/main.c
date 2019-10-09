#include <stdio.h>
#include <stdlib.h>

void mostrarNombres(char matriz[][20], int tam);
int main()
{
    char nombres[5][20]; //definimos una matriz de nombres (5 filas y 20 caracteres cada una)

    for (int i = 0; i < 5; i++)
        {
            printf("Ingrese un nombre: ");
            fflush(stdin);
            gets(nombres[i]);
        }
    mostrarNombres(nombres, 5);

    printf("\n\n");
    return 0;
}

void mostrarNombres(char matriz[][20])
{
    for (int i = 0; i < tam; i++)
        {
            printf("%s\n", nombres[i]);
        }
}
