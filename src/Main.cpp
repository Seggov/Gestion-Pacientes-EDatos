#include <iostream>
#include <string>

using namespace std;

Hospital hospital = new Hospital();

void main(){

    lecturaInput();
    menu();
    selector();

}

int selector()
{ 
    int aux = 1; // por defecto visuliza el historial
// llamar al input del usuario
    return aux;


}


void menu()
{
    string opciones = "[1] Visualizar el Historial \n[2] Agregar Pacientes a la Fila";
    cout << opciones << endl;

}

// 001; Emilio Vargas; 62; Cardiologia
void lecturaInput()
{
    ifstream archivo("datos.txt");
    string linea;

    if(!archivo.is_open()){
        cout << "no se puede abrir" << endl;
    }

    while (getline(archivo,linea)){

        // le hacemos la linea con split de (";")
        cout << linea << endln;

    }


    archivo.close();
    return 0;


}

void exportarHistorial()
{
    ofstream salida("historialPacientes.txt");
    if (!salida.is_open()){
    cerr << "No se puede crear el archivo" << endl;
    return 1; // significa que el programa 
    // aborto con algun tipo de error
    // directamente lo detiene el progrma
    }
    
    // if condicion si los nodos que los contienen dicen que ya pasaron
    salida << "Nombre,Edad,Profesion" << endl;
    

    salida.close();
    cout << "Archivo exportado con exito" << endl;
    return 0; // exito en el ciclo
}
