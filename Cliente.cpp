//
// Created by Tere Solano on 9/1/2021.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &id, bool ingresaNinno, bool embarazada, bool adultoMayor,
                 const string &categoria) : nombre(nombre), id(id), ingresaNinno(ingresaNinno), embarazada(embarazada),
                                            adultoMayor(adultoMayor), categoria(categoria) {}

Cliente::Cliente() {}

Cliente::~Cliente() {

}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getId() const {
    return id;
}

void Cliente::setId(const string &id) {
    Cliente::id = id;
}

bool Cliente::isIngresaNinno() const {
    return ingresaNinno;
}

void Cliente::setIngresaNinno(bool ingresaNinno) {
    Cliente::ingresaNinno = ingresaNinno;
}

bool Cliente::isEmbarazada() const {
    return embarazada;
}

void Cliente::setEmbarazada(bool embarazada) {
    Cliente::embarazada = embarazada;
}

bool Cliente::isAdultoMayor() const {
    return adultoMayor;
}

void Cliente::setAdultoMayor(bool adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}

const string &Cliente::getCategoria() const {
    return categoria;
}

void Cliente::setCategoria(const string &categoria) {
    Cliente::categoria = categoria;
}
