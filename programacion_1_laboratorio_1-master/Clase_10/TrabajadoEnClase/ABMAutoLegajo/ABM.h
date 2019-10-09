#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct{
    int id;
    char description[20];
}eCarrera;

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
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
}eAlumno;

#endif // ABM_H_INCLUDED

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, int idCarrera, eFecha fecha);
void mostrarAlumnos(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumno(eAlumno x, eCarrera carreras[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void startAlumnos(eAlumno alumnos[], int tam);
void mostrarCarreras(eCarrera vec[], int tam);
void mostrarCarrera(eCarrera);
int cargarDescCarrera(int idCarrera, eCarrera carreras[], int tam, char descripcion[]);
int highAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int highAlumnoAuto(eAlumno alumnos[], int tam, int leg);
int lowAlumno (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int modifyAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int searchEmpty(eAlumno alumnos[], int tam);
int searchAlumno(int legajo, eAlumno alumnos[], int tam);
int hardcodearAlumnos(eAlumno vec[], int tam, int cantidad);
int menu();
