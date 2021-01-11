//
// Created by Tere Solano on 11/1/2021.
//

#include "Lista.h"
template <typename T>
Lista<T>::Lista(){
    raiz = new Nodo<T>;
}

template <typename T>
Lista<T>::~Lista(){
    Nodo<T> *temp;
    Nodo<T> *anterior;
    if(raiz->getSiguiente() == nullptr){
        delete raiz;
    }else{
        while(raiz->getSiguiente() != nullptr){
            temp = raiz;
            while(temp->getSiguiente() != nullptr){
                anterior = temp;
                temp = temp->getSiguiente();
            }
            anterior->setSiguiente(nullptr);
            delete temp;
        }
    }
    cout << "lista borrada!" << endl;
}
template <typename T>
void Lista<T>::agregarFinal(T* data){
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setMiPersona(data);
    nuevo->setSiguiente(nullptr);
    Nodo<T> *temp = raiz->getSiguiente();
    if(temp == nullptr){
        raiz->setSiguiente(nuevo);
    }else{
        while (temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
    }
}
template <typename T>
void Lista<T>::agregarInicio(T data){
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setMiPersona(data);
    nuevo->setSiguiente(raiz->getSiguiente());
    raiz->setSiguiente(nuevo);
}
template <typename T>
bool Lista<T>::borrar(T* data, string &mensaje){
    Nodo<T> *temp = raiz->getSiguiente();
    Nodo<T> *anterior;

    if(temp->getSiguiente() == nullptr){
        return false;
    }
    if(temp->getMiPersona() == data){
        raiz->setSiguiente(temp->getSiguiente());
        delete temp;
        mensaje = "Persona Borrada con exito \n";
        return true;
    }else{
        while(temp!= nullptr){
            anterior = temp;
            temp = temp->getSiguiente();
            if(temp == nullptr){
                mensaje = "Persona no encontrado \n";
                return false;
            }
            if(temp->getMiPersona() == data){
                anterior->setSiguiente(temp->getSiguiente());
                delete temp;
                mensaje = "Persona Borrada con exito \n";
                return true;
            }
        }
    }
}
template <typename T>
string Lista<T>::toString(){
    stringstream ss;
    Nodo<T> *temporal = raiz;
    if(temporal->getSiguiente() == nullptr){
        ss << "Lista vacia!!" << endl;
    }else{
        temporal = temporal->getSiguiente();
        do{
            ss << temporal->getMiPersona()->toString();
            ss << "-->";
            temporal = temporal->getSiguiente();
        }while(temporal != nullptr);
        ss <<  " NULL" << endl;
    }
    return ss.str();
}
template <typename T>
basic_string<char, char_traits<char>, allocator<char>> Lista<T>::at(int pos){
    Nodo<T>* current = this->first;
    for (int i = 0; i < pos; i++)
        current = current->getNext();
    return current->getData();
}