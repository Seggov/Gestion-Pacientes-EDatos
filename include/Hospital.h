#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Estructura.h"

class Hospital {
public:
    Estructura fila; // La fila de pacientes del hospital

    // Constructor mínimo
    Hospital() {}

    // Delegamos la acción a la estructura
    void registrarPaciente(Persona p) {
        fila.agregar(p);
    }

    void mostrarPacientes() {
        fila.mostrar();
    }
};

#endif