#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "controller.h"
#include "validacionesHerrera.h"
#include "bicicletas.h"

#define TAMPILOTOS 5

int getRandom();

void* aplicarTiempo(void* aux);

int main()
{
    srand(time(NULL));

    char confirm = 'n';
    char seguir = 's';
    char archivo[20];
    LinkedList* listaBicis = ll_newLinkedList();
    LinkedList* listaMapeada = ll_newLinkedList();
    int flagMapeado = 0;

    if(listaBicis != NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s",archivo);
                if(strcmp(archivo,"bicicletas.csv")==0)
                {
                    cargarDesdeArchivo(archivo, listaBicis);
                }
                else
                {
                    printf("nombre incorrecto, recuerde que el archivo se llama bicicletas.csv.\n");
                }
                system("pause");
                break;
            case 2:
                if(!ll_isEmpty(listaBicis))
                {
                    if(flagMapeado == 0)
                    {
                        printf("no se cargarno los tiempos aun.\n");
                        system("pause");
                    }
                    else
                    {
                        controller_ListarBicis(listaBicis);
                    }
                }
                else
                {
                    printf("La lista de bicis esta vacia.\n");
                }
                system("pause");
                break;
            case 3:
                listaMapeada = ll_map(listaBicis,aplicarTiempo);
                printf("Tiempo agregado con exito");
                flagMapeado = 1;
                system("pause");
                break;
            case 4:
                if(flagMapeado == 0)
                {
                    printf("No se cargarno los tiempos aun\n");
                    system("pause");
                }
                else
                {
                    controller_filtrarPorTipo(listaMapeada);
                    system("pause");
                }
                break;
            case 5:
                if(flagMapeado == 0)
                {
                    printf("no se cargaron los tiempos aun\n");
                    system("pause");
                }
                else
                {
                    if(controller_sortBici(listaMapeada))
                    {
                        controller_ListarBicis(listaMapeada);
                        system("pause");
                    }
                    else
                    {
                        printf("No se pudo ordenar.\n");
                    }
                }
                break;
            case 6:
                if(flagMapeado==0)
                {
                    printf("no se cargaron los tiempos aun\n");
                    system("pause");
                }
                else
                {
                    controller_guardarComoTexto("BicisOrdenadas.csv",listaMapeada);
                    printf("guarado con exito.\n");
                }
                break;
            case 7:
                printf("Esta seguro que desea salir? [s/n] : ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (confirm == 's')
                {
                    seguir = 'n';
                }
                break;
            }
        }
        while(seguir == 's');
        ll_deleteLinkedList(listaBicis);
    }
    else
    {
        printf("no se consigio memoria.\n");
    }

    return 0;
}



int getRandom()
{
    int aleatorio;

    aleatorio = rand()% 71 + 50;

    return aleatorio;
}

void* aplicarTiempo(void* aux)
{
    Bicicleta* x;
    int random;
    if(aux != NULL)
    {
        random = getRandom();
        x=(Bicicleta*) aux;
        bici_setTiempoStr(x,random);
        x=(void*) aux;
    }
    return x;
}
