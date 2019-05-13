#ifndef INFORMES_H_INCLUDED

int ordenarAnoDeEstreno(eFechaDeEstreno* fecha, int limite);
int ordenarActoresPorPais(eActor* actor, int limite);
int mostrarPeliculasOrdenadas(ePeliculas* pelicula, eActor* actor, eFechaDeEstreno* fecha, eGenero* genero, int limite);
int actorDeEeuu(eActor* actor, int limite);
int ordenarPorGenero(ePeliculas* pelicula, eGenero* genero, int limite);
int cantDePeliculasPorGenero(eGenero* genero, int limite);
int generoConMenosPeliculas(eGenero* genero, int limite);

#endif // INFORMES_H_INCLUDED
