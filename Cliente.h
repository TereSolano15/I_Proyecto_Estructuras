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
    bool ingresaNinno;
    bool embarazada;
    bool adultoMayor;
    int categoria;
public:
    Cliente(const string &nombre, const string &id, bool ingresaNinno, bool embarazada, bool adultoMayor,
            int categoria);
    Cliente();
    Cliente(istream& input);
    virtual ~Cliente();
    const string &getNombre();
    void setNombre( string &nombre);
    const string &getId();
    void setId(string &id);
    bool isIngresaNinno();
    void setIngresaNinno(bool ingresaNinno);
    bool isEmbarazada();
    void setEmbarazada(bool embarazada);
    bool isAdultoMayor() ;
    void setAdultoMayor(bool adultoMayor);
    int getCategoria() ;
    void setCategoria(int categoria);
    float porcentajeInfluencia();
    string toString();
};


#endif //I_PROYECTO_ESTRUCTURAS_CLIENTE_H
