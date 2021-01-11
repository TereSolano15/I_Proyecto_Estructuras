//
// Created by efrai on 11/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_IREADER_H
#define I_PROYECTO_ESTRUCTURAS_IREADER_H
#include"ArbolABB.h"
using namespace std;

template<class T>
class IReader
{
public:
    virtual ArbolABB<T>* leerTodos() = 0;
    virtual ~IReader() = default;
};
#endif //I_PROYECTO_ESTRUCTURAS_IREADER_H
