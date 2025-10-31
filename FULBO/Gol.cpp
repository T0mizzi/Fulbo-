#include "Gol.h"
#include <cstring>

// Constructor
Gol::Gol(int _idGol, int _nroPartido, int _dniJugador, int _tipoGol, const char* _minuto, bool _eliminado)
{
    idGol = _idGol;
    nroPartido = _nroPartido;
    dniJugador = _dniJugador;
    tipoGol = _tipoGol;
    strcpy(minuto, _minuto);
    eliminado = _eliminado;
}

// Getters
int Gol::getIdGol() const { return idGol; }
int Gol::getNroPartido() const { return nroPartido; }
int Gol::getDniJugador() const { return dniJugador; }
int Gol::getTipoGol() const { return tipoGol; }
const char* Gol::getMinuto() const { return minuto; }
bool Gol::isEliminado() const { return eliminado; }

// Setters
void Gol::setIdGol(int _idGol) { idGol = _idGol; }
void Gol::setNroPartido(int _nroPartido) { nroPartido = _nroPartido; }
void Gol::setDniJugador(int _dniJugador) { dniJugador = _dniJugador; }
void Gol::setTipoGol(int _tipoGol) { tipoGol = _tipoGol; }
void Gol::setMinuto(const char* _minuto) { strcpy(minuto, _minuto); }
void Gol::setEliminado(bool _eliminado) { eliminado = _eliminado; }

