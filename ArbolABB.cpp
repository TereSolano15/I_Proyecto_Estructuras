//
// Created by Tere Solano on 9/1/2021.
//

#include "ArbolABB.h"
#include "ArbolABB.h"
void ArbolABB::Podar(Nodo* &nodo){
    // Algoritmo recursivo, recorrido en postorden
    if(nodo) {
        Podar(nodo->izquierdo); // Podar izquierdo
        Podar(nodo->derecho);   // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = nullptr;
    }
}
void ArbolABB::Insertar(const int dat){
    Nodo *padre = nullptr;
    actual = raiz;
    while(!vacio(actual) && dat != actual->dato) {
        padre = actual;
        if(dat > actual->dato) actual = actual->derecho;
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    if(!vacio(actual)) return;
    if(vacio(padre)) raiz = new Nodo(dat);
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
    else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
    else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const int dat){
    Nodo *padre = NULL;
    Nodo *nodo;
    int aux;
    actual = raiz;
    while(!vacio(actual)) {
        if(dat == actual->dato) { // Si el valor está en el nodo actual
            if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
                if(padre) // Si tiene padre (no es el nodo raiz)
                    // Anulamos el puntero que le hace referencia
                    if(padre->derecho == actual) padre->derecho = NULL;
                    else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // borrar el nodo
                actual = NULL;
                return;
            }
            else { // Si el valor está en el nodo actual, pero no es hoja
                // buscar nodo
                padre = actual;
                // buscar nodo más izquierdo de rama derecha
                if(actual->derecho) {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                    // O buscar nodo más derecho de rama izquierda
                else {
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else { // Todavía no hemos encontrado el valor, seguir buscándolo
            padre = actual;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
}

void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
    if(r) nodo = raiz;
    if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato);
    if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
    if(r) nodo = raiz;
    func(nodo->dato);
    if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r){
    if(r) nodo = raiz;
    if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato);
}

bool ArbolABB::Buscar(const int dat){
    actual = raiz;

    while(!vacio(actual)) {
        if(dat == actual->dato) return true; // int encontrado
        else if(dat > actual->dato) actual = actual->derecho; // Seguir
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // No está en árbol
}

int ArbolABB::Altura(const int dat){
    int _altura = 0;
    actual = raiz;
    // Todavía puede aparecer, ya que quedan nodos por mirar
    while(!vacio(actual)) {
        if(dat == actual->dato) return altura; // int encontrado
        else {
            altura++; // Incrementamos la altura, seguimos buscando
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1; // No está en árbol
}

const int ArbolABB::NumeroNodos(){
    contador = 0;
    auxContador(raiz); // FUnción auxiliar
    return contador;
}

void ArbolABB::auxContador(Nodo *nodo){
    contador++;  // Otro nodo
    // Continuar recorrido
    if(nodo->izquierdo) auxContador(nodo->izquierdo);
    if(nodo->derecho)   auxContador(nodo->derecho);
}
const int ArbolABB::AlturaArbol(){
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

void ArbolABB::auxAltura(Nodo *nodo, int a){
    // Recorrido postorden
    if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // árbol, actualizamos la altura actual del árbol
    if(EsHoja(nodo) && a > altura) altura = a;
}

void Mostrar(int &d){
    cout << d << ",";
}