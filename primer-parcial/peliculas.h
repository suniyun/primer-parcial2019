#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char nombrePelicula[51];
    int isEmpty;
    int actores;
} ePeliculas;

typedef struct
{
    int dia;
    int mes;
    int ano;
    int isEmpty;
} eFechaDeEstreno;

typedef struct
{
    int genero;
    int accion;
    int comedia;
    int drama;
    int romance;
    int terror;

} eGenero;

int indicesVaciosdePelicula(ePeliculas* pelicula, int limite, int* indiceVacio);
int chequearIndicedePelicula(ePeliculas* pelicula, int limite);
int cargarDatosVaciodePelicula(ePeliculas* pelicula, int limite);
int buscarPeliculaPorID(ePeliculas* pelicula, int limite, int id);
int altasDePelicula(ePeliculas* pelicula, int indice, int limite);
int modificarPelicula(ePeliculas* pelicula, int indice, int limite);
int bajasDePelicula(ePeliculas* pelicula, int indice, int limite);

int altaFechaDeEstreno(eFechaDeEstreno* fecha, int indice, int limite);
int modificarFechaDeEstreno(eFechaDeEstreno* fecha, int indice, int limite);

//void hardcodearDatos(ePeliculas* pelicula, eActor* actor, eFechaDeEstreno* fecha, int limite);

#endif // PELICULAS_H_INCLUDED
