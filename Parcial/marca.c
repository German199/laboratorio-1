#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int harcodearMarcas(Marcas marcas[], int tamM, int cantidad){
    int contador = 0;
        Marcas listaAuxiliar[] = {
            {1000, "Renault"},
            {1001, "Fiat"},
            {1002, "Ford"},
            {1003, "Chevrolet"},
            {1004, "Peugeot"}
            };
    if (cantidad <= 5 && tamM >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            marcas[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarMarca(Marcas marca){
    printf("  %d      %10s\n", marca.id, marca.descripcion);
}

void mostrarMarcas(Marcas marca[], int tamM){
    system("cls");
    printf("------ Lista de marcas ------\n\n");
    printf("ID MARCA     DESCRIPCION\n\n");
    for(int i = 0; i < tamM; i++)
        {
            mostrarMarca(marca[i]);
        }
}

int mostrarDescMarca(int id, Marcas marca[], int tamM, char desc[]){
    int Ok = 0;

    for (int i = 0; i < tamM; i++){
        if (id == marca[i].id){
            strcpy(desc, marca[i].descripcion);
            Ok = 1;
            break;
        }
    }
}
