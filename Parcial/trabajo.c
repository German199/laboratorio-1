#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "auto.h"
#include "trabajo.h"
#include "servicio.h"

Trabajos nuevoTrabajo(int idTrabajo, int patente, int idServicio, int dia, int mes, int anio){
    Trabajos x;

    x.id = idTrabajo;
    x.patente = patente;
    x.idServicio = idServicio;
    x.fechaTrabajo.dia = dia;
    x.fechaTrabajo.mes = mes;
    x.fechaTrabajo.anio = anio;
    x.isEmpty = 0;

    return x;
}

int altaTrabajo(int idTrabajo, Trabajos trabajo[], int tamT, Autos vehiculos[], int tamA, Servicios servicio[], int tamS){
    int Ok = 0;
    int idAuto;
    int idServicio;
    int indiceAuto;
    int indiceServicio;
    int indiceTrabajo;
    int dia;
    int auxDia;
    int mes;
    int auxMes;
    int auxCheckMes;
    int anio;
    int auxAnio;

    system("cls");
    printf("\n------ Alta Servicio ------\n");

    indiceTrabajo = buscarLibreTrabajo(trabajo, tamT);

    if (indiceTrabajo == -1){
        printf("No es posible agregar mas trabajos\n");
    } else{
    printf("Ingrese el ID del Auto: ");
    scanf("%d", &idAuto);
    indiceAuto = verificarAutoExistente(idAuto, vehiculos, tamA);

    if (indiceAuto == -1){
        printf("El ID del vehiculo ingresado es invalido\n");
    } else{
        printf("Ingrese el ID del Servicio a aplicar: ");
        scanf("%d", &idServicio);
        indiceServicio = verificarServicioExistente(idServicio, servicio, tamS);
        if (indiceServicio == -1){
            printf("El ID del servicio ingresado es invalido\n");
        } else{
            printf("Ingrese la fecha del Trabajo:\n");
            printf("Dia: ");
            scanf("%d", &auxDia);
            dia = validarDia(auxDia);
            printf("Mes: ");
            scanf("%d", &auxMes);
            auxCheckMes = validarMes(auxMes);
            mes = validarMeses(dia, auxCheckMes);
            printf("Anio: ");
            scanf("%d", &auxAnio);
            anio = validarAnio(auxAnio);

            trabajo[indiceTrabajo] = nuevoTrabajo(idTrabajo, vehiculos[indiceAuto].patente, servicio[indiceServicio].id, dia, mes, anio);
            printf("\nSe ha registrado el Trabajo\n");
            Ok = 1;
            }
        }
    }
    return Ok;
}

void mostrarTrabajo(Trabajos trabajo, Servicios servicio[], int tamS){
    char descServicio[20];
    cargarDescServicio(servicio, tamS, trabajo.idServicio, descServicio);
    printf("  %d              %d     %10s     %02d/%02d/%d\n",
           trabajo.id,
           trabajo.patente,
           descServicio,
           trabajo.fechaTrabajo.dia,
           trabajo.fechaTrabajo.mes,
           trabajo.fechaTrabajo.anio
           );
}

void mostrarTrabajos(Trabajos trabajo[], int tamT, Servicios servicio[], int tamS){
    system("cls");
    printf("------ Lista de Trabajos Realizados ------\n");
    printf("ID TRABAJO        PATENTE       SERVICIO       FECHA\n");
    for (int i = 0; i < tamT; i++){
        if(trabajo[i].isEmpty == 0){
        mostrarTrabajo(trabajo[i], servicio, tamS);
        }
    }
}

void inicializarTrabajos(Trabajos trabajo[], int tamT){
    for(int i = 0; i < tamT; i++){
        trabajo[i].isEmpty = 1;
    }
}

int buscarLibreTrabajo(Trabajos trabajo[], int tamT){
    int indice = -1;
    for(int i = 0; i < tamT; i++){
        if (trabajo[i].isEmpty == 1){
            indice = i;
        }
    }
    return indice;
}

int checkTrabajo(Trabajos trabajo[], int tamT){
    int Ok = 0;
    for (int i = 0; i < tamT; i++){
        if (trabajo[i].isEmpty == 0){
            Ok = 1;
        }
    }
    return Ok;
}

int harcodearTrabajos(Trabajos trabajo[], int tamT, int cantidad){
    int contador;
    Trabajos listaAuxiliar[] = {
        {200, 511511, 20001, {22,3,2005}, 0},
        {201, 852451, 20002, {31,1,2007}, 0},
        {202, 330005, 20003, {15,4,2011}, 0},
        {203, 178435, 20002, {11,10,2009}, 0},
        {204, 567314, 20001, {21,2,2008}, 0},
        {205, 330005, 20003, {18,7,2015}, 0},
        {206, 511511, 20000, {9,5,2014}, 0}
    };
    if (cantidad <= 7 && cantidad <= tamT){
        for (int i = 0; i < cantidad; i++){
            trabajo[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}
