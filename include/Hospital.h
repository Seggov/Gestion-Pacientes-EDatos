#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include "Estructuras.h"

using namespace std;

// total de departamentos
const int TOTAL_SERVICIOS = 8;

// clase que controla todo el hospital
class Hospital {
private:
    // estructuras que manejan los datos
    ColaPacientes colaEspera;
    ListaServicios servicios;
    PilaHistorial historial;

    // arreglo para los servicios
    string nombresServicios[TOTAL_SERVICIOS];

    // metodos con aritmetica de punteros
    void inicializarServicios();
    bool esServicioValido(string servLeido, string& servOficial) const;
    bool parsearLinea(string linea, string& id, string& nombre, int& edad, string& serv) const;

public:
    Hospital();
    ~Hospital();

    // funciones principales
    bool cargarPacientes(string ruta);
    void atenderPacientes(int cantidad);
    void mostrarCola() const;
    void mostrarDepartamentos() const;
    void mostrarEstadoDepartamento(int indice) const;
    void mostrarHistorial() const;
    void buscarPaciente(string criterio) const;

    int getCantidadEnEspera() const;
};

#endif
