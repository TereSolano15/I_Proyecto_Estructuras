//
// Created by Tere Solano on 9/1/2021.
//
#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#include <fstream>
#include "ArbolABB.h"
#include "Cliente.h"
#include<string>
#include "Lista.h"
using namespace std;

template<class T>
class ITransformadorCsv{
public:
    virtual Lista<string>* toStringVector(T elemento) = 0;
    virtual T fromStringVector(Lista<string>* vector) = 0;
    virtual ~ITransformadorCsv() = default;
};

class TransformadorCsvPersona : public ITransformadorCsv<Cliente*>{
public:
    Lista<string> * toStringVector(Cliente* elemento) override{
        Lista<string>* list = new Lista<string>;
        list->agregarInicio(elemento->getNombre());
        list->agregarInicio(elemento->getId());
        list->agregarInicio(to_string(elemento->isIngresaNinno()));
        list->agregarInicio(to_string(elemento->isEmbarazada()));
        list->agregarInicio(to_string(elemento->isAdultoMayor()));
        list->agregarInicio(to_string(elemento->getCategoria()));
        return list;
    }

    Cliente* fromStringVector(Lista<string>* lista) override{
        return new Cliente(lista->at(0),lista->at(1), stoi(lista->at(2)),stoi(lista->at(3)),stoi(lista->at(4)),stoi(lista->at(5)));
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
