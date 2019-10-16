#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "color.h"
#include "validaciones.h"
#include "marca.h"

int autoAltaAutos(Autos vehiculos[], int tamA, int idAuto){
    int Ok = 0;
    int indice;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int auxInt;
    int auxPatente;

    system("cls");
    printf("------ Alta de Auto ------\n\n");

    indice = buscarLibreAuto(vehiculos, tamA);
    if (indice == -1){
        printf("Sistema completo, no se puede ingresar nuevo auto\n");
    } else {
            printf("\nIngrese patente: ");
            scanf("%d", &auxInt);
            auxPatente = validarPatente(auxInt);
            while(verificarPatenteExistente(auxPatente, vehiculos, tamA)){
                printf("Patente ingresada ya existe en el sistema, intente nuevamente: ");
                scanf("%d", &auxInt);
                auxPatente = validarPatente(auxInt);
            }
            patente = auxPatente;

            printf("Ingrese ID de la marca del vehiculo: ");
            scanf("%d", &auxInt);
            idMarca = validarMarca(auxInt);

            printf("Ingrese ID del color del vehiculo: ");
            scanf("%d", &auxInt);
            idColor = validarColor(auxInt);

            printf("Ingrese el modelo del vehiculo: ");
            scanf("%d", &auxInt);
            modelo = validarModelo(auxInt);

            vehiculos[indice] = nuevoAuto(idAuto, patente, idMarca, idColor, modelo);
            printf("Se ha registrado el nuevo auto!\n");
            Ok = 1;
    }
    return Ok;
}

