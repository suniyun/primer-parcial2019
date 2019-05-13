#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "actores.h"
#include "library.h"
#include "informes.h"

/**
    mostrarPeliculasOrdenados: Muestra los datos ordenados por pais y por año de estreno de
    todas las posiciones del array.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int mostrarPeliculasOrdenadas(ePeliculas* pelicula, eActor* actor, eFechaDeEstreno* fecha, eGenero* genero, int limite)
{
    int retorno=-1;
    int i;
    if(pelicula!= NULL && limite > 0)
    {
        if(ordenarActoresPorPais(actor, limite) == 0 && ordenarAnoDeEstreno(fecha, limite) == 0)
        {
            for(i=0; i<limite; i++)
            {
                if(pelicula[i].isEmpty==0)
                {
                    printf("%d,%s, %d, %s, %s, %d/%d/%d\n", pelicula[i].id, pelicula[i].nombrePelicula, genero[i].genero, actor[i].nombreActor, actor[i].pais, fecha[i].dia, fecha[i].mes, fecha[i].ano);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

/**
    ordenarActorPorPais: Recibe el array y lo ordena usando el metodo Insertion.
    \param actor: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int ordenarActoresPorPais(eActor* actor, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int auxId;
    char auxPais[51];
    char auxNombreActor[51];
    if(actor != NULL && limite > 0)
    {
        for(i=0; i < limite; i++)
        {
            if(actor[i].isEmpty == 0)
            {
                strcpy(auxNombreActor, actor[i].nombreActor);
                strcpy(auxPais, actor[i].pais);
                auxId = actor[i].id;
                j = i-1;

                while(j>=0 && strcmp(auxPais, actor[i].pais) < 0)
                {
                    actor[j+1] = actor[j];
                    j--;
                }
                strcpy(actor[j+1].nombreActor, auxNombreActor);
                strcpy(actor[j+1].pais, auxPais);
                actor[j+1].id = auxId;
            }
            retorno = 0;
        }
    }
    return retorno;
}

/**
    ordenarAnoDeEstreno: Recibe el array y lo ordena usando el metodo Insertion.
    \param fecha: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int ordenarAnoDeEstreno(eFechaDeEstreno* fecha, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int auxDia;
    int auxMes;
    int auxAno;

    if(fecha != NULL && limite > 0)
    {
        for(i=0; i < limite; i++)
        {
            if(fecha[i].isEmpty == 0)
            {
                auxDia = fecha[i].dia;
                auxMes = fecha[i].mes;
                auxAno = fecha[i].ano;
                j = i-1;

                while(j >= 0 && auxAno < fecha[j].ano)
                {
                    fecha[j+1] = fecha[j];
                    j--;
                }
                fecha[j+1].dia = auxDia;
                fecha[j+1].mes = auxMes;
                fecha[j+1].ano = auxAno;
            }
            retorno = 0;
        }
    }
    return retorno;
}


int actorDeEeuu(eActor* actor, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int auxNacionalidad[51];
    if(actor != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            if(actor[i].pais == 'EEUU')
            {
                strcpy(auxNacionalidad, actor[i].pais);
                j = i-1;

                while(j>= 0 && auxNacionalidad > actor[i].pais)
                {
                    actor[j+1] = actor[j];
                    j--;
                }
                strcpy(actor[j+1].pais, auxNacionalidad);
            }
            retorno = 0;
        }
    }

    return retorno;
}


