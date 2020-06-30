#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int cargarDesdeArchivo(char* path, LinkedList* listaBicis);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int controller_ListarBicis(LinkedList* listaBicis);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

int controller_guardarComoTexto(char* path, LinkedList* listaBicis);
  /** \brief
   *
   * \param
   * \param
   * \return
   *
   */
int controller_filtrarPorTipo(LinkedList* this);

int controller_sortBici(LinkedList* listaBicis);
