#include <iostream>
#include <cstdio>
#include <string>
#include "ArrayInt.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	ArrayString array;

	array.adiciona("um");
	array.adiciona("dois");
	array.adiciona("tres");
	array.adiciona("quatro");
	array.adiciona("cinco");
	array.adiciona("seis");
	array.adiciona("sete");
	array.adiciona("oito");

	array.remover();

	cout << "Representa��o do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";

	array.adiciona("oito");
	array.adiciona("nove");
	array.adiciona("dez");
	array.adiciona("onze");

	array.remover();

	cout << "Representa��o do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";
	cout << "�ltimo valor do array: " << array.obterValor() << endl;
	cout << "Valor do array na posi��o 3: " << array.obterValorEm(3) << endl;
	cout << "Quantidade de elementos no array: " << array.getQtdElementos() << endl;
	cout << "Tamanho do array: " << array.getTamanhoArray() << endl;

	array.desalocaArray();

	cout << "|-------------------------------------------------|\n";

	system("pause");
	return 0;
}