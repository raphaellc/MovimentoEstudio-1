#include "ArmaBase.h"

void ArmaBase::atacar()
{
	if (ammo > 0) {
		if (getID() != "Auto-Rifle") {
			if (gTeclado.pressionou[TECLA_A]) {
				ammo--;
			}
		}
		else {
			Sleep(80);
			ammo--;
		}
	}
}

void ArmaBase::recarregar()
{
	ammo = maxAmmo;
}

string ArmaBase::getAmmo()
{
	if (id == "Chainsaw") {
		return "Ammo: Unlimited\n";
	}
	else {
		return "Ammo: " + to_string(ammo) + "/" + to_string(maxAmmo) + "\n";
	}
}
