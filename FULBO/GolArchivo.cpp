#include "GolArchivo.h"
#include <cstdio>   // fopen, fwrite, fread, etc.
#include <iostream>

GolArchivo::GolArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool GolArchivo::guardar(const Gol &registro) {
    FILE *p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&registro, sizeof(Gol), 1, p);
    fclose(p);
    return ok;
}

bool GolArchivo::guardar(int pos, const Gol &registro) {
    FILE *p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Gol), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Gol), 1, p);
    fclose(p);
    return ok;
}

Gol GolArchivo::leer(int pos) {
    Gol reg;
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Gol), SEEK_SET);
    fread(&reg, sizeof(Gol), 1, p);
    fclose(p);
    return reg;
}

int GolArchivo::leerTodos(Gol goles[], int cantidad) {
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;
    int leidos = fread(goles, sizeof(Gol), cantidad, p);
    fclose(p);
    return leidos;
}

int GolArchivo::getCantidadRegistros() {
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Gol);
}

int GolArchivo::buscarID(int id) {
    Gol reg;
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Gol), 1, p)) {
        if (reg.getIdGol() == id && !reg.isEliminado()) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool GolArchivo::eliminar(int pos) {
    Gol reg = leer(pos);
    if (reg.isEliminado()) return false;
    reg.setEliminado(true);
    return guardar(pos, reg);
}

int GolArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad == 0) return 1;
    Gol ultimo = leer(cantidad - 1);
    return ultimo.getIdGol() + 1;
}
