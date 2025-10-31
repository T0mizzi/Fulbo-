#pragma once
#include "Menu.h"
#include "GolMenu.h"

class AppMenu : public Menu {
public:
    AppMenu();
    void mostrarOpciones();


protected:

    void ejecutarOpcion(int opcion);
    GolMenu _golMenu;
};
