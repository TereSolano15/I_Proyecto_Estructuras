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
class TransformadorCsvCliente {
public:
    ArbolABB<string> * toStringVector(Cliente* elemento){
        ArbolABB<string>* list = new ArbolABB<string>;
        list->Insertar(elemento->getNombre());
        list->Insertar(elemento->getId());
        list->Insertar(to_string(elemento->isIngresaNinno()));
        list->Insertar(to_string(elemento->isEmbarazada()));
        list->Insertar(to_string(elemento->isAdultoMayor()));
        list->Insertar(to_string(elemento->getCategoria()));
        return list;
    }

    Cliente* fromStringLista(ArbolABB<string>* lista) {
        Cliente* cliente = new Cliente();
        cliente->setNombre(lista->ValorActual());
        cliente->setId(reinterpret_cast<string &>(lista->getActual()->getSiguiente()->data));
        cliente->setIngresaNinno(lista->getActual()->getSiguiente()->getSiguiente()->data);
        cliente->setEmbarazada(lista->getActual()->getSiguiente()->getSiguiente()->getSiguiente()->data);
        cliente->setAdultoMayor(lista->getActual()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->data);
        cliente->setCategoria(
                reinterpret_cast<int>(lista->getActual()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->data));

        return cliente;
    }
};
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
