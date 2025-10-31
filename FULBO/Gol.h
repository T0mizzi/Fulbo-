#pragma once

class Gol {
private:
    int idGol;
    int nroPartido;
    int dniJugador;
    int tipoGol;       // 1: penal, 2: tiro libre, 3: jugada
    char minuto[10];
    bool eliminado;

public:
    // Constructor
    Gol(int _idGol = 0, int _nroPartido = 0, int _dniJugador = 0, int _tipoGol = 0, const char* _minuto = "", bool _eliminado = false);

    // Getters
    int getIdGol() const;
    int getNroPartido() const;
    int getDniJugador() const;
    int getTipoGol() const;
    const char* getMinuto() const;
    bool isEliminado() const;

    // Setters
    void setIdGol(int _idGol);
    void setNroPartido(int _nroPartido);
    void setDniJugador(int _dniJugador);
    void setTipoGol(int _tipoGol);
    void setMinuto(const char* _minuto);
    void setEliminado(bool _eliminado);


};
