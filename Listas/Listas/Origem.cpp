#include "Lista.h"
#include <iostream> 
#include <ctime>


using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	Lista* minha_lista = new Lista;

	//N�s de 0 a 4
	for (int i = 0; i < 5; i++) {
		minha_lista->inserirLista(i);
	}

	cout << "Dado no N� da posi��o 3: " << minha_lista->buscarLista(3) << endl;
	cout << "Quantidade de N�s: " << minha_lista->quantidadeElementos() << endl;
	cout << "Primeiro N�: " << minha_lista->obterPrimeiroElemento() << endl;
	cout << "�ltimo N�: " << minha_lista->obterUltimoElemento() << endl;

	minha_lista->removerLista();
	
	//cout << "Dado no N� da posi��o 4: " << minha_lista->buscarLista(4) << endl;
	//cout << "�ltimo N�: " << minha_lista->obterUltimoElemento() << endl;

	return 0;
}
