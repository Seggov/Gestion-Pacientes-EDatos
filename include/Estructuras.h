#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include "Paciente.h"
#include <iostream>

/**
 * @struct Nodo
 * @brief Nodo básico para estructuras lineales dinámicas basadas en punteros.
 */
struct Nodo {
    Paciente dato;        ///< Información del paciente almacenado
    Nodo* siguiente;      ///< Puntero al siguiente nodo en la estructura

    /**
     * @brief Constructor del nodo.
     * @param p Objeto Paciente a almacenar.
     */
    Nodo(const Paciente& p) : dato(p), siguiente(nullptr) {}
};

/**
 * @class Cola
 * @brief Implementación de una cola (Queue - FIFO: Primero en entrar, primero en salir) con punteros.
 * 
 * Se utiliza para modelar la fila de espera de pacientes que aguardan atención médica.
 */
class Cola {
private:
    Nodo* frente;         ///< Puntero al primer elemento de la cola (próximo a atender)
    Nodo* fin;            ///< Puntero al último elemento de la cola (último que llegó)
    int cantidad;         ///< Contador de pacientes en la cola

public:
    Cola();
    ~Cola();

    /**
     * @brief Inserta un nuevo paciente al final de la cola.
     * @param p Paciente a encolar.
     */
    void encolar(const Paciente& p);

    /**
     * @brief Remueve y retorna el paciente al frente de la cola.
     * @param pacienteAtendido Variable por referencia donde se almacena el paciente retirado.
     * @return true si se desencoló con éxito, false si la cola estaba vacía.
     */
    bool desencolar(Paciente& pacienteAtendido);

    /**
     * @brief Verifica si la cola no tiene elementos.
     */
    bool estaVacia() const;

    /**
     * @brief Retorna la cantidad de elementos en la cola.
     */
    int getCantidad() const;

    /**
     * @brief Imprime todos los pacientes formados en la cola en orden de llegada.
     */
    void mostrar() const;

    /**
     * @brief Obtiene el puntero al frente (útil para recorridos de solo lectura).
     */
    Nodo* getFrente() const;
};

/**
 * @class Pila
 * @brief Implementación de una pila (Stack - LIFO: Último en entrar, primero en salir) con punteros.
 * 
 * Se utiliza para registrar el historial de atenciones médicas.
 */
class Pila {
private:
    Nodo* tope;           ///< Puntero al elemento en la cima de la pila (atención más reciente)
    int cantidad;         ///< Contador de pacientes atendidos

public:
    Pila();
    ~Pila();

    /**
     * @brief Inserta un paciente atendido en el tope de la pila.
     * @param p Paciente atendido a registrar.
     */
    void apilar(const Paciente& p);

    /**
     * @brief Retira y retorna el paciente más reciente del tope.
     * @param p Variable por referencia donde se almacena el paciente retirado.
     * @return true si se desapiló correctamente, false si la pila estaba vacía.
     */
    bool desapilar(Paciente& p);

    /**
     * @brief Verifica si la pila no tiene elementos.
     */
    bool estaVacia() const;

    /**
     * @brief Retorna la cantidad de elementos en la pila.
     */
    int getCantidad() const;

    /**
     * @brief Muestra el historial completo de atenciones.
     */
    void mostrar() const;

    /**
     * @brief Retorna el puntero al nodo tope (para iteraciones o exportaciones).
     */
    Nodo* getTope() const;
};

#endif // ESTRUCTURAS_H
