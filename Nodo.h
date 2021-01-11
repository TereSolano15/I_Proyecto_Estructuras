//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_NODO_H
#define I_PROYECTO_ESTRUCTURAS_NODO_H
#include <iostream>
using namespace std;

template<typename T>
class Nodo {
public:
    Nodo(const T dat, Nodo *izq= nullptr, Nodo *der= nullptr) :dato(dat), izquierdo(izq), derecho(der) {}

    Nodo(int dato, Nodo *siguiente)
    : dato(dato), izquierdo(izquierdo),derecho(derecho), siguiente(siguiente) {}
    int dato;
    Nodo *izquierdo;
    Nodo *derecho;
    Nodo* siguiente;

    Nodo *getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Nodo *siguiente) {
        Nodo::siguiente = siguiente;
    }

};
#endif //I_PROYECTO_ESTRUCTURAS_NODO_H
