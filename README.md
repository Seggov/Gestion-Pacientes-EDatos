# Taller 1: Gestión de Pacientes - Estructura de Datos
**Hospital Marmaja — II Semestre 2026**
**Universidad Católica del Norte — Sede Coquimbo**

---

## Integrantes
- **Nombre:** Pedro Segovia
- **RUT:** 21672694-4
- **GitHub:** [Seggov](https://github.com/Seggov)
- **Carrera:** Ingeniería en Tecnologías de la Información

---

## Descripción del proyecto
Sistema de consola en C++ que gestiona el flujo de pacientes del hospital Marmaja: los recibe desde un archivo de texto, los atiende en orden FIFO mediante una cola manual, los deriva a su servicio correspondiente en una lista enlazada de departamentos, y registra cada atención en un historial implementado como pila (LIFO). Todas las estructuras (Cola, Listas Enlazadas y Pila) están implementadas manualmente con nodos y punteros, sin usar contenedores de la STL.

---

## Compilación y ejecución

### Requisitos
- Compilador compatible con C++17 (g++ recomendado, versión 9 o superior)

### Compilar

**Linux / macOS:**
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o hospital
```

**Windows (MinGW):**
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o hospital.exe
```

### Ejecutar

Debe ejecutarse **desde la raíz del proyecto**, ya que el programa busca el archivo de entrada en `data/data.txt`:

```bash
./hospital
```

En Windows:
```bash
hospital.exe
```

### Uso
Al iniciar, el programa carga automáticamente los pacientes desde `data/data.txt` y muestra un menú interactivo:

```
1. Atender pacientes
2. Ver departamento
3. Revisar historial de atención
4. Salir
5. Buscar paciente
```

---

## Formato del archivo de entrada

Cada línea de `data/data.txt` debe seguir el formato:

```
ID;Nombre;Edad;Servicio
```

Ejemplo:
```
001;Juan Perez;25;Cardiologia
```

Los servicios válidos son: Urgencias, Medicina General, Cardiología, Neurología, Traumatología, Cirugía, Pediatría y Hospitalización (no distingue mayúsculas ni tildes).

---

## Arquitectura de carpetas

```text
Gestion-Pacientes-EDatos/
├── data/
│   └── data.txt               # Archivo de entrada con los registros de pacientes
├── include/                   # Archivos de cabecera (.h)
│   ├── Persona.h               # Clase base (ID, Nombre, Edad)
│   ├── Paciente.h               # Clase derivada con herencia (Servicio asignado)
│   ├── Estructuras.h            # Nodos, Cola, Listas Enlazadas y Pila manuales
│   └── Hospital.h               # Controlador principal y lógica del hospital
├── src/                        # Código fuente (.cpp)
│   ├── Persona.cpp
│   ├── Paciente.cpp
│   ├── Estructuras.cpp
│   ├── Hospital.cpp
│   └── Main.cpp
├── .gitignore
├── PedroSegoviaITI.txt
└── README.md
```
