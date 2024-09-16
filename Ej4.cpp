#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una cola, pedir también un numero entero "n". Luego crear una función que
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de
la cola. Devuelva la suma de los elementos de la cola hasta llegar a "n" (sin incluir a n). Si el
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de
la cola. Imprimir primero la cola antes de la suma de sus elementos.*/

void suma(Cola<int> &cola, int n) {
    Cola<int> aux;
    int suma = 0;
    bool encontrado = false;

    cout << "\nCola: ";
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        cout << dato << " ";
        if (dato == n) {
            encontrado = true;
            break;
        }
        suma += dato;
        aux.encolar(dato);
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }

    if (encontrado) {
        cout << "\nLa suma de los elementos de la cola hasta llegar a " << n << " es: " << suma << endl;
    } else {
        cout << "\nEl numero " << n << " no se encuentra en la cola" << endl;
        cout << "La suma de todos los elementos de la cola es: " << suma << endl;
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

    suma(cola, n);


    return 0;
}
