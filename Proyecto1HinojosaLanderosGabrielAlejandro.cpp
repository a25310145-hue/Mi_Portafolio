#include <stdio.h>
#include <string.h>

#define TAM 20

//----- ESTRUCTURA ANIDADA 1 -----
struct Actividad{
    char nombre[30];
    char tipo[20];
    int horas;
};

//----- ESTRUCTURA PRINCIPAL 1 -----
struct Hobby{
    int idHobby;
    char descripcion[50];
    struct Actividad actividad;
};

//----- ESTRUCTURA ANIDADA 2 -----
struct DetalleHobby{
    char nivel[20];
    int anios;
    char frecuencia[20];
};

//----- ESTRUCTURA PRINCIPAL 2 -----
struct Interes{
    int idInteres;
    char categoria[30];
    struct DetalleHobby detalle;
};

// FUNCIONES 
void menuHobbies(struct Hobby *h, int *n);
void menuIntereses(struct Interes *i, int *n);

void capturarHobby(struct Hobby *h, int *n);
void imprimirHobby(struct Hobby *h, int n);
void buscarHobby(struct Hobby *h, int n);
void eliminarHobby(struct Hobby *h, int *n);

void capturarInteres(struct Interes *i, int *n);
void imprimirInteres(struct Interes *i, int n);
void buscarInteres(struct Interes *i, int n);
void eliminarInteres(struct Interes *i, int *n);

int main(){

    struct Hobby hobbies[TAM];
    struct Interes intereses[TAM];

    int nHobbies = 0;
    int nIntereses = 0;

    int op;

    do{
        printf("\nMENU PRINCIPAL\n");
        printf("1. Menu Hobbies\n");
        printf("2. Menu Intereses\n");
        printf("3. Salir\n");
        printf("Seleccione: ");
        scanf("%d",&op);

        switch(op){
            case 1: menuHobbies(hobbies,&nHobbies); break;
            case 2: menuIntereses(intereses,&nIntereses); break;
        }

    }while(op!=3);
}

//------------------ MENU HOBBIES ------------------

void menuHobbies(struct Hobby *h, int *n){

    int op;

    do{
        printf("\nMENU HOBBIES\n");
        printf("1 Capturar\n");
        printf("2 Imprimir\n");
        printf("3 Buscar\n");
        printf("4 Eliminar\n");
        printf("5 Regresar\n");
        scanf("%d",&op);

        switch(op){
            case 1: capturarHobby(h,n); break;
            case 2: imprimirHobby(h,*n); break;
            case 3: buscarHobby(h,*n); break;
            case 4: eliminarHobby(h,n); break;
        }

    }while(op!=5);
}

void capturarHobby(struct Hobby *h, int *n){

    if(*n==TAM){
        printf("Arreglo lleno\n");
        return;
    }

    printf("ID Hobby: ");
    scanf("%d",&(h[*n].idHobby));

    printf("Descripcion: ");
    scanf("%s",h[*n].descripcion);

    printf("Nombre actividad: ");
    scanf("%s",h[*n].actividad.nombre);

    printf("Tipo (deporte, arte, etc): ");
    scanf("%s",h[*n].actividad.tipo);

    printf("Horas por semana: ");
    scanf("%d",&(h[*n].actividad.horas));

    (*n)++;
}

void imprimirHobby(struct Hobby *h, int n){

    if(n==0){
        printf("No hay registros\n");
        return;
    }

    for(int i=0;i<n;i++){
        printf("\nHobby %d\n",i);
        printf("ID: %d\n",h[i].idHobby);
        printf("Descripcion: %s\n",h[i].descripcion);
        printf("Actividad: %s\n",h[i].actividad.nombre);
        printf("Tipo: %s\n",h[i].actividad.tipo);
        printf("Horas: %d\n",h[i].actividad.horas);
    }
}

void buscarHobby(struct Hobby *h, int n){

    char nombre[30];
    int encontrado=0;

    printf("Actividad a buscar: ");
    scanf("%s",nombre);

    for(int i=0;i<n;i++){
        if(strcmp(h[i].actividad.nombre,nombre)==0){
            printf("Encontrado en posicion %d\n",i);
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("No encontrado\n");
}

void eliminarHobby(struct Hobby *h, int *n){

    char nombre[30];

    printf("Actividad a eliminar: ");
    scanf("%s",nombre);

    for(int i=0;i<*n;i++){
        if(strcmp(h[i].actividad.nombre,nombre)==0){

            for(int j=i;j<*n-1;j++)
                h[j]=h[j+1];

            (*n)--;
            printf("Eliminado\n");
            return;
        }
    }

    printf("No existe\n");
}

//------------------ MENU INTERESES ------------------

void menuIntereses(struct Interes *i, int *n){

    int op;

    do{
        printf("\nMENU INTERESES\n");
        printf("1 Capturar\n");
        printf("2 Imprimir\n");
        printf("3 Buscar\n");
        printf("4 Eliminar\n");
        printf("5 Regresar\n");
        scanf("%d",&op);

        switch(op){
            case 1: capturarInteres(i,n); break;
            case 2: imprimirInteres(i,*n); break;
            case 3: buscarInteres(i,*n); break;
            case 4: eliminarInteres(i,n); break;
        }

    }while(op!=5);
}

void capturarInteres(struct Interes *i, int *n){

    if(*n==TAM){
        printf("Arreglo lleno\n");
        return;
    }

    printf("ID Interes: ");
    scanf("%d",&(i[*n].idInteres));

    printf("Categoria (musica, deporte, etc): ");
    scanf("%s",i[*n].categoria);

    printf("Nivel (principiante, medio, pro): ");
    scanf("%s",i[*n].detalle.nivel);

    printf("Anios practicando: ");
    scanf("%d",&(i[*n].detalle.anios));

    printf("Frecuencia (diario, semanal): ");
    scanf("%s",i[*n].detalle.frecuencia);

    (*n)++;
}

void imprimirInteres(struct Interes *i, int n){

    if(n==0){
        printf("No hay registros\n");
        return;
    }

    for(int j=0;j<n;j++){
        printf("\nInteres %d\n",j);
        printf("ID: %d\n",i[j].idInteres);
        printf("Categoria: %s\n",i[j].categoria);
        printf("Nivel: %s\n",i[j].detalle.nivel);
        printf("Anios: %d\n",i[j].detalle.anios);
        printf("Frecuencia: %s\n",i[j].detalle.frecuencia);
    }
}

void buscarInteres(struct Interes *i, int n){

    char categoria[30];
    int encontrado=0;

    printf("Categoria a buscar: ");
    scanf("%s",categoria);

    for(int j=0;j<n;j++){
        if(strcmp(i[j].categoria,categoria)==0){
            printf("Encontrado en posicion %d\n",j);
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("No existe\n");
}

void eliminarInteres(struct Interes *i, int *n){

    char categoria[30];

    printf("Categoria a eliminar: ");
    scanf("%s",categoria);

    for(int j=0;j<*n;j++){
        if(strcmp(i[j].categoria,categoria)==0){

            for(int k=j;k<*n-1;k++)
                i[k]=i[k+1];

            (*n)--;
            printf("Eliminado\n");
            return;
        }
    }

    printf("No encontrado\n");
}