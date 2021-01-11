//
// Created by Tere Solano on 9/1/2021.
//

#include "ArbolABB.h"

template <typename T>
ArbolABB<T>::ArbolABB():raiz(nullptr), actual(nullptr){}

template <typename T>
ArbolABB<T>::~ArbolABB<T>() {
    eliminar(raiz);
}
template<typename T>
Nodo<T> *ArbolABB<T>::getRaiz() const {
    return raiz;
}

template<typename T>
void ArbolABB<T>::setRaiz(Nodo<T> *raiz) {
    ArbolABB::raiz = raiz;
}
template <typename T>
void ArbolABB<T>::eliminar(Nodo<T>* &nodo){
    if(nodo) {
        eliminar(nodo->izquierdo); // eliminar izquierdo
        eliminar(nodo->derecho);   // eliminar derecho
        delete nodo;            // Eliminar nodo
        nodo = nullptr;
    }
}
template <typename T>
void ArbolABB<T>::Insertar(const T dat){
    Nodo<T> *padre = nullptr;
    actual = raiz;
    while(!vacio(actual) && dat != actual->dato) {
        padre = actual;
        if(dat > actual->dato) actual = actual->derecho;
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    if(!vacio(actual)) return;
    if(vacio(padre)) raiz = new Nodo<T>(dat);
    else if(dat < padre->dato) padre->izquierdo = new Nodo<T>(dat);
    else if(dat > padre->dato) padre->derecho = new Nodo<T>(dat);
}
template <typename T>
void ArbolABB<T>::Borrar(const T dat){
    Nodo<T> *padre = nullptr;
    Nodo<T> *nodo;
    int aux;
    actual = raiz;
    while(!vacio(actual)) {
        if(dat == actual->dato) {
            if(EsHoja(actual)) {
                if(padre)
                    if(padre->derecho == actual) padre->derecho = nullptr;
                    else if(padre->izquierdo == actual) padre->izquierdo = nullptr;
                delete actual;
                actual = nullptr;
                return;
            }
            else {
                padre = actual;
                if(actual->derecho) {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                else {
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else {
            padre = actual;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
}
template <typename T>
bool ArbolABB<T>::vacio(Nodo<T> *r) {
     return r == nullptr;
}
template <typename T>
bool ArbolABB<T>::EsHoja(Nodo<T> *r) {
     return !r->derecho && !r->izquierdo;
}
template <typename T>
T& ArbolABB<T>::ValorActual() {
    return actual->dato;
}
template <typename T>
T& ArbolABB<T>::ValorSiguiente() {
    return actual+1;
}

template <typename T>
void ArbolABB<T>::InOrden(void (*func)(T&) , Nodo<T> *nodo, bool r){
    if(r) nodo = raiz;
    if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato);
    if(nodo->derecho) InOrden(func, nodo->derecho, false);
}
template <typename T>
void ArbolABB<T>::PreOrden(void (*func)(T&), Nodo<T> *nodo, bool r){
    if(r) nodo = raiz;
    func(nodo->dato);
    if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}
template <typename T>
void ArbolABB<T>::PostOrden(void (*func)(T&), Nodo<T> *nodo, bool r){
    if(r) nodo = raiz;
    if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato);
}
template <typename T>
bool ArbolABB<T>::Buscar(const T dat){
    actual = raiz;

    while(!vacio(actual)) {
        if(dat == actual->dato) return true;
        else if(dat > actual->dato) actual = actual->derecho;
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    return false;
}
template <typename T>
int ArbolABB<T>::Altura(const T dat){
    int _altura = 0;
    actual = raiz;
    while(!vacio(actual)) {
        if(dat == actual->dato) return altura;
        else {
            altura++;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1;
}
template <typename T>
const int ArbolABB<T>::NumeroNodos(){
    cant = 0;
    auxContador(raiz);
    return cant;
}
template <typename T>
void ArbolABB<T>::auxContador(Nodo<T> *nodo){
    cant++;
    if(nodo->izquierdo) auxContador(nodo->izquierdo);
    if(nodo->derecho)   auxContador(nodo->derecho);
}
template <typename T>
const int ArbolABB<T>::AlturaArbol(){
    altura = 0;
    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}
template <typename T>
void ArbolABB<T>::auxAltura(Nodo<T> *nodo, T a){
    if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)   auxAltura(nodo->derecho, a+1);

    if(EsHoja(nodo) && a > altura) altura = a;
}
template <typename T>
void ArbolABB<T>::Mostrar(T &d){
    cout << d << ",";
}

template<typename T>
Nodo<T> *ArbolABB<T>::getActual() const {
    return actual;
}

template<typename T>
void ArbolABB<T>::setActual(Nodo<T> *actual) {
    ArbolABB::actual = actual;
}

