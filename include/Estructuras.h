#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <iostream>
#include <string>
#include "Paciente.h"

using namespace std;

// struct nodo para pacientes
struct NodoPaciente {
    Paciente dato;
    NodoPaciente* siguiente;
    NodoPaciente(Paciente p) : dato(p), siguiente(nullptr) {}
};

// struct nodo para historial
struct NodoHistorial {
    Paciente paciente;
    NodoHistorial* siguiente;
    NodoHistorial(Paciente p) : paciente(p), siguiente(nullptr) {}
};

// cola de pacientes fifo
class ColaPacientes {
private:
    NodoPaciente* front;
    NodoPaciente* back;
    int tamano;

public:
    ColaPacientes();
    ~ColaPacientes();

    // mete a la cola
    void enqueue(Paciente p);
    void encolar(Paciente p) { enqueue(p); }

    // saca de la cola
    bool dequeue(Paciente& p);
    bool desencolar(Paciente& p) { return dequeue(p); }

    // funciones basicas
    bool isEmpty() const;
    int size() const;
    void mostrar() const;
    bool existe(string id) const;
    bool buscar(string criterio, Paciente& encontrado) const;
};

// lista enlazada de pacientes por servicio
class ListaPacientes {
private:
    NodoPaciente* head;
    int tamano;

public:
    ListaPacientes();
    ~ListaPacientes();

    // mete al final
    void insertar(Paciente p);
    bool isEmpty() const;
    int size() const;
    void mostrar() const;
    bool existe(string id) const;
    bool buscar(string criterio, Paciente& encontrado) const;
};

// nodo que contiene el nombre del servicio y su lista
struct NodoServicio {
    string nombre;
    ListaPacientes pacientes;
    NodoServicio* siguiente;
    NodoServicio(string n) : nombre(n), siguiente(nullptr) {}
};

// lista principal con los departamentos
class ListaServicios {
private:
    NodoServicio* head;
    int tamano;

public:
    ListaServicios();
    ~ListaServicios();

    // agrega servicio a la lista
    void agregarServicio(string nombre);
    NodoServicio* buscarServicio(string nombre) const;
    NodoServicio* obtenerPorIndice(int indice) const;
    int size() const;
    void mostrar() const;
    bool agregarPacienteAServicio(string nombreServicio, Paciente p);
    bool buscarPaciente(string criterio, Paciente& encontrado, string& servicio) const;
    bool existePaciente(string id) const;
};

// pila lifo para el historial
class PilaHistorial {
private:
    NodoHistorial* top;
    int tamano;

public:
    PilaHistorial();
    ~PilaHistorial();

    // push al tope
    void push(Paciente p);
    void apilar(Paciente p) { push(p); }

    // pop del tope
    bool pop(Paciente& p);
    bool desapilar(Paciente& p) { return pop(p); }

    bool isEmpty() const;
    int size() const;
    void mostrar() const;
};

#endif
