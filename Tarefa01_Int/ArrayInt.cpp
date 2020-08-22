#include "ArrayInt.h"
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

ArrayInt::ArrayInt()
{
	array = new int[5];
	arrayTemp = nullptr;
	indice = qtd_elementos = 0;
	tamanho = tamNovo = 5;

	for (int i = 0; i < tamanho; i++) {
		array[i] = NULL;
	}
}

void ArrayInt::adiciona(int i)
{
	if (indice >= tamanho) realocar();
	array[indice] = i;
	indice++;
}

void ArrayInt::remover()
{
	indice--;
	array[indice] = NULL;
}

int ArrayInt::obterValorEm(int i)
{
	if (i < tamanho && i >= 0) {
		if (array[i] != NULL) {
			return array[i];
		}
		else return NULL;
	}
	else {
		cout << "A posição selecionada é inexistente\n";
		return NULL;
	}
}

int ArrayInt::obterValor()
{
	return array[indice-1];
}

int ArrayInt::mostrarValores()
{
	for (int i = 0; i < tamanho; i++) {
		cout << array[i];
		cout << endl;
	}
	return 0;
}

void ArrayInt::desalocaArray()
{
	delete[] array;
}

void ArrayInt::realocar()
{
	tamNovo += 5;
	arrayTemp = new int[tamanho];

	for (int i = 0; i < tamanho; i++) {
		arrayTemp[i] = array[i];
	}

	array = new int[tamNovo];

	for (int i = tamanho; i < tamNovo; i++) {
		array[i] = NULL;
	}

	for (int i = 0; i < tamanho; i++) {
		array[i] = arrayTemp[i];
	}
	tamanho = tamNovo;
	
	delete[] arrayTemp;
}
