#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int selector();
void menu();
int lecturaInput();
int exportarHistorial();

int main()
{
    lecturaInput();
    bool esTerminado = false;
    while (!esTerminado)
    {
        menu();
        int user_selector = selector();

        switch (user_selector)
        {
        case 1:
            cout << "1";
            break;

        case 2:
            cout << "2";

            break;
        }
        esTerminado = false;
    }

    return 0;
}

int selector()
{
    int aux = 1; // por defecto visuliza el historial
    cout << "Ingresa tu Opcion: ";
    try
    {
        cin >> aux; // INP menu
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return aux;
}

void menu()
{
    string opciones = "[1] Visualizar el Historial \n[2] Agregar Pacientes a la Fila \n";
    cout << opciones << endl;
}

// 001; Emilio Vargas; 62; Cardiologia
int lecturaInput()
{
    ifstream archivo("datos.txt");
    string linea;
    if (!archivo.is_open())
    {
        cout << "no se puede abrir" << endl;
    }
    while (getline(archivo, linea))
    {
        // le hacemos la linea con split de (";")
        cout << linea << endl;
    }

    archivo.close();
    return 0; // termino correctamente
}

int exportarHistorial()
{
    ofstream salida("historialPacientes.txt");
    if (!salida.is_open())
    {
        cerr << "No se puede crear el archivo" << endl;
        return 1; // significa que el programa
        // aborto con algun tipo de error
        // directamente lo detiene el progrma
    }

    // if condicion si los nodos que los contienen dicen que ya pasaron
    // aqui tenemos que llamar a los nodos
    salida << "Nombre,Edad,Profesion" << endl;
    salida.close();

    cout << "Archivo exportado con exito" << endl;
    return 0; // exito en el ciclo
}
