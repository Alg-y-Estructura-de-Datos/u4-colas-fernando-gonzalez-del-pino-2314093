#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son
iguales. Nota: los elementos constitutivos de las colas son caracteres*/

bool iguales(Cola<char> cola1, Cola<char> cola2) {
    while (!cola1.esVacia() && !cola2.esVacia()) {
        if (cola1.peek() != cola2.peek()) {
            return false;
        }
        cola1.desencolar();
        cola2.desencolar();
    }
    return cola1.esVacia() && cola2.esVacia();
}

int main() {
    Cola<char> cola1, cola2;
    char dato;

    cout << "\nIngrese los elementos de la cola 1 (termina con '.'): ";
    while (cin >> dato && dato != '.') {
        cola1.encolar(dato);
    }

    cout << "\nIngrese los elementos de la cola 2 (termina con '.'): ";
    while (cin >> dato && dato != '.') {
        cola2.encolar(dato);
    }

    if (iguales(cola1, cola2)) {
        cout << "Las colas son iguales" << endl;
    } else {
        cout << "Las colas no son iguales" << endl;
        \
    }

    return 0;
}
