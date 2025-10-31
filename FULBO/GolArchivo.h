#pragma once
#include "Gol.h"
#include <string>

class GolArchivo
{
public:
    GolArchivo(std::string nombreArchivo = "goles.dat");

    bool guardar(const Gol &registro);
    bool guardar(int pos, const Gol &registro);

    int buscarID(int id);
    bool eliminar(int pos);

    Gol leer(int pos);
    int leerTodos(Gol goles[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();

private:
    std::string _nombreArchivo;
};
