#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "peliculas.h"
#define CANT_PELICULAS 1000
#define CANT_ACTORES 1000

int main()
{
    ePeliculas pelicula[CANT_PELICULAS];
    eActor actor[CANT_ACTORES];
    eFechaDeEstreno fecha[CANT_PELICULAS];
    int opcion;
    int id;
    int indiceVacio;
    int bandera=0;
    int salir=0;
    cargarDatosVacio(pelicula,CANT_PELICULAS);
    hardcodearDatos(pelicula, actor, fecha, 20);

    do
    {
        system("cls");
        fflush(stdin);
        if(chequearIndice(pelicula,CANT_PELICULAS) == -1)
        {
            bandera = 1;
        }
        else
        {
            bandera = 0;
        }
        getEntero(&opcion,3,"1)Cargar peliculas, un actor y su fecha de estreno.\n2)Modificar datos.\n3)Baja de peliculas.\n4)Mostrar lista de peliculas ordenada\n5)Salir\n","\nError\n",5,0);
        switch(opcion)
        {
        case 1:
            if(indicesVacios(pelicula,CANT_PELICULAS,&indiceVacio)==0)
            {
                altasDePelicula(pelicula,indiceVacio, CANT_PELICULAS );
                altasDeActor(actor, indiceVacio, CANT_ACTORES);
                altaFechaDeEstreno(fecha, indiceVacio, CANT_PELICULAS);
                break;
            }
            else
            {
                printf("\nNo hay indice.\n");
            }
            break;
        case 2:
            if(bandera == 1)
            {
                if(getEntero(&id,2,"\nIngrese el ID a modificar: ","Error", CANT_PELICULAS,-1) == 0)
                {
                    if(id >=0)
                    {
                        modificarPelicula(pelicula,id,CANT_PELICULAS);
                        modificarActor(actor,id, CANT_ACTORES);
                        modificarFechaDeEstreno(fecha,id, CANT_PELICULAS);
                    }
                    else
                    {
                        printf("\nError, indice invalido.\n");
                    }
                }
            }
            else
            {
                printf("\nNo hay datos cargados\n");
            }
            system("pause");
            break;
        case 3:
            if(bandera == 1)
            {
                if(getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_PELICULAS, -1) == 0)
                {
                    if(id >=0)
                    {
                        bajasDePelicula(pelicula,id,CANT_PELICULAS);
                    }
                    else
                    {
                        printf("\nError, indice invalido.\n");
                    }
                }
            }
            else
            {
                printf("\nNo hay datos cargados\n");
            }
            system("pause");
            break;
        case 4:
            if(bandera == 1)
            {
                mostrarPeliculasOrdenadas(pelicula, actor, fecha, CANT_PELICULAS);
            }
            else
            {
                printf("\nNo hay datos cargados\n");
            }
            system("pause");
            break;
        case 5:
            salir = 1;
        }
    }
    while(salir==0);
    return 0;
}
