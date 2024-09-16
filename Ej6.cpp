#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Implementar un programa con un menú de opciones para manejar un sistema de citas en un
consultorio médico. Añadiremos funcionalidades adicionales, como mostrar pacientes, agregar
nuevos pacientes y atender a los pacientes en espera. También manejaremos los datos de
pacientes de manera más detallada, como con nombres y números de teléfono*/

struct Paciente {
    string nombre;
    string telefono;

    Paciente(const string &nombre = "", const string &telefono = "") : nombre(nombre), telefono(telefono) {}

    void mostrar() {
        cout << "Nombre: " << nombre << ", Telefono: " << telefono << endl;
    }
};

void mostrarpacientes(Cola<Paciente> &pacientes) {
    Cola<Paciente> aux;

    cout << "\nPacientes en espera: " << endl;
    while (!pacientes.esVacia()) {
        Paciente paciente = pacientes.desencolar();
        paciente.mostrar();
        aux.encolar(paciente);
    }

    while (!aux.esVacia()) {
        pacientes.encolar(aux.desencolar());
    }
}

void agregarPaciente(Cola<Paciente> &pacientes) {
    string nombre, telefono;
    cout << "\nIngrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el telefono del paciente: ";
    cin >> telefono;

    Paciente nuevoPaciente(nombre, telefono);
    pacientes.encolar(nuevoPaciente);
    cout << "\nPaciente agregado a la cola de espera" << endl;
}

void atenderPaciente(Cola<Paciente> &pacientes) {
    if (pacientes.esVacia()) {
        cout << "\nNo hay pacientes en espera" << endl;
        return;
    }
    Paciente paciente = pacientes.desencolar();
    cout << "\nAtendiendo a: ";
    paciente.mostrar();
}

int main() {
    Cola<Paciente> pacientes;
    int opcion;
    string nombre, telefono;

    do {
        cout << "\nMenu de opciones: " << endl;
        cout << "1. Mostrar pacientes en espera" << endl;
        cout << "2. Agregar paciente" << endl;
        cout << "3. Atender paciente" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarpacientes(pacientes);
                break;
            case 2:
                agregarPaciente(pacientes);
                break;
            case 3:
                atenderPaciente(pacientes);
                break;
            case 4:
                cout << "\nSaliendo..." << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }
    } while (opcion != 4);


    return 0;
}