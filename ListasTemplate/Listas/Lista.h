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
	int obterPrimeiroElementoObsoleto(); //Retorna o dado do primeiro no da lista
	int obterUltimoElementoObsoleto(); //Retorna o dado do ultimo elemento

	//Novos m�todos
	void insereFimLista(int * elemento); //Insere um n� com dado definido por par�metro no fim da lista
	void insereInicioLista(int * elemento);
	void insereEm(int posicao, int * elemento);
	void removeUltimoNo();
	void removePrimeiroNo();
	void removeNo(int * elemento);//
	void esvaziaLista();
	bool contemNaLista(int* elemento/*, No * param_lista = lista*/);
	int* obterUltimoElemento();
	int* obterPrimeiroElemento();
	int* obterElementoEm(int posicao);
	
	void imprimirLista();

private:
	void percorrerLista(); //Percorre todos elementos da lista
	bool listaVazia(); //Verifica se a lista est� vazia

	No* inicio_lista;
	No* fim_lista;
	No* aux;
	int* temp;
	int temporaria;
	int qtdNo;
};
