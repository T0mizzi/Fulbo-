#include <iostream>
#include "GolMenu.h"
using namespace std;

GolMenu::GolMenu() {
    _cantidadOpciones = 6;
}

void GolMenu::mostrarOpciones() {
    cout << "--- MENU GOLES ---" << endl;
    cout << "1 - REGISTRAR GOL" << endl;
    cout << "2 - MOSTRAR GOLES" << endl;
    cout << "3 - ELIMINAR GOL" << endl;
    cout << "4 - MODIFICAR GOL" << endl;
    cout << "5 - MOSTRAR GOLES POR PARTIDO" << endl;
    cout << "6 - MOSTRAR GOLES ORDENADOS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void GolMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            _golManager.cargarGol();
            break;
        case 2:
            _golManager.mostrarGoles();
            break;
        case 3:
            _golManager.eliminarGol();
            break;
        case 4:
            _golManager.modificarGol();
            break;
        case 5:
            _golManager.mostrarGolesPorPartido();
            break;
        case 6:
            _golManager.mostrarGolesOrdenados();
            break;
    }
}
