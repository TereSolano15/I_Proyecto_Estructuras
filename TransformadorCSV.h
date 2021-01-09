//
// Created by Tere Solano on 9/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
#define I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
using namespace std;

template<class T>
class TransformadorCsvPersona {
public:
    vector<string>* toStringVector(Persona* elemento) override{
        vector<string>* campos = new vector<string>();
        campos->push_back(elemento->getNombre());
        campos->push_back(to_string(elemento->getEdad()));
        return campos;
    }

    Persona* fromStringVector(vector<string>* vector) override{
        return new Persona(vector->at(0), stoi(vector->at(1)));
    }
};
#endif //I_PROYECTO_ESTRUCTURAS_TRANSFORMADORCSV_H
