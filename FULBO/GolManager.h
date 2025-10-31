#pragma once
#include "GolArchivo.h"

class GolManager {
public:
    GolManager();

    void cargarGol();
    void mostrarGoles();
    void eliminarGol();
    void modificarGol();
    void mostrarGolesPorPartido();
    void mostrarGolesOrdenados();

protected:
    void mostrarGolLista(const Gol &gol);

private:
    GolArchivo _repo;
};
