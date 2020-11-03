#pragma once
#include "Lista.h"
#include "DialogBox.h"
#include "GameObject.h"

enum dialogoAtual { Posdo = 0, Amanda = 5};

class DialogManager
{
public:
	DialogManager();
	~DialogManager() {};

	Dialog* obterDialogo(ID id_p, int ic);
private:
	Lista<Dialog*>* dialogs;
	DialogBox* dialog;
};