#ifndef NODO_H
#define NODO_H
#include <stdlib.h>


template <typename T>

class Nodo{
	
	
	public:
	
	 Nodo(T*);
	 T *valor;
	 int index;
	
	 Nodo * siguiente;
	 Nodo * anterior;
	 
	 T * getValor();
	 int getIndex();
	 void setIndex(int);
	
};

template <typename T>

Nodo<T>::Nodo(T *val){
	
	
	this->siguiente=NULL;
	this->anterior = NULL;
	this->valor=val;

}

template <class T>
T *Nodo<T>::getValor(){
	
	return this->valor;
}

template <typename T>
int Nodo<T>::getIndex(){

	return this->index;
}
template <typename T>
void Nodo<T>::setIndex(int indice){

	this->index=indice;
}

#endif
