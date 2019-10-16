#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int harcodearServicios(Servicios servicio[], int tamS, int cantidad){
    int contador = 0;
        Servicios listaAuxiliar[] = {
            {20000, "Lavado", 250},
            {20001, "Pulido", 300},
            {20002, "Encerado", 400},
            {20003, "Completo", 600}
            };
    if (cantidad <= 4 && tamS >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            servicio[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarServicio(Servicios servicio){
    printf("  %d         %10s        $%d\n",servicio.id, servicio.descripcion, servicio.precio);
}

void mostrarServicios(Servicios servicio[], int tamS){
    printf("ID SERVICIO      DESCRIPCION     PRECIO\n");
    for (int i = 0; i < tamS; i++){
        mostrarServicio(servicio[i]);
    }
    printf("\n");
}

int cargarDescServicio(Servicios servicio[], int tamS, int idServicio, char desc[]){
    int Ok = 0;
    for(int i=0; i < tamS; i++){
        if(idServicio == servicio[i].id){
            strcpy(desc, servicio[i].descripcion);
            Ok = 1;
            break;
        }
    }

    return Ok;
}
