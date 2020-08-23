#include <iostream>
#include <cstdio>
#include "ArrayFloat.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	ArrayFloat array;

	array.adiciona(1.1);
	array.adiciona(2.1);
	array.adiciona(3.1);
	array.adiciona(4.1);
	array.adiciona(5.1);
	array.adiciona(6.1);
	array.adiciona(7.1);
	array.adiciona(8.1);

	array.remover();

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";

	array.adiciona(8.2);
	array.adiciona(9.1);
	array.adiciona(10.1);
	array.adiciona(11.1);

	array.remover();

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";
	cout << "Representação do ultimo valor do array: " << array.obterValor() << endl;
	cout << "Representação do valor do array na posição 3: " << array.obterValorEm(3) << endl;
	cout << "Quantidade de elementos no array: " << array.getQtdElementos() << endl;
	cout << "Tamanho do array: " << array.getTamanhoArray() << endl;

	array.desalocaArray();
	array.~ArrayFloat();

	cout << "|-------------------------------------------------|\n";

	system("pause");
	return 0;
}