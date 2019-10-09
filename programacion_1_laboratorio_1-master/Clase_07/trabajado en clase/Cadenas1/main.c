#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // la biblioteca string.h es para strlen - strcpy/strncpy - strcmp/stricmp

int main()
{
    /*char nombre[10];
    char auxCad[100];

    printf("Ingrese un nombre: ");
    gets(auxCad);

    while( strlen(auxCad) > 9)
     {
         printf("Error! Nombre demasiado largo. Reingrese: ");
         gets(auxCad);
     }
    strcpy(nombre, auxCad);
    printf("%s\n", nombre);

    return 0;
    */

    char n1[10] = "Juan";
    char n2[10] = "alberto";

    strcat(n1, n2);

    printf("%s\n", n1);

    return 0;
}


// strupr = Convierte una cadena de caracteres en MAYUSCULAS
// strlwr = Convierte una cadena de caracteres en minusculas
// n2[0] = toupper(n2[0]) devuelve el primer caracter en MAYUSCULAS
