#pragma once
template<class T>

class No
{
public:
	No();
	~No();

	T getDado();
	void setDado(T Dado);

	No<T>* getAnterior();
	No<T>* getSeguinte();
	void setAnterior(No<T> *nAnt);
	void setSeguinte(No<T> *nSeg);

private:
	T dado;
	No<T>* noAnterior;
	No<T>* noSeguinte;
};

template<class T>
inline No<T>::No()
{
	noSeguinte = noAnterior = nullptr;
	dado = NULL;
}

template<class T>
inline No<T>::~No()
{
}

template<class T>
inline T No<T>::getDado()
{
	return dado;
}

template<class T>
inline void No<T>::setDado(T Dado)
{
	dado = Dado;
}

template<class T>
inline No<T> *No<T>::getAnterior()
{
	return noAnterior;
}

template<class T>
inline No<T> *No<T>::getSeguinte()
{
	return noSeguinte;
}

template<class T>
inline void No<T>::setAnterior(No<T> *nAnt)
{
	noAnterior = nAnt;
}

template<class T>
inline void No<T>::setSeguinte(No<T> *nSeg)
{
	noSeguinte = nSeg;
}
