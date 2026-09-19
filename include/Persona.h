#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

// definicion de clase base persona
class Persona {
protected:
    // datos basicos de persona
    string id;
    string nombre;
    int edad;

public:
    // constructor vacio
    Persona();

    // constructor con datos
    Persona(string id, string nombre, int edad);

    // destructor virtual para la herencia
    virtual ~Persona();

    // getters de los datos
    string getId() const;
    string getNombre() const;
    int getEdad() const;

    // out para mostrar
    virtual void mostrar() const;
};

#endif
