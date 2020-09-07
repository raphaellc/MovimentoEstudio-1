#pragma once
#include <iostream>
#include <string>

using namespace std;

enum  tipoArma { Pistol, Motoss };

class ArmaBase
{
public:
	void atacar();

protected:
	string id;
	int ammo, maxAmmo;
};

