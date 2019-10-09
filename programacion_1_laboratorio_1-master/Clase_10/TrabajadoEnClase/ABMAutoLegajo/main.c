#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ABM.h"

#define TAM 10
#define TAMC 3
int main()
{
    eAlumno lista[TAM];
    eCarrera carreras[] = {
    {1000, "TUP"},
    {1001, "TUSI"},
    {1002, "LICP"},
    };

    char salir = 'n';
    int legajo = 20000;

    startAlumnos(lista, TAM);

    // Esta linea luego se vea, ONLY FOR TESTING
    legajo = legajo + hardcodearAlumnos(lista, TAM, 10);

    do{
        switch(menu()){
    case 1:
        //highAlumno(lista, TAM);
        if (highAlumnoAuto(lista, TAM, legajo)){
            legajo++;
        }
        break;
    case 2:
        lowAlumno(lista, TAM, carreras, TAMC);
        break;
    case 3:
        modifyAlumno(lista, TAM, carreras, TAMC);
        break;
    case 4:
        mostrarAlumnos(lista, TAM, carreras, TAMC);
        break;
    case 5:
        ordenarAlumnos(lista, TAM);
        break;
    case 6:
        printf("-----INFORMES-----\n");
        break;
    case 7:
        mostrarCarreras(carreras, 3);
        break;
    case 8:
        printf("Confirma salida?");
        printf("\n\n");
        fflush(stdin);
        salir = getch();
        break;
    default:
        printf("Opcion Invalida.\n");
        }
    system("pause");
    }while(salir == 'n');

      return 0;
}
