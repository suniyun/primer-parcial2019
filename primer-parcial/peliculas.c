#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "library.h"

static int generarID(void);

/**
    generarID: Genera un ID. Comienza en 999 para ir generando IDs desde el 1000 en adelante.
    \param cont: Contador.
    \return return cont + 1.
*/

static int generarID(void)
{
    static int cont = 999;
    return ++cont;
}

/**
    indicesVacios: Busca dentro del array hasta encontrar un indice vacio donde cargar un dato.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param indiceVacio: Guarda el indice de la posicion vacia del array.
    \return return 0 OK, -1 Error.
*/

int indicesVacios(ePeliculas* pelicula, int limite, int* indiceVacio)
{
    int i = 0;
    int retorno = -1;
    while(i < limite)
    {
        if(pelicula[i].isEmpty == -1)
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

int chequearIndice(ePeliculas* pelicula, int limite)
{
    int i=0;
    int retorno = 0;
    if(pelicula!= NULL && limite > 0)
    {
        while(i<limite)
        {
            if(pelicula[i].isEmpty==0)
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

int cargarDatosVacio(ePeliculas* pelicula, int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        pelicula[i].isEmpty=-1;
    }
    return 0;
}
/**
    buscarPeliculaPorID: Recibe un ID para buscar una pelicula.
    \param Peliculas: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param id: Guarda el int de la pelicula a buscar.
    \return return el indice del array donde esta la pelicula.
*/

int buscarPeliculaPorID(ePeliculas* pelicula, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pelicula[i].isEmpty == 0 && pelicula[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
/**
    altasDePelicula: carga valores en la posicion del array recibido.
    \param Peliculas: Guarda el array recibido.
    \param indice: Guarda el int de la posicion del array.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/

int altasDePelicula(ePeliculas* pelicula,int indice, int limite)
{
    char auxNombrePelicula[51];
    int auxGenero;

    printf("Ingrese el titulo de la pelicula: \n");
    if(getString(auxNombrePelicula,51)==0)
    {
        if(getEntero(&auxGenero,2, "Ingrese el genero: 1) Accion 2) Comedia 3) Drama 4) Romance 5)Terror\n", "\nError\n", 6, 0) == 0)
        {
            strncpy(pelicula[indice].nombrePelicula,auxNombrePelicula,51);
            pelicula[indice].genero = auxGenero;
            pelicula[indice].isEmpty = 0;
            pelicula[indice].id = generarID();
        }
    }
    return 0;
}


/**
    modificarPelicula: Recibe un ID para modificar una posicion del array.
    \param pelicula: Guarda el array recibido.
    \param id: Guarda el int recibido del ID a modificar.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/

int modificarPelicula(ePeliculas* pelicula, int indice, int limite)
{

    char auxNombrePelicula[51];
    int auxGenero;
    int opciones;
    int salir=0;
    indice = buscarPeliculaPorID(pelicula,limite,indice);
    if(indice >= 0)
    {
        if(pelicula != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                getEntero(&opciones,4,"1)Modificar titulo de pelicula:\n2)Modificar genero:\n3)Salir\n","\nError\n",5,0);
                switch(opciones)
                {
                case 1:
                    printf("Nuevo titulo: \n");
                    if(getString(auxNombrePelicula,51)==0)
                    {
                        strncpy(pelicula[indice].nombrePelicula,auxNombrePelicula,51);
                    }
                    break;
                case 3:
                    if(getEntero(&auxGenero,2,"Nuevo genero: \n", "\nError\n",6,0) == 0)
                    {
                        pelicula[indice].genero = auxGenero;
                    }
                    break;
                case 4:
                    salir = 1;
                }
            }
            while(salir==0);
        }
    }
    return 0;
}

/**
    bajasdePelicula: Recibe un ID para borrar una pelicula.
    \param pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param id: Guarda el int de la pelicula a borrar.
    \return return 0 OK, -1 Error.
*/

int bajasDePelicula(ePeliculas* pelicula, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pelicula[i].isEmpty == 0 && pelicula[i].id == id)
        {
            pelicula[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
    mostrarPeliculasOrdenados: Muestra los datos ordenados por pais y por año de estreno de
    todas las posiciones del array.
    \param Pelicula: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int mostrarPeliculasOrdenadas(ePeliculas* pelicula, eActor* actor, eFechaDeEstreno* fecha, int limite)
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
                    printf("%d, %s, %s, %s, %d/%d/%d\n", pelicula[i].id, pelicula[i].nombrePelicula, actor[i].nombreActor, actor[i].pais, fecha[i].dia, fecha[i].mes, fecha[i].ano);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
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

int altaFechaDeEstreno(eFechaDeEstreno* fecha, int indice, int limite)
{
    int auxDia;
    int auxMes;
    int auxAno;

    if(getEntero(&auxDia,2,"Ingrese el dia de estreno:\n","\nError\n",32,0) == 0)
    {
        if(getEntero(&auxMes,2,"Ingrese el mes de estreno: \n","\nError\n",12,0)== 0)
        {
            if(getEntero(&auxAno,2,"Ingrese el Ano del estreno:\n","\nError\n",9999,0)== 0)
            {
                fecha[indice].dia = auxDia;
                fecha[indice].mes = auxMes;
                fecha[indice].ano = auxAno;
                fecha[indice].isEmpty = 0;
            }
        }
    }
    return 0;
}

int modificarFechaDeEstreno(eFechaDeEstreno* fecha, int indice, int limite)
{
    int auxDia;
    int auxMes;
    int auxAno;
    int opciones;
    int salir=0;

    if(indice >= 0)
    {
        if(fecha!= NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                getEntero(&opciones,4,"1)Modificar Dia:\n2)Modificar Mes:\n3)Modificar fecha:\n4)Salir.","\nError\n",5,0);
                switch(opciones)
                {
                case 1:
                    if(getEntero(&auxDia,2,"Nuevo Dia: \n", "\nError\n",32,0) == 0)
                    {
                        fecha[indice].dia = auxDia;
                    }
                    break;
                case 2:
                    if(getEntero(&auxMes,2,"Nuevo Mes: \n", "\nError\n",32,0) == 0)
                    {
                        fecha[indice].mes = auxMes;
                    }
                    break;

                case 3:
                    if(getEntero(&auxAno,2,"Nuevo ano: \n", "\nError\n",9999,0) == 0)
                    {
                        fecha[indice].ano = auxAno;
                    }
                    break;

                case 4:
                    salir = 1;
                    break;
                }
            }
            while(salir==0);
        }
    }
    return 0;
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

void hardcodearDatos(ePeliculas* pelicula, eActor* actor, eFechaDeEstreno* fecha, int limite)
{
    int i;
    int id[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020};
    char titulo[][50] = {"Avengers End Game", "Thor", "Cellular", "Men in Black 4", "Iron Man", "13 Going 30", "Lucy", "Nace una Estrella", "Dime con cuantos", "Guardianes de la galaxia", "A perfect Murder", "La Isla", "Que paso ayer", "Home Alone 3", "Deadpool", "Sherlock Holmes", "Men in Black 3", "Avengers Infinity War", "Grandes esperanzas"};
    int genero[] = {1, 1, 1, 1, 1, 4, 1, 4, 4, 1, 3, 3, 2, 2, 1, 1, 1, 1, 4};
    int actorPorPelicula[] = {2, 5, 4, 5, 2, 3, 1, 9, 4, 9, 7, 1, 9, 1, 10, 2, 10, 10, 7};
    int fechaDia[] = {20, 10, 2, 10, 5, 7, 9, 8, 4, 20, 6, 3, 5, 6, 7, 5, 2, 6, 8};
    int fechaMes[] = {4, 6, 5, 7, 9, 5, 2, 3, 4, 5, 8, 10, 2, 10, 12, 6, 5, 4, 12};
    int fechaAno[] = {2019, 2013, 2004, 2019, 2012, 2004, 2014, 2018, 2010, 2014, 2018, 2010, 2014, 1995, 2005, 2013, 1997, 2015, 2011, 2010, 2017};
    int idActor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char nombreActor[][50] = {"Scarlett Johansson", "Robert Downey Jr", "Mark Ruffalo", "Chris Evans", "Chris Hemsworth", "Samuel Jackson", "Gwyneth Paltrow", "Paul Rudd", "Bradley Cooper", "Josh Brolin"};
    char pais[][50] = {"Argentina", "EEUU", "Canada", "EEUU", "Argentina", "EEUU", "Canada", "Argentina", "EEUU", "Canada"};

    for(i=0; i < limite; i++)
    {
        pelicula[i].id = id[i];
        strcpy(pelicula[i].nombrePelicula, titulo[i]);
        pelicula[i].genero = genero[i];
        pelicula[i].actores = actorPorPelicula[i];
        fecha[i].dia = fechaDia[i];
        fecha[i].mes = fechaMes[i];
        fecha[i].ano = fechaAno[i];
        actor[i].id = idActor[i];
        strcpy(actor[i].nombreActor, nombreActor[i]);
        strcpy(actor[i].pais, pais[i]);
    }

}



