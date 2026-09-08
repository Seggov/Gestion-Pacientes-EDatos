#include <iostream>
using namespace std;


    
struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
}; // punto y coma necesarios para el sctruc 
