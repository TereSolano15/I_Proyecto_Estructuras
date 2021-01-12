//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_CLIENTE_H
#define I_PROYECTO_ESTRUCTURAS_CLIENTE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Cliente {
private:
    string nombre;
    string id;
    string ingresaNinno;
    string embarazada;
    string adultoMayor;
    string categoria;
public:
    Cliente(const string &nombre, const string &id, const string &ingresaNinno, const string &embarazada, const string &adultoMayor,
            const string &categoria);
    Cliente();
    //Cliente(istream& input);
    virtual ~Cliente();
    const string &getNombre();
    void setNombre( string &nombre);
    const string &getId();
    void setId(string &id);
    const string &isIngresaNinno();
    void setIngresaNinno(string &ingresaNinno);
    const string &isEmbarazada();
    void setEmbarazada(string &embarazada);
    const string &isAdultoMayor() ;
    void setAdultoMayor(string &adultoMayor);
    const string &getCategoria() ;
    void setCategoria(string &categoria);
    float porcentajeInfluencia();
    string toString();
};


#endif //I_PROYECTO_ESTRUCTURAS_CLIENTE_H
