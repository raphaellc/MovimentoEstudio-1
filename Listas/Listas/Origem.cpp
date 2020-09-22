#include "Lista.h"
#include <iostream> 
#include <ctime>


using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	Lista* minha_lista = new Lista;

	//N�s de 0 a 4
	int* zero = new int;
	int* um = new int;
	int* dois = new int;

	*zero = 0;
	*um = 1;
	*dois = 2;

	minha_lista->insereFimLista(zero);
	minha_lista->insereFimLista(um);

	

	//cout << "Dado no N� da posi��o 1: " << minha_lista->obterElementoEm(1) << endl;
	//cout << "Quantidade de N�s: " << minha_lista->quantidadeElementos() << endl;
	//cout << "�ltimo N�: " << minha_lista->obterUltimoElemento() << endl;

	minha_lista->removeUltimoNo();//+

	minha_lista->imprimirLista();//+

	//minha_lista->insereFimLista(um);

	//minha_lista->insereFimLista(dois);

	minha_lista->removePrimeiroNo();//+

	minha_lista->imprimirLista();//+

	//minha_lista->removeElemento(dois);

	minha_lista->imprimirLista();//+

	//minha_lista->insereEm(0, zero);

	if (minha_lista->contemNaLista(zero)) cout << "Tem sim\n";//+

	//minha_lista->esvaziaLista();

	minha_lista->imprimirLista();//+

	cout << "/-------------------------------------------------------------------------/\n";

	for (int i = 0; i < 5; i++) {
		minha_lista->inserirLista(i);
	}

	cout << "Dado no N� da posi��o 3: " << minha_lista->buscarLista(3) << endl;
	cout << "Quantidade de N�s: " << minha_lista->quantidadeElementos() << endl;
	cout << "Primeiro N�: " << minha_lista->obterPrimeiroElementoObsoleto() << endl;
	cout << "�ltimo N�: " << minha_lista->obterUltimoElementoObsoleto() << endl;

	minha_lista->removerLista();
	
	cout << "�ltimo N�: " << minha_lista->obterUltimoElementoObsoleto() << endl;

	minha_lista->imprimirLista();


	return 0;
}
