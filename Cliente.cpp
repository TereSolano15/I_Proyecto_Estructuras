//
// Created by Tere Solano on 9/1/2021.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &id, bool ingresaNinno, bool embarazada, bool adultoMayor,
                 int categoria) : nombre(nombre), id(id), ingresaNinno(ingresaNinno), embarazada(embarazada),
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
int Cliente::getCategoria() const {
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



