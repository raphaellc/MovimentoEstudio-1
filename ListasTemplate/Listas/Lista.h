#pragma once
#include "No.h"
class Lista
{
public: 
	Lista();
	~Lista() {};
	void inserirLista(int elemento); //Insere um Nó com dado no próximo espaço vago
	void removerLista(); //Remove o último elemento da lista
	int buscarLista(int pos); //Retorna o dado de um Nó na posição especificada
	int quantidadeElementos(); //Retorna quantos nos tem na lista
	int obterPrimeiroElementoObsoleto(); //Retorna o dado do primeiro no da lista
	int obterUltimoElementoObsoleto(); //Retorna o dado do ultimo elemento

	//Novos métodos
	void insereFimLista(int * elemento); //Insere um nó com dado definido por parâmetro no fim da lista
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
	bool listaVazia(); //Verifica se a lista está vazia

	No* inicio_lista;
	No* fim_lista;
	No* aux;
	int* temp;
	int temporaria;
	int qtdNo;
};
