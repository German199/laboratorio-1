#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu();

int main()
{
    char seguir = 'n';

    do{
    switch(menu())
    {
    case 'a':
        printf("\nUsted elegio sumar:\n");
        system("pause");
        break;
    case 'b':
        printf("\nUsted elegio restar:\n");
        system("pause");
        break;
    case 'c':
        printf("\nUsted elegio multiplicar:\n");
        system("pause");
        break;
    case 'd':
        printf("\nUsted elegio dividir:\n");
        system("pause");
        break;
    case 'e':
        printf("\nUsted elegio Salir:\n");
        printf("\n¿Confirma salida?\n\n");
        fflush(stdin);
        seguir = getch();
        system("pause");
        break;
    default:
        printf("\nOpcion Inválida\n\n");
        system("pause");
        break;
    }
    }while (seguir == 'n');
    return 0;
}

int menu()
{
    char opcion;

    system("cls");
    printf("-----Menu de Opciones-----\n\n");
    printf("A- Sumar\n");
    printf("B- Restar\n");
    printf("C- Multiplicar\n");
    printf("D- Dividir\n");
    printf("E- Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    opcion = getchar();

    return opcion;
}
