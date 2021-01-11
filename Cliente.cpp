//
// Created by Tere Solano on 9/1/2021.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &id, bool ingresaNinno, bool embarazada, bool adultoMayor,
                 int categoria) : nombre(nombre), id(id), ingresaNinno(ingresaNinno), embarazada(embarazada),
                                  adultoMayor(adultoMayor), categoria(categoria) {}

Cliente::Cliente(istream& input) {

    getline(input, this->nombre, ',');
    getline(input, this->id, ',');
    input >> this->ingresaNinno;
    input >> this->embarazada;
    input >> this->adultoMayor;
    input >> this->categoria;

}

Cliente::Cliente() {}

Cliente::~Cliente() {

}

const string &Cliente::getNombre() {
    return nombre;
}

void Cliente::setNombre( string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getId(){
    return id;
}

void Cliente::setId( string &id) {
    Cliente::id = id;
}

bool Cliente::isIngresaNinno(){
    return ingresaNinno;
}

void Cliente::setIngresaNinno(bool ingresaNinno) {
    Cliente::ingresaNinno = ingresaNinno;
}

bool Cliente::isEmbarazada() {
    return embarazada;
}

void Cliente::setEmbarazada(bool embarazada) {
    Cliente::embarazada = embarazada;
}

bool Cliente::isAdultoMayor() {
    return adultoMayor;
}

void Cliente::setAdultoMayor(bool adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}
int Cliente::getCategoria() {
    return categoria;
}

void Cliente::setCategoria(int categoria) {
    Cliente::categoria = categoria;
}
float Cliente::porcentajeInfluencia() {
    float porcentaje = 0;
    int cat = getCategoria();
    if(ingresaNinno)
        porcentaje += 0.20;
    if(embarazada)
        porcentaje *= 0.25;
    if(adultoMayor)
        porcentaje += 0.30;
    switch (categoria) {
        case 1:
            porcentaje += 0.20;
        case 2:
            porcentaje += 0.10;
    }
    return porcentaje;
}

string Cliente::toString() {
    stringstream s;
    s<<"Nombre: "<< this->nombre<<endl;
    s<<"ID: "<< this->id<<endl;
    s<<"Ingresa con ninno"<<this->ingresaNinno<<endl;
    s<<"Embarazada: "<< this->embarazada<<endl;
    s<<"Adulto Mayor: "<<this->adultoMayor<<endl;
    s<<"Categoria: "<<this->categoria<<endl;
    return s.str();
}

