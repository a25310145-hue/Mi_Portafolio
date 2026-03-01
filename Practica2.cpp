#include <iostream>
#include <cstring>
using namespace std;

//Codigo de POO Segunda Practica

void capturar(char *cadena)
{
    cout << "Ingrese los deportes separados por un simbolo: ";
    cin.ignore();
    cin.getline(cadena, 200);
}

void imprimir(char *cadena)
{
    char *ptr = cadena;

    while (*ptr != '\0')
    {
        char deporte[50];
        char *pDep = deporte;

        int vocales = 0, consonantes = 0, espacios = 0, longitud = 0;

        while (*ptr != '#' && *ptr != '\0')
        {
            *pDep = *ptr;

            char c = *ptr;

            if (c == ' ')
                espacios++;
            else if (strchr("aeiouAEIOU", c))
                vocales++;
            else if (isalpha(c))
                consonantes++;

            pDep++;
            ptr++;
            longitud++;
        }

        *pDep = '\0';

        cout << "\nDeporte: " << deporte << endl;
        cout << "Vocales: " << vocales << endl;
        cout << "Consonantes: " << consonantes << endl;
        cout << "Espacios: " << espacios << endl;
        cout << "Longitud: " << longitud << endl;

        if (*ptr == '#')
            ptr++;
    }
}

void comparar()
{
    char cad1[100], cad2[100];

    cout << "Cadena 1: ";
    cin.ignore();
    cin.getline(cad1, 100);

    cout << "Cadena 2: ";
    cin.getline(cad2, 100);

    char *p1 = cad1;
    char *p2 = cad2;

    while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0')
    {
        p1++;
        p2++;
    }

    if (*p1 == *p2)
        cout << "Las cadenas son iguales\n";
    else if (*p1 > *p2)
        cout << "La primera es mayor\n";
    else
        cout << "La segunda es mayor\n";
}
void invertir(char *cadena)
{
    char invertida[200];

    char *p = cadena;
    char *fin;

    while (*p != '\0')
        p++;

    fin = p - 1;

    char *inv = invertida;

    while (fin >= cadena)
    {
        *inv = *fin;
        inv++;
        fin--;
    }

    *inv = '\0';

    cout << "Cadena invertida: " << invertida << endl;
}

void quitarEspacios()
{
    char cadena[200];

    cout << "Ingrese cadena con espacios: ";
    cin.ignore();
    cin.getline(cadena, 200);

    char *inicio = cadena;
    char *fin = cadena;

    while (*inicio == ' ')
    {
        inicio++;
    }

    while (*fin != '\0')
    {
        fin++;
    }

    fin--;

    while (*fin == ' ')
    {
        fin--;
    }

    fin++;

    *fin = '\0';

    cout << "Cadena sin espacios: " << inicio << endl;
}
int main()
{
    char cadena[200];
    int opcion;

    do
    {
        cout << "\nMENU\n";
        cout << "1. Capturar\n";
        cout << "2. Imprimir\n";
        cout << "3. Comparar\n";
        cout << "4. Invertir\n";
        cout << "5. Espacios\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            capturar(cadena);
            break;

        case 2:
            imprimir(cadena);
            break;

        case 3:
            comparar();
            break;

        case 4:
            invertir(cadena);
            break;

        case 5:
            quitarEspacios();
            break;

        }

    } while (opcion != 6);
    
    return 0;
}