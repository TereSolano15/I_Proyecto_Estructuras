//
// Created by efrai on 11/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_IWRITER_H
#define I_PROYECTO_ESTRUCTURAS_IWRITER_H
#include"ArbolABB.h"
using namespace std;

template<class T>
class IWriter{
public:
    virtual void escribir(T elemento) = 0;
    virtual void escribirTodos(ArbolABB<T>* elementos) = 0;
    virtual ~IWriter() = default;
};
#endif //I_PROYECTO_ESTRUCTURAS_IWRITER_H
