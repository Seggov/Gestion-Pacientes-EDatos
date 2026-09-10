#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Paciente.h"
#include "Estructuras.h"
#include <string>

/**
 * @class Hospital
 * @brief Modela la gestión hospitalaria de pacientes: fila de espera e historial.
 * 
 * Centraliza las operaciones de:
 * - Cargar pacientes desde un archivo de texto con delimitadores ';'.
 * - Encolar nuevos pacientes a la fila de espera (FIFO).
 * - Atender al siguiente paciente en la fila y registrarlo en el historial (LIFO).
 * - Mostrar el estado de la fila y del historial.
 * - Exportar el historial de pacientes a un archivo de salida.
 */
class Hospital {
private:
    Cola filaEspera;      ///< Cola para los pacientes que esperan ser atendidos
    Pila historial;       ///< Pila para el registro cronológico inverso de pacientes atendidos

public:
    /**
     * @brief Constructor de la clase Hospital.
     */
    Hospital();

    /**
     * @brief Destructor de la clase Hospital.
     */
    ~Hospital();

    /**
     * @brief Lee y procesa un archivo de pacientes línea por línea.
     * 
     * Formato esperado en el archivo: ID; Nombre; Edad; Especialidad
     * 
     * @param rutaArchivo Ruta relativa o absoluta del archivo a leer.
     * @return true si se abrió y leyó correctamente, false en caso contrario.
     */
    bool cargarPacientesDesdeArchivo(const std::string& rutaArchivo);

    /**
     * @brief Registra un nuevo paciente en la fila de espera.
     * @param p Paciente a ingresar a la cola.
     */
    void agregarPacienteAFila(const Paciente& p);

    /**
     * @brief Atiende al primer paciente de la fila de espera y lo transfiere al historial.
     * @param atendido Variable por referencia donde se retorna el paciente atendido.
     * @return true si había paciente y fue atendido, false si la fila estaba vacía.
     */
    bool atenderSiguientePaciente(Paciente& atendido);

    /**
     * @brief Imprime en pantalla todos los pacientes esperando turno.
     */
    void mostrarFilaEspera() const;

    /**
     * @brief Imprime en pantalla el historial de pacientes ya atendidos.
     */
    void mostrarHistorial() const;

    /**
     * @brief Guarda los pacientes atendidos en un archivo de texto.
     * @param rutaArchivo Nombre o ruta del archivo de exportación.
     * @return true si el archivo se creó y escribió con éxito, false si falló.
     */
    bool exportarHistorial(const std::string& rutaArchivo) const;

    /**
     * @brief Retorna cuántos pacientes hay en la fila de espera.
     */
    int getCantidadEnFila() const;

    /**
     * @brief Retorna cuántos pacientes han sido atendidos hasta el momento.
     */
    int getCantidadAtendidos() const;
};

#endif // HOSPITAL_H
