//
// Created by efrai on 11/1/2021.
//

#ifndef I_PROYECTO_ESTRUCTURAS_MENU_H
#define I_PROYECTO_ESTRUCTURAS_MENU_H


class Menu {
private:
    char mostrarOpciones();
public:
    Menu();
    void invocarMenu();
    void encolarClientes();
    void encolarCliente();
    void atenderCinco();
    void mostarSiguiente();
    void simulacionCliente();
    void agregarCliente();
    ~Menu();
};


#endif //I_PROYECTO_ESTRUCTURAS_MENU_H
