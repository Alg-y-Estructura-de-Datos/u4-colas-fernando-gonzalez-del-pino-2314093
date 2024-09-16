#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std;

/*Implementar una función que reciba una cola de números enteros y una pila entera vacía, y
separe los elementos de la cola de tal manera que los elementos pares de la cola permanezcan
en la cola, y los elementos impares formen parte de la pila.
Observaciones:
● Al insertar los elementos en la pila, deberán aparecer en orden inverso a como estaban
en la cola: el elemento de la posición 1 de la cola estará al fondo de la pila, el de la
posición 3 será el segundo desde el fondo, etc.
● Si la cola estuviera vacía mostrar mensaje de error*/

void separar(Cola<int> &cola, Pila<int> &pila) {

    if (cola.esVacia()) {
        cerr << "\nLa cola esta vacia" << endl;
    }

    Cola<int> aux;

    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato % 2 == 0) {
            aux.encolar(dato);
        } else {
            pila.push(dato);
        }
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }

}

int main() {
    Cola<int> cola;
    Pila<int> pila;
    int dato;

    cout << "\nIngrese los elementos de la cola (termina con -1): " << endl;
    while (cin >> dato && dato != -1) {
        cola.encolar(dato);
    }

    separar(cola, pila);

    cout << "\nCola resultante: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }

    cout << "\nPila resultante: ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}