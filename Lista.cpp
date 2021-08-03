#include<stdlib.h>
#include<iostream>
#include"Nodo.cpp"
using namespace std;

template <typename T>
class Lista{
	public:
		Nodo<T> * primero;
		Nodo<T> * ultimo;
		Lista();
		void insertar(T val);
		void imprimir();
		void eliminar(T val);
};

template <typename T>

Lista<T>::Lista(){
	
	this->primero=NULL;
	this->ultimo=NULL;
}


template <typename T>
void Lista<T>::insertar(T val){
	
	Nodo<T> * nuevo = new Nodo<T>(val);
	
	
	if(this->primero==NULL){
		
		this->primero=nuevo;
		this->ultimo=nuevo;
	}else{
		
		this->ultimo->siguiente =nuevo;
		nuevo->anterior = this->ultimo;
		this->ultimo =nuevo;
	}
}

template <typename T>

void Lista<T>::imprimir(){
	
	Nodo<T>  * temp = this->primero;
	
	while (temp !=NULL){
		
		cout<<temp->valor<<endl;
		temp =temp->siguiente;
		
		
	}
	
}


template <typename T>
void Lista<T>::eliminar(T val){
	Nodo<T> * tmp= this-> primero;
	
	while (tmp !=NULL){
		
		if (tmp->valor== val){
			
			cout<<"se encontro el valor"<<endl;
			tmp->anterior->siguiente = tmp->siguiente;
			tmp->siguiente->anterior = tmp->anterior;
			break;
		
		
			
			
		}else{
			
			tmp= tmp->siguiente;
		}
		
		
	}



}
