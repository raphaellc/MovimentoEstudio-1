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
	No * n = new No; //Define o nó e insere o elemento no nó
	n->setDado(elemento); //Encapsula o dado no nó
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o nó na lista
	}
	else {//Caso não esteja vazia
		percorrerLista(); //Encontrar o último nó da lista
		aux->setProximo(n); //Insere o nó na lista
	}
	fim_lista = n; //Configura o novo nó como sendo o último da lista
	qtdNo++;
}

void Lista::removerLista()
{
	qtdNo--;
	percorrerLista(); //Encontrar o penúltimo nó da lista
	delete fim_lista; //Desaloca a última posição
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		aux->setProximo(nullptr); //Configura valor nulo para o ponteiro proximoNo do penúltimo nó
		fim_lista = aux; //Corrige qual o último nó da lista
	}
}

int Lista::buscarLista(int pos)
{
	aux = inicio_lista;
	for(int i= 0; i < pos; i++) { //Percorre a lista até encontrar o nó na posição inserida
		aux = aux->getProximo();
	}
	return aux->getDado(); //Retorna o nó desejado
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

int Lista::obterPrimeiroElementoObsoleto()
{
	return inicio_lista->getDado();
}

int Lista::obterUltimoElementoObsoleto()
{
	return fim_lista->getDado();
}


void Lista::insereFimLista(int* elemento)
{
	No * n = new No; //Define o nó e insere o elemento no nó
	n->setDado(*elemento); //Encapsula o dado no nó
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o nó na lista
	}
	else {//Caso não esteja vazia
		percorrerLista(); //Encontrar o último nó da lista
		aux->setProximo(n); //Insere o nó na lista
	}
	fim_lista = n; //Configura o novo nó como sendo o último da lista
	qtdNo++;
}


int Lista::insereEm(int posicao, int* elemento)
{
	aux = inicio_lista;
	for (int i = 0; i < posicao; i++) {//Atinge a posição desejada
		aux->getProximo();
	}
	if (aux->getDado() == NULL) {
		aux->setDado(*elemento);
		return 1;
	}
	else return 0;
}

void Lista::removeUltimoNo()
{
	qtdNo--;
	percorrerLista(); //Encontrar o penúltimo nó da lista
	delete fim_lista; //Desaloca a última posição
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		aux->setProximo(nullptr); //Configura valor nulo para o ponteiro proximoNo do penúltimo nó
		fim_lista = aux; //Corrige qual o último nó da lista
	}
}

void Lista::removePrimeiroNo()
{
	qtdNo--;
	aux = inicio_lista;//Seta o Aux na posição Inicial
	aux=aux->getProximo();//Se desloca para a segunda posição
	if (inicio_lista->getProximo() == nullptr) {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = aux; //Corrige qual o primeiro nó da lista
	}
}

void Lista::removeElemento(int* elemento)
{
	
	aux = inicio_lista;//Seta o Aux na posição Inicial
	while (aux->getDado() != *elemento)//Avança até chegar na posição em que o Elemento se encontra
	{
		aux->getProximo();
	}
	aux->setDado(NULL);//Remove o dado da posição, mas mantém o nó
}

void Lista::esvaziaLista()
{
	if (listaVazia()) {
		aux = inicio_lista;
		while (aux->getProximo() != nullptr) removePrimeiroNo();//Esvazia até o penúltimo Nó
		removePrimeiroNo();//Esvazia o último Nó
	}
	else cout << "Lista vazia!\n";
}

bool Lista::contemNaLista(int* elemento/*, No* param_lista*/)
{
	aux = inicio_lista;
	for (int i = 0; i < qtdNo; i++)
	{
		if (aux->getDado() == *elemento) return true;
		else if(aux->getProximo() != nullptr) aux = aux->getProximo();
	}
	return false;
}

int* Lista::obterUltimoElemento()
{
	*temp = fim_lista->getDado();
	return temp;
}

int* Lista::obterPrimeiroElemento()
{
	*temp = inicio_lista->getDado();
	return temp;
}

int* Lista::obterElementoEm(int posicao)
{
	buscarLista(posicao);
	*temp = aux->getDado();
	return temp;
}

void Lista::imprimirLista()
{
	aux = inicio_lista;
	if (listaVazia()) {
		cout << "Lista vazia!\n";
	}
	else {
		cout << "Posição 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posição " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
