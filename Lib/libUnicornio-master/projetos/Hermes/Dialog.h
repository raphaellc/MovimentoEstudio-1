#pragma once
#include "Lista.h"

class Dialog
{
public:
	int* getId();
	int* getId_Personagem();
	Lista<string*> getFala();

private:
	int* id;
	int* id_personagem;
	Lista<string*> fala;
};

