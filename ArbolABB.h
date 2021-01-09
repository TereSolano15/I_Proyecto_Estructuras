//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
#define I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
#include "Nodo.h"

class ArbolABB {
private:
    Nodo *raiz;
    Nodo *actual;
    int contador;
    int altura;
public:
    ArbolABB() : raiz(nullptr), actual(nullptr) {}
    ~ArbolABB() { Podar(raiz); }
    void Insertar(const int dat);
    void Borrar(const int dat);
    bool Buscar(const int dat);
    bool vacio(Nodo *r) { return r == nullptr; }
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(const int dat);
    int &ValorActual() { return actual->dato; }
    void Raiz() { actual = raiz; }
    void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
private:

    void Podar(Nodo* &);
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
};

#endif //I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
