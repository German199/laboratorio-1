#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];

}Color;

#endif // COLOR_H_INCLUDED

/** \brief Harcoding colores
 *
 * \param Color colores[]
 * \param int tamC
 * \param int cantidad
 * \return counter
 */

 int harcodearColores(Color colores[], int tamM, int cantidad);

 /** \brief lista de color
  *
  * \param Color col
  * \return array de color en posicion 0
  */

 void mostrarColor(Color col);

 /** \brief lista de colores
  *
  * \param Color colores[]
  * \param int tamC
  * \return array de colores
  *
  */

 void mostrarColores(Color colores[], int tamC);

 /** \brief muestra la descripcion del color segun ID
 *
 * \param int id
 * \param Color color[]
 * \param int tamC
 * \param char desc[]
 * \return descripcion del color si id en el array es igual a la recibida
 * por parámetro
 */

 int mostrarDescColor(int id, Color color[], int tamC, char desc[]);
