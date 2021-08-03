#include<stdlib.h>
#include<iostream>
#include"Nodoc.cpp"
using namespace std;

template <typename T>
class Listacirc{
	public:
		Nodoc<T> * primero;
		Nodoc<T> * ultimo;
		Lista();
		void insertar(T val);
		void imprimir();
		void eliminar(T val);
		void printStep();
};

template <typename T>

Listacirc<T>::Lista(){
	
	this->primero=NULL;
	this->ultimo=NULL;
}


template <typename T>
void Listacirc<T>::insertar(T val){
	
	Nodoc<T> * nuevo = new Nodoc<T>(val);
	
	
	if(this->primero==NULL){
		
		this->primero=nuevo;
		this->ultimo=nuevo;
	}else{
		
		this->ultimo->siguiente =nuevo;
		nuevo->anterior = this->ultimo;
		this->ultimo =nuevo;
		nuevo->siguiente= this->primero;
		this->primero->anterior=nuevo;
	}
}

template <typename T>

void Listacirc<T>::imprimir(){
	
	Nodoc<T>  * temp = this->primero;
	
	while (temp !=NULL){
		
		cout<<temp->valor<<endl;
		temp =temp->siguiente;
		
		
	}
	
}

template <typename T>
void Listacirc<T>::printStep(){
	
	Nodoc<T>  * temp = this->primero;
	
	int op=1;
	
	cout<<"printstep"<<endl;
	
	while (op == 1){
			
		cout<<"en while"<<endl;
		cout<<temp->valor<<endl;
		temp =temp->siguiente;
		cin>>op;
	
	}
	
}


template <typename T>
void Listacirc<T>::eliminar(T val){
	Nodoc<T> * tmp= this-> primero;
	
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
