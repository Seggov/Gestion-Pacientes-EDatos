#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"

// clase paciente que hereda de persona
class Paciente : public Persona {
private:
    // departamento asignado
    string servicio;

public:
    // constructores
    Paciente();
    Paciente(string id, string nombre, int edad, string servicio);

    // destructor
    virtual ~Paciente() override;

    // get servicio
    string getServicio() const;

    // sobreescritura de mostrar
    void mostrar() const override;

    // metodos de out para cada caso del taller
    void mostrarEnFila(int correlativo) const;
    void mostrarEnAtencion() const;
    void mostrarEnDepartamento() const;
    void mostrarEnHistorial() const;
};

#endif
