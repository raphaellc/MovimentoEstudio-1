#include "Lista.h"
#include <iostream> 

Lista::Lista()
{
	inicio_lista = fim_lista = nullptr;

	qtdNo = 0;
}

void Lista::inserirLista(int elemento)
{
	
	No * n = new No; //Define o n� e insere o elemento no n�
	n->setDado(elemento); //Encapsula o dado no n�
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o n� na lista
	}
	else {//Caso n�o esteja vazia
		percorrerLista(); //Encontrar o �ltimo n� da lista
		aux->setProximo(n); //Insere o n� na lista
	}
	fim_lista = n; //Configura o novo n� como sendo o �ltimo da lista
	qtdNo++;
}

void Lista::removerLista()
{
	percorrerListaAte(fim_lista); //Encontrar o pen�ltimo n� da lista
	delete fim_lista; //Desaloca a �ltima posi��o
	aux->setProximo(nullptr); //Configura valor nulo para a vari�vel proximoNo do pen�ltimo n�
	fim_lista = aux; //Corrige qual o �ltimo n� da lista
	qtdNo--;
}

int Lista::buscarLista(int pos)
{
	aux = inicio_lista;
	for(int i= 0; i < pos; i++) { //Percorre a lista at� encontrar o n� na posi��o inserida
		aux = aux->getProximo();
	}

	return aux->getDado(); //Retorna o n� desejado
}

bool Lista::listaVazia()
{
	if (inicio_lista == nullptr)
		return true;
	else
		return false;
}

void Lista::percorrerLista()
{
	aux = inicio_lista;
	while (aux->getProximo() != nullptr) {
		aux = aux->getProximo();
	}
}

void Lista::percorrerListaAte(No* n) //Modifica��o do m�todo percorrerLista(), percorre a lista at� o n� recebido por par�metro
{
	aux = inicio_lista;
	while (aux->getProximo() != n) {
		aux = aux->getProximo();
	}
}

int Lista::quantidadeElementos()
{
	return qtdNo;
}

int Lista::obterPrimeiroElemento()
{
	return inicio_lista->getDado();
}

int Lista::obterUltimoElemento()
{
	return fim_lista->getDado();
}