int buscarLibreAuto(Autos vehiculos[], int tamA)
{
    int indice = -1;
    for(int i = 0; i < tamA; i++)
    {
        if(vehiculos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int checkAuto(Autos vehiculos[], int tamA)
{
    int Ok = 0;
    for(int i = 0; i < tamA; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            Ok = 1;
        }
    }
    return Ok;
}

Autos nuevoAuto(int id, int patente, int idMarca, int idColor, int modelo){
    Autos x;
    x.id = id;
    x.patente = patente;
    x.idColor = idColor;
    x.idMarca = idMarca;
    x.modelo = modelo;
    x.isEmpty = 0;

    return x;
}

void inicializarAutos(Autos vehiculos[], int tamA)
{
    for(int i = 0; i < tamA; i++)
    {
        vehiculos[i].isEmpty = 1;
    }
}

int bajaAuto(Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color colores[], int tamC){
    int Ok = 0;
    int indice;
    int autos;
    char resp;

    system("cls");
    printf("------ Baja Auto ------\n");
    printf("Ingrese el ID del Auto: ");
    scanf("%d", &autos);

    indice = buscarAutoEnArray(vehiculos, tamA, autos);

    if (indice == -1)
    {
        printf("No se ha encontrado el Auto\n");
    } else{
        printf("\nID AUTO  PATENTE  ID MARCA  ID COLOR  MODELO\n\n");
        mostrarAuto(vehiculos[indice], marca, tamM, colores, tamC);
        printf("\n\nConfimar BAJA (y/n): ");
        fflush(stdin);
        scanf("%c", &resp);

        if(resp == 'y'){
            vehiculos[indice].isEmpty = 1;
            Ok = 1;
            printf("Se ha dado de baja correctamente el vehiculo.\n");
        } else{
            printf("Se ha cancelado exitosamente la operacion.\n");
        }
    }
    return Ok;
}

void mostrarAuto(Autos vehiculos, Marcas marca[], int tamM, Color colores[], int tamC){
    char descColores[20];
    char descMarca[20];

    mostrarDescColor(vehiculos.idColor, colores, tamC, descColores);
    mostrarDescMarca(vehiculos.idMarca, marca, tamM, descMarca);

    printf("  %d    %d %10s   %8s   %d\n",
            vehiculos.id,
            vehiculos.patente,
            descMarca,
            descColores,
            vehiculos.modelo);
}

void mostrarAutos(Autos vehiculos[], int tamA, Marcas marcas[], int tamM, Color color[], int tamC){
    system("cls");
    printf("------ Lista de Vehiculos Actuales ------\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for(int i = 0; i < tamA; i++)
        {
            if (vehiculos[i].isEmpty == 0){
            mostrarAuto(vehiculos[i], marcas, tamM, color, tamC);
            }
        }
}

int menuModificarAutos(Autos vehiculos[], int tamA, Color colores[], int tamC, Marcas marca[], int tamM){
    int Ok = 0;
    int opcion;
    int patente;
    int indice;
    int idColor;
    int modelo;
    int auxInt;
        system("cls");
        printf("------ Modificaciones de Auto ------\n");
        printf("Ingrese patente del vehiculo: \n");
        scanf("%d", &patente);
        indice = buscarPatenteEnArray(vehiculos, tamA, patente);

        if(indice == -1){
            printf("No existe un auto con la patente ingresada. Volviendo al menu..\n");
        } else{
        printf("\nID AUTO   PATENTE  ID MARCA  ID COLOR  MODELO\n\n");
        mostrarAuto(vehiculos[indice], marca, tamM, colores, tamC);
        printf("\n1) MODIFICAR COLOR\n");
        printf("2) MODIFICAR MODELO\n");
        printf("3) SALIR\n\n");
        printf("Elija opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
    case 1:
        printf("Ingrese la nueva ID de color: ");
        scanf("%d", &auxInt);
        idColor = validarColor(auxInt);
        vehiculos[indice].idColor = idColor;
            printf("Se ha modificado exitosamente el color.\n\n");
            Ok = 1;
        break;
    case 2:
        printf("Ingrese la fecha del modelo: ");
        scanf("%d", &auxInt);
        modelo = validarModelo(auxInt);
        vehiculos[indice].modelo = modelo;
            printf("Se ha modificado exitosamente el modelo.\n\n");
            Ok = 1;
        break;
    case 3:
        printf("Saliendo del menu...\n");
        break;
    default:
        printf("Opcion invalida\n");
        break;
        }
    }
    return Ok;
}

int buscarAutoEnArray(Autos vehiculos[], int tamA, int id){

    int indice = -1;
    for (int i = 0; i < tamA; i++){
        if (vehiculos[i].id == id && vehiculos[i].isEmpty == 0){
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPatenteEnArray(Autos vehiculos[], int tamA, int patente){

    int indice = -1;
    for (int i = 0; i < tamA; i++){
        if (vehiculos[i].patente == patente && vehiculos[i].isEmpty == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

void listarVehiculosOrdenados(Autos vehiculos[], int tamA){
    int auxInt;
    for (int i = 0; i < tamA - 1; i++){
        for(int j = i + 1; j < tamA; j++){
            if(vehiculos[i].idMarca > vehiculos[j].idMarca && vehiculos[i].isEmpty == 0 && vehiculos[j].isEmpty == 0){
                auxInt = vehiculos[i].id;
                vehiculos[i].id = vehiculos[j].id;
                vehiculos[j].id = auxInt;

                auxInt = vehiculos[i].patente;
                vehiculos[i].patente = vehiculos[j].patente;
                vehiculos[j].patente = auxInt;

                auxInt = vehiculos[i].idMarca;
                vehiculos[i].idMarca = vehiculos[j].idMarca;
                vehiculos[j].idMarca = auxInt;

                auxInt = vehiculos[i].idColor;
                vehiculos[i].idColor = vehiculos[j].idColor;
                vehiculos[j].idColor = auxInt;

                auxInt = vehiculos[i].modelo;
                vehiculos[i].modelo = vehiculos[j].modelo;
                vehiculos[j].modelo = auxInt;
            }
            if (vehiculos[i].idMarca == vehiculos[j].idMarca && vehiculos[i].patente > vehiculos[j].patente && vehiculos[i].isEmpty == 0 && vehiculos[j].isEmpty == 0){
                auxInt = vehiculos[i].id;
                vehiculos[i].id = vehiculos[j].id;
                vehiculos[j].id = auxInt;

                auxInt = vehiculos[i].patente;
                vehiculos[i].patente = vehiculos[j].patente;
                vehiculos[j].patente = auxInt;

                auxInt = vehiculos[i].idMarca;
                vehiculos[i].idMarca = vehiculos[j].idMarca;
                vehiculos[j].idMarca = auxInt;

                auxInt = vehiculos[i].idColor;
                vehiculos[i].idColor = vehiculos[j].idColor;
                vehiculos[j].idColor = auxInt;

                auxInt = vehiculos[i].modelo;
                vehiculos[i].modelo = vehiculos[j].modelo;
                vehiculos[j].modelo = auxInt;
            }
        }
    }
}

int harcodearAutos(Autos vehiculos[], int tamA, int cantidad){
    int contador;

    Autos listaAuxiliar[] = {
        {7000, 842365, 1000, 5005, 1950, 0},
        {7001, 321789, 1002, 5001, 1987, 0},
        {7002, 258963, 1001, 5003, 2000, 0},
        {7003, 487521, 1000, 5002, 1970, 0},
        {7004, 993254, 1004, 5004, 2002, 0},
        {7005, 555896, 1001, 5006, 2001, 0},
        {7006, 255690, 1002, 5000, 1999, 0}
    };
    if (cantidad <= 7 && cantidad <= tamA){
        for (int i = 0; i < cantidad; i++){
            vehiculos[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}
