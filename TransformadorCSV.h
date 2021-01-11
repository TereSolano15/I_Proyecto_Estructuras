//
// Created by Tere Solano on 9/1/2021.
//
#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#include <fstream>
#include "ArbolABB.h"
#include "Cliente.h"
#include<string>
using namespace std;

template<class T>
class ITransformadorCsv{
public:
    virtual ArbolABB<string>* toStringVector(T elemento) = 0;
    virtual T fromStringVector(ArbolABB<string>* vector) = 0;
    virtual ~ITransformadorCsv() = default;
};

class TransformadorCsvPersona : public ITransformadorCsv<Cliente*>{
public:
    ArbolABB<string>* toStringVector(Cliente* elemento) override{
        ArbolABB<string>* campos = new ArbolABB<string>;
        campos->Insertar(elemento->getNombre());
        campos->Insertar(elemento->getId());
        campos->Insertar(to_string(elemento->isIngresaNinno()));
        campos->Insertar(to_string(elemento->isEmbarazada()));
        campos->Insertar(to_string(elemento->isAdultoMayor()));
        campos->Insertar(to_string(elemento->getCategoria()));
        return campos;
    }

    Cliente* fromStringVector(ArbolABB<string>* vector) override{

        return new Cliente(vector->at(0), stoi(vector->at(1)));
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
