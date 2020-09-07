#include "ArmaBase.h"

void ArmaBase::atacar()
{
	cout << "Using: " << id << endl;
	
	if (id == "MOTOSSERRA") {
		cout << "Ammo: Unlimited\n";
	}
	else{
		ammo--;
		cout << "Ammo: " << ammo << "/" << maxAmmo << endl;
	}
	
	
}
