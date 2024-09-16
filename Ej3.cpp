#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir
la cola al final para verificar si hubo o no modificaciones*/

void eliminar(Cola<int> &cola, int n) {
    Cola<int> aux;
    bool encontrado = false;
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato == n && !encontrado) {
            encontrado = true;
            aux.encolar(dato);
        } else if (dato != n) {
            aux.encolar(dato);
        }
    }
    if (!encontrado) {
        cout << "\nEl numero " << n << " no se encuentra en la cola" << endl;
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
    cout << "\nCola resultante: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }
    cout << endl;

}

int main() {
    Cola<int> cola;
    int n, dato;

    cout << "\nIngrese los elementos de la cola (termina con -1): " << endl;
    while (cin >> dato && dato != -1) {
        cola.encolar(dato);
    }

    cout << "\nIngrese el valor de n: " << endl;
    cin >> n;

    eliminar(cola, n);

    return 0;
}
