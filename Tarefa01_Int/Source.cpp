#include <iostream>
#include <cstdio>
#include "ArrayInt.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	ArrayInt array;

	array.adiciona(1);
	array.adiciona(2);
	array.adiciona(3);
	array.adiciona(4);
	array.adiciona(5);
	array.adiciona(6);
	array.adiciona(7);
	array.adiciona(8);

	array.remover();

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";

	array.adiciona(8);
	array.adiciona(9);
	array.adiciona(10);
	array.adiciona(11);

	array.remover();

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";
	cout << "Representação do ultimo valor do array: " << array.obterValor() << endl;
	cout << "Representação do valor do array na posição 3: " << array.obterValorEm(3) << endl;

	array.desalocaArray();

	cout << "|-------------------------------------------------|\n";

	system("pause");
	return 0;
}