#pragma once
template<class T>

class FilaNo
{
public:
	FilaNo();
	~FilaNo();

	void push(T* elemento);
	void pop();
	T front();
	T back();
	bool estaVazia();
	int tamanho();
	void print();
	void erase();

private:
	void percorrerFila();

	No<T>* no_inicial;
	No<T>* no_final; 
	No<T>* aux;
	int tam;
};
using namespace std;

template<class T>
inline FilaNo<T>::FilaNo()
{
	tam = 0;
	no_inicial = no_final = aux = nullptr;
}

template<class T>
inline FilaNo<T>::~FilaNo()
{
}

template<class T>
inline void FilaNo<T>::push(T* elemento)
{
	No<T>* n = new No<T>;
	n->setDado(*elemento);
	if (estaVazia() == true) {
		no_inicial = n;
	}
	else {
		percorrerFila();
		aux->setSeguinte(n);
		n->setAnterior(aux);
	}
	no_final = n;
	tam++;
}

template<class T>
inline void FilaNo<T>::pop()
{
	tam--;
	aux = no_inicial;
	aux = aux->getSeguinte();

	delete no_inicial;
	if (aux == nullptr) {
		no_final = aux = no_inicial = nullptr;
	}
	else {
		aux->setAnterior(nullptr);
		no_inicial = aux;
	}
}

template<class T>
inline T FilaNo<T>::front()
{
	return no_inicial->getDado();
}

template<class T>
inline T FilaNo<T>::back()
{
	return no_final->getDado();
}

template<class T>
inline bool FilaNo<T>::estaVazia()
{
	if (tam == 0)
	{
		return true;
	}

	else return false;
}

template<class T>
inline int FilaNo<T>::tamanho()
{
	return tam;
}

template<class T>
inline void FilaNo<T>::percorrerFila()
{
	aux = no_inicial;
	for (int x = 0; x < tam - 1; x++) {
		aux = aux->getSeguinte();
	}
}

template<class T>
inline void FilaNo<T>::print()
{
	if (estaVazia()) cout << "A fila está vazia!\n";
	else {
		aux = no_inicial;
		for (int x = 0; x < tam; x++) {
			cout << "O Nó de número " << x + 1 << " possui o dado: " << aux->getDado() << ";\n";
			aux = aux->getSeguinte();
		}
	}


}

template<class T>
inline void FilaNo<T>::erase()
{
	while (!estaVazia()) pop();
}
