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
    int dato;
    Nodo *izquierdo;
    Nodo *derecho;
};
#endif //I_PROYECTO_ESTRUCTURAS_NODO_H
