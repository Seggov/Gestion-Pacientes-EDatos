#include "../include/Hospital.h"
#include <fstream>
#include <cctype>

// limpia texto para comparar
static string limpiar(string s) {
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
        else if (c != ' ' && c != '\t' && c != '\r' && c != '\n') res += (char)c;
    }
    return res;
}

// constructor
Hospital::Hospital() {
    inicializarServicios();
}

// destructor
Hospital::~Hospital() {}

void Hospital::inicializarServicios() {
    string catalogo[TOTAL_SERVICIOS] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    const string* pOrigen = catalogo;
    string* pDestino = nombresServicios;

    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        // copia con aritmetica de punteros
        *(pDestino + i) = *(pOrigen + i);
        servicios.agregarServicio(*(pDestino + i));
    }
}

// valida departamento con punteros
bool Hospital::esServicioValido(string servLeido, string& servOficial) const {
    const string* inicio = nombresServicios;
    const string* fin = nombresServicios + TOTAL_SERVICIOS;

    for (const string* ptr = inicio; ptr < fin; ptr++) {
        if (limpiar(*ptr) == limpiar(servLeido)) {
            servOficial = *ptr;
            return true;
        }
    }
    return false;
}

// metodo para separar la linea con punteros
bool Hospital::parsearLinea(string linea, string& id, string& nombre, int& edad, string& serv) const {
    if (linea.empty()) return false;

    const char* ptr = linea.c_str();
    string tokens[4];
    int tokenIdx = 0;

    while (*ptr != '\0' && tokenIdx < 4) {
        // salta espacios
        while (*ptr == ' ' || *ptr == '\t' || *ptr == '\r') {
            ptr++;
        }
        if (*ptr == '\0') break;

        const char* inicioToken = ptr;

        // avanza hasta el separador
        while (*ptr != '\0' && *ptr != ';') {
            ptr++;
        }

        // retrocede espacios
        const char* finToken = ptr - 1;
        while (finToken >= inicioToken && (*finToken == ' ' || *finToken == '\t' || *finToken == '\r')) {
            finToken--;
        }

        if (finToken >= inicioToken) {
            tokens[tokenIdx] = string(inicioToken, finToken - inicioToken + 1);
        }
        tokenIdx++;

        if (*ptr == ';') {
            ptr++;
        }
    }

    if (tokenIdx < 4 || tokens[0].empty() || tokens[1].empty() || tokens[2].empty() || tokens[3].empty()) {
        return false;
    }

    id = tokens[0];
    nombre = tokens[1];
    try {
        edad = stoi(tokens[2]);
        if (edad < 0 || edad > 130) return false;
    } catch (...) {
        return false;
    }
    serv = tokens[3];
    return true;
}

// metodo para la lectura de pacientes
bool Hospital::cargarPacientes(string ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        archivo.open("../" + ruta);
        if (!archivo.is_open()) {
            cout << "[ERROR] No se pudo abrir: " << ruta << endl;
            return false;
        }
    }

    string linea;
    int cargados = 0;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        string id, nombre, serv, servOficial;
        int edad = 0;

        if (!parsearLinea(linea, id, nombre, edad, serv)) continue;
        if (!esServicioValido(serv, servOficial)) continue;

        // si ya existe
        if (colaEspera.existe(id) || servicios.existePaciente(id)) continue;

        Paciente p(id, nombre, edad, servOficial);
        colaEspera.enqueue(p);
        cargados++;
    }

    archivo.close();
    cout << "-> Pacientes cargados en cola: " << cargados << endl;
    return cargados > 0;
}

// out para la cola
void Hospital::mostrarCola() const {
    cout << "\n=== PACIENTES EN ESPERA ===" << endl;
    colaEspera.mostrar();
}

// atencion de pacientes y derivacion
void Hospital::atenderPacientes(int cantidad) {
    if (colaEspera.isEmpty()) {
        cout << "\n(No hay pacientes en cola de espera)" << endl;
        return;
    }

    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
    int atendidos = 0;

    while (atendidos < cantidad && !colaEspera.isEmpty()) {
        Paciente p;
        if (colaEspera.dequeue(p)) {
            // deriva al servicio
            servicios.agregarPacienteAServicio(p.getServicio(), p);

            // guarda en historial
            historial.push(p);

            // imprime la ficha
            p.mostrarEnAtencion();
            cout << endl;
            atendidos++;
        }
    }
}

// out de departamentos
void Hospital::mostrarDepartamentos() const {
    cout << "\n=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    servicios.mostrar();
}

// out de pacientes en el servicio seleccionado
void Hospital::mostrarEstadoDepartamento(int indice) const {
    NodoServicio* nodo = servicios.obtenerPorIndice(indice);
    if (nodo != nullptr) {
        string nomMayus = nodo->nombre;
        for (char& c : nomMayus) c = toupper((unsigned char)c);

        cout << "\n=== ESTADO " << nomMayus << " ===" << endl;
        cout << "Pacientes en el departamento de " << nodo->nombre << ": " << nodo->pacientes.size() << endl;
        nodo->pacientes.mostrar();
    } else {
        cout << "\n[ERROR] Departamento no valido." << endl;
    }
}

// out para el historial
void Hospital::mostrarHistorial() const {
    cout << "\n=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << endl;
    historial.mostrar();
}

// consulta de paciente
void Hospital::buscarPaciente(string criterio) const {
    if (criterio.empty()) return;

    cout << "\n--- Resultado de Busqueda: '" << criterio << "' ---" << endl;

    Paciente p;
    if (colaEspera.buscar(criterio, p)) {
        cout << "[EN COLA DE ESPERA] ID: " << p.getId() << " | Nombre: " << p.getNombre()
             << " | Edad: " << p.getEdad() << " | Servicio: " << p.getServicio() << endl;
        return;
    }

    string serv;
    if (servicios.buscarPaciente(criterio, p, serv)) {
        cout << "[ATENDIDO EN: " << serv << "] ID: " << p.getId()
             << " | Nombre: " << p.getNombre() << " | Edad: " << p.getEdad() << endl;
        return;
    }

    cout << "No se encontro ningun paciente con ese criterio." << endl;
}

int Hospital::getCantidadEnEspera() const {
    return colaEspera.size();
}
