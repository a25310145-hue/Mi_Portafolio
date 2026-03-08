#include <stdio.h>
#include <string.h>

#define TAM 20

// Estructura del piloto
struct Piloto{
    char nombre[30];
    char apellido[30];
    int horasVuelo;
    int numLicencia;
};

// Estructura principal (Vuelo) con estructura anidada
struct Vuelo{
    int numero;
    char fecha[15];
    char origen[30];
    char destino[30];
    struct Piloto piloto; // estructura anidada
};

// Prototipos de funciones
void capturar(struct Vuelo *v);
void mostrar(struct Vuelo v[], int total);
void buscar(struct Vuelo v[], int total);

int main(){

    struct Vuelo vuelos[TAM]; // arreglo de 20 posiciones
    int opcion;
    int total = 0; // contador de registros capturados

    do{

        printf("\n----- MENU -----\n");
        printf("1. Capturar\n");
        printf("2. Mostrar\n");
        printf("3. Buscar\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){

            case 1:
                if(total < TAM){
                    // Se envía la dirección de la posición del arreglo
                    // &vuelos[total] es un PUNTERO a la estructura
                    capturar(&vuelos[total]);
                    total++;
                }else{
                    printf("Arreglo lleno\n");
                }
            break;

            case 2:
                mostrar(vuelos,total);
            break;

            case 3:
                buscar(vuelos,total);
            break;

            case 4:
                printf("Programa finalizado\n");
            break;

            default:
                printf("Opcion invalida\n");
        }

    }while(opcion != 4);

    return 0;
}

// FUNCION CAPTURAR
void capturar(struct Vuelo *v){

    // v es un PUNTERO a una estructura Vuelo
    // se usa -> para acceder a los campos del puntero

    printf("\nNumero de vuelo: ");
    scanf("%d",&v->numero);

    printf("Fecha: ");
    scanf("%s",v->fecha);

    printf("Origen: ");
    scanf("%s",v->origen);

    printf("Destino: ");
    scanf("%s",v->destino);

    printf("\nDatos del piloto\n");

    printf("Nombre: ");
    scanf("%s",v->piloto.nombre);

    printf("Apellido: ");
    scanf("%s",v->piloto.apellido);

    printf("Horas de vuelo: ");
    scanf("%d",&v->piloto.horasVuelo);

    printf("Numero de licencia: ");
    scanf("%d",&v->piloto.numLicencia);

    printf("Registro guardado correctamente\n");
}


// FUNCION MOSTRAR
void mostrar(struct Vuelo v[], int total){

    if(total == 0){
        printf("\nNo hay registros capturados\n");
        return;
    }

    printf("\n--- LISTA DE VUELOS ---\n");

    for(int i=0;i<total;i++){

        printf("\nVuelo %d\n",i+1);
        printf("Numero: %d\n",v[i].numero);
        printf("Fecha: %s\n",v[i].fecha);
        printf("Origen: %s\n",v[i].origen);
        printf("Destino: %s\n",v[i].destino);

        printf("Piloto: %s %s\n",
        v[i].piloto.nombre,
        v[i].piloto.apellido);

        printf("Horas de vuelo: %d\n",
        v[i].piloto.horasVuelo);

        printf("Licencia: %d\n",
        v[i].piloto.numLicencia);
    }
}


// FUNCION BUSCAR
void buscar(struct Vuelo v[], int total){

    if(total == 0){
        printf("\nNo hay datos capturados\n");
        return;
    }

    char nombre[30];
    char apellido[30];
    int encontrado = 0;

    printf("\nNombre del piloto a buscar: ");
    scanf("%s",nombre);

    printf("Apellido del piloto: ");
    scanf("%s",apellido);

    for(int i=0;i<total;i++){

        if(strcmp(nombre,v[i].piloto.nombre)==0 &&
           strcmp(apellido,v[i].piloto.apellido)==0){

            printf("\nVuelo encontrado\n");
            printf("Numero: %d\n",v[i].numero);
            printf("Fecha: %s\n",v[i].fecha);
            printf("Origen: %s\n",v[i].origen);
            printf("Destino: %s\n",v[i].destino);

            printf("Piloto: %s %s\n",
            v[i].piloto.nombre,
            v[i].piloto.apellido);

            printf("Horas de vuelo: %d\n",
            v[i].piloto.horasVuelo);

            printf("Licencia: %d\n",
            v[i].piloto.numLicencia);

            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nNo se encontro el piloto\n");
    }
}