#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"

int parser_BicisDesdeTexto(FILE* pFile, LinkedList* listaBicis)
{
    int cantParametros;
    Bicicleta* auxBici;
    int todoOk = -1;
    char buffer[4][100];

    if (pFile != NULL  && listaBicis != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxBici = nuevaBici();
            cantParametros = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantParametros == 4)
            {
                auxBici = nuevaBiciParam(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(listaBicis, auxBici);
                todoOk = 1;
            }
            else
            {
                break;
            }
        }
    }

    return todoOk;
}

