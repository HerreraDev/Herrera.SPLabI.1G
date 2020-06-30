#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
typedef struct
{
    int id_bike;
    char nombre[61];
    char tipo[61];
    int tiempo;

}Bicicleta;


#endif // BICICLETAS_H_INCLUDED
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Bicicleta* nuevaBici();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Bicicleta* nuevaBiciParam(char* idBike, char* nombre,char* tipo,char* tiempo);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_setIdBiciStr(Bicicleta* this,int idbike);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_setNombreStr(Bicicleta* this,char* nombre);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_setTipoStr(Bicicleta* this,char* tipo);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_setTiempoStr(Bicicleta* this,int tiempo);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_getTipo(char* tipoNombre, Bicicleta* bici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int bici_getTiempo(int* tiempo, Bicicleta* bici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int mostrarBici(Bicicleta* this);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int filtrarPorBMX(void* auxBici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int filtrarPorPlayera(void* auxBici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int filtrarPorMTB(void* auxBici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int filtrarPorPaseo(void* auxBici);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cmpBiciTiempoTipo(void* biciA,void* biciB);
