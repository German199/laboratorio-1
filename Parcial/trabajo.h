#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "auto.h"

typedef struct{
    int id;
    int patente;
    int idServicio;
    Fecha fechaTrabajo;
    int isEmpty;

}Trabajos;
#endif // TRABAJO_H_INCLUDED

/** \brief Ingresa en el Array trabajos los datos llegados por
 * parametro.
 * \param int idTrabajo,int patente, int idServicio
 * \param int dia
 * \param int mes
 * \param int anio
 * \return los datos llegado por parametro en el array Trabajos en la
 * primera posicion libre.
 */

Trabajos nuevoTrabajo(int idTrabajo, int patente, int idServicio, int dia, int mes, int anio);

/** \brief Ingresa un nuevo trabajo preguntando la ID del vehiculo y
 * el ID del servicio.
 * \param int id
 * \param Trabajos trabajo[]
 * \param int tamT
 * \param Autos vehiculos[]
 * \param int tamA
 * \param Servicios servicio[]
 * \param int tamS
 * \return [1] Si se ha registrado el trabajo correctamente o [0] si
 * no se ha realizado el alta trabajo
 */

int altaTrabajo(int id, Trabajos trabajo[], int tamT, Autos vehiculos[], int tamA, Servicios servicio[], int tamS);

/** \brief Muestra un trabajo en el array Trabajos
 *
 * \param Trabajos trabajo
 * \param Servicios servicio[]
 * \param int tamS
 */

void mostrarTrabajo(Trabajos trabajo, Servicios servicio[], int tamS);

/** \brief Muestra el array completo Trabajos si estan activos (isEmpty = 0)
 *
 * \param Trabajos trabajo[]
 * \param int tamT
 * \param Servicios servicio[]
 * \param int tamS
 */

void mostrarTrabajos(Trabajos trabajo[], int tamT, Servicios servicio[], int tamS);

/** \brief Inicializa el array Trabajo con isEmpty en 1
 *
 * \param Trabajos trabajo[]
 * \param int tamT
 *
 */

void inicializarTrabajos(Trabajos trabajo[], int tamT);

/** \brief Busca en el array Trabajo si hay un lugar disponible
 *
 * \param Trabajos trabajo[]
 * \param int tamT
 * \return [-1] Si no hay lugar disponible en el array o el indice [i]
 * del primer lugar disponible hallado.
 */

int buscarLibreTrabajo(Trabajos trabajo[], int tamT);

/** \brief Verifica que exista al menos un trabajo en el Array Trabajos
 *
 * \param Trabajos trabajo[]
 * \param int tamT
 * \return [1] Si se ha encontrado un trabajo en el array o [0] si
 * no se ha encontrado trabajos en el array.
 */

int checkTrabajo(Trabajos trabajo[], int tamT);

int harcodearTrabajos(Trabajos trabajo[], int tamT, int cantidad);
