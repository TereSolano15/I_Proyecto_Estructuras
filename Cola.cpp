//
// Created by Tere Solano on 10/1/2021.
//

#include "Cola.h"
template <typename T>
Cola<T>::~Cola(){
    while(primero) Leer();
}
template <typename T>
void Cola<T>::Anadir(int v){
    Nodo<T>* nuevo;
    nuevo = new nodo(v);
    if(ultimo) ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if(!primero) primero = nuevo;
}
template <typename T>
int Cola<T>::Leer(){
    Nodo<T>* nodo; /* variable auxiliar para manipular nodo */
    int v;      /* variable auxiliar para retorno */

    /* Nodo apunta al primer elemento de la pila */
    nodo = primero;
    if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
    /* Asignamos a primero la dirección del segundo nodo */
    primero = nodo->siguiente;
    /* Guardamos el valor de retorno */
    v = nodo->valor;
    /* Borrar el nodo */
    delete nodo;
    /* Si la Cola quedó vacía, ultimo debe ser NULL también*/
    if(!primero) ultimo = nullptr;
    return v;
}
