#ifndef _LISTACIRCULAR_H_
#define _LISTACIRCULAR_H_

#include "lista.h"

template <typename T>
class ListaCircular : public  ListaLigada<T> {
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
ListaCircular<T>::ListaCircular(): ListaLigada<T>(){
	// this->cauda = nullptr;
	// this->cauda->setNext(this->cauda);
}

template<typename T>
ListaCircular<T>::~ListaCircular(){
	// while(this->cauda->getNext() != this->cauda) {
	//     this->cauda = this->cauda->getNext();
	// }
}

template<typename T>
bool ListaCircular<T>::InsereNoInicio(T _valor){
	auto newFirst = make_shared<Node<T>>(_valor);
	if(!newFirst) return false;

	if(this->size() == 0) {
		this->cauda = newFirst;
		this->cauda->setNext(this->cauda);
	}else{
		newFirst->setNext(this->cauda->getNext());
		this->cauda->setNext(newFirst);
	}

	this->tamanho++;

	return true;
}

template<typename T>
bool ListaCircular<T>::InsereNoFinal(T _valor){
	auto newLast = make_shared<Node<T>>(_valor);
	if(!newLast) return false;

	if(this->size() == 0) {
		this->cauda = newLast;
		this->cauda->setNext(this->cauda);
	}else{
		newLast->setNext(this->cauda->getNext());
		this->cauda->setNext(newLast);
		this->cauda = newLast;
	}

	this->tamanho++;

	return true;
}

template<typename T>
bool ListaCircular<T>::InsereNaPosicao(int pos, T _valor){
	auto novo = make_shared<Node<T>>(_valor);
	if(!novo) return false;

	auto aux = this->cauda->getNext();

	int i = 1;
	while(i != pos-1 && aux->getNext() != this->cauda) {
	    aux = aux->getNext();
	    i++;
	}

	if(i != pos-1) return false;

	novo->setNext(aux->getNext());
	aux->setNext(novo);

	this->tamanho++;

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNoInicio(){
	if(this->tamanho == 0) return false;

	if(this->tamanho == 1) {
		this->cauda = nullptr;	
	}else{
		auto aux = this->cauda->getNext();
		this->cauda->setNext(aux->getNext());

		aux = nullptr;
	}

	this->tamanho--;

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNoFinal(){
	if(this->cauda->getNext() == this->cauda) return false;

	auto prev = this->cauda->getNext();

	while (prev->getNext() != this->cauda){
		prev = prev->getNext();
	}

	prev->setNext(this->cauda->getNext());
	this->cauda = prev;

	this->tamanho--;

	return true;
}

template<typename T>
bool ListaCircular<T>::RemoveNaPosicao(int pos){
	if(this->cauda->getNext() == this->cauda) return false;

	auto aux = this->cauda;
	auto prev = aux;

	int i = 0;
	do{
		prev = aux;
	    aux = aux->getNext();
	} while (i != pos && aux->getNext() != this->cauda);

	prev->setNext(aux->getNext());

	this->tamanho--;

	return true;
}

#endif