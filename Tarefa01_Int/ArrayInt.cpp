#include "ArrayInt.h"
#include <iostream>
#include <cstdio>

using namespace std;

ArrayInt::ArrayInt()
{
	array = new int[5];
	arrayTemp = nullptr;
	indice = 0;
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
		return array[i];
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

void ArrayInt::mostrarValores()
{
	for (int i = 0; i < tamanho; i++) {
		cout << array[i] << endl;
	}
}

void ArrayInt::desalocaArray()
{
	delete[] array;
}

int ArrayInt::getQtdElementos()
{
	return indice;
}

int ArrayInt::getTamanhoArray()
{
	return tamanho;
}

void ArrayInt::realocar()
{
	tamNovo += 5;
	arrayTemp = new int[tamanho];

	for (int i = 0; i < tamanho; i++) {
		arrayTemp[i] = array[i];
	}

	array = new int[tamNovo];

	for (int i = 0; i < tamanho; i++) {
		array[i] = arrayTemp[i];
	}

	for (int i = tamanho; i < tamNovo; i++) {
		array[i] = NULL;
	}

	tamanho = tamNovo;
	
	delete[] arrayTemp;
}
