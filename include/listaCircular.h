#ifndef _LISTACIRCULAR_H_
#define _LISTACIRCULAR_H_

#include "lista.h"

template <typename T>
class ListaCircular : public  ListaLigada{
private:
	
public:
	ListaCircular();
	~ListaCircular();

	bool InsereNoInicio(T _valor);
	bool InsereNoFinal(T _valor);
	bool InsereNaPosicao(int pos, T _valor);
	bool RemoveNoInicio();
	bool RemoveNoFinal();
	bool RemoveNaPosicao(int pos);
};

template<typename T>
ListaCircular<T>::ListaCircular():ListaLigada(), cauda(nullptr){
	cauda->setNext(cauda);
}

template<typename T>
ListaCircular<T>::~ListaCircular()
{}

template<typename T>
bool ListaCircular<T>::InsereNoInicio(T _valor){
	auto newFirst = make_shared<Node<T>>(_valor);
	if(!newFirst) return false;

	newFirst->setNext(cauda->getNext());
	cauda->setNext(newFirst);

	return true;
}

template<typename T>
bool ListaCircular<T>::InsereNoFinal(T _valor){
	auto newLast = make_shared<Node<T>>(_valor);
	if(!newLast) return false;

	auto aux = cauda->getNext();

	while(aux->getNext() != cauda) {
	    aux = aux->getNext();
	}

	aux->setNext(newLast);
	newLast->setNext(cauda);

	return true;
}

template<typename T>
bool ListaCircular<T>::InsereNaPosicao(int pos, T _valor){
	auto novo = make_shared<Node<T>>(_valor);
	if(!novo) return false;

	auto aux = cauda->getNext();

	int i = 0;
	while(i != pos-1 && aux->getNext() != cauda) {
	    aux = aux->getNext();
	    i++;
	}

	if(i != pos-1) return false;

	aux->setNext(novo);
	novo->setNext(cauda);

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNoInicio(){
	if(cauda->getNext() == cauda) return false;

	cauda->setNext(cauda->getNext()->getNext());

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNoFinal(){
	if(cauda->getNext() == cauda) return false;

	auto aux = cauda;
	auto prev;

	do{
		prev = aux;
	    aux = aux->getNext();
	} while (aux->getNext() != cauda);

	prev->setNext(cauda);

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNaPosicao(int pos){
	if(cauda->getNext() == cauda) return false;

	auto aux = cauda;
	auto prev;

	int i = 0;
	do{
		prev = aux;
	    aux = aux->getNext();
	} while (i != pos && aux->getNext() != cauda);

	prev->setNext(cauda);

	return true;
}

#endif