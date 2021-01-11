//
// Created by Tere Solano on 9/1/2021.
//
#ifndef I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
#define I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
#include "Nodo.h"

template <typename T>
class ArbolABB {
private:
    Nodo<T> *raiz;
    Nodo<T> *actual;
    int cant;
    int altura;
public:
    ArbolABB();
    ~ArbolABB();

    Nodo<T> *getRaiz() const;

    void setRaiz(Nodo<T> *raiz);

    void Insertar(const T dat);
    void Borrar(const T dat);
    bool Buscar(const T dat);
    bool vacio(Nodo<T> *r);
    bool EsHoja(Nodo<T> *r) ;
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(const T dat);
    T &ValorActual();
    void InOrden(void (*func)(T&) , Nodo<T> *nodo= nullptr, bool r=true);
    void PreOrden(void (*func)(T&) , Nodo<T> *nodo= nullptr, bool r=true);
    void PostOrden(void (*func)(T&) , Nodo<T> *nodo= nullptr, bool r=true);
    void Mostrar(T &d);
private:
    void eliminar(Nodo<T>* &);
    void auxContador(Nodo<T>*);
    void auxAltura(Nodo<T>*, T);
};

#endif //I_PROYECTO_ESTRUCTURAS_ARBOLABB_H
