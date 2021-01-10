//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#include <fstream>
using namespace std;

template<class T>
class TransformadorCsvCliente {
public:
    vector<string>* toStringVector(Cliente* elemento) override{
        vector<string>* campos = new vector<string>();
        campos->push_back(elemento->getNombre());
        campos->push_back(to_string(elemento->getId()));
        campos->push_back(elemento->isIngresaNinno());
        campos->push_back(elemento->isEmbarazada());
        campos->push_back(elemento->isAdultoMayor());
        campos->push_back(elemento->getCategoria());
        return campos;
    }

    Cliente* fromStringVector(vector<string>* vector) override{
        return new Cliente(vector->at(0), stoi(vector->at(1)));
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
