#include "../include/Estructuras.h"

// constructor de cola
ColaPacientes::ColaPacientes() : front(nullptr), back(nullptr), tamano(0) {}

// destructor que borra todos los nodos
ColaPacientes::~ColaPacientes() {
    while (front != nullptr) {
        NodoPaciente* temp = front;
        front = front->siguiente;
        delete temp;
    }
    back = nullptr;
    tamano = 0;
}

// mete al final de la cola
void ColaPacientes::enqueue(Paciente p) {
    NodoPaciente* nuevo = new NodoPaciente(p);
    if (isEmpty()) {
        front = back = nuevo;
    } else {
        back->siguiente = nuevo;
        back = nuevo;
    }
    tamano++;
}

// saca del frente
bool ColaPacientes::dequeue(Paciente& p) {
    if (isEmpty()) return false;
    NodoPaciente* temp = front;
    p = temp->dato;
    front = front->siguiente;
    if (front == nullptr) {
        back = nullptr;
    }
    delete temp;
    tamano--;
    return true;
}

// revisa si esta vacia
bool ColaPacientes::isEmpty() const {
    return front == nullptr;
}

// cantidad en la cola
int ColaPacientes::size() const {
    return tamano;
}

// imprime los pacientes esperando
void ColaPacientes::mostrar() const {
    if (isEmpty()) {
        cout << "(No hay pacientes en espera)" << endl;
        return;
    }
    NodoPaciente* actual = front;
    int correlativo = 1;
    while (actual != nullptr) {
        actual->dato.mostrarEnFila(correlativo++);
        actual = actual->siguiente;
    }
}

// busca por id
bool ColaPacientes::existe(string id) const {
    NodoPaciente* actual = front;
    while (actual != nullptr) {
        if (actual->dato.getId() == id) return true;
        actual = actual->siguiente;
    }
    return false;
}

