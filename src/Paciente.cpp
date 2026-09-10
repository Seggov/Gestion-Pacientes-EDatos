#include "Paciente.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Constructor por defecto.
 */
Paciente::Paciente() : id(""), nombre(""), edad(0), especialidad("") {}

/**
 * @brief Constructor con parámetros inicializadores.
 */
Paciente::Paciente(const string& id, const string& nombre, int edad, const string& especialidad)
    : id(id), nombre(nombre), edad(edad), especialidad(especialidad) {}

// --- Getters ---
string Paciente::getId() const { 
    return id; 
}

string Paciente::getNombre() const { 
    return nombre; 
}

int Paciente::getEdad() const { 
    return edad; 
}

string Paciente::getEspecialidad() const { 
    return especialidad; 
}

// --- Setters ---
void Paciente::setId(const string& id) { 
    this->id = id; 
}

void Paciente::setNombre(const string& nombre) { 
    this->nombre = nombre; 
}

void Paciente::setEdad(int edad) { 
    this->edad = edad; 
}

void Paciente::setEspecialidad(const string& especialidad) { 
    this->especialidad = especialidad; 
}

/**
 * @brief Imprime los datos del paciente en una sola línea con columnas ordenadas.
 */
void Paciente::mostrarInfo() const {
    cout << "ID: " << left << setw(6) << id
         << " | Paciente: " << setw(24) << nombre
         << " | Edad: " << setw(4) << edad
         << " | Especialidad: " << especialidad << endl;
}
