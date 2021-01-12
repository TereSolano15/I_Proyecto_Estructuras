//
// Created by Tere Solano on 9/1/2021.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &id, const string &ingresaNinno, const string &embarazada, const string &adultoMayor,
                 const string &categoria) : nombre(nombre), id(id), ingresaNinno(ingresaNinno), embarazada(embarazada),
                                  adultoMayor(adultoMayor), categoria(categoria) {}

/*Cliente::Cliente(istream& input) {

    getline(input, this->nombre, ',');
    getline(input, this->id, ',');
    getline(input, this->ingresaNinno, ',');
    getline(input, this->embarazada, ',');
    getline(input, this->adultoMayor, ',');
    getline(input, this->categoria);
}
*/
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

const string &Cliente::isIngresaNinno(){
    return ingresaNinno;
}

void Cliente::setIngresaNinno(string &ingresaNinno) {
    Cliente::ingresaNinno = ingresaNinno;
}

const string &Cliente::isEmbarazada() {
    return embarazada;
}

void Cliente::setEmbarazada(string &embarazada) {
    Cliente::embarazada = embarazada;
}

const string &Cliente::isAdultoMayor() {
    return adultoMayor;
}

void Cliente::setAdultoMayor(string &adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}
const string &Cliente::getCategoria() {
    return categoria;
}

void Cliente::setCategoria(string &categoria) {
    Cliente::categoria = categoria;
}
float Cliente::porcentajeInfluencia() {
    float porcentaje = 0;
    string cat = getCategoria();
    if(ingresaNinno == "Yes")
        porcentaje += 0.20;
    if(embarazada == "Yes")
        porcentaje *= 0.25;
    if(adultoMayor == "Yes")
        porcentaje += 0.30;
    if(categoria == "1")
        porcentaje += 0.20;
    if(categoria == "2")
        porcentaje += 0.10;
    /*switch (categoria) {
        case 1:
            porcentaje += 0.20;
        case 2:
            porcentaje += 0.10;
    }*/
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

