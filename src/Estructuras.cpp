#include "Estructuras.h"
#include <iostream>

using namespace std;

// ==========================================
//           IMPLEMENTACIÓN DE COLA (FIFO)
// ==========================================

Cola::Cola() : frente(nullptr), fin(nullptr), cantidad(0) {}

Cola::~Cola() {
    // Liberación de memoria dinámica de todos los nodos en la cola
    Paciente temp;
    while (desencolar(temp)) {
        // desencolar() elimina nodo a nodo
    }
}

void Cola::encolar(const Paciente& p) {
    Nodo* nuevo = new Nodo(p);
    if (estaVacia()) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    cantidad++;
}

bool Cola::desencolar(Paciente& pacienteAtendido) {
    if (estaVacia()) {
        return false;
    }
    
    Nodo* temp = frente;
    pacienteAtendido = temp->dato;
    frente = frente->siguiente;

    // Si la cola quedó vacía, actualizamos fin
    if (frente == nullptr) {
        fin = nullptr;
    }

    delete temp; // Liberación del nodo de la memoria dinámica
    cantidad--;
    return true;
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

int Cola::getCantidad() const {
    return cantidad;
}

void Cola::mostrar() const {
    if (estaVacia()) {
        cout << "[!] La fila de espera esta actualmente vacia." << endl;
        return;
    }

    cout << "\n--- PACIENTES EN FILA DE ESPERA (" << cantidad << ") ---" << endl;
    Nodo* actual = frente;
    int posicion = 1;
    while (actual != nullptr) {
        cout << "#" << posicion++ << " -> ";
        actual->dato.mostrarInfo();
        actual = actual->siguiente;
    }
}

Nodo* Cola::getFrente() const {
    return frente;
}

// ==========================================
//           IMPLEMENTACIÓN DE PILA (LIFO)
// ==========================================

Pila::Pila() : tope(nullptr), cantidad(0) {}

Pila::~Pila() {
    // Liberación de memoria dinámica de todos los nodos en la pila
    Paciente temp;
    while (desapilar(temp)) {
        // desapilar() elimina nodo a nodo
    }
}

void Pila::apilar(const Paciente& p) {
    Nodo* nuevo = new Nodo(p);
    nuevo->siguiente = tope;
    tope = nuevo;
    cantidad++;
}

bool Pila::desapilar(Paciente& p) {
    if (estaVacia()) {
        return false;
    }

    Nodo* temp = tope;
    p = temp->dato;
    tope = tope->siguiente;

    delete temp; // Liberación del nodo de la memoria dinámica
    cantidad--;
    return true;
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}

int Pila::getCantidad() const {
    return cantidad;
}

void Pila::mostrar() const {
    if (estaVacia()) {
        cout << "[!] El historial de atenciones esta vacio." << endl;
        return;
    }

    cout << "\n--- HISTORIAL DE PACIENTES ATENDIDOS (" << cantidad << ") ---" << endl;
    cout << "(Orden: Desde la atencion mas reciente a la mas antigua)\n" << endl;
    Nodo* actual = tope;
    int contador = 1;
    while (actual != nullptr) {
        cout << "[" << contador++ << "] ";
        actual->dato.mostrarInfo();
        actual = actual->siguiente;
    }
}

Nodo* Pila::getTope() const {
    return tope;
}
