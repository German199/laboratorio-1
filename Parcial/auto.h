#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"

typedef struct{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}Autos;

#endif // AUTO_H_INCLUDED

/** \brief Verifica si hay lugar disponible en el array Autos
 *
 * \param Autos vehiculos[]
 * \param int tamA
 * \return El primer indice libre encontrado
 *
 */

int buscarLibreAuto(Autos vehiculos[], int tamA);

/** \brief Registra un nuevo vehiculo en el array Autos
 *
 * \param int tamA
 * \param Autos vehiculos[]
 * \param int idAuto
 * \return El vehiculo registrado
 *
 */

int autoAltaAutos(Autos vehiculos[], int tamA, int idAuto);

/** \brief Busca un auto especifico en el array Autos
 *
 * \param Autos vehiculos[]
 * \param int tamA
 * \param int id
 * \return El indice del vehiculo o "-1" si no encontro vehiculo.
 *
 */

int buscarAutoEnArray(Autos vehiculos[], int tamA, int id);

/** \brief Ingresa en el array Autos los datos ingresados por
 * parametro.
 * \param int id
 * \param int patente
 * \param int idMarca
 * \param int idColor
 * \param int modelo
 * \return Los datos cargados hacia el array Autos
 *
 */

Autos nuevoAuto(int id, int patente, int idMarca, int idColor, int modelo);

/** \brief Setea el array completo de Autos en isEmpty 1 (vacio)
 *
 * \param Autos vehiculos[]
 * \param int tamA
 *
 */

void inicializarAutos(Autos vehiculos[], int tamA);

/** \brief Dar de baja un vehiculo registrado en el Array Autos
 *
 * \param Autos vehiculos[]
 * \param int tamA
 * \param Marcas marca[]
 * \param int tamM
 * \param Color colores[]
 * \param int tamC
 * \return [1] Si el vehiculo se ha dado de baja correctamente o
 * [0] si se ha cancelado la operacion.
 */

int bajaAuto(Autos vehiculos[], int tamA, Marcas marca[], int tamM, Color colores[], int tamC);

/** \brief Muestra un vehiculo en el Array Autos
 *
 * \param Autos vehiculos[]
 * \param Marcas marca[]
 * \param int tamM
 * \param Color colores[]
 * \param int tamC
 *
 */

void mostrarAuto(Autos vehiculos, Marcas marca[], int tamM, Color colores[], int tamC);

/** \brief Muestra los vehiculos en el Array Autos si el array
 * no está vacio.
 * \param Autos vehiculos[]
 * \param Marcas marca[]
 * \param int tamM
 * \param Color colores[]
 * \param int tamC
 *
 */

void mostrarAutos(Autos vehiculos[], int tamA, Marcas marcas[], int tamM, Color color[], int tamC);

/** \brief Modifica el color o el modelo de un vehiculo preguntando
 * el patente primeramente.
 * \param Autos vehiculos[]
 * \param int tamA
 * \param Marcas marca[]
 * \param int tamM
 * \param Color colores[]
 * \param int tamC
 * \return [-1] Si no se encuentra el patente en el Array Autos. Sino se muestra
 * el menu de modificaciones.
 */

int menuModificarAutos(Autos vehiculos[], int tamA, Color colores[], int tamC, Marcas marca[], int tamM);

/** \brief Ordena el array Autos segun marca y patente.
 *
 * \param Autos vehiculos[]
 * \param int tamA
 *
 */

void listarVehiculosOrdenados(Autos vehiculos[], int tamA);

/** \brief Busca en el Array Autos el patente que coincida
 *
 * \param Autos vehiculos[]
 * \param int tamA
 * \param int patente
 * \return [-1] Si no se ha encontrado el vehiculo en el array con el
 * patente obtenido por parametro. Sino devuelve el indice donde se ha
 * encontrado el vehiculo.
 */

int buscarPatenteEnArray(Autos vehiculos[], int tamA, int patente);

/** \brief Verifica si existe vehiculos en el array
 *
 * \param Autos vehiculos[]
 * \param int tamA
 * \return [1] Si existe al menos un vehiculo en el array. [0] Si no existen
 * vehiculos en el array.
 */

int checkAuto(Autos vehiculos[], int tamA);

int harcodearAutos(Autos vehiculos[], int tamA, int cantidad);
