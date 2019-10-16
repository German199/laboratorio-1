#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    int precio;

}Servicios;


#endif // SERVICIO_H_INCLUDED

/** \brief Harcoding Servicios
 *
 * \param Servicios servicio[]
 * \param int tamS
 * \param int cantidad
 * \return contador de id servicio
 */

int harcodearServicios(Servicios servicio[], int tamS, int cantidad);

/** \brief Muestra un servicio en el array Servicios
 *
 * \param Servicios servicio
 */

void mostrarServicio(Servicios servicio);

/** \brief Muestra el array completo Servicios
 *
 * \param Servicios servicio[]
 * \param int tamS
 */

void mostrarServicios(Servicios servicio[], int tamS);

/** \brief Obtiene la descripcion del Servicio segun ID obtenido
 * por parametro.
 * \param Servicios servicio[]
 * \param int tamS
 * \param int idServicio
 * \param char desc[]
 * \return [1] Si la descripcion se ha cargado correctamente o [0]
 * si no se ha cargado ninguna descripcion.
 */

int cargarDescServicio(Servicios servicio[], int tamS, int idServicio, char desc[]);
