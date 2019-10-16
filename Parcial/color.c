#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int harcodearColores(Color colores[], int tamC, int cantidad){
    int contador = 0;
        Color listaAuxiliar[] = {
            {5000, "Negro"},
            {5001, "Blanco"},
            {5002, "Gris"},
            {5003, "Rojo"},
            {5004, "Azul"}
            };
    if (cantidad <= 5 && tamC >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            colores[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarColor(Color col){
    printf("  %d    %10s\n", col.id, col.nombreColor);
}

void mostrarColores(Color colores[], int tamC){
    system("cls");
    printf("------ Lista de Colores ------\n\n");
    printf("ID COLOR     DESCRIPCION\n\n");
    for(int i = 0; i < tamC; i++)
        {
            mostrarColor(colores[i]);
        }
    printf("\n");
}

int mostrarDescColor(int id, Color color[], int tamC, char desc[]){
    int Ok = 0;

    for (int i = 0; i < tamC; i++){
        if (id == color[i].id){
            strcpy(desc, color[i].nombreColor);
            Ok = 1;
            break;
        }
    }
    return Ok;
}
