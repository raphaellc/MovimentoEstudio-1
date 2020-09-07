#include "ArrayFloat.h"
#include <iostream>
#include <cstdio>

using namespace std;

ArrayFloat::ArrayFloat()
{
	array = new float[5];
	arrayTemp = nullptr;
	indice = 0;
	tamanho = tamNovo = 5;

	for (int i = 0; i < tamanho; i++) {
		array[i] = NULL;
	}
}

void ArrayFloat::adiciona(float i)
{
	if (indice >= tamanho) realocar();//realocar == aumentar tamanho
	array[indice] = i;
	indice++;
}

void ArrayFloat::remover()
{
	indice--;
	array[indice] = NULL;
}

float ArrayFloat::obterValorEm(int i)
{
	if (i < tamanho && i >= 0) {
		return array[i];
	}
	else {
		cout << "A posição selecionada é inexistente\n";
		return NULL;
	}
}

float ArrayFloat::obterValor()
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
	arrayTemp = new float[tamanho];

	for (int i = 0; i < tamanho; i++) {
		arrayTemp[i] = array[i];
	}

	delete[] array;
	array = new float[tamNovo];

	for (int i = 0; i < tamanho; i++) {
		array[i] = arrayTemp[i];
	}

	for (int i = tamanho; i < tamNovo; i++) {
		array[i] = NULL;
	}

	tamanho = tamNovo;
	
	delete[] arrayTemp;
}
