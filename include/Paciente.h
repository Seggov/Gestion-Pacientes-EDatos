#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

/**
 * @class Paciente
 * @brief Modela la entidad de un paciente dentro del sistema del Hospital.
 * 
 * Contiene los atributos personales y médicos básicos del paciente:
 * identificador, nombre completo, edad y especialidad médica a la que acude.
 */
class Paciente {
private:
    std::string id;            ///< Identificador único del paciente (ej: "001")
    std::string nombre;        ///< Nombre y apellidos del paciente
    int edad;                  ///< Edad del paciente
    std::string especialidad;  ///< Especialidad o área médica (ej: "Cardiologia")

public:
    /**
     * @brief Constructor por defecto. Inicializa los atributos con valores vacíos o cero.
     */
    Paciente();

    /**
     * @brief Constructor parametrizado.
     * @param id Identificador único.
     * @param nombre Nombre del paciente.
     * @param edad Edad en años.
     * @param especialidad Área médica asignada.
     */
    Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& especialidad);

    // --- Métodos de Acceso (Getters) ---
    std::string getId() const;
    std::string getNombre() const;
    int getEdad() const;
    std::string getEspecialidad() const;

    // --- Métodos de Modificación (Setters) ---
    void setId(const std::string& id);
    void setNombre(const std::string& nombre);
    void setEdad(int edad);
    void setEspecialidad(const std::string& especialidad);

    /**
     * @brief Muestra por consola la información formateada del paciente.
     */
    void mostrarInfo() const;
};

#endif // PACIENTE_H
