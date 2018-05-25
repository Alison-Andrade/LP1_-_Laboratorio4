#ifndef _FILACIRCULAR_H_
#define _FILACIRCULAR_H_

#include "listaCircular.h"

template<typename T>
class FilaCircular{
private:
	ListaCircular<T> m_listaC;
	shared_ptr<Node<T>> m_front;
	shared_ptr<Node<T>> m_back;
public:
	FilaCircular();
	~FilaCircular();

	bool empty();
	int size();
	T front();
	T back();
	bool push(T _valor);
	bool pop();
};

template<typename T>
FilaCircular<T>::FilaCircular(): m_front(nullptr), m_back(nullptr)
{}

template<typename T>
FilaCircular<T>::~FilaCircular()
{}

template<typename T>
bool FilaCircular<T>::empty(){
	return this->size() == 0 ? true : false;
}

template<typename T>
int FilaCircular<T>::size(){
	return m_listaC.size();
}

template<typename T>
T FilaCircular<T>::front(){
	return m_front.getValor();
}

template<typename T>
T FilaCircular<T>::back(){
	return m_back.getValor();
}

template<typename T>
bool FilaCircular<T>::push(T _valor){
	if(!m_listaC.InsereNoFinal(_valor)) return false;

	if(this->size() == 1) {
		m_front = m_listaC.getCauda()->getNext();
	}
}

template<typename T>
bool FilaCircular<T>::pop(){
	m_listaC.getCauda()->setNext(m_listaC.getCauda()->getNext()->getNext());

}

#endif