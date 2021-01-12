//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#include <fstream>
#include <string>
#include<vector>
#include "ArbolABB.h"
#include "Cliente.h"
using namespace std;

template<class T>
class ITransformadorCsv
{
public:
    virtual vector<string>* toStringVector(T elemento) = 0;
    virtual T fromStringVector(vector<string>* vector) = 0;
    virtual ~ITransformadorCsv() = default;
};

class TransformadorCsvCliente : public ITransformadorCsv<Cliente*>
{
public:
    vector<string>* toStringVector(Cliente* elemento) override
    {
        vector<string>* campos = new vector<string>();
        campos->push_back(elemento->getNombre());
        campos->push_back(elemento->getId());
        campos->push_back(elemento->isIngresaNinno());
        campos->push_back(elemento->isIngresaNinno());
        campos->push_back(elemento->isEmbarazada());
        campos->push_back(elemento->isAdultoMayor());
        campos->push_back(elemento->getCategoria());
        return campos;
    }

    Cliente* fromStringVector(vector<string>* vector) override
    {
        return new Cliente(vector->at(0),vector->at(1),vector->at(2),vector->at(3),vector->at(4),vector->at(5) );
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
