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

## Descripción del Proyecto
Sistema básico de gestión y derivación hospitalaria desarrollado en **C++** bajo el paradigma de **Programación Orientada a Objetos (POO)** y **manejo manual de memoria dinámica con punteros**. 

El sistema implementa estructuras de datos lineales desde cero (sin el uso de la biblioteca estándar STL como `vector`, `list`, `queue` o `stack`), cumpliendo con el flujo:
$$\text{Archivo de texto} \longrightarrow \text{Cola de Espera (Queue FIFO)} \longrightarrow \text{Atención y Derivación (Lista Enlazada)} \longrightarrow \text{Historial (Stack LIFO)}$$

---

## Arquitectura de Carpetas

```text
Gestion-Pacientes-EDatos/
├── data/
│   └── data.txt               # Archivo de entrada con los registros de pacientes
├── include/                   # Archivos de cabecera (.h)
│   ├── Persona.h              # Clase base (ID, Nombre, Edad)
│   ├── Paciente.h             # Clase derivada con herencia (Servicio asignado)
│   ├── Estructuras.h          # Nodos, Cola, Listas Enlazadas y Pila manuales
│   └── Hospital.h             # Controlador principal y logica del hospital
├── src/                       # Codigo fuente (.cpp)
│   ├── Persona.cpp            # Implementacion de Persona
│   ├── Paciente.cpp           # Implementacion de Paciente
│   ├── Estructuras.cpp        # Implementacion de Queue, List y Stack
│   ├── Hospital.cpp           # Carga de datos, punteros y flujo clinico
│   └── Main.cpp               # Menu interactivo por consola
├── .gitignore                 # Exclusion de binarios y temporales
├── PedroSegoviaITI.txt        # Identificacion y enlace de entrega
└── README.md                  # Documentacion del proyecto