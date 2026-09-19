#include "../include/Paciente.h"

// constructor vacio que llama al padre
Paciente::Paciente() : Persona(), servicio("") {}

// constructor con datos llamando a persona
Paciente::Paciente(string id, string nombre, int edad, string servicio)
    : Persona(id, nombre, edad), servicio(servicio) {}

// destructor
Paciente::~Paciente() {}

// devuelve el servicio
string Paciente::getServicio() const {
    return servicio;
}

// muestra los datos completos
void Paciente::mostrar() const {
    cout << "[" << id << "] " << nombre << " | " << edad << " anios | " << servicio << endl;
}

// out para la cola de espera
void Paciente::mostrarEnFila(int correlativo) const {
    cout << correlativo << ". " << id << " - " << nombre << endl;
}

// out para cuando se atiende
void Paciente::mostrarEnAtencion() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Servicio: " << servicio << endl;
    cout << "Paciente enviado a " << servicio << "." << endl;
}

// out de departamento
void Paciente::mostrarEnDepartamento() const {
    cout << nombre << " (" << edad << ")" << endl;
}

// out del historial
void Paciente::mostrarEnHistorial() const {
    cout << "Nombre: " << nombre << " | Edad: " << edad << " | Departamento: " << servicio << endl;
}
