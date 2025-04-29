#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int TareaID;//Numerico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 - 100
    }Tarea;


typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
    }Nodo;
    

Nodo *CrearListaVacia();
Nodo *CrearNodo(Tarea *tarea);
void InsertarNodo(Nodo **Start, Nodo* Nodo);







int main() {

    char buff[100];
    char *palabraClave;
    int num = 1;
    int ID = 1000;



    Nodo *StartPendiente = CrearListaVacia(); 
    Nodo *StartRealizadas = CrearListaVacia();


    printf("Cargar Tareas Pendientes\n");

    while(num != 0){

        Tarea * tarea = (Tarea*)malloc(sizeof(Tarea));

        printf("\nIngrese la descripcion de la tarea: ");
        fflush(stdin);
        gets(buff);

        tarea->Descripcion = (char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(tarea->Descripcion,buff);

        tarea->TareaID = ID;


        printf("\nIngrese la duracion de la tarea entre 10 a 100: ");
        scanf("%d",&tarea->Duracion);
        InsertarNodo(&StartPendiente,CrearNodo(tarea));

        printf("\nSi quiere seguir cargando tareas ingrese el valor 1 sino ingrese 0 ");                
        scanf("%d",&num);
        //getchar(); // Limpiar el buffer del teclado

        ID++;

    }







    return 0;

}

Nodo *CrearListaVacia() {
    return NULL;
}


Nodo *CrearNodo(Tarea *tarea){

    Nodo * NNodo = (Nodo*)malloc(sizeof(Nodo));
    NNodo->T = *tarea;
    NNodo->Siguiente = NULL;

    return NNodo;
}

void InsertarNodo(Nodo **Start, Nodo* Nodo){
    Nodo->Siguiente = *Start;
    *Start = Nodo;
}

