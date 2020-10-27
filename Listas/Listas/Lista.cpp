#include "Lista.h"
#include <iostream> 

using namespace std;

Lista::Lista()
{
	inicio_lista = fim_lista = aux = nullptr;
	temp = new int;
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
	No * n = new No; //Define o n� e insere o elemento no n�
	n->setDado(*elemento); //Encapsula o dado no n�
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o n� na lista
		n->setAnterior(nullptr);
	}
	else {//Caso n�o esteja vazia
		percorrerLista(); //Encontrar o �ltimo n� da lista
		aux->setProximo(n); //Insere o n� na lista
		n->setAnterior(aux);
	}
	fim_lista = n; //Configura o novo n� como sendo o �ltimo da lista
	qtdNo++;
}

void Lista::insereInicioLista(int* elemento)
{
	No* n = new No; //Define o n� e insere o elemento no n�
	n->setDado(*elemento); //Encapsula o dado no n�

	aux = inicio_lista;
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = fim_lista = n; //Insere o n� na lista
	}
	else {//Caso n�o esteja vazia
		aux->setAnterior(n); //Insere o n� na lista
		n->setProximo(aux);
		inicio_lista = n;
		}
	n->setAnterior(nullptr);
	qtdNo++;
}

void Lista::insereEm(int posicao, int* elemento)
{
	if (posicao == 0) 
	{
		insereInicioLista(elemento);
	}
	else if (posicao == qtdNo)
	{
		insereFimLista(elemento);
	}
	else 
	{
		// 0 * 1
		// aux = 0  proximoNo(aux) = * anteriorNo(auxiliar) = * auxiliar = 1
		No* n = new No; //Define o n� e insere o elemento no n�
		n->setDado(*elemento); //Encapsula o dado no n�

		No* auxiliar; //Define um ponteiro de n� como auxiliar para o m�todo
		
		aux = inicio_lista;
		for (int i = 0; i < posicao - 1; i++) {//Atinge a posi��o anterior a dejada
			aux = aux->getProximo();
		}
		auxiliar = aux->getProximo(); //Define o ponteiro auxiliar do m�todo como sendo o antigo n� na posi��o que ser� alterada
		n->setAnterior(aux);
		n->setProximo(auxiliar);
		aux->setProximo(n); //Define o endere�o da pr�xima posi��o do n� anterior ao que foi "afastado"
		auxiliar->setAnterior(n);//Define o endere�o da posi��o anterior ao n� que estava na posi��o do novo como o novo n�

		qtdNo++;
	}
}

void Lista::removeUltimoNo()
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

void Lista::removePrimeiroNo()
{
	qtdNo--;
	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	aux = aux->getProximo();//Se desloca para a segunda posi��o
	if (inicio_lista->getProximo() == nullptr) {
		delete inicio_lista;//Desaloca a primeira posi��o
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		delete inicio_lista;//Desaloca a primeira posi��o
		inicio_lista = aux; //Corrige qual o primeiro n� da lista
		aux->setAnterior(nullptr);
	}
}

void Lista::removeNo(int* elemento)
{
	No* auxiliar;

	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	while (aux->getDado() != *elemento)//Avan�a at� chegar na posi��o em que o Elemento se encontra
	{
		aux = aux->getProximo();
		if (aux == nullptr) break;
	}
	if (aux == nullptr) 
	{
		cout << "O elemento inserido n�o est� presente na lista!\n";
	}
	else if (aux->getAnterior() == nullptr) removePrimeiroNo();
	else if (aux->getProximo() == nullptr) removeUltimoNo();
	else
	{
		auxiliar = aux->getAnterior();
		auxiliar->setProximo(aux->getProximo());

		auxiliar = aux->getProximo();
		auxiliar->setAnterior(aux->getAnterior());

		delete aux;
		aux = auxiliar = nullptr;
		qtdNo--;
	}
}

void Lista::esvaziaLista()
{
	if (!listaVazia()) {
		aux = inicio_lista;
		while (aux->getProximo() != nullptr) removePrimeiroNo();//Esvazia at� o pen�ltimo N�
		removePrimeiroNo();//Esvazia o �ltimo N�
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
	temporaria = fim_lista->getDado();
	return &temporaria;
}

int *Lista::obterPrimeiroElemento()
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
		cout << "Posi��o 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posi��o " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
