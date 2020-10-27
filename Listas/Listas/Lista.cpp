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
		n->setAnterior(nullptr);
	}
	else {//Caso não esteja vazia
		percorrerLista(); //Encontrar o último nó da lista
		aux->setProximo(n); //Insere o nó na lista
		n->setAnterior(aux);
	}
	fim_lista = n; //Configura o novo nó como sendo o último da lista
	qtdNo++;
}

void Lista::insereInicioLista(int* elemento)
{
	No* n = new No; //Define o nó e insere o elemento no nó
	n->setDado(*elemento); //Encapsula o dado no nó

	aux = inicio_lista;
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = fim_lista = n; //Insere o nó na lista
	}
	else {//Caso não esteja vazia
		aux->setAnterior(n); //Insere o nó na lista
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
		No* n = new No; //Define o nó e insere o elemento no nó
		n->setDado(*elemento); //Encapsula o dado no nó

		No* auxiliar; //Define um ponteiro de nó como auxiliar para o método
		
		aux = inicio_lista;
		for (int i = 0; i < posicao - 1; i++) {//Atinge a posição anterior a dejada
			aux = aux->getProximo();
		}
		auxiliar = aux->getProximo(); //Define o ponteiro auxiliar do método como sendo o antigo nó na posição que será alterada
		n->setAnterior(aux);
		n->setProximo(auxiliar);
		aux->setProximo(n); //Define o endereço da próxima posição do nó anterior ao que foi "afastado"
		auxiliar->setAnterior(n);//Define o endereço da posição anterior ao nó que estava na posição do novo como o novo nó

		qtdNo++;
	}
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
	aux = aux->getProximo();//Se desloca para a segunda posição
	if (inicio_lista->getProximo() == nullptr) {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = aux; //Corrige qual o primeiro nó da lista
		aux->setAnterior(nullptr);
	}
}

void Lista::removeNo(int* elemento)
{
	No* auxiliar;

	aux = inicio_lista;//Seta o Aux na posição Inicial
	while (aux->getDado() != *elemento)//Avança até chegar na posição em que o Elemento se encontra
	{
		aux = aux->getProximo();
		if (aux == nullptr) break;
	}
	if (aux == nullptr) 
	{
		cout << "O elemento inserido não está presente na lista!\n";
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
		cout << "Posição 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posição " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
