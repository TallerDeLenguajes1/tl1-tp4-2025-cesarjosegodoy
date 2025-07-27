#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int TareaID;       // Numerico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 - 100
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

// prototipo de funciones

Nodo *CrearListaVacia();
Nodo *CrearNodo(Tarea *tarea);
void InsertarNodo(Nodo **Start, Nodo *Nodo);
Nodo *QuitarNodo(Nodo **Start, int dato);
void MostrarLista(Nodo *start);
void BuscarListaID(Nodo **Start, int dato);
void BuscarListaP(Nodo **Start, char *palabra);

// funcion principal

int main()
{

    char buff[100];
    char *palabraClave;
    int num = 1; // se carga solo un valor
    int ID = 1000;
    int IDCambio;
    int IDbusca;

    Nodo *StartPendiente = CrearListaVacia();
    Nodo *StartRealizadas = CrearListaVacia();

    printf("Cargar Tareas Pendientes\n");

    while (num != 0)
    {

        Tarea *tarea = (Tarea *)malloc(sizeof(Tarea)); // reservo memoria tipo structura y lo gurdo en *tarea

        printf("\nIngrese la descripcion de la tarea: ");
        fflush(stdin);
        gets(buff); // lo ingresado se guarda en buff que tiene 100

        tarea->Descripcion = (char *)malloc(sizeof(char) * (strlen(buff) + 1)); // reservo en la estructura
        strcpy(tarea->Descripcion, buff);                                       // copio las dos estructuras dinamicas

        tarea->TareaID = ID; 

        printf("\nIngrese la duracion de la tarea entre 10 a 100: ");
        scanf("%d", &tarea->Duracion); // guardo en la estructura

        InsertarNodo(&StartPendiente, CrearNodo(tarea)); //

        printf("\nSi quiere seguir cargando tareas ingrese el valor 1 sino ingrese 0 ");

        scanf("%d", &num); // doy un valor para  volver a entrara al bucle

        // getchar(); // Limpiar el buffer del teclado

        ID++;//se incremeta en 1000
    }

    int i = 1;

    while (i != 0)
    {
        printf("\n** Ingrese el ID de la tarea de la lista de pendientes que quiere mover a la lista de realizadas ");
        scanf("%d", &IDCambio);

        InsertarNodo(&StartRealizadas, QuitarNodo(&StartPendiente, IDCambio)); // doy el id para eliminar de de pendiente y esta la guarda en realizadas

        printf("\nSi quiere seguir moviendo tareas ingrese el valor 1 sino ingrese 0 ");
        scanf("%d", &i);
    }

    printf(" \n------ Lista de Tareas Pendientes -----");
    MostrarLista(StartPendiente);

    printf(" \n----- Lista de Tareas Realizadas -----");
    MostrarLista(StartRealizadas);

    printf("\nIngrese el ID de la tarea que quiere buscar: "); // busca en pedientes y realizadas
    scanf("%d", &IDbusca);

    printf("\nLista de Pendientes");
    BuscarListaID(&StartPendiente, IDbusca);

    printf("\nLista de Realizadas");
    BuscarListaID(&StartRealizadas, IDbusca);

    printf("\nIngrese la palabra clave con la que quiere buscar la tarea: ");
    fflush(stdin);
    gets(buff);
    palabraClave = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(palabraClave, buff);

    printf("\nLa palabra clave de busqueda es: ");
    puts(palabraClave);

    printf("\nLista de Pendientes");
    BuscarListaP(&StartPendiente, palabraClave);

    printf("\nLista de Realizadas");
    BuscarListaP(&StartRealizadas, palabraClave);

    printf("-----fin del Programa-----");

    getchar();
    return 0;
}

// Defino las funciones

Nodo *CrearListaVacia()
{
    return NULL;
}

Nodo *CrearNodo(Tarea *tarea)
{

    Nodo *NNodo = (Nodo *)malloc(sizeof(Nodo));
    NNodo->T = *tarea;
    NNodo->Siguiente = NULL;

    return NNodo;
}

void InsertarNodo(Nodo **Start, Nodo *Nodo)
{
    Nodo->Siguiente = *Start;
    *Start = Nodo;
}

Nodo *QuitarNodo(Nodo **Start, int dato)
{

    Nodo *nodoAux = (*Start);
    Nodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->T.TareaID != dato)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }
    if (nodoAux != NULL)
    {
        if (nodoAux == (*Start))
        {
            (*Start) = nodoAux->Siguiente;
        }
        else
        {
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }

    return (nodoAux);
}

void MostrarLista(Nodo *start)
{
    Nodo *aux;
    aux = start;

    while (aux)
    {
        printf("ID de la tarea: %d\n", aux->T.TareaID);
        printf("Descripcion de tarea : \n");
        puts(aux->T.Descripcion);
        printf("Duracion de la tarea: %d\n", aux->T.Duracion);

        aux = aux->Siguiente;
    }
}

void BuscarListaID(Nodo **Start, int dato)
{

    Nodo *aux = *Start;

    while (aux != NULL && aux->T.TareaID != dato)
    {
        aux = aux->Siguiente;
    }

    if (aux != NULL)
    {
        printf("\n--Se encuentra en esta lista--");
        printf("\nLa tarea encontrada es la siguiente: ");
        printf("\nID de la tarea: %d", aux->T.TareaID);
        printf("\nDescripcion de tarea : ");
        puts(aux->T.Descripcion);
        printf("\nDuracion de la tarea: %d", aux->T.Duracion);
    }
    else
    {
        printf("\nTarea no encontrada en esta lista");
    }
}

void BuscarListaP(Nodo **Start, char *palabra)
{

    Nodo *aux = *Start;

    while (aux != NULL && strstr(aux->T.Descripcion, palabra) == NULL)
    {
        aux = aux->Siguiente;
    }

    if (aux != NULL)
    {
        printf("\n--Se encuentra en esta lista--");
        printf("\nLa tarea encontrada es la siguiente: ");
        printf("\nID de la tarea: %d", aux->T.TareaID);
        printf("\nDescripcion de tarea : ");
        puts(aux->T.Descripcion);
        printf("\nDuracion de la tarea: %d", aux->T.Duracion);
    }
    else
    {
        printf("\nTarea no encontrada en esta lista");
    }
}