#pragma once
#include "Menu.h"
#include "GolManager.h"

class GolMenu : public Menu
{
public:
    GolMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

private:
    GolManager _golManager;
};