// busca por id o nombre
bool ColaPacientes::buscar(string criterio, Paciente& encontrado) const {
    NodoPaciente* actual = front;
    while (actual != nullptr) {
        if (actual->dato.getId() == criterio || actual->dato.getNombre() == criterio) {
            encontrado = actual->dato;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// constructor lista pacientes
ListaPacientes::ListaPacientes() : head(nullptr), tamano(0) {}

// destructor lista pacientes
ListaPacientes::~ListaPacientes() {
    while (head != nullptr) {
        NodoPaciente* temp = head;
        head = head->siguiente;
        delete temp;
    }
    tamano = 0;
}

// inserta al final de la lista
void ListaPacientes::insertar(Paciente p) {
    NodoPaciente* nuevo = new NodoPaciente(p);
    if (head == nullptr) {
        head = nuevo;
    } else {
        NodoPaciente* actual = head;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    tamano++;
}

bool ListaPacientes::isEmpty() const {
    return head == nullptr;
}

int ListaPacientes::size() const {
    return tamano;
}

// imprime la lista del departamento
void ListaPacientes::mostrar() const {
    NodoPaciente* actual = head;
    while (actual != nullptr) {
        actual->dato.mostrarEnDepartamento();
        actual = actual->siguiente;
    }
}

bool ListaPacientes::existe(string id) const {
    NodoPaciente* actual = head;
    while (actual != nullptr) {
        if (actual->dato.getId() == id) return true;
        actual = actual->siguiente;
    }
    return false;
}

bool ListaPacientes::buscar(string criterio, Paciente& encontrado) const {
    NodoPaciente* actual = head;
    while (actual != nullptr) {
        if (actual->dato.getId() == criterio || actual->dato.getNombre() == criterio) {
            encontrado = actual->dato;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// constructor lista servicios
ListaServicios::ListaServicios() : head(nullptr), tamano(0) {}

// destructor lista servicios
ListaServicios::~ListaServicios() {
    while (head != nullptr) {
        NodoServicio* temp = head;
        head = head->siguiente;
        delete temp;
    }
    tamano = 0;
}

// inserta servicio
void ListaServicios::agregarServicio(string nombre) {
    NodoServicio* nuevo = new NodoServicio(nombre);
    if (head == nullptr) {
        head = nuevo;
    } else {
        NodoServicio* actual = head;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    tamano++;
}

// funcion para comparar texto sin acentos
static string normalizar(string s) {
    string res = "";
    for (size_t i = 0; i < s.length(); i++) {
        unsigned char c = (unsigned char)s[i];
        if (c == 0xC3 && i + 1 < s.length()) {
            unsigned char next = (unsigned char)s[i + 1];
            if (next == 0xAD || next == 0x8D) { res += 'i'; i++; continue; }
            if (next == 0xA1 || next == 0x81) { res += 'a'; i++; continue; }
            if (next == 0xA9 || next == 0x89) { res += 'e'; i++; continue; }
            if (next == 0xB3 || next == 0x93) { res += 'o'; i++; continue; }
            if (next == 0xBA || next == 0x9A) { res += 'u'; i++; continue; }
        }
        if (c >= 'A' && c <= 'Z') res += (char)(c + 32);
        else if (c != ' ') res += (char)c;
    }
    return res;
}

// busca nodo por nombre
NodoServicio* ListaServicios::buscarServicio(string nombre) const {
    string busq = normalizar(nombre);
    NodoServicio* actual = head;
    while (actual != nullptr) {
        if (normalizar(actual->nombre) == busq) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// busca por indice numerico
NodoServicio* ListaServicios::obtenerPorIndice(int indice) const {
    if (indice < 1 || indice > tamano) return nullptr;
    NodoServicio* actual = head;
    for (int i = 1; i < indice && actual != nullptr; i++) {
        actual = actual->siguiente;
    }
    return actual;
}

int ListaServicios::size() const {
    return tamano;
}

// imprime los departamentos
void ListaServicios::mostrar() const {
    NodoServicio* actual = head;
    int i = 1;
    while (actual != nullptr) {
        cout << i++ << ". " << actual->nombre << endl;
        actual = actual->siguiente;
    }
}

// agrega paciente a un servicio
bool ListaServicios::agregarPacienteAServicio(string nombreServicio, Paciente p) {
    NodoServicio* serv = buscarServicio(nombreServicio);
    if (serv != nullptr) {
        serv->pacientes.insertar(p);
        return true;
    }
    return false;
}

// busca paciente en todos los departamentos
bool ListaServicios::buscarPaciente(string criterio, Paciente& encontrado, string& servicio) const {
    NodoServicio* actual = head;
    while (actual != nullptr) {
        if (actual->pacientes.buscar(criterio, encontrado)) {
            servicio = actual->nombre;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// verifica si el paciente ya esta en algun servicio
bool ListaServicios::existePaciente(string id) const {
    NodoServicio* actual = head;
    while (actual != nullptr) {
        if (actual->pacientes.existe(id)) return true;
        actual = actual->siguiente;
    }
    return false;
}

// constructor pila
PilaHistorial::PilaHistorial() : top(nullptr), tamano(0) {}

// destructor pila
PilaHistorial::~PilaHistorial() {
    while (top != nullptr) {
        NodoHistorial* temp = top;
        top = top->siguiente;
        delete temp;
    }
    tamano = 0;
}

// agrega al tope
void PilaHistorial::push(Paciente p) {
    NodoHistorial* nuevo = new NodoHistorial(p);
    nuevo->siguiente = top;
    top = nuevo;
    tamano++;
}

// saca del tope
bool PilaHistorial::pop(Paciente& p) {
    if (isEmpty()) return false;
    NodoHistorial* temp = top;
    p = temp->paciente;
    top = top->siguiente;
    delete temp;
    tamano--;
    return true;
}

bool PilaHistorial::isEmpty() const {
    return top == nullptr;
}

int PilaHistorial::size() const {
    return tamano;
}

// imprime historial en orden lifo
void PilaHistorial::mostrar() const {
    if (isEmpty()) {
        cout << "(Historial vacio, no se han atendido pacientes aun)" << endl;
        return;
    }
    NodoHistorial* actual = top;
    while (actual != nullptr) {
        actual->paciente.mostrarEnHistorial();
        actual = actual->siguiente;
    }
}
