#include <iostream>
#include "AppMenu.h"
using namespace std;

AppMenu::AppMenu() {
    _cantidadOpciones = 1; // por ahora solo el men£ de goles
}

void AppMenu::mostrarOpciones() {
    cout << "--- MENU PRINCIPAL ---" << endl;
    cout << "1 - MENU DE GOLES" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "---------------------------------" << endl;
}

void AppMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            _golMenu.mostrar();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opci¢n incorrecta." << endl;
            break;
    }
}
