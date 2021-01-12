//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#include <fstream>
#include <string>
#include "ArbolABB.h"
#include "Cliente.h"
using namespace std;

template<class T>
class ITransformadorCsv
{
public:
    virtual ArbolABB<string>* toStringVector(T elemento) = 0;
    virtual T fromStringArbol(ArbolABB<string>* arbol) = 0;
    virtual ~ITransformadorCsv() = default;
};
class TransformadorCsvCliente  : public ITransformadorCsv<Cliente*>{
public:
    ArbolABB<string>* toStringVector(Cliente* elemento){
        ArbolABB<string>* arbol = new ArbolABB<string>();
        arbol->push_back(elemento->getNombre());
        arbol->push_back(elemento->getId());
        arbol->push_back(elemento->isIngresaNinno());
        arbol->push_back(elemento->isEmbarazada());
        arbol->push_back(elemento->isAdultoMayor());
        arbol->push_back(elemento->getCategoria());
        return arbol;
    }

    Cliente* fromStringArbol(ArbolABB<string>* arbol){
        return new Cliente(arbol->at(0),arbol->at(1),arbol->at(2),arbol->at(3),arbol->at(4),arbol->at(5));
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
