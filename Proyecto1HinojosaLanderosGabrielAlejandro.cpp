#include <stdio.h>
#include <string.h>

#define TAM 20

//----- ESTRUCTURA ANIDADA 1 -----
struct Producto{
    char nombre[30];
    float precio;
    int cantidad;
};

//----- ESTRUCTURA PRINCIPAL 1 -----
struct Venta{
    int idVenta;
    char fecha[20];
    struct Producto producto;
};

//----- ESTRUCTURA ANIDADA 2 -----
struct DetallePago{
    char metodo[20];
    float monto;
    char moneda[10];
};

//----- ESTRUCTURA PRINCIPAL 2 -----
struct Compra{
    int idCompra;
    char proveedor[30];
    struct DetallePago pago;
};

// FUNCIONES
void menuVentas(struct Venta *v, int *n);
void menuCompras(struct Compra *c, int *n);

void capturarVenta(struct Venta *v, int *n);
void imprimirVenta(struct Venta *v, int n);
void buscarVenta(struct Venta *v, int n);
void eliminarVenta(struct Venta *v, int *n);

void capturarCompra(struct Compra *c, int *n);
void imprimirCompra(struct Compra *c, int n);
void buscarCompra(struct Compra *c, int n);
void eliminarCompra(struct Compra *c, int *n);

int main(){

    struct Venta ventas[TAM];
    struct Compra compras[TAM];

    struct Venta *ptrVentas = ventas;
    struct Compra *ptrCompras = compras;

    int nVentas = 0;
    int nCompras = 0;

    int op;

    do{
        printf("\nMENU PRINCIPAL\n");
        printf("1. Menu Ventas\n");
        printf("2. Menu Compras\n");
        printf("3. Salir\n");
        printf("Seleccione: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                menuVentas(ptrVentas,&nVentas);
            break;

            case 2:
                menuCompras(ptrCompras,&nCompras);
            break;
        }

    }while(op!=3);

}

//------------------ MENU VENTAS ------------------

void menuVentas(struct Venta *v, int *n){

    int op;

    do{
        printf("\nMENU VENTAS\n");
        printf("1 Capturar\n");
        printf("2 Imprimir\n");
        printf("3 Buscar\n");
        printf("4 Eliminar\n");
        printf("5 Regresar\n");
        scanf("%d",&op);

        switch(op){

            case 1: capturarVenta(v,n); break;
            case 2: imprimirVenta(v,*n); break;
            case 3: buscarVenta(v,*n); break;
            case 4: eliminarVenta(v,n); break;
        }

    }while(op!=5);

}

void capturarVenta(struct Venta *v, int *n){

    if(*n==TAM){
        printf("Arreglo lleno\n");
        return;
    }

    printf("ID venta: ");
    scanf("%d",&(v[*n].idVenta));

    printf("Fecha: ");
    scanf("%s",v[*n].fecha);

    printf("Nombre producto: ");
    scanf("%s",v[*n].producto.nombre);

    printf("Precio: ");
    scanf("%f",&(v[*n].producto.precio));

    printf("Cantidad: ");
    scanf("%d",&(v[*n].producto.cantidad));

    (*n)++;
}

void imprimirVenta(struct Venta *v, int n){

    if(n==0){
        printf("No hay registros\n");
        return;
    }

    for(int i=0;i<n;i++){

        printf("\nVenta %d\n",i);

        printf("ID: %d\n",v[i].idVenta);
        printf("Fecha: %s\n",v[i].fecha);

        printf("Producto: %s\n",v[i].producto.nombre);
        printf("Precio: %.2f\n",v[i].producto.precio);
        printf("Cantidad: %d\n",v[i].producto.cantidad);
    }

}

void buscarVenta(struct Venta *v, int n){

    char nombre[30];
    int encontrado=0;

    printf("Nombre producto a buscar: ");
    scanf("%s",nombre);

    for(int i=0;i<n;i++){

        if(strcmp(v[i].producto.nombre,nombre)==0){

            printf("Encontrado en posicion %d\n",i);
            printf("ID %d Fecha %s\n",v[i].idVenta,v[i].fecha);
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("No encontrado\n");

}

void eliminarVenta(struct Venta *v, int *n){

    char nombre[30];

    printf("Producto a eliminar: ");
    scanf("%s",nombre);

    for(int i=0;i<*n;i++){

        if(strcmp(v[i].producto.nombre,nombre)==0){

            for(int j=i;j<*n-1;j++)
                v[j]=v[j+1];

            (*n)--;

            printf("Eliminado\n");
            return;
        }
    }

    printf("No existe\n");

}

//------------------ MENU COMPRAS ------------------

void menuCompras(struct Compra *c, int *n){

    int op;

    do{

        printf("\nMENU COMPRAS\n");
        printf("1 Capturar\n");
        printf("2 Imprimir\n");
        printf("3 Buscar\n");
        printf("4 Eliminar\n");
        printf("5 Regresar\n");
        scanf("%d",&op);

        switch(op){

            case 1: capturarCompra(c,n); break;
            case 2: imprimirCompra(c,*n); break;
            case 3: buscarCompra(c,*n); break;
            case 4: eliminarCompra(c,n); break;
        }

    }while(op!=5);

}

void capturarCompra(struct Compra *c, int *n){

    if(*n==TAM){
        printf("Arreglo lleno\n");
        return;
    }

    printf("ID compra: ");
    scanf("%d",&(c[*n].idCompra));

    printf("Proveedor: ");
    scanf("%s",c[*n].proveedor);

    printf("Metodo pago: ");
    scanf("%s",c[*n].pago.metodo);

    printf("Monto: ");
    scanf("%f",&(c[*n].pago.monto));

    printf("Moneda: ");
    scanf("%s",c[*n].pago.moneda);

    (*n)++;

}

void imprimirCompra(struct Compra *c, int n){

    if(n==0){
        printf("No hay registros\n");
        return;
    }

    for(int i=0;i<n;i++){

        printf("\nCompra %d\n",i);

        printf("ID: %d\n",c[i].idCompra);
        printf("Proveedor: %s\n",c[i].proveedor);

        printf("Metodo: %s\n",c[i].pago.metodo);
        printf("Monto: %.2f\n",c[i].pago.monto);
        printf("Moneda: %s\n",c[i].pago.moneda);
    }

}

void buscarCompra(struct Compra *c, int n){

    char proveedor[30];
    int encontrado=0;

    printf("Proveedor a buscar: ");
    scanf("%s",proveedor);

    for(int i=0;i<n;i++){

        if(strcmp(c[i].proveedor,proveedor)==0){

            printf("Encontrado en posicion %d\n",i);
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("No existe\n");

}

void eliminarCompra(struct Compra *c, int *n){

    char proveedor[30];

    printf("Proveedor a eliminar: ");
    scanf("%s",proveedor);

    for(int i=0;i<*n;i++){

        if(strcmp(c[i].proveedor,proveedor)==0){

            for(int j=i;j<*n-1;j++)
                c[j]=c[j+1];

            (*n)--;

            printf("Eliminado\n");
            return;
        }
    }

    printf("No encontrado\n");

}