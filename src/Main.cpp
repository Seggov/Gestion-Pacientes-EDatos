#include <iostream>
#include <string>
#include <limits>
#include "../include/Hospital.h"

using namespace std;

// prototipos para el menu
void menu();
int leerNumero();
int selector();

int main() {
    Hospital hospital;

    // carga inicial de pacientes
    cout << "Iniciando sistema Hospital Marmaja..." << endl;
    hospital.cargarPacientes("data/data.txt"); // verificar con "pacientes.txt"

    bool esTerminado = false;

    // ciclo del menu
    while (!esTerminado) {
        menu();
        int user_selector = selector();
        // a,b,c,d - d
        switch (user_selector) {
            // opcion atender
            case 1: {
                hospital.mostrarCola();
                if (hospital.getCantidadEnEspera() > 0) {
                    cout << "\nIndique la cantidad de pacientes a atender: ";
                    int cant = leerNumero();
                    hospital.atenderPacientes(cant);
                }
                break;
            }

            // opcion ver departamentos
            case 2: {
                hospital.mostrarDepartamentos();
                cout << "\nSeleccionar opcion: ";
                int depto = leerNumero();
                hospital.mostrarEstadoDepartamento(depto);
                break;
            }

            // opcion revisar historial
            case 3: {
                hospital.mostrarHistorial();
                break;
            }

            // opcion salir
            case 4: {
                cout << "\nHasta luego :D." << endl;
                esTerminado = true;
                break;
            }

            // opcion buscar
            case 5: {
                cout << "\nIngrese el ID o Nombre a buscar: ";
                string criterio;
                getline(cin, criterio);
                hospital.buscarPaciente(criterio);
                break;
            }

            // caso default
            default: {
                cout << "\nOpcion no valida. Intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}

// inputs para el menu por consola
void menu() {
    cout << "\n=== HOSPITAL MARMAJA ===" << endl;
    cout << "1. Atender pacientes" << endl;
    cout << "2. Ver departamento" << endl;
    cout << "3. Revisar historial de atencion" << endl;
    cout << "4. Salir" << endl;
    cout << "5. Buscar paciente" << endl;
}

// lee numero evitando errores
int leerNumero() {
    int valor = 0;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Ingrese un numero: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

// selector de opcion
int selector() {
    cout << "\nSeleccionar opcion: ";
    return leerNumero();
}
