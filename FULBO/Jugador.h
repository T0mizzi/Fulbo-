#include "Fecha.h"

class Jugador {
private:
    int dni;
    int idClub;
    char nombre[30];
    char apellido[30];
    char telefono[15];
    char email[40];
    Fecha fechaNacimiento;
    char posicion[20];
    int partidosJugados;
    int golesConvertidos;
    bool lesionado;
    bool eliminado;

public:
    // Constructor
    Jugador(int _dni = 0, int _idClub = 0, const char* _nombre = "", const char* _apellido = "",
            const char* _telefono = "", Fecha _fechaNacimiento = Fecha(),
            const char* _posicion = "", int _partidosJugados = 0, int _golesConvertidos = 0,
            bool _lesionado = false, bool _eliminado = false);

    // Getters
    int getDni();
    int getIdClub();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    Fecha getFechaNacimiento();
    const char* getPosicion();
    int getPartidosJugados();
    int getGolesConvertidos();
    bool isLesionado();
    bool isEliminado();

    // Setters
    void setDni(int _dni);
    void setIdClub(int _idClub);
    void setNombre(const char* _nombre);
    void setApellido(const char* _apellido);
    void setTelefono(const char* _telefono);
    void setFechaNacimiento(Fecha _fecha);
    void setPosicion(const char* _posicion);
    void setPartidosJugados(int _partidos);
    void setGolesConvertidos(int _goles);
    void setLesionado(bool _lesionado);
    void setEliminado(bool _eliminado);
};


