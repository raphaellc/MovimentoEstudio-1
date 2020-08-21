#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include "ArrayInt.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ptb");

	/*int* array;
	int* arrayTemp;
	int tam, tamTemp;
	tam = 5;

	array = new int[tam];


	for (int i = 0; i < tam; i++) {
		array[i] = NULL;
	}


	for (int i = 0; i < tam; i++) {
		cout << array[i];
	}

	cout << endl;
	
	tamTemp = 10;

	arrayTemp = new int[tam];

	for (int i = 0; i < tam; i++) {
		arrayTemp[i] = array[i];
	}

	for (int i = 0; i < 10; i++) {
		cout << array[i];
		cout << endl;
	}
	
	array = new int[tamTemp];

	for (int i = tam; i < tamTemp; i++) {
		array[i] = NULL;
	}

	for (int i = 0; i < tam; i++) {
		array[i] = arrayTemp[i];
	}

	for (int i = tam; i < tamTemp; i++) {
		if(array[i] == 0) 77;
		else array[i] = 56;
	}
	
	for (int i = 0; i < tamTemp; i++) {
		cout << array[i];
		cout << endl;
	}
	cout << endl;

	delete[] array;
	delete[] arrayTemp;*/

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

	array.mostrarValores();

	cout << array.obterValor();
	cout << array.obterValorEm(3);

	array.~ArrayInt();

	system("pause");
	return 0;
}