#ifndef CLUB_H
#define CLUB_H
#include "Fecha.h"

class Club {
private:
    int idClub;
    char nombre[40];
    char presidente[40];
    Fecha fechaInscripcion;
    int torneosGanados;
    char telefono[15];
    char email[40];
    int socios;
    int partidosJugados;
    int golesTotales;
    bool eliminado;

public:
    // Constructor
    Club(int _idClub = 0, const char* _nombre = "", const char* _presidente = "", Fecha _fechaInscripcion = Fecha(),
         int _torneosGanados = 0, const char* _telefono = "", const char* _email = "",
         int _socios = 0, int _partidosJugados = 0, int _golesTotales = 0, bool _eliminado = false);

    // Getters
    int getIdClub();
    const char* getNombre();
    const char* getPresidente();
    Fecha getFechaInscripcion();
    int getTorneosGanados();
    const char* getTelefono();
    const char* getEmail();
    int getSocios();
    int getPartidosJugados();
    int getGolesTotales();
    bool isEliminado();

    // Setters
    void setIdClub(int _idClub);
    void setNombre(const char* _nombre);
    void setPresidente(const char* _presidente);
    void setFechaInscripcion(Fecha _fecha);
    void setTorneosGanados(int _torneos);
    void setTelefono(const char* _telefono);
    void setEmail(const char* _email);
    void setSocios(int _socios);
    void setPartidosJugados(int _partidos);
    void setGolesTotales(int _goles);
    void setEliminado(bool _eliminado);
};


#endif
