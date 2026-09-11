#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    // ATRIBUTOS BASICO
    string id;
    string nombre;
    int edad;
    string especialidad;

    // 1. Constructor vacío por defecto (para poder crear variables vacías)
    Persona() {
        id = "";
        nombre = "";
        edad = 0;
        especialidad = "";
    }

    // 2. Constructor con parámetros: inicializa la persona con sus datos reales
    Persona(string _id, string _nombre, int _edad, string _esp) {
        id = _id;
        nombre = _nombre;
        edad = _edad;
        especialidad = _esp;
    }
    
    // Método mínimo para imprimir los datos
    void mostrar() {
        cout << "[" << id << "] " << nombre << " | " << edad << " anios | " << especialidad << endl;
    }
};

#endif