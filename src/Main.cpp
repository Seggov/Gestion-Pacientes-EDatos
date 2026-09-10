#include <iostream>
#include <string>
#include <limits>

#include "Hospital.h"
#include "Paciente.h"
#include "Estructuras.h"

using namespace std;

// ========================================================
//              DECLARACIÓN DE PROTOTIPOS
// ========================================================

/**
 * @brief Imprime en pantalla las opciones del menú principal.
 */
void mostrarMenu();

/**
 * @brief Captura y valida la opción numérica ingresada por el usuario.
 * @return Opción seleccionada como número entero.
 */
int selector();

/**
 * @brief Solicita al usuario los datos de un paciente por consola y lo encola en el hospital.
 * @param hospital Referencia al objeto principal del hospital.
 */
void registrarNuevoPaciente(Hospital& hospital);

/**
 * @brief Ejecuta el proceso de atención del primer paciente en la cola.
 * @param hospital Referencia al objeto principal del hospital.
 */
void atenderPaciente(Hospital& hospital);

// ========================================================
//                FUNCIÓN PRINCIPAL (MAIN)
// ========================================================

int main() {
    Hospital hospital;

    cout << "======================================================" << endl;
    cout << "    SISTEMA DE GESTION HOSPITALARIA - HOSPITAL MARMAJA" << endl;
    cout << "======================================================" << endl;

    // 1. Carga inicial de pacientes desde el archivo de texto
    const string rutaDatos = "data/data.txt";
    cout << "\n[*] Cargando lista inicial de pacientes desde '" << rutaDatos << "'..." << endl;
    if (!hospital.cargarPacientesDesdeArchivo(rutaDatos)) {
        cout << "[!] No se pudo cargar el archivo inicial. Se iniciara con la fila vacia." << endl;
    }

    int opcion = -1;

    // 2. Bucle principal de interacción con el usuario
    do {
        mostrarMenu();
        opcion = selector();

        switch (opcion) {
            case 1:
                // Visualizar la fila de espera actual (Cola FIFO)
                hospital.mostrarFilaEspera();
                break;

            case 2:
                // Agregar un paciente manualmente por consola
                registrarNuevoPaciente(hospital);
                break;

            case 3:
                // Atender al paciente en turno
                atenderPaciente(hospital);
                break;

            case 4:
                // Visualizar el historial de atenciones (Pila LIFO)
                hospital.mostrarHistorial();
                break;

            case 5:
                // Exportar el historial a un archivo de texto
                hospital.exportarHistorial("historialPacientes.txt");
                break;

            case 0:
                cout << "\nSaliendo del sistema... Que tenga un buen dia!" << endl;
                break;

            default:
                cout << "\n[!] Opcion invalida. Por favor, ingrese un numero del menu." << endl;
                break;
        }

    } while (opcion != 0);

    return 0; // Finalización exitosa del programa
}

// ========================================================
//              IMPLEMENTACIÓN DE FUNCIONES
// ========================================================

void mostrarMenu() {
    cout << "\n------------------------------------------------------" << endl;
    cout << "                     MENU PRINCIPAL                   " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " [1] Visualizar Fila de Espera" << endl;
    cout << " [2] Agregar Nuevo Paciente a la Fila" << endl;
    cout << " [3] Atender Siguiente Paciente" << endl;
    cout << " [4] Visualizar Historial de Atenciones" << endl;
    cout << " [5] Exportar Historial a Archivo (historialPacientes.txt)" << endl;
    cout << " [0] Salir" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Seleccione una opcion: ";
}

int selector() {
    int opcion;
    // Validación de entrada para evitar bucles infinitos en caso de ingresar caracteres no numéricos
    while (!(cin >> opcion)) {
        cin.clear(); // Limpia la bandera de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
        cout << "[!] Entrada invalida. Ingrese un numero: ";
    }
    // Limpia el salto de línea sobrante en el búfer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return opcion;
}

void registrarNuevoPaciente(Hospital& hospital) {
    string id, nombre, especialidad;
    int edad;

    cout << "\n--- REGISTRAR NUEVO PACIENTE ---" << endl;
    cout << "Ingrese ID (ej: 101): ";
    getline(cin, id);

    cout << "Ingrese Nombre Completo: ";
    getline(cin, nombre);

    cout << "Ingrese Edad: ";
    while (!(cin >> edad) || edad < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[!] Ingrese una edad valida mayor o igual a 0: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese Especialidad (ej: Cardiologia, Pediatria): ";
    getline(cin, especialidad);

    // Creación y agregado del nuevo paciente a la cola
    Paciente nuevo(id, nombre, edad, especialidad);
    hospital.agregarPacienteAFila(nuevo);
}

void atenderPaciente(Hospital& hospital) {
    Paciente atendido;
    cout << "\n--- ATENCION MEDICA ---" << endl;
    if (hospital.atenderSiguientePaciente(atendido)) {
        cout << "[+] Paciente atendido con exito:" << endl;
        cout << "    ";
        atendido.mostrarInfo();
        cout << "    -> Registrado en el historial de atenciones." << endl;
    } else {
        cout << "[!] No hay pacientes en la fila de espera para atender." << endl;
    }
}