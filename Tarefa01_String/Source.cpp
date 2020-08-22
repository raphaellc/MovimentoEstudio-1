#include <iostream>
#include <cstdio>
#include <iomanip>
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

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";

	array.adiciona("oito");
	array.adiciona("nove");
	array.adiciona("dez");
	array.adiciona("onze");

	array.remover();

	cout << "Representação do array:\n";
	array.mostrarValores();

	cout << "|-------------------------------------------------|\n";
	cout << "Representação do ultimo valor do array: " << array.obterValor() << endl;
	cout << "Representação do valor do array na posição 3: " << array.obterValorEm(3) << endl;

	array.desalocaArray();

	cout << "|-------------------------------------------------|\n";

	//string a = "ola";
	//cout << a;

	//cout << endl;

	//int* x = new int[3];
	//x[0] = 0;
	//x[1] = 1;
	//x[2] = 2;

	//for (int i = 0; i < 3; i++) {
	//	cout << x[i];
	//}
	//
	//cout << endl;

	//string* b = new string;

	//*b = "WTF";
	//cout << *b;

	//delete b;

	//cout << endl;

	//string* c = new string[2];
	//c[0] = "zero";
	//c[1] = "um";

	//for (int i = 0; i < 2; i++) {
	//	cout << c[i] << ", ";
	//}

	//cout << endl;

	system("pause");
	return 0;
}