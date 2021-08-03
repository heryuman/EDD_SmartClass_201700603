#include <stdlib.h>


template <typename T>

class Nodoc{
	
	
	public:
	
	 Nodoc(T);
	 T valor;
	
	 Nodoc * siguiente;
	 Nodoc * anterior;
	
};

template <typename T>

Nodoc<T>::Nodoc(T val){
	
	
	this->siguiente=NULL;
	this->anterior = NULL;
	this->valor=val;
}
