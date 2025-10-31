#include <iostream>
#include <cstring>       // para strcmp
#include "GolManager.h"

using namespace std;

GolManager::GolManager() { }

void GolManager::cargarGol() {
    int id, nroPartido, dniJugador, tipoGol;
    char minuto[10];

    id = _repo.getNuevoID();

    cout << "---- Registrar nuevo gol ----" << endl;
    cout << "ID del gol: " << id << endl;
    cout << "N£mero de partido: ";
    cin >> nroPartido;
    cout << "DNI del jugador: ";
    cin >> dniJugador;
    cout << "Tipo de gol (1: Penal, 2: Tiro libre, 3: Jugada): ";
    cin >> tipoGol;
    cout << "Minuto del gol (ej: 45+2): ";
    cin.ignore();
    cin.getline(minuto, 10);

    Gol nuevoGol(id, nroPartido, dniJugador, tipoGol, minuto, false);

    if (_repo.guardar(nuevoGol)) {
        cout << "El gol fue registrado con ‚xito!" << endl;
    } else {
        cout << "Ocurri¢ un error al intentar guardar el gol." << endl;
    }
}

void GolManager::mostrarGoles() {
    cout << "---- Lista de goles ----" << endl;
    int cantidad = _repo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Gol reg = _repo.leer(i);
        if (!reg.isEliminado()) {
            mostrarGolLista(reg);
        }
    }
}

void GolManager::mostrarGolLista(const Gol &gol) {
    cout << "--------------------------" << endl;
    cout << "ID Gol: " << gol.getIdGol() << endl;
    cout << "Nro Partido: " << gol.getNroPartido() << endl;
    cout << "DNI Jugador: " << gol.getDniJugador() << endl;
    cout << "Tipo Gol: ";
    switch (gol.getTipoGol()) {
        case 1: cout << "Penal"; break;
        case 2: cout << "Tiro libre"; break;
        case 3: cout << "Jugada"; break;
        default: cout << "Desconocido"; break;
    }
    cout << endl;
    cout << "Minuto: " << gol.getMinuto() << endl;
    cout << "Estado: " << (gol.isEliminado() ? "Eliminado" : "Activo") << endl;
}

void GolManager::eliminarGol() {
    int id, pos;
    char respuesta;
    cout << "---- Eliminar gol ----" << endl;
    cout << "Ingrese ID del gol: ";
    cin >> id;

    pos = _repo.buscarID(id);
    if (pos != -1) {
        Gol reg = _repo.leer(pos);
        mostrarGolLista(reg);

        cout << "¨Est  seguro que desea eliminarlo? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') {
            if (_repo.eliminar(pos)) {
                cout << "El gol fue eliminado correctamente." << endl;
            } else {
                cout << "Error al eliminar el gol." << endl;
            }
        }
    } else {
        cout << "El gol no existe." << endl;
    }
}

void GolManager::modificarGol() {
    int id, pos;
    cout << "---- Modificar gol ----" << endl;
    cout << "Ingrese ID del gol: ";
    cin >> id;

    pos = _repo.buscarID(id);
    if (pos == -1) {
        cout << "El gol no existe." << endl;
        return;
    }

    Gol reg = _repo.leer(pos);
    mostrarGolLista(reg);

    int nuevoTipo;
    char nuevoMinuto[10];

    cout << "Nuevo tipo de gol (1: Penal, 2: Tiro libre, 3: Jugada): ";
    cin >> nuevoTipo;
    cout << "Nuevo minuto: ";
    cin.ignore();
    cin.getline(nuevoMinuto, 10);

    reg.setTipoGol(nuevoTipo);
    reg.setMinuto(nuevoMinuto);

    if (_repo.guardar(pos, reg)) {
        cout << "El gol fue modificado correctamente." << endl;
    } else {
        cout << "Error al modificar el gol." << endl;
    }
}

void GolManager::mostrarGolesPorPartido() {
    int nroPartido;
    cout << "---- Mostrar goles por partido ----" << endl;
    cout << "Ingrese n£mero de partido: ";
    cin >> nroPartido;

    int cantidad = _repo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Gol reg = _repo.leer(i);
        if (!reg.isEliminado() && reg.getNroPartido() == nroPartido) {
            mostrarGolLista(reg);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron goles para el partido #" << nroPartido << endl;
    }
}

void GolManager::mostrarGolesOrdenados() {
    cout << "---- Goles ordenados por minuto ----" << endl;
    int cantidad = _repo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay registros." << endl;
        return;
    }

    Gol *goles = new Gol[cantidad];
    _repo.leerTodos(goles, cantidad);

    for (int i = 0; i < cantidad - 1; i++) {
        bool intercambio = false;
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (strcmp(goles[j].getMinuto(), goles[j + 1].getMinuto()) > 0) {
                Gol aux = goles[j];
                goles[j] = goles[j + 1];
                goles[j + 1] = aux;
                intercambio = true;
            }
        }
        if (!intercambio) break;
    }

    for (int i = 0; i < cantidad; i++) {
        if (!goles[i].isEliminado())
            mostrarGolLista(goles[i]);
    }

    delete[] goles;
}

