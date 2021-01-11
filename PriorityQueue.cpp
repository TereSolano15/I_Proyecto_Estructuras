//
// Created by Tere Solano on 9/1/2021.
//
#include "PriorityQueue.h"
template <typename E, typename C>
int PriorityQueue<typename E, typename C>::size() const{
    return arbol->cant;
}
template <typename E, typename C>
bool PriorityQueue<typename E, typename C>::empty() const{
   arbol->vacio();
}
/*
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::insert(const E& e){
    typename std::list<E>::iterator p;
    p = lista.begin();
    while(p != lista.end() && !isLess(e, *p)) ++p;
    lista.insert(p, e);
}
 */
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::insertElem(const E& e){
    ArbolABB<Cliente> arbolC;
   for(int i=0; i<arbol->NumeroNodos();i++){
       if(arbolC.ValorActual().porcentajeInfluencia() > arbolC.ValorSiguiente().porcentajeInfluencia()){
        cola->Anadir(e);
       }
   }
}
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::insert(ArbolABB<E> &arbolC) {
    for(int i=0; i < arbolC.NumeroNodos();i++){
        if(arbolC.ValorActual().porcentajeInfluencia() > arbolC.ValorSiguiente().porcentajeInfluencia()){
            cola->Anadir(arbolC.ValorActual());
        }
    }
}
template <typename E, typename C>
const E& PriorityQueue<typename E, typename C>::min() const{
    arbol->ValorActual(0);
}
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::removeMin(){
  //  return lista.pop_front();
    return arbol->eliminar();
}