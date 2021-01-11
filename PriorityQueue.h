//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H
#define I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H
#include "ArbolABB.h"
#include "Cliente.h"
#include "Cola.h"
using namespace std;
template <typename E, typename C>
class PriorityQueue {
private:
    ArbolABB<E>* arbol;
    Cola<E>* cola;
    C isLess;
public:
    int size() const;
    bool empty() const;
    void insertElem(const E& e);
    void insert(ArbolABB<E>& arbolAbb);
    const E& min() const;
    void removeMin();
   // void mergeSort(list<E>& s,const C& less);
};



#endif //I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H
