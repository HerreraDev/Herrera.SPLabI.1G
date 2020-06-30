#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "validacionesHerrera.h"

Bicicleta* nuevaBici()
{
    return (Bicicleta*) malloc(sizeof(Bicicleta));
}

//************************************************************************************************************************************/
Bicicleta* nuevaBiciParam(char* idBike, char* nombre,char* tipo,char* tiempo)
{
    Bicicleta*  nuevaBicis;

    nuevaBicis = nuevaBici();

    if(nuevaBicis != NULL)
    {

        if   ( (bici_setIdBiciStr(nuevaBicis, atoi(idBike)) == -1) ||
                (bici_setNombreStr(nuevaBicis,  nombre) ==-1) ||
                (bici_setTipoStr(nuevaBicis, tipo) ==-1) ||
                (bici_setTiempoStr(nuevaBicis,  atoi(tiempo)) ==-1))
        {
            free(nuevaBicis);
            nuevaBicis = NULL;
        }
    }
    return nuevaBicis;
}

int bici_setIdBiciStr(Bicicleta* this,int idbike)
{
    int todoOk = -1;

    if ( this != NULL && idbike >0 && idbike <= 100000)
    {
        this-> id_bike = idbike;
        todoOk = 1;
    }
    return todoOk;
}

int bici_setNombreStr(Bicicleta* this,char* nombre)
{
    int todoOk = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 61)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bici_setTipoStr(Bicicleta* this,char* tipo)
{
    int todoOk = -1;

    if (this != NULL  && strlen(tipo) >= 1  && strlen(tipo) < 61)
    {
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }
    return todoOk;
}

int bici_setTiempoStr(Bicicleta* this,int tiempo)
{
    int todoOk = -1;

    if ( this != NULL && tiempo >=0 && tiempo <= 100000)
    {
        this->tiempo = tiempo;
        todoOk = 1;
    }
    return todoOk;
}

int bici_getTipo(char* tipoNombre, Bicicleta* bici)
{
    int todoOk = -1;
    if (bici != NULL && tipoNombre != NULL)
    {
        strcpy(tipoNombre,bici->tipo);
        todoOk = 1;
    }

    return todoOk;
}

int bici_getTiempo(int* tiempo, Bicicleta* bici)
{
    int todoOk = -1;
    if (bici != NULL && tiempo != NULL)
    {
        *tiempo = bici->tiempo;
        todoOk = 1;
    }

    return todoOk;
}
int menu()
{
    int option;

    system("cls");
    printf("**** Menu de Bici **** \n\n");
    printf("1.   Cargar archivo.  \n");
    printf("2.   Imprimir lista. \n");
    printf("3.   Asignar tiempo.\n");
    printf("4.   Filtrar por tipo.\n");
    printf("5.   Mostrar posiciones.\n");
    printf("6.   Guardar posiciones.\n");
    printf("7.   Salir.\n");

    if(utn_getNumero(&option, "Introduza una opcion: ","Error, numero incorrecto.",1,7,0) == -1)
    {
        option = 0;
    }

    return option;
}

int mostrarBici(Bicicleta* this)
{
    int todoOk =-1;
    if (this != NULL)
    {
        todoOk = 1;
        printf("%4d          %10s          %6s        %4d \n",this->id_bike,this->nombre,this->tipo,this->tiempo);
    }
    return todoOk;
}

int filtrarPorBMX(void* auxBici)
{
    int retorno = 0;
    Bicicleta* x ;
    char nameTipo[61];
    if(auxBici != NULL)
    {
        x=(Bicicleta*) auxBici;
        bici_getTipo(nameTipo,x);
        if(strcmp(x->tipo,"BMX")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int filtrarPorPlayera(void* auxBici)
{
    int retorno = 0;
    Bicicleta* x ;
    char nameTipo[61];
    if(auxBici != NULL)
    {
        x=(Bicicleta*) auxBici;
        bici_getTipo(nameTipo,x);
        if(strcmp(x->tipo,"PLAYERA")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int filtrarPorMTB(void* auxBici)
{
    int retorno = 0;
    Bicicleta* x ;
    char nameTipo[61];
    if(auxBici != NULL)
    {
        x=(Bicicleta*) auxBici;
        bici_getTipo(nameTipo,x);
        if(strcmp(x->tipo,"MTB")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int filtrarPorPaseo(void* auxBici)
{
    int retorno = 0;
    Bicicleta* x ;
    char nameTipo[61];
    if(auxBici != NULL)
    {
        x=(Bicicleta*) auxBici;
        bici_getTipo(nameTipo,x);
        if(strcmp(x->tipo,"PASEO")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int cmpBiciTiempoTipo(void* biciA,void* biciB)
{
    int orden = 0;
    char tipoA[61];
    char tipoB[61];

    int tiempoA;
    int tiempoB;

    if( biciA != NULL && biciB != NULL )
    {
        Bicicleta* auxBiciA = (Bicicleta*) biciA;
        Bicicleta* auxBiciB = (Bicicleta*) biciB;
        bici_getTipo(tipoA,auxBiciA);
        bici_getTipo(tipoB,auxBiciB);
        bici_getTiempo(&tiempoA,auxBiciA);
        bici_getTiempo(&tiempoB,auxBiciB);
        if (strcmp(tipoA, tipoB) > 0 )
        {
            orden = 1;
        }
        else if ( strcmp(tipoA, tipoB) ==0 )
        {
            if(auxBiciA->tiempo > auxBiciB->tiempo)
            {
                orden = 1;
            }else
            {
                orden = -1;
            }
        }

    }
    return orden;
}




