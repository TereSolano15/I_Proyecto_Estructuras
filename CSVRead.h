//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_CSVREAD_H
#define I_PROYECTO_ESTRUCTURAS_CSVREAD_H
#include "ArbolABB.h"
#include"IReader.h"
#include <string>
#include "TransformadorCSV.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

template<class T>
class CsvReader : public IReader<T>{
private:
    fstream entrada;
    ITransformadorCsv<T>* transformadorCsv;

    ArbolABB<T>* generarCampos(string registroActual){
       ArbolABB<T>* campos = new ArbolABB<T>;
        string valor;
        istringstream iss(registroActual);
        while (getline(iss, valor, ',')){
            campos->push_back(valor);
        }
        return campos;
    }

public:
    CsvReader(string rutaArchivo, ITransformadorCsv<T>* transformadorCsv){
        this->transformadorCsv = transformadorCsv;
        this->entrada.open(rutaArchivo, ios::in);
        if (!entrada.good())
        {
            throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
        }
    }

   ArbolABB<T>* leerTodos(){
        string registroActual;
       ArbolABB<T>* objetos = new ArbolABB<T>();
        while (getline(this->entrada, registroActual)){
            ArbolABB<string>* campos = this->generarCampos(registroActual);
            objetos->push_back(this->transformadorCsv->fromStringVector(campos));
            delete campos;
        }
        return objetos;
    }

    ~CsvReader(){
        delete this->transformadorCsv;
    }
};

#endif //I_PROYECTO_ESTRUCTURAS_CSVREAD_H
