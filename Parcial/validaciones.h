#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#endif // VALIDACIONES_H_INCLUDED
#include "auto.h"
#include "servicio.h"

/** \brief Valida la patente llegado por parametro
 *
 * \param int idPatente
 * \return la ID si cumple las condiciones
 */

int validarPatente(int idPatente);

/** \brief Valida el modelo llegado por parametro
 *
 * \param int modelo
 * \return la ID si cumple las condiciones
 */

int validarModelo(int modelo);

/** \brief Valida el color llegado por parametro
 *
 * \param int idColor
 * \return la ID si cumple las condiciones
 */

int validarColor(int idColor);

/** \brief Valida la marca llegado por parametro
 *
 * \param int idMarca
 * \return la ID si cumple las condiciones
 */

int validarMarca(int idMarca);

/** \brief Verifica si ya existe la patente en el array
 *
 * \param int idPatente
 * \param Autos vehiculos[]
 * \param int tamA
 * \return [1] Si se ha encontrado la patente repetida en el array.
 * [0] si no se ha encontrado repetida.
 */

int verificarPatenteExistente(int idPatente, Autos vehiculos[], int tamA);

/** \brief Verifica si existe el vehiculo en el Array Autos con
 * la id llegada por parametro
 * \param int id
 * \param Autos vehiculos[]
 * \param int tamA
 * \return [-1] Si la ID del vehiculo no existe en el array o
 * el indice del vehiculo.
 */

int verificarAutoExistente(int id, Autos vehiculos[], int tamA);

/** \brief Verifica si existe el servicio en el Array Servicios con
 * la id llegada por parametro
 * \param int id
 * \param Servicios servicio[]
 * \param int tamS
 * \return [-1] Si la ID del servicio no existe en el array o
 * el indice del servicio.
 */

int verificarServicioExistente(int id, Servicios servicio[], int tamS);

/** \brief Verifica que el dia sea correcto
 *
 * \param int dia
 * \return el dia verificado
 */

int validarDia(int dia);

/** \brief Verifica que el mes sea correcto
 *
 * \param int mes
 * \return el mes verificado
 */
int validarMes(int mes);

/** \brief Verifica que el anio sea correcto
 *
 * \param int anio
 * \return el anio verificado
 */
int validarAnio(int anio);

/** \brief Valida que el dia ingresado corresponda
 * con el mes
 * \param int dia
 * \param int mes
 * \return el mes verificado
 */

int validarMeses(int dia, int mes);
