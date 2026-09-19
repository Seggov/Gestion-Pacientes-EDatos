#include "../include/Persona.h"

// constructor por defecto
Persona::Persona() : id(""), nombre(""), edad(0) {}

// constructor que recibe valores
Persona::Persona(string id, string nombre, int edad)
    : id(id), nombre(nombre), edad(edad) {}

// destructor vacio
Persona::~Persona() {}

// get id
string Persona::getId() const {
    return id;
}

// get nombre
string Persona::getNombre() const {
    return nombre;
}

// get edad
int Persona::getEdad() const {
    return edad;
}

// print de datos
void Persona::mostrar() const {
    cout << "[" << id << "] " << nombre << " | " << edad << " anios" << endl;
}
