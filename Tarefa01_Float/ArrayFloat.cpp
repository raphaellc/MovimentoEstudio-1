#include "ArrayFloat.h"
#include <iostream>
#include <cstdio>

using namespace std;

ArrayFloat::ArrayFloat()
{
	array = new int[5];
	arrayTemp = nullptr;
	indice = 0;
	tamanho = tamNovo = 5;

	for (int i = 0; i < tamanho; i++) {
		array[i] = NULL;
	}
}

void ArrayFloat::adiciona(int i)
{
	if (indice >= tamanho) realocar();
	array[indice] = i;
	indice++;
}

void ArrayFloat::remover()
{
	indice--;
	array[indice] = NULL;
}

int ArrayFloat::obterValorEm(int i)
{
	if (i < tamanho && i >= 0) {
		return array[i];
	}
	else {
		cout << "A posi��o selecionada � inexistente\n";
		return NULL;
	}
}

int ArrayFloat::obterValor()
{
	return array[indice-1];
}

void ArrayFloat::mostrarValores()
{
	for (int i = 0; i < tamanho; i++) {
		cout << array[i] << endl;
	}
}

void ArrayFloat::desalocaArray()
{
	delete[] array;
}

int ArrayFloat::getQtdElementos()
{
	return indice;
}

int ArrayFloat::getTamanhoArray()
{
	return tamanho;
}

void ArrayFloat::realocar()
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