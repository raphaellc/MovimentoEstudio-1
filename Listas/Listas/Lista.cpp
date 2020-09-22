#include "Lista.h"
#include <iostream> 

using namespace std;

Lista::Lista()
{
	inicio_lista = fim_lista = aux = nullptr;
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
	qtdNo--;
	percorrerLista(); //Encontrar o pen�ltimo n� da lista
	delete fim_lista; //Desaloca a �ltima posi��o
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		aux->setProximo(nullptr); //Configura valor nulo para o ponteiro proximoNo do pen�ltimo n�
		fim_lista = aux; //Corrige qual o �ltimo n� da lista
	}
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
	for (int i = 0; i < qtdNo-1; i++) {
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


void Lista::insereFimLista(int* elemento)
{
	No * n = new No; //Define o n� e insere o elemento no n�
	n->setDado(*elemento); //Encapsula o dado no n�
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


int Lista::insereEm(int posicao, int* elemento)
{
	int elemente = *elemento;
	aux = inicio_lista;
	for (int i = 0; i < posicao; i++) {//Atinge a posi��o desejada
		aux->getProximo();
	}
	qtdNo++;
	aux->setDado(*elemento);
	
}

void Lista::removePrimeiroNo()
{
	qtdNo--;
	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	aux=aux->getProximo();//Se desloca para a segunda posi��o
	delete inicio_lista; //Desaloca a primeira posi��o
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		
		inicio_lista = aux; //Corrige qual o primeiro n� da lista
	}
}

void Lista::removeElemento(int* elemento)
{
	
	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	while (aux->getDado() != *elemento)//Avan�a at� chegar na posi��o em que o Elemento se encontra
	{
		aux->getProximo();
	}
	aux->setDado(NULL);//Remove o dado da posi��o, mas mant�m o n�
}

void Lista::esvaziaLista()
{
	for (int x = 0; x < qtdNo; x++)
	{
		aux = inicio_lista;//Seta o Aux na posi��o Inicial
		aux = aux->getProximo();//Se desloca para a segunda posi��o
		delete inicio_lista; //Desaloca a primeira posi��o
		if (fim_lista == inicio_lista) {
			inicio_lista = fim_lista = aux = nullptr;
		}
		else {

			inicio_lista = aux; //Corrige qual o primeiro n� da lista
		}
	}

	qtdNo = 0;
}

bool Lista::contemNaLista(const int* elemento, No* param_lista)
{
	return false;
}

void Lista::imprimirLista()
{
	aux = inicio_lista;
	if (listaVazia()) {
		cout << "Lista vazia!";
	}
	else {
		cout << "Posi��o 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posi��o " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
