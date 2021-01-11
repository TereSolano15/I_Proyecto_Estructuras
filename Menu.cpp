//
// Created by efrai on 11/1/2021.
//


#include <iostream>
#include<Windows.h>
#include "Menu.h"
using namespace std;
char Menu::mostrarOpciones()
{
    char opcion;
    system("cls");
    cout << "Menu - Seleccionar una opcion:" << endl;
    cout << "1) Encolar a todos los clientes. " << endl;
    cout << "2) Encolar a un Cliente. " << endl;
    cout << "3) Atender a los siguientes 5 Clientes." << endl;
    cout << "4) Mostrar el siguiente Cliente a ser atendido." << endl;
    cout << "5) Simulación de Atención de Clientes." << endl;
    cout << "6) Agregar un Cliente Nuevo." << endl;
    cout << "7) Salir" << endl;
    cin >> opcion;
    system("cls");
    return opcion;
}

Menu::Menu()
{
}

void Menu::invocarMenu()
{
    system("color E1");
    const char opcionSalida = '7';
    char opcion;
    do {
        opcion = mostrarOpciones();
        switch (opcion)
        {
            case '1':
                encolarClientes();
                break;
            case '2':
                encolarCliente();
                break;
            case '3':
                atenderCinco();
                break;
            case '4':
                mostarSiguiente();
                break;
            case '5':
                simulacionCliente();
                break;
            case '6':
                agregarCliente();
                break;
            case opcionSalida:
                break;
            default:
                cerr << "Opcion invalida, digite otra vez" << endl;
        }
    } while (opcion != opcionSalida);
    cout << endl;
    cout << endl;
    system("color A1");
    cout << "\t" << "\t" << "\t" << "--------------Saliendo con exito-------------" << endl;
    cout << endl;
}

void Menu::encolarClientes()
{
}

void Menu::encolarCliente()
{
}

void Menu::atenderCinco()
{
}

void Menu::mostarSiguiente()
{
}

void Menu::simulacionCliente()
{
}

void Menu::agregarCliente()
{
}

Menu::~Menu()
{
}