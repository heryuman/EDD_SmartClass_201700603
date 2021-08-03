#include <stdlib.h>


template <typename T>

class Nodo{
	
	
	public:
	
	 Nodo(T);
	 T valor;
	
	 Nodo * siguiente;
	 Nodo * anterior;
	
};

template <typename T>

Nodo<T>::Nodo(T val){
	
	
	this->siguiente=NULL;
	this->anterior = NULL;
	this->valor=val;
}
