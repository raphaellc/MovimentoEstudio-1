#pragma once
#include <iostream>
#include <string>
#include "libUnicornio.h"

using namespace std;

enum  tipoArma { PISTOLA, MOTOSSERRA, METRALHADORA, CALIBRE12, NADA};

class ArmaBase
{
public:
	void atacar();
	void recarregar();
	string getAmmo();
	Texto getAtacar() { return menuAtacar; }

	string getID() { return id; }
protected:
	Texto menuAtacar;
	string id;
	int ammo, maxAmmo;
};