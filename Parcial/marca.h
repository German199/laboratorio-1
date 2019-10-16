#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];

}Marcas;


#endif // MARCA_H_INCLUDED

/** \brief Harcoding Marcas
 *
 * \param Marca marcas[]
 * \param int tamM
 * \param int cantidad
 * \return counter
 */

int harcodearMarcas(Marcas marcas[], int tamM, int cantidad);

/** \brief muestra una marca
 *
 * \param Marcas marca
 * \return array de marcas en la posicion 0
 */

void mostrarMarca(Marcas marca);

/** \brief lista de marcas
 *
 * \param Marcas marca[]
 * \param int tamM
 * \return array of marcas
 *
 */

void mostrarMarcas(Marcas marca[], int tamM);

/** \brief muestra la descripcion de la marca segun ID
 *
 * \param int id
 * \param Marcas marca[]
 * \param int tamM
 * \param char desc[]
 * \return descripcion de la marca si id en el array es igual a la recibida
 * por parámetro
 */


int mostrarDescMarca(int id, Marcas marca[], int tamM, char desc[]);
