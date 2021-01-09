//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H
#define I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H

using namespace std;
template <typename E, typename C>
class PriorityQueue {
private:
   // list<E> lista;
    C isLess;
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
   // void mergeSort(list<E>& s,const C& less);
};



#endif //I_PROYECTO_ESTRUCTURAS_PRIORITYQUEUE_H
