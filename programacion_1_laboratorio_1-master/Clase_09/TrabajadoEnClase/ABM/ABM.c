#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "ABM.h"

void mostrarAlumno(eAlumno x){
    printf("  %d  %20s    %d    %c    %2d    %2d    %.2f     %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam){
    int flag = 0;

    printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
    for(int i=0; i < tam; i++){
        if(vec[i].isEmpty == 0){
        mostrarAlumno(vec[i]);
        flag = 1;
        }
    }
    if (flag == 0)
    {
        system("cls");
        printf("\nNo se ha encontrado Alumnos.");
    }
printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

int menu(){
    int opcion;

    system("cls");
    printf("-------Menu de Opciones-------\n\n");
    printf("1.- ALTA Alumno\n");
    printf("2.- BAJA Alumno\n");
    printf("3.- MODIFICAR Alumno\n");
    printf("4.- LISTAR Alumnos\n");
    printf("5.- ORDENAR Alumnos\n");
    printf("6.- Informes\n");
    printf("7.- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void startAlumnos(eAlumno alumnos[], int tam){
    for (int i = 0; i < tam; i++){
        alumnos[i].isEmpty = 1;
    }
}

int searchEmpty(eAlumno alumnos[], int tam){
    int indice = -1;
        for(int i = 0; i < tam; i++){
         if (alumnos[i].isEmpty){
          indice = i;
          break;
         }
        }
    return indice;
}

int searchAlumno(int legajo, eAlumno alumnos[], int tam){
    int indice = -1;
        for(int i = 0; i < tam; i++){
         if (!alumnos[i].isEmpty && alumnos[i].legajo == legajo){
          indice = i;
          break;
        }
    }
    return indice;
}

int highAlumno(eAlumno alumnos[], int tam){
    int seguir = 0;
    int indice;
    int disponible;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    int nota1aux;
    int nota2aux;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("-----  ALTA ALUMNO  -----\n\n");
    indice = searchEmpty(alumnos, tam);
    // Pregunto si quedan lugares para ingresar alumnos
    if (indice == -1){
        printf("Sistema Completo. Imposible ingresar mas alumnos.\n");
    } else{ // INGRESO ALUMNO
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);
        disponible = searchAlumno(legajo, alumnos, tam);
        if (disponible != -1){
            printf("Legajo ya registrado.\n");
            mostrarAlumno(alumnos[disponible]);
            system("pause");
        } else{
            printf("Ingrese nombre (Maximo 20 caracteres): ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad (18-60):");
            scanf("%d", &edad);
            while (edad > 60 || edad < 18){
                printf("Error, edad ingresada invalida. Reingrese: ");
                scanf("%d", &edad);
            }

            printf("Ingrese sexo ('f' o 'm'): ");
            fflush(stdin);
            scanf("%c", &sexo);
            while (sexo != 'f' && sexo != 'm'){
                printf("Error, sexo ingresado invalido. Reingrese: ");
                fflush(stdin);
                scanf("%c", &sexo);
            }

            printf("Ingrese nota parcial 1 (0-10):");
            scanf("%d", &nota1aux);
            while(nota1aux > 10 || nota1aux < 0){
                    printf("Error, nota ingresada invalida. Reingrese: ");
                    scanf("%d", &nota1aux);
                }
            nota1 = nota1aux;

            printf("Ingrese nota parcial 2 (0-10):");
            scanf("%d", &nota2aux);
            while(nota2aux > 10 || nota2aux < 0)
                {
                    printf("Error, nota ingresada invalida. Reingrese: ");
                    scanf("%d", &nota2aux);
                }
            nota2 = nota2aux;

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }
            //Armo una estructura auxiliar de un alumno en una nueva funcion
            alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha);
            printf("\nSe ha registrado exitosamente el Alumno.\n\n");
            seguir = 1;
        }
    return seguir;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha){
    eAlumno nuevoAlumno;

            nuevoAlumno.legajo = legajo;
            strcpy(nuevoAlumno.nombre, nombre);
            nuevoAlumno.edad = edad;
            nuevoAlumno.sexo = sexo;
            nuevoAlumno.nota1 = n1;
            nuevoAlumno.nota2 = n2;
            nuevoAlumno.promedio = (float) (n1+n2) / 2;
            nuevoAlumno.fechaIngreso = fecha;
            nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int lowAlumno (eAlumno alumnos[], int tam){
    int seguir = 0;
    int indice;
    int legajo;
    char resp;

    system("cls");
    printf("-----  BAJA ALUMNO  -----\n\n");

    printf("Ingrese el legajo correspondiente: ");
    scanf("%d", &legajo);

    indice = searchAlumno(legajo, alumnos, tam);
    if (indice == -1){
        printf("Legajo ingresado no existe en el sistema.\n");
        system("pause");
    } else{
        mostrarAlumno(alumnos[indice]);
        printf("Confirma BAJA?: ");
        fflush(stdin);
        resp = getche();
        if (resp == 's'){
            alumnos[indice].isEmpty = 1;
            printf("\n\nAlumno dado de BAJA.\n\n");
            seguir = 1;
        } else{
            printf("\n\nSe ha cancelado la operacion.\n");
        }
    }
    return seguir;
}

int modifyAlumno(eAlumno alumnos[], int tam){
    int seguir = 0;
    int indice;
    int legajo;
    int resp;
    int nota1;
    int nota2;

    system("cls");
    printf("-----  MODIFICAR ALUMNO  -----\n\n");

    printf("Ingrese el legajo correspondiente: ");
    scanf("%d", &legajo);

    indice = searchAlumno(legajo, alumnos, tam);
    if (indice == -1){
        printf("Legajo ingresado no existe en el sistema.\n");
        system("pause");
    } else {
        printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
        mostrarAlumno(alumnos[indice]);
        printf("\nElija lo que desea modificar:\n\n");
        printf("1.) Legajo\n");
        printf("2.) Nombre\n");
        printf("3.) Edad\n");
        printf("4.) Sexo\n");
        printf("5.) Nota del Primer Parcial\n");
        printf("6.) Nota del Segundo Parcial\n");
        printf("7.) Cancelar operacion\n\n");
        printf("Opcion elegida: ");
        scanf("%d", &resp);
        switch (resp){
            case 5:
            printf("Ingrese la nueva nota (PRIMER PARCIAL): ");
            scanf("%d", &nota1);
            alumnos[indice].nota1 = nota1;
            printf("\n\nNota del Primer Parcial MODIFICADO.\n\n");
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
            mostrarAlumno(alumnos[indice]);
            seguir = 1;
            break;
            case 6:
            printf("Ingrese la nueva nota (SEGUNDO PARCIAL): ");
            scanf("%d", &nota2);
            alumnos[indice].nota2 = nota2;
            printf("\n\nNota del Segundo Parcial MODIFICADO.\n\n");
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("-----  ALUMNO CON DATOS ACTUALIZADOS  -----\n\n");
            printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
            mostrarAlumno(alumnos[indice]);
            seguir = 1;
            case 7:
            printf("\n\nSe ha cancelado la operacion.\n");
            break;
        }
    }
    return seguir;
}
