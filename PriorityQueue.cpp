//
// Created by Tere Solano on 9/1/2021.
//

#include "PriorityQueue.h"
template <typename E, typename C>
int PriorityQueue<typename E, typename C>::size() const{
    return arbol.cant;
}
template <typename E, typename C>
bool PriorityQueue<typename E, typename C>::empty() const{
    lista.empty();
}
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::insert(const E& e){
    typename std::list<E>::iterator p;
    p = lista.begin();
    while(p != lista.end() && !isLess(e, *p)) ++p;
    lista.insert(p, e);
}
template <typename E, typename C>
const E& PriorityQueue<typename E, typename C>::min() const{
    return lista.front();
}
template <typename E, typename C>
void PriorityQueue<typename E, typename C>::removeMin(){
    return lista.pop_front();
}