#ifndef ACTORES_H_INCLUDED
typedef struct
{
    int id;
    char nombreActor[51];
    char pais[51];
    int isEmpty;
} eActor;

int indicesVacios(eActor* actor, int limite, int* indiceVacio);
int chequearIndice(eActor* actor, int limite);
int cargarDatosVacio(eActor* actor, int limite);

int altasDeActor(eActor* actor, int indice, int limite);
int modificarActor(eActor* actor, int indice, int limite);
int ordenarActoresPorPais(eActor* actor, int limite);
int buscarActorPorId(eActor* actor, int limite, int id);

#endif // ACTORES_H_INCLUDED
