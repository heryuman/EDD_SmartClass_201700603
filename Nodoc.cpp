#ifndef NODOC_H
#define NODOC_H
#include <stdlib.h>


template <typename T>

class Nodoc{
	
	
	public:
	
	 Nodoc(T*);
	 T *valor;
	
	 Nodoc * siguiente;
	 Nodoc * anterior;
	 
	 T * getValor();
	
};

template <typename T>

Nodoc<T>::Nodoc(T *val){
	
	
	this->siguiente=NULL;
	this->anterior = NULL;
	this->valor=val;
}


template <typename T>
T *Nodoc<T>::getValor(){
	
	return this->valor;
}
#endif
