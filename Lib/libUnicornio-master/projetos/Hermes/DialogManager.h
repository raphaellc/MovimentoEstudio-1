#pragma once
#include "Lista.h"
#include "DialogBox.h"
class DialogManager
{
public:

private:
	Lista<Dialog*> dialogs;
	DialogBox* dialog;
};

