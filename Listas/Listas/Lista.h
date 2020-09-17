#pragma once
#include "No.h"
class Lista
{
public: 
	Lista();
	~Lista() {};
	void inserirLista(int elemento); //Insere um N� com dado no pr�ximo espa�o vago
	void removerLista(); //Remove o �ltimo elemento da lista
	int buscarLista(int pos); //Retorna o dado de um N� na posi��o especificada
	int quantidadeElementos(); //Retorna quantos nos tem na lista
	int obterPrimeiroElemento(); //Retorna o dado do primeiro no da lista
	int obterUltimoElemento(); //Retorna o dado do ultimo elemento
	
	void imprimirLista();

private:
	void percorrerLista(); //Percorre todos elementos da lista
	bool listaVazia(); //Verifica se a lista est� vazia

	No* inicio_lista;
	No* fim_lista;
	No* aux;
	int qtdNo;
};