#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "marca.h"
#include "fecha.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"

#define TAMF 100
#define TAMM 5
#define TAMC 5
#define TAMA 15
#define TAMS 4
#define TAMT 25

int menuPrincipal();

void mostrarVehiculosModernos(Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color color[], int tamC);
void precioTotalTrabajos(Trabajos trabajo[], int tamT, Servicios servicio[], int tamS);
void menuInformesInterno(Trabajos trabajos[], int tamT, Servicios servicio[], int tamS, Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color color[], int tamC);
int menuCentral();

int main()
{
    Marcas listaMarcas[TAMM];
    Color listaColores[TAMC];
    Servicios listaServicios[TAMS];
    Autos listaAutos[TAMA];
    Trabajos listaTrabajos[TAMT];

    int marca = 1000;
    int color = 5000;
    int servicio = 20000;
    int trabajo = 200;
    int autos = 7000;
    char seguir = 'n';
    int cTrue;

    inicializarAutos(listaAutos, TAMA);
    inicializarTrabajos(listaTrabajos, TAMT);

    marca = marca + harcodearMarcas(listaMarcas, TAMM, 5);
    color = color + harcodearColores(listaColores, TAMC, 5);
    servicio = servicio + harcodearServicios(listaServicios, TAMS, 4);
    autos = autos + harcodearAutos(listaAutos, TAMA, 7);
    trabajo = trabajo + harcodearTrabajos(listaTrabajos, TAMT, 7);

    do{
        switch(menuCentral()){
    case 'a':
        if(autoAltaAutos(listaAutos, TAMA, autos)){
            autos++;
        }
        break;
    case 'b':
        cTrue = checkAuto(listaAutos, TAMA);
        if (cTrue == 1){
        menuModificarAutos(listaAutos, TAMA, listaColores, TAMC, listaMarcas, TAMM);
        } else
            {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        break;
    case 'c':
        cTrue = checkAuto(listaAutos, TAMA);
        if (cTrue == 1){
        bajaAuto(listaAutos, TAMA, listaMarcas, TAMM, listaColores, TAMC);
        } else
            {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        break;
    case 'd':
        cTrue = checkAuto(listaAutos, TAMA);
        if (cTrue == 1){
        listarVehiculosOrdenados(listaAutos, TAMA);
        mostrarAutos(listaAutos, TAMA, listaMarcas, TAMM, listaColores, TAMC);
        } else
            {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        break;
    case 'e':
        system("cls");
        printf("------ Lista de Marcas ------\n\n");
        mostrarMarcas(listaMarcas, TAMM);
        break;
    case 'f':
        system("cls");
        printf("------ Lista de Colores ------\n\n");
        mostrarColores(listaColores, TAMC);
        break;
    case 'g':
        system("cls");
        printf("------ Lista de Servicios ------\n\n");
        mostrarServicios(listaServicios, TAMS);
        break;
    case 'h':
        cTrue = checkAuto(listaAutos, TAMA);
        if(cTrue == 1){
            altaTrabajo(trabajo, listaTrabajos, TAMT, listaAutos, TAMA, listaServicios, TAMS);
            trabajo++;
        } else
            {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        break;
    case 'i':
        cTrue = checkAuto(listaAutos, TAMA);
        if(cTrue == 1){
            cTrue = checkTrabajo(listaTrabajos, TAMT);
            if(cTrue == 1){
            mostrarTrabajos(listaTrabajos, TAMT, listaServicios, TAMS);
            } else {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        } else
            {
                printf("\nSe debe ingresar un vehiculo antes de realizar esta accion.\n");
            }
        break;
    case 'j':
        menuInformesInterno(listaTrabajos, TAMT, listaServicios, TAMS, listaAutos, TAMA, listaMarcas, TAMM, listaColores, TAMC);
        break;
    case 'k':
        printf("Confirmar salir? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
        while(seguir != 's' && seguir != 'n'){
            printf("Opcion invalida, intente nuevamente: \n");
            fflush(stdin);
            scanf("%c", &seguir);
        }
        break;

    default:
        system("cls");
        printf("Opcion invalida, intente nuevamente: \n");
        break;
        }
    system("pause");
    }while(seguir == 'n');

    return 0;
}

int menuCentral()
{
    char seguir;
    system("cls");
    printf("------ Autos ------\n\n");
    printf("a) Alta de Autos\n");
    printf("b) Modificar Auto/s\n");
    printf("c) Baja Auto\n");
    printf("d) Listar Autos\n");
    printf("e) Listar Marcas\n");
    printf("f) Listar Colores\n");
    printf("g) Listar Servicios\n");
    printf("h) Alta Trabsjo\n");
    printf("i) Listar Trabajos\n");
    printf("j) Informes\n");
    printf("k) Salir\n\n");
    printf("Elija opcion: ");
    fflush(stdin);
    scanf("%c", &seguir);
    while (seguir != 'a' && seguir != 'b' && seguir != 'c' && seguir != 'd' && seguir != 'e' && seguir != 'f' && seguir != 'g' && seguir != 'h' && seguir != 'i' && seguir != 'j' && seguir != 'k')
    {
        printf("\nOpcion seleccionada incorrecta. Reingrese: ");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return seguir;
}

int menuInformes(){

    char seguir;
    system("cls");
    printf("------ Informes ------\n\n");
    printf("a) Informar precio de todos los trabajos\n");
    printf("b) Mostrar vehiculos del XXXX hacia adelante\n");
    printf("c) Mostrar vehiculos por :\n");
    printf("d)\n");
    printf("e) Salir\n\n");
    printf("Elija opcion: ");
    fflush(stdin);
    scanf("%c", &seguir);
    while (seguir != 'a' && seguir != 'b' && seguir != 'c' && seguir != 'd' && seguir != 'e'){
       printf("\nOpcion seleccionada invalida, intente nuevamente: ");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return seguir;
}

void menuInformesInterno(Trabajos trabajos[], int tamT, Servicios servicio[], int tamS, Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color color[], int tamC){
    char seguir = 'n';

    do{
        switch(menuInformes()){
    case 'a':
        precioTotalTrabajos(trabajos, tamT, servicio, tamS);
        break;
    case 'b':
        mostrarVehiculosModernos(vehiculos, tamA, marca, tamM, color, tamC);
        break;
    case 'c':
        break;
    case 'd':
        break;
    case 'e':
        printf("Confirmar salir? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
        while(seguir != 's' && seguir != 'n'){
            printf("Opcion invalida, intente nuevamente: \n");
            fflush(stdin);
            scanf("%c", &seguir);
        }
        break;

    default:
        system("cls");
        printf("Opcion invalida, intente nuevamente: \n");
        break;
        }
    system("pause");
    }while(seguir == 'n');

}

void precioTotalTrabajos(Trabajos trabajo[], int tamT, Servicios servicio[], int tamS){
    int sumar = 0;
    for(int i = 0; i < tamT;  i++){
        for(int j = 0; j < tamS; j++){
            if(trabajo[i].idServicio == servicio[j].id){
                sumar+=servicio[j].precio;
            }
        }
    }
    printf("El precio total de los trabajos realizados es: $%d\n\n", sumar);
}

void mostrarVehiculosModernos(Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color color[], int tamC){
    printf("\n\n------ Lista de Vehiculos de Modelo xxxx ------\n\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (int i = 0; i < tamA; i++){
        if(vehiculos[i].modelo >= 1990 && vehiculos[i].isEmpty == 0){
            mostrarAuto(vehiculos[i], marca, tamM, color, tamC);
        }
    }
}
