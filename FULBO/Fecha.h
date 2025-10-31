#pragma once
#include <string>


class Fecha {
private:
    int _dia, _mes, _anio;

public:
    // Constructores
    Fecha();
    Fecha(int dia, int mes, int anio);

    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    // Otros m‚todos
    std::string toString();
};
