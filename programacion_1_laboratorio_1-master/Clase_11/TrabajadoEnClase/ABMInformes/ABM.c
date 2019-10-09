#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "ABM.h"

void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam)
{
    char descCarrera[20];
    cargarDescCarrera(x.idCarrera, carreras, tam, descCarrera);
    printf("  %d  %10s   %d    %c    %2d    %2d    %3.2f     %02d/%02d/%d      %s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descCarrera);
}

void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC)
{
    int flag = 0;

    printf(" Legajo       Nombre  Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso Carrera\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i], carreras, tamC);
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

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].promedio > vec[j].promedio && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("\n Alumnos ordenados por promedio.\n\n");
}

int menu()
{
    int opcion;

    system("cls");
    printf("-------Menu de Opciones-------\n\n");
    printf("1.- ALTA Alumno\n");
    printf("2.- BAJA Alumno\n");
    printf("3.- MODIFICAR Alumno\n");
    printf("4.- LISTAR Alumnos\n");
    printf("5.- ORDENAR Alumnos\n");
    printf("6.- INFORMES\n");
    printf("7.- MOSTRAR Carreras\n");
    printf("8.- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void startAlumnos(eAlumno alumnos[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        alumnos[i].isEmpty = 1;
    }
}

int searchEmpty(eAlumno alumnos[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if (alumnos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int searchAlumno(int legajo, eAlumno alumnos[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if (!alumnos[i].isEmpty && alumnos[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int highAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int seguir = 0;
    int indice;
    int disponible;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    int nota1aux;
    int nota2aux;
    int idCarrera;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("-----  ALTA ALUMNO  -----\n\n");
    indice = searchEmpty(alumnos, tam);
    // Pregunto si quedan lugares para ingresar alumnos
    if (indice == -1)
    {
        printf("Sistema Completo. Imposible ingresar mas alumnos.\n");
    }
    else    // INGRESO ALUMNO
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);
        disponible = searchAlumno(legajo, alumnos, tam);
        if (disponible != -1)
        {
            printf("Legajo ya registrado.\n");
            mostrarAlumno(alumnos[disponible], carreras, tamC);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre (Maximo 20 caracteres): ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad (18-60):");
            scanf("%d", &edad);
            while (edad > 60 || edad < 18)
            {
                printf("Error, edad ingresada invalida. Reingrese: ");
                scanf("%d", &edad);
            }

            printf("Ingrese sexo ('f' o 'm'): ");
            fflush(stdin);
            scanf("%c", &sexo);
            while (sexo != 'f' && sexo != 'm')
            {
                printf("Error, sexo ingresado invalido. Reingrese: ");
                fflush(stdin);
                scanf("%c", &sexo);
            }

            printf("Ingrese nota parcial 1 (0-10):");
            scanf("%d", &nota1aux);
            while(nota1aux > 10 || nota1aux < 0)
            {
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

            printf("Ingrese la ID de la carrera correspondiente: ");
            scanf("%d", &idCarrera);
        }
        //Armo una estructura auxiliar de un alumno en una nueva funcion
        alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, idCarrera, fecha);
        printf("\nSe ha registrado exitosamente el Alumno.\n\n");
        seguir = 1;
    }
    return seguir;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2,int idCarrera, eFecha fecha)
{
    eAlumno nuevoAlumno;

    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1+n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.idCarrera = idCarrera;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int lowAlumno (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int seguir = 0;
    int indice;
    int legajo;
    char resp;

    system("cls");
    printf("-----  BAJA ALUMNO  -----\n\n");

    printf("Ingrese el legajo correspondiente: ");
    scanf("%d", &legajo);

    indice = searchAlumno(legajo, alumnos, tam);
    if (indice == -1)
    {
        printf("Legajo ingresado no existe en el sistema.\n");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice], carreras, tamC);
        printf("Confirma BAJA?: ");
        fflush(stdin);
        resp = getche();
        if (resp == 's')
        {
            alumnos[indice].isEmpty = 1;
            printf("\n\nAlumno dado de BAJA.\n\n");
            seguir = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la operacion.\n");
        }
    }
    return seguir;
}

int modifyAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
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
    if (indice == -1)
    {
        printf("Legajo ingresado no existe en el sistema.\n");
        system("pause");
    }
    else
    {
        printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
        mostrarAlumno(alumnos[indice], carreras, tamC);
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
        switch (resp)
        {
        case 5:
            printf("Ingrese la nueva nota (PRIMER PARCIAL): ");
            scanf("%d", &nota1);
            alumnos[indice].nota1 = nota1;
            printf("\n\nNota del Primer Parcial MODIFICADO.\n\n");
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf(" Legajo               Nombre   Edad Sexo Nota1 Nota2 Promedio Fecha de Ingreso\n");
            mostrarAlumno(alumnos[indice], carreras, tamC);
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
            mostrarAlumno(alumnos[indice], carreras, tamC);
            seguir = 1;
        case 7:
            printf("\n\nSe ha cancelado la operacion.\n");
            break;
        }
    }
    return seguir;
}

int highAlumnoAuto(eAlumno alumnos[], int tam, int leg)
{
    int seguir = 0;
    int indice;
    int edad;
    int nota1;
    int nota2;
    int nota1aux;
    int nota2aux;
    int idCarrera;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("-----  ALTA ALUMNO  -----\n\n");
    indice = searchEmpty(alumnos, tam);
    // Pregunto si quedan lugares para ingresar alumnos
    if (indice == -1)
    {
        printf("Sistema Completo. Imposible ingresar mas alumnos.\n");
    }
    else
    {
        printf("Ingrese nombre (Maximo 20 caracteres): ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad (18-60):");
        scanf("%d", &edad);
        while (edad > 60 || edad < 18)
        {
            printf("Error, edad ingresada invalida. Reingrese: ");
            scanf("%d", &edad);
        }

        printf("Ingrese sexo ('f' o 'm'): ");
        fflush(stdin);
        scanf("%c", &sexo);
        while (sexo != 'f' && sexo != 'm')
        {
            printf("Error, sexo ingresado invalido. Reingrese: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        printf("Ingrese nota parcial 1 (0-10):");
        scanf("%d", &nota1aux);
        while(nota1aux > 10 || nota1aux < 0)
        {
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

        printf("Ingrese la ID de la carrera correspondiente: ");
        scanf("%d", &idCarrera);

        //Armo una estructura auxiliar de un alumno en una nueva funcion
        alumnos[indice] = newAlumno(leg, nombre, sexo, edad, nota1, nota2, idCarrera, fecha);
        printf("\nSe ha registrado exitosamente el Alumno.\n\n");
        seguir = 1;
    }
    return seguir;
}

int hardcodearAlumnos(eAlumno vec[], int tam, int cantidad)
{
    int counter = 0;
    eAlumno listaAuxiliar[] =
    {
        {20000, "Juan", 21, 'm', 2, 10, 6, {12, 5, 2018}, 1000, 0},
        {20001, "Ana", 19, 'f', 5, 10, 7.5, {25, 8, 2017}, 1002, 0},
        {20002, "Pedro", 25, 'm', 8, 6, 7, {12, 6, 2016}, 1001, 0},
        {20003, "Enrique", 20, 'm', 9, 10, 9.5, {12, 3, 2015}, 1001, 0},
        {20004, "Tiziano", 22, 'm', 4, 3, 3.5, {25, 3, 2018}, 1000, 0},
        {20005, "Florencia", 21, 'f', 1, 10, 5.5, {25, 4, 2019}, 1002, 0},
        {20006, "Alejandra", 23, 'f', 10, 10, 10, {25, 5, 2014}, 1002, 0},
        {20007, "Cristian", 27, 'm', 8, 4, 6, {15, 8, 2010}, 1000, 0},
        {20008, "Rodolfo", 24, 'm', 3, 9, 6, {5, 1, 2009}, 1001, 0},
        {20009, "Maria", 19, 'f', 7, 8, 7.5, {12, 11, 2005}, 1002, 0},
    };

    if (cantidad <= tam && cantidad < 11)
    {
        for (int i = 0; i < cantidad; i++)
        {
            vec[i] = listaAuxiliar[i];
            counter++;
        }
    }
    return counter;
}

void mostrarCarreras(eCarrera vec[], int tam)
{
    printf("   ID     Descripcion\n\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarCarrera(vec[i]);
    }
    printf("\n\n");
}

void mostrarCarrera(eCarrera carrera)
{
    printf("  %d      %s\n", carrera.id, carrera.description);
}

int cargarDescCarrera(int idCarrera, eCarrera carreras[], int tam, char descripcion[])
{
    int todoOk = 0;

    for (int i = 0; i < tam; i++)
    {
        if (carreras[i].id == idCarrera)
        {
            strcpy(descripcion, carreras[i].description);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int menuInformes ()
{

    int opcion;

    system("cls");
    printf("--------- INFORMES ---------\n\n");
    printf("1) Mostrar alumnos por carrera\n");
    printf("2) Mostrar alumnos de cada carrera\n");
    printf("3) Mostrar cantidad de alumnos por carrera\n");
    printf("4) Mostrar carrera con mas inscriptos\n");
    printf("5) Mostrar mejor promedio general\n");
    printf("6) Mostrar mejor promedio por carrera\n");
    printf("7) Mostrar alumnos varones\n");
    printf("8) Mostrar mujeres de alguna carrera\n");
    printf("9) Mostrar alumnos mayores a 30 de licenciatura\n");
    printf("10) Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    char salir = 'n';
    system("cls");
    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;
        case 2:
            mostrarAlumnoXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 3:
            mostrarCantidadAlumnosPorCarrera(alumnos, tam, carreras, tamC);
            break;
        case 4:
            carreraConMasInscriptos(alumnos, tam, carreras, tamC);
            break;
        case 5:
            printf("Informe 5\n");
            break;
        case 6:
            mejoresPromediosXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 7:
            printf("Informe 7\n");
            break;
        case 8:
            printf("Informe 8\n");
            break;
        case 9:
            printf("Informe 9\n");
            break;
        case 10:
            printf("Confirma salir?: ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("\nOpcion Invalida. Reingrese...\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}


void mostrarAlumnoXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    system("cls");
    printf("------ Listado de Alumnos por Carrera ------\n\n");
    for(int i = 0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }
    printf("\n");
}

void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    system("cls");
    int idCarrera;
    printf("------ Carreras ------\n\n");

    mostrarCarreras(carreras, tamC);
    printf("Ingrese el ID de la carrera: ");
    scanf("%d", &idCarrera);
    fflush(stdin);
    // VALIDACION

    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int id)
{
    char desc[20];
    int flag = 0;

    cargarDescCarrera(id, carreras, 20, desc);
    printf("Carrera: %s\n\n", desc);
    for (int i = 0; i < tam; i++)
    {
        if(alumnos[i].idCarrera == id && alumnos[i].isEmpty == 0)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No se han encontrado Alumnos cursando %s.\n", desc);
    }
}

void mostrarCantidadAlumnosPorCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int counter = 0;
    char desc[20];
    printf("------ ALUMNOS SEGUN CARRERA ------\n\n");
    for (int i = 0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        for (int j = 0; j < tam; j++)
        {
            if (alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                counter++;
            }
        }
        printf("Cantidad de Alumnos de %s: %d\n", desc, counter);
        //printf("Cantidad: %d\n", counter);
        counter = 0;
    }
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam, int id)
{
    int counter = 0; //

    for (int i = 0; i < tam; i++)
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == id)
        {
            counter++;
        }
    }
    return counter;
}

void carreraConMasInscriptos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int cantidades[tamC];
    int mayor;
    int flag = 0;
    char desc[20];
    printf("------  CARRERA CON MAS INSCRIPTOS ------\n\n");

    for (int i = 0; i < tamC; i++)
    {
        cantidades[i] = cantidadAlumnosCarrera(alumnos, tam, carreras[i].id);
    }
    for (int i = 0; i < tamC; i++)
    {
        if (mayor < cantidades[i] || flag == 0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }
    for (int i = 0; i < tamC; i++)
    {
        if(cantidades[i] == mayor)
        {
            cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
            printf("Carrera %s con %d Alumno(s)\n", desc, mayor);
        }
    }
}

void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char desc[20];
    float mayor;
    int flag = 0;
    system("cls");
    printf("------ Mejores Promedios por Carrera ------\n\n");

    for( int i=0; i < tamC; i++){
         cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
         printf("Carrera: %s\n", desc);

         for(int j=0; j < tam; j++){
            if((mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id)){
                mayor = alumnos[j].promedio;
                flag = 1;
            }
         }

         printf("Mejor promedio: %.2f\n\n", mayor);
         mayor = 0;
         flag = 0;
    }
}
