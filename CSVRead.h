//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_CSVREAD_H
#define I_PROYECTO_ESTRUCTURAS_CSVREAD_H
#include "ArbolABB.h"
#include "TransformadorCSV.h"
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class CSVRead : public TransformadorCsvCliente<T>{
private:
    fstream entrada;
    TransformadorCsvCliente<T>* transformadorCsv;
    ArbolABB<T>* generarCampos(const string& registroActual){
        ArbolABB<string>* campos = new vector<string>();
        string valor;
        istringstream iss(registroActual);
        while (getline(iss, valor, ',')){
            campos->Insertar(valor);
        }
        return campos;
    }
public:
    CSVRead(string rutaArchivo, TransformadorCsvCliente<T>* transformadorCsv){
        this->transformadorCsv = transformadorCsv;
        this->entrada.open(rutaArchivo, ios::in);
        if (!entrada.good())
        {
            throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
        }
    }
    ArbolABB<T>* leerTodos(){
        string registroActual;
        auto* objetos = new ArbolABB<T>();
        while (getline(this->entrada, registroActual))
        {
            ArbolABB<T>* campos = this->generarCampos(registroActual);
            objetos->push_back(this->transformadorCsv->fromStringVector(campos));
            delete campos;
        }
        return objetos;
    }
    ~CSVRead(){
        delete this->transformadorCsv;
    }
};

#endif //I_PROYECTO_ESTRUCTURAS_CSVREAD_H
