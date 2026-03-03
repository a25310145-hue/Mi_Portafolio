#include <iostream>
#include <string>

using namespace std;

int main() {

    struct Gerente {
        string nombre;
        int edad;
        float salario;
    };

    struct Sucursal {
        string nombre;
        string direccion;
        int empleados;
    };

    Gerente gerente;
    Sucursal sucursal;

    // PUNTERO:
    // ptrGerente guarda la dirección de memoria de la variable "gerente"
    // Es decir, apunta a donde está almacenado "gerente"
    Gerente *ptrGerente = &gerente;

    // PUNTERO:
    // ptrSucursal guarda la dirección de memoria de la variable "sucursal"
    Sucursal *ptrSucursal = &sucursal;

    int opcionPrincipal, opcionSubmenu;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Capturar\n";
        cout << "2. Mostrar\n";
        cout << "3. Modificar\n";
        cout << "4. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcionPrincipal;

        switch(opcionPrincipal) {

            case 1:
                cout << "\n--- CAPTURAR ---\n";
                cout << "1. Gerente\n";
                cout << "2. Sucursal\n";
                cout << "3. Regresar\n";
                cout << "Seleccione opcion: ";
                cin >> opcionSubmenu;

                if(opcionSubmenu == 1) {
                    cout << "\n--- Capturar Gerente ---\n";

                    cin.ignore();
                    cout << "Nombre: ";

                    // Aquí usamos el puntero para acceder al atributo nombre
                    // -> significa "accede al atributo del objeto al que apunta"
                    getline(cin, ptrGerente->nombre);

                    cout << "Edad: ";
                    // Accedemos al atributo edad usando el puntero
                    cin >> ptrGerente->edad;

                    cout << "Salario: ";
                    // Accedemos al atributo salario usando el puntero
                    cin >> ptrGerente->salario;
                }
                else if(opcionSubmenu == 2) {
                    cout << "\n--- Capturar Sucursal ---\n";

                    cin.ignore();
                    cout << "Nombre: ";

                    // Usamos el puntero para guardar el nombre
                    getline(cin, ptrSucursal->nombre);

                    cout << "Direccion: ";
                    // Usamos el puntero para guardar la dirección
                    getline(cin, ptrSucursal->direccion);

                    cout << "Numero de empleados: ";
                    // Usamos el puntero para guardar empleados
                    cin >> ptrSucursal->empleados;
                }
                break;

            case 2:
                cout << "\n--- MOSTRAR ---\n";
                cout << "1. Gerente\n";
                cout << "2. Sucursal\n";
                cout << "3. Regresar\n";
                cout << "Seleccione opcion: ";
                cin >> opcionSubmenu;

                if(opcionSubmenu == 1) {
                    cout << "\n--- Datos del Gerente ---\n";

                    // Mostramos datos accediendo mediante el puntero
                    cout << "Nombre: " << ptrGerente->nombre << endl;
                    cout << "Edad: " << ptrGerente->edad << endl;
                    cout << "Salario: $" << ptrGerente->salario << endl;
                }
                else if(opcionSubmenu == 2) {
                    cout << "\n--- Datos de la Sucursal ---\n";

                    // Mostramos datos accediendo mediante el puntero
                    cout << "Nombre: " << ptrSucursal->nombre << endl;
                    cout << "Direccion: " << ptrSucursal->direccion << endl;
                    cout << "Empleados: " << ptrSucursal->empleados << endl;
                }
                break;

            case 3:
                cout << "\n--- MODIFICAR ---\n";
                cout << "1. Gerente\n";
                cout << "2. Sucursal\n";
                cout << "3. Regresar\n";
                cout << "Seleccione opcion: ";
                cin >> opcionSubmenu;

                if(opcionSubmenu == 1) {
                    int opcion;
                    do {
                        cout << "\n--- Modificar Gerente ---\n";
                        cout << "1. Nombre\n";
                        cout << "2. Edad\n";
                        cout << "3. Salario\n";
                        cout << "4. Regresar\n";
                        cout << "Seleccione opcion: ";
                        cin >> opcion;

                        cin.ignore();

                        switch(opcion) {
                            case 1:
                                cout << "Nuevo nombre: ";
                                // Modificamos el nombre usando el puntero
                                getline(cin, ptrGerente->nombre);
                                break;

                            case 2:
                                cout << "Nueva edad: ";
                                // Modificamos la edad usando el puntero
                                cin >> ptrGerente->edad;
                                break;

                            case 3:
                                cout << "Nuevo salario: ";
                                // Modificamos el salario usando el puntero
                                cin >> ptrGerente->salario;
                                break;
                        }
                    } while(opcion != 4);
                }
                else if(opcionSubmenu == 2) {
                    int opcion;
                    do {
                        cout << "\n--- Modificar Sucursal ---\n";
                        cout << "1. Nombre\n";
                        cout << "2. Direccion\n";
                        cout << "3. Numero de empleados\n";
                        cout << "4. Regresar\n";
                        cout << "Seleccione opcion: ";
                        cin >> opcion;

                        cin.ignore();

                        switch(opcion) {
                            case 1:
                                cout << "Nuevo nombre: ";
                                // Modificamos el nombre usando el puntero
                                getline(cin, ptrSucursal->nombre);
                                break;

                            case 2:
                                cout << "Nueva direccion: ";
                                // Modificamos la dirección usando el puntero
                                getline(cin, ptrSucursal->direccion);
                                break;

                            case 3:
                                cout << "Nuevo numero de empleados: ";
                                // Modificamos empleados usando el puntero
                                cin >> ptrSucursal->empleados;
                                break;
                        }
                    } while(opcion != 4);
                }
                break;

            case 4:
                cout << "\nPrograma finalizado.\n";
                break;

            default:
                cout << "\nOpcion no valida.\n";
        }

    } while(opcionPrincipal != 4);

    return 0;
}