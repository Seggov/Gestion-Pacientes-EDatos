#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <iostream>
#include "Persona.h"

using namespace std;

struct Nodo {
    Persona dato;       // La persona que esta en este turno
    Nodo* siguiente;    // Puntero que guarda la dirección del siguiente nodo en la fila

    // Constructor: guarda la persona y por defecto apunta a la NADA (nullptr)
    Nodo(Persona p) : dato(p), siguiente(nullptr) {}
};

// B. LA COLA O FILA (Estructura con punteros)
    struct Estructura {
    Nodo* primero = nullptr; // Apunta al primer paciente de la fila (el que será atendido)
    Nodo* ultimo = nullptr;  // Apunta al último paciente que llegó a la fila

    // Función mínima: Agregar un paciente a la fila (Encolar)
    void agregar(Persona p) {
        // PASO 1: Reservamos memoria para el nuevo nodo con 'new'
        // 'nuevo' tiene los datos del paciente y su 'siguiente' apunta a nullptr
        Nodo* nuevo = new Nodo(p);

        // PASO 2: ¿La fila estaba vacía?
        if (primero == nullptr) {
            // Si estaba vacía, el nuevo paciente es tanto el primero como el último
            primero = nuevo;
            ultimo = nuevo;
        } else {
            // Si ya había gente en la fila:
            // 1. El que era el último ahora apunta con su 'siguiente' al nuevo
            ultimo->siguiente = nuevo; 

            // 2. Actualizamos la flecha 'ultimo' para que ahora sea el recién llegado
            ultimo = nuevo;
        }
    }

    // Función mínima: Recorrer y mostrar la fila
    void mostrar() {
        // Creamos un puntero 'auxiliar' que empieza en el primero
        Nodo* actual = primero;

        // Mientras 'actual' no llegue al final (nullptr)
        while (actual != nullptr) {
            actual->dato.mostrar();      // Mostramos los datos del paciente
            actual = actual->siguiente;  // AVANZAMOS al siguiente nodo
        }
    }
};

#endif