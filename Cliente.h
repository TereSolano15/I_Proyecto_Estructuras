//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_CLIENTE_H
#define I_PROYECTO_ESTRUCTURAS_CLIENTE_H
#include <iostream>
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
    virtual ~Cliente();
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getId() const;
    void setId(const string &id);
    bool isIngresaNinno() const;
    void setIngresaNinno(bool ingresaNinno);
    bool isEmbarazada() const;
    void setEmbarazada(bool embarazada);
    bool isAdultoMayor() const;
    void setAdultoMayor(bool adultoMayor);
    int getCategoria() const;
    void setCategoria(int categoria);
    float porcentajeInfluencia();
};


#endif //I_PROYECTO_ESTRUCTURAS_CLIENTE_H
