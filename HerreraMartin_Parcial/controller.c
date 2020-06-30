#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "bicicletas.h"
#include "validacionesHerrera.h"

int cargarDesdeArchivo(char* path, LinkedList* listaBicis)
{
    int todoOk = -1;
    FILE* pFile;
    if(path != NULL && listaBicis != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_BicisDesdeTexto(pFile, listaBicis) == 1)
            {
                todoOk = 1;
                printf("Bicis cargados correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar las Bicis.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
    }

    return todoOk;
}


//************************************************************************************************************************************/

int controller_ListarBicis(LinkedList* listaBicis)
{
    int todoOk = -1;
    int tam = ll_len(listaBicis);
    int flag = 0;
    Bicicleta* auxBici;

    if( listaBicis != NULL)
    {
        todoOk = 1;
        printf("\n  Id_Bike    Nombre       Tipo       Tiempo \n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {
            auxBici = (Bicicleta*) ll_get(listaBicis, i);
            if (  auxBici  != NULL )
            {
                mostrarBici(auxBici);
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay bicis que mostrar\n");
        }
    }
    return todoOk;
}

//************************************************************************************************************************************/
int controller_guardarComoTexto(char* path, LinkedList* listaBicis)
{
    FILE* f = fopen(path,"w") ;
    int tam =  ll_len(listaBicis);
    Bicicleta* auxBici;
    int todoOk = -1;

    if(f != NULL)
    {
        fprintf(f,"  Id_bike       Nombre   Tipo    Tiempo\n");
        for (int i =0; i<tam; i++)
        {
            auxBici = (Bicicleta*) ll_get(listaBicis, i);
            if (auxBici !=NULL)
            {
                fprintf(f, "%d,%s,%s,%d\n",auxBici->id_bike,auxBici->nombre,auxBici->tipo,auxBici->tiempo);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}


int controller_filtrarPorTipo(LinkedList* this)
{
    int tipoElegido;
    LinkedList* listanueva;
    if(this!=NULL)
    {
        printf("Digite uno de los siguientes opciones de bici: ");
        printf("1: BMX o 2: PLAYERA o 3: MTB o 4: PASEO\n");
        scanf("%d",&tipoElegido);

        switch(tipoElegido)
        {
        case 1:
            listanueva = ll_filter(this,filtrarPorBMX);
            if(listanueva!=NULL)
            {
                controller_guardarComoTexto("filtradoBMX.csv",listanueva);
                printf("Archivo filtrado por BMX hecho.\n");
            }
            break;
        case 2:
            listanueva = ll_filter(this,filtrarPorPlayera);
            if(listanueva!=NULL)
            {
                controller_guardarComoTexto("filterPlayera.csv",listanueva);
                printf("Archivo filtrado por PLAYERA hecho.\n");
            }
            break;
        case 3:
            listanueva = ll_filter(this,filtrarPorMTB);
            if(listanueva!=NULL)
            {
                controller_guardarComoTexto("filterMTB.csv",listanueva);
                printf("Archivo filtrado por MTB hecho.\n");
            }
            break;
        case 4:
            listanueva = ll_filter(this,filtrarPorPaseo);
            if(listanueva!=NULL)
            {
                controller_guardarComoTexto("filterPaseo.csv",listanueva);
                printf("Archivo filtrado por PASEO hecho.\n");
            }
            break;
        default:
            printf("Numero incorrecto.\n");
            break;
        }
    }
    return 1;
}

int controller_sortBici(LinkedList* listaBicis)
{
    int todoOk = 0;
    if(listaBicis != NULL)
    {
    ll_sort(listaBicis,cmpBiciTiempoTipo,1);
    todoOk = 1;
    }
    return todoOk;
}

