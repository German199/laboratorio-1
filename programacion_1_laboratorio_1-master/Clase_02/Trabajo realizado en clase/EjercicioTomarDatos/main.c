#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char nombre[20];
   char nombreMin[20];
   char nombreMax[20];
   char sexo;
   char sexoMax;
   char sexoMin;
   int contador = 0;
   int contadorF = 0;
   int acumNotas = 0;
   int acumNotasF = 0;
   int nota;
   int notaMayor;
   int notaMenor;
   int flag = 0;
   float promedioTotales;
   float promedioF = 0;
   char respuesta;

   do{
    printf("\nIngrese un nombre: ");
    gets(nombre);

    printf("\nIngrese la nota: ");
    fflush(stdin);
    scanf("%d", &nota);

    while (nota < 0 || nota > 10)
        {
            printf("Error, debe ingresar una nota entre 0-10: ");
            fflush(stdin);
            scanf("%d", &nota);
        }

    printf("\nIngrese el sexo (f/m): ");
    fflush(stdin);
    scanf("%c", &sexo);

    while (sexo != 'f' && sexo != 'm')
        {
            printf("Error, debe ingresar f o m: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }
    acumNotas += nota;
    contador++;

    if (sexo == 'f')
        {
            acumNotasF += nota;
            contadorF++;
        }
    if (nota < notaMayor || flag == 0)
        {
            strcpy(nombreMax, nombre);
            notaMayor = nota;
            sexoMax = sexo;
        }
    if (nota > notaMenor || flag == 0)
        {
            strcpy(nombreMin, nombre);
            notaMenor = nota;
            sexoMin = sexo;
            flag = 1;
        }

    printf("\n¿Desea continuar?: ");
    fflush(stdin);
    respuesta = getche();
   }while (respuesta == 's');

   promedioTotales = (float) acumNotas / contador;

   if (contadorF != 0)
   {
       promedioF = (float) acumNotasF / contadorF;
   }

   printf("Promedio de notas totales: %.2f\n", promedioTotales);
   printf("Promedio de notas de Mujeres: %.2f\n", promedioF);
   printf("Nota maxima: %d - Nombre: %s - Sexo: %c\n", notaMayor, nombreMax,sexoMax);
   printf("Nota minima: %d - Nombre: %s - Sexo: %c\n", notaMenor, nombreMin,sexoMin);
}
    // printf("%s %c %d\n", nombre, sexo, nota); Esto me ayuda a comprobar los datos
