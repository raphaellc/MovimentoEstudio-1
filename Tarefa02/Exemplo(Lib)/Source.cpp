#include <iostream> // Entrada/Saida padrao
#include <ctime>
#include <string>
#include <cmath>
#include <cstdio>
#include <fstream> //Trabalha com arquivos
#include <iomanip>
#include "Pistola.h"
#include "Motosserra.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	ArmaBase array[2];
	tipoArma i;
	array[Pistol] = Pistola(); 
	array[Motoss] = Motosserra();

	//
	i = Pistol;

	array[i].atacar();

	array[i].atacar();

	i = Motoss;

	array[i].atacar();

	/*do {
		if () {
			switch()
		}
		else {
			switch ()
		}
	}while()*/



	system("pause");
	return 0;
}