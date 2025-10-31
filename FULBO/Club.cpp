#include "Club.h"
#include <cstring>

// Constructor
Club::Club(int _idClub, const char* _nombre, const char* _presidente, Fecha _fechaInscripcion,
           int _torneosGanados, const char* _telefono, const char* _email,
           int _socios, int _partidosJugados, int _golesTotales, bool _eliminado)
{
    idClub = _idClub;
    strcpy(nombre, _nombre);
    strcpy(presidente, _presidente);
    fechaInscripcion = _fechaInscripcion;
    torneosGanados = _torneosGanados;
    strcpy(telefono, _telefono);
    strcpy(email, _email);
    socios = _socios;
    partidosJugados = _partidosJugados;
    golesTotales = _golesTotales;
    eliminado = _eliminado;
}

// Getters
int Club::getIdClub() { return idClub; }
const char* Club::getNombre() { return nombre; }
const char* Club::getPresidente() { return presidente; }
Fecha Club::getFechaInscripcion() { return fechaInscripcion; }
int Club::getTorneosGanados() { return torneosGanados; }
const char* Club::getTelefono() { return telefono; }
const char* Club::getEmail() { return email; }
int Club::getSocios() { return socios; }
int Club::getPartidosJugados() { return partidosJugados; }
int Club::getGolesTotales() { return golesTotales; }
bool Club::isEliminado() { return eliminado; }

// Setters
void Club::setIdClub(int _idClub) { idClub = _idClub; }
void Club::setNombre(const char* _nombre) { strcpy(nombre, _nombre); }
void Club::setPresidente(const char* _presidente) { strcpy(presidente, _presidente); }
void Club::setFechaInscripcion(Fecha _fecha) { fechaInscripcion = _fecha; }
void Club::setTorneosGanados(int _torneos) { torneosGanados = _torneos; }
void Club::setTelefono(const char* _telefono) { strcpy(telefono, _telefono); }
void Club::setEmail(const char* _email) { strcpy(email, _email); }
void Club::setSocios(int _socios) { socios = _socios; }
void Club::setPartidosJugados(int _partidos) { partidosJugados = _partidos; }
void Club::setGolesTotales(int _goles) { golesTotales = _goles; }
void Club::setEliminado(bool _eliminado) { eliminado = _eliminado; }
