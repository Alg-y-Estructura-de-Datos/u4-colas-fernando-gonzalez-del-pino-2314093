#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Imagina una oficina con varias impresoras compartidas por varios empleados. Cada vez que un
empleado envía un documento para imprimir, este se coloca en una cola de impresión. Las
impresoras trabajan de manera que el primer documento enviado es el primero en ser impreso.
Si una impresora está ocupada, el documento queda en espera en la cola hasta que la impresora
esté disponible.
Implementar un sistema de gestión de colas de impresión en el que se:
 Agreguen documentos a la cola de impresión.
 Se impriman documentos en el orden en que fueron enviados.
 Se pueda mostrar el estado de la cola de impresión y los documentos pendientes*/

struct Documento {
    string nombre;
    int paginas;

    Documento(const string &nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar () {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};

void mostrarCola(Cola<Documento> &cola) {
    Cola<Documento> aux;

    cout << "\nCola de impresion: " << endl;
    while (!cola.esVacia()) {
        Documento doc = cola.desencolar();
        doc.mostrar();
        aux.encolar(doc);
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

void agregarDocumento(Cola<Documento> &cola) {
    string nombre;
    int paginas;
    cout << "\nIngrese el nombre del documento: ";
    cin.ignore();
    getline(cin,nombre);
    cout << "Ingrese la cantidad de paginas: ";
    cin >> paginas;

    Documento nuevoDoc(nombre, paginas);
    cola.encolar(nuevoDoc);
    cout << "\nDocumento agregado a la cola de impresion" << endl;
}

void imprimirDocumento(Cola<Documento> &cola) {
    if (cola.esVacia()) {
        cout << "\nNo hay documentos en espera" << endl;
        return;
    }

    Documento doc = cola.desencolar();
    cout << "\nImprimiendo documento: " << endl;
    doc.mostrar();
}

int main() {
    Cola<Documento> cola;
    int opcion;
    do {
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Mostrar cola de impresion\n";
        cout << "2. Agregar nuevo documento a la cola\n";
        cout << "3. Imprimir siguiente documento\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarCola(cola);
            break;
            case 2:
                agregarDocumento(cola);
            break;
            case 3:
                imprimirDocumento(cola);
            break;
            case 4:
                cout << "\nSaliendo del programa..." << endl;
            break;
            default:
                cerr << "\nOpción invalida. Intentelo de nuevo." << endl;
            break;
        }
    } while (opcion != 4);


    return 0;
}
