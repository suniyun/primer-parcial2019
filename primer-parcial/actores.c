#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "actores.h"
#include "peliculas.h"

static int generarID(void);

/**
    generarID: Genera un ID. Comienza en -1 para ir generando IDs desde el 0 en adelante.
    \param cont: Contador.
    \return return cont + 1.
*/

static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}

/**
    indicesVacios: Busca dentro del array hasta encontrar un indice vacio donde cargar un dato.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param indiceVacio: Guarda el indice de la posicion vacia del array.
    \return return 0 OK, -1 Error.
*/

int indicesVacios(eActor* actor, int limite, int* indiceVacio)
{
    int i = 0;
    int retorno = -1;
    while(i < limite)
    {
        if(actor[i].isEmpty == -1)
        {
            *indiceVacio = i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

/**
    chequearIndice: Recibe el array para chequear si esta cargado o no.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/

int chequearIndice(eActor* actor, int limite)
{
    int i=0;
    int retorno = 0;
    if(actor!= NULL && limite > 0)
    {
        while(i<limite)
        {
            if(actor[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/**
    cargarDatosVacio: Carga un valor en el mismo campo de todas las posiciones del array recibido.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/

int cargarDatosVacio(eActor* actor, int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        actor[i].isEmpty=-1;
    }
    return 0;
}

int altasDeActor(eActor* actor, int indice, int limite)
{
    char auxNombreActor[51];
    char auxPais[51];
    printf("Ingrese el nombre de un Actor:\n");
    if(getString(auxNombreActor,51)==0)
    {
        {
            printf("Ingrese el pais de origen del actor: \n");
            if(getString(auxPais, 51) == 0)
            {
                strncpy(actor[indice].nombreActor,auxNombreActor,51);
                strncpy(actor[indice].pais, auxPais, 51);
                actor[indice].isEmpty = 0;
                actor[indice].id = generarID();
            }
        }
    }
    return 0;
}

int modificarActor(eActor* actor, int indice, int limite)
{
    char auxNombreActor[51];
    char auxPais[51];
    int opciones;
    int salir=0;
    indice = buscarActorPorId(actor,limite,indice);
    if(indice >= 0)
    {
        if(actor != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                getEntero(&opciones,4,"1)Modificar nombre del actor:\n2)Modificar el pais de origen:\n3)Salir\n","\nError\n",5,0);
                switch(opciones)
                {
                case 1:
                    printf("Nuevo nombre:\n");
                    if(getString(auxNombreActor,51)==0)
                    {
                        strncpy(actor[indice].nombreActor,auxNombreActor,51);
                    }
                    break;
                case 2:
                    printf("Nuevo pais: \n");
                    if(getString(auxPais,51)==0)
                    {
                        strncpy(actor[indice].pais,auxPais,51);
                    }
                    break;

                case 3:
                    salir = 1;
                }
            }
            while(salir==0);
        }
    }
    return 0;
}

int buscarActorPorId(eActor* actor, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(actor[i].isEmpty == 0 && actor[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
