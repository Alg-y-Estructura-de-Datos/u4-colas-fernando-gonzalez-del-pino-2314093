#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Implementar una función que suprima de la cola todos los elementos mayores que un número 'n'
 dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original*/

void suprimir(Cola<int> &cola, int n) {
    Cola<int> aux;

    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato <= n) {
            aux.encolar(dato);
        }
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
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

    suprimir(cola, n);

    cout << "\nCola resultante: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }

    return 0;
}