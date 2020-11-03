#include "Dialog.h"

Dialog::Dialog()
{
    id = new int;
    id_personagem = new int;
    fala = new Lista<string*>;
}

int* Dialog::getId()
{
    return id;
}

int* Dialog::getId_Personagem()
{
    return id_personagem;
}

Lista<string*>* Dialog::getFala()
{
    return fala;
}
