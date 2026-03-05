#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct Tarjeta {
    char serie[50];
    int numPuertos;
    float voltaje;
    float ancho;
    float largo;
};

struct PC {
    char marca[50];
    char modelo[50];
    int ram;
    float velocidadProcesador;
    Tarjeta tarjeta;
};

// eliminar espacios al inicio
void quitarEspaciosInicio(char *cadena){
    int i=0;
    while(cadena[i]==' ')
        i++;

    if(i>0){
        int j=0;
        while(cadena[i] != '\0'){
            cadena[j++] = cadena[i++];
        }
        cadena[j] = '\0';
    }
}

// eliminar vocales
void quitarVocales(char *cadena){
    int i=0,j=0;
    char temp[50];

    while(cadena[i] != '\0'){
        char c = tolower(cadena[i]);

        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u'){
            temp[j++] = cadena[i];
        }
        i++;
    }
    temp[j]='\0';
    strcpy(cadena,temp);
}

// CAPTURAR
void capturar(PC *pc){
    cin.ignore();

    cout<<"Marca: ";
    cin.getline(pc->marca,50);
    quitarEspaciosInicio(pc->marca);
    quitarVocales(pc->marca);

    cout<<"Modelo: ";
    cin.getline(pc->modelo,50);
    quitarEspaciosInicio(pc->modelo);

    cout<<"Memoria RAM (GB): ";
    cin>>pc->ram;

    cout<<"Velocidad procesador (GHz): ";
    cin>>pc->velocidadProcesador;

    cin.ignore();

    cout<<"Serie tarjeta: ";
    cin.getline(pc->tarjeta.serie,50);
    quitarEspaciosInicio(pc->tarjeta.serie);

    cout<<"Numero de puertos: ";
    cin>>pc->tarjeta.numPuertos;

    cout<<"Voltaje: ";
    cin>>pc->tarjeta.voltaje;

    cout<<"Ancho: ";
    cin>>pc->tarjeta.ancho;

    cout<<"Largo: ";
    cin>>pc->tarjeta.largo;
}

// MOSTRAR
void mostrar(PC *pc){
    cout<<"\n--- DATOS PC ---\n";
    cout<<"Marca: "<<pc->marca<<endl;
    cout<<"Modelo: "<<pc->modelo<<endl;
    cout<<"RAM: "<<pc->ram<<" GB"<<endl;
    cout<<"Velocidad Procesador: "<<pc->velocidadProcesador<<" GHz"<<endl;

    cout<<"\n--- TARJETA ---\n";
    cout<<"Serie: "<<pc->tarjeta.serie<<endl;
    cout<<"Numero Puertos: "<<pc->tarjeta.numPuertos<<endl;
    cout<<"Voltaje: "<<pc->tarjeta.voltaje<<endl;
    cout<<"Ancho: "<<pc->tarjeta.ancho<<endl;
    cout<<"Largo: "<<pc->tarjeta.largo<<endl;
}

// MODIFICAR
void modificar(PC *pc){
    int op;

    cout<<"\n--- MODIFICAR ---\n";
    cout<<"1. Marca\n";
    cout<<"2. Modelo\n";
    cout<<"3. RAM\n";
    cout<<"4. Velocidad Procesador\n";
    cout<<"5. Serie Tarjeta\n";
    cout<<"6. Numero Puertos\n";
    cout<<"7. Voltaje\n";
    cout<<"8. Ancho\n";
    cout<<"9. Largo\n";
    cout<<"Opcion: ";
    cin>>op;

    cin.ignore();

    switch(op){
        case 1:
            cout<<"Nueva marca: ";
            cin.getline(pc->marca,50);
            quitarEspaciosInicio(pc->marca);
            quitarVocales(pc->marca);
        break;

        case 2:
            cout<<"Nuevo modelo: ";
            cin.getline(pc->modelo,50);
            quitarEspaciosInicio(pc->modelo);
        break;

        case 3:
            cout<<"Nueva RAM: ";
            cin>>pc->ram;
        break;

        case 4:
            cout<<"Nueva velocidad: ";
            cin>>pc->velocidadProcesador;
        break;

        case 5:
            cout<<"Nueva serie: ";
            cin.getline(pc->tarjeta.serie,50);
            quitarEspaciosInicio(pc->tarjeta.serie);
        break;

        case 6:
            cout<<"Nuevo numero de puertos: ";
            cin>>pc->tarjeta.numPuertos;
        break;

        case 7:
            cout<<"Nuevo voltaje: ";
            cin>>pc->tarjeta.voltaje;
        break;

        case 8:
            cout<<"Nuevo ancho: ";
            cin>>pc->tarjeta.ancho;
        break;

        case 9:
            cout<<"Nuevo largo: ";
            cin>>pc->tarjeta.largo;
        break;

        default:
            cout<<"Opcion invalida\n";
    }
}

int main(){
    PC pc;
    int opcion;

    do{
        cout<<"\n--- MENU ---\n";
        cout<<"1. Capturar\n";
        cout<<"2. Mostrar\n";
        cout<<"3. Modificar\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: capturar(&pc); break;
            case 2: mostrar(&pc); break;
            case 3: modificar(&pc); break;
        }

    }while(opcion != 4);

    return 0;
}