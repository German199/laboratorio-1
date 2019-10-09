#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 19

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[50];
    char auxCad[100];
    int i = 0;

    printf("Ingrese un nombre: ");
    gets(nombre);
    while (strlen(auxCad) > TAM)
    {
        printf("Error! Nombre demasiado largo, reingrese: ");
        gets(nombre);
    }
    strcpy(auxCad, nombre);
    printf("Ingrese un apellido: ");
    gets(apellido);
    while (strlen(auxCad) > TAM)
    {
        printf("Error! Apellido demasiado largo, reingrese: ");
        gets(apellido);
    }
    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);
    strlwr(nombreCompleto); // Paso todo a minusculas

    nombreCompleto[0] = toupper(nombreCompleto[0]);
    while (nombreCompleto[i] != '\0')
    {
        if(nombreCompleto[i] == ' ') // pregunto dentro de la cadena cuando un caracter es un espacio
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]); // si lo encuentra, el siguiente caracter sera una mayuscula
        }
        i++;
    }
    printf("%s\n", nombreCompleto);
    return 0;
}
