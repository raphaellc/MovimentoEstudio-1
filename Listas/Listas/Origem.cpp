#include "Lista.h"
#include <iostream> 
#include <ctime>


using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	Lista* minha_lista = new Lista;

	//Nós de 0 a 4
	for (int i = 0; i < 5; i++) {
		minha_lista->inserirLista(i);
	}

	cout << "Dado no Nó da posição 3: " << minha_lista->buscarLista(3) << endl;
	cout << "Quantidade de Nós: " << minha_lista->quantidadeElementos() << endl;
	cout << "Primeiro Nó: " << minha_lista->obterPrimeiroElemento() << endl;
	cout << "Último Nó: " << minha_lista->obterUltimoElemento() << endl;

	minha_lista->removerLista();
	
	//cout << "Dado no Nó da posição 4: " << minha_lista->buscarLista(4) << endl;
	//cout << "Último Nó: " << minha_lista->obterUltimoElemento() << endl;

	return 0;
}
