//
// Created by Tere Solano on 11/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_LISTA_H
#define I_PROYECTO_ESTRUCTURAS_LISTA_H
#include "Nodo.h"
#include <sstream>
template <typename T>
class Lista {
private:
    Nodo<T> *raiz;
public:
    Lista();
    ~Lista();
    string toString();
    void agregarFinal(T*);
    void agregarInicio(T);
    bool borrar(T*, string &);
    basic_string<char, char_traits<char>, allocator<char>> at(int pos);

};


#endif //I_PROYECTO_ESTRUCTURAS_LISTA_H
