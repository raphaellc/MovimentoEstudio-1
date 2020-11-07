#pragma once

template<class T>

class Tree
{
public:
	Tree();
	~Tree() {};

	//Novos métodos
	void push(T* elemento); //Insere um nó com dado definido por parâmetro no fim da lista

	void removeRoot();
	void removeNode(T* elemento);//
	void empty();
	bool searchNode(T* elemento/*, No * param_lista = lista*/);
	T* getRoot();
	void print();

private:
	bool isEmpty(); //Verifica se a lista está vazia

	No<T>* root;
	int qtdNodes;
	int qtdLeafNodes;
};

