#include <stdio.h>
#include <stdlib.h>
//
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaDeIngreso;
}eAlumno;

int main()
{
    eAlumno alumno1;

    printf("Ingrese nombre: ");
    gets(alumno1.nombre);

    printf("Ingrese legajo: ");
    scanf("%d", &alumno1.legajo);

    printf("Ingrese edad: ");
    scanf("%d", &alumno1.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno1.sexo);

    printf("Ingrese nota primer parcial: ");
    scanf("%d", &alumno1.nota1);

    printf("Ingrese nota segundo parcial: ");
    scanf("%d", &alumno1.nota2);

    printf("--Fecha de Ingreso--\n");
    printf("Dia: ");
    scanf("%d", &alumno1.fechaDeIngreso.dia);
    printf("Mes: ");
    scanf("%d", &alumno1.fechaDeIngreso.mes);
    printf("Anio: ");
    scanf("%d", &alumno1.fechaDeIngreso.anio);
    printf("\n\n");

    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2) / 2;

    printf("Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota 1P: %d\nNota 2P: %d\nPromedio: %.2f\nFecha de Ingreso: %02d/%02d/%d",
            alumno1.nombre,
            alumno1.legajo,
            alumno1.edad,
            alumno1.sexo,
            alumno1.nota1,
            alumno1.nota2,
            alumno1.promedio,
            alumno1.fechaDeIngreso.dia,
            alumno1.fechaDeIngreso.mes,
            alumno1.fechaDeIngreso.anio);
    printf("\n\n");

    return 0;
}
