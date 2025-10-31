#include "Jugador.h"
#include <cstring>

// Constructor
Jugador::Jugador(int _dni, int _idClub, const char* _nombre, const char* _apellido,
                 const char* _telefono, Fecha _fechaNacimiento,
                 const char* _posicion, int _partidosJugados, int _golesConvertidos,
                 bool _lesionado, bool _eliminado)
{
    dni = _dni;
    idClub = _idClub;
    strcpy(nombre, _nombre);
    strcpy(apellido, _apellido);
    strcpy(telefono, _telefono);
    fechaNacimiento = _fechaNacimiento;
    strcpy(posicion, _posicion);
    partidosJugados = _partidosJugados;
    golesConvertidos = _golesConvertidos;
    lesionado = _lesionado;
    eliminado = _eliminado;
}

// Getters
int Jugador::getDni() { return dni; }
int Jugador::getIdClub() { return idClub; }
const char* Jugador::getNombre() { return nombre; }
const char* Jugador::getApellido() { return apellido; }
const char* Jugador::getTelefono() { return telefono; }
Fecha Jugador::getFechaNacimiento() { return fechaNacimiento; }
const char* Jugador::getPosicion() { return posicion; }
int Jugador::getPartidosJugados() { return partidosJugados; }
int Jugador::getGolesConvertidos() { return golesConvertidos; }
bool Jugador::isLesionado() { return lesionado; }
bool Jugador::isEliminado() { return eliminado; }

// Setters
void Jugador::setDni(int _dni) { dni = _dni; }
void Jugador::setIdClub(int _idClub) { idClub = _idClub; }
void Jugador::setNombre(const char* _nombre) { strcpy(nombre, _nombre); }
void Jugador::setApellido(const char* _apellido) { strcpy(apellido, _apellido); }
void Jugador::setTelefono(const char* _telefono) { strcpy(telefono, _telefono); }
void Jugador::setFechaNacimiento(Fecha _fecha) { fechaNacimiento = _fecha; }
void Jugador::setPosicion(const char* _posicion) { strcpy(posicion, _posicion); }
void Jugador::setPartidosJugados(int _partidos) { partidosJugados = _partidos; }
void Jugador::setGolesConvertidos(int _goles) { golesConvertidos = _goles; }
void Jugador::setLesionado(bool _lesionado) { lesionado = _lesionado; }
void Jugador::setEliminado(bool _eliminado) { eliminado = _eliminado; }

