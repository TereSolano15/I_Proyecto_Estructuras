//
// Created by Tere Solano on 10/1/2021.
//
#ifndef I_PROYECTO_ESTRUCTURAS_COLA_H
#define I_PROYECTO_ESTRUCTURAS_COLA_H
#include "Nodo.h"
template <typename T>
class Cola {
public:
    Cola() : primero(nullptr), ultimo(nullptr) {}
    ~Cola();
    void Anadir(int v);
    int Leer();
private:
   Nodo<T>* primero;
   Nodo<T>* ultimo;
};
#endif //I_PROYECTO_ESTRUCTURAS_COLA_H
