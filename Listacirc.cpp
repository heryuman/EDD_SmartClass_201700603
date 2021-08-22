#ifndef LISTACIRC_H
#define LISTACIRC_H

#include<stdlib.h>
#include<iostream>
#include"Nodo.cpp"
#include "Alumno.cpp"
using namespace std;

template <typename T>
class Listacirc{
	public:
		int size=0;
		Nodo<T> * primero;
		Nodo<T> * ultimo;
		Listacirc();
		void insertar(T *val);
		void imprimir();
		void eliminar(int val);
		void printStep();
		int  getSize();
		T *getObjeto(int pos);
		bool existCarnet(string val);
		bool existDPI(string val);
		
};

template <typename T>

Listacirc<T>::Listacirc(){
	
	this->primero=NULL;
	this->ultimo=NULL;
}


template <typename T>
void Listacirc<T>::insertar(T *val){
	
	Nodo<Alumno> * nuevo = new Nodo<T>(val);
	
	
	if(this->primero==NULL){
		
		this->primero=nuevo;
		this->ultimo=nuevo;
		
		this->size++;
	}else{
		
		this->ultimo->siguiente =nuevo;
		nuevo->anterior = this->ultimo;
		this->ultimo =nuevo;
		nuevo->siguiente= this->primero;
		this->primero->anterior=nuevo;
		this->size++;
	}
}

template <typename T>

void Listacirc<T>::imprimir(){
	
	Nodo<T>  * temp = this->primero;
	
	while (temp !=NULL){
		
		cout<<temp->valor<<endl;
		temp =temp->siguiente;
		
		
	}
	
}



template <typename T>

 T * Listacirc<T>::getObjeto(int pos){
	int iterador=0;
	Nodo<T>  * temp = this->primero;
	
	while (iterador < pos){
		
		
		temp =temp->siguiente;
		
		iterador++;
	}
	
	return temp->getValor();
	
}



template <typename T>

bool Listacirc<T>::existCarnet(string valor){
	int i=0;
	Nodo<T>  * temp = this->primero;
	bool existe=false;
	if(this->size>0){

					while (temp->getValor()->getCarnet()!=valor && i < this->size){
		//cout<<"comparando carnet"<<i<<endl;
								temp=temp->siguiente;
								i++;
								existe=false;
							}

							if(temp->getValor()->getCarnet()==valor){
								existe=true;
							}
	}

	return existe;
	
	
	
  	
}
template <typename T>				   
bool Listacirc<T>::existDPI(string valor){
	int i=0;
	Nodo<T>  * temp = this->primero;
	bool existe=false;
	if(this->size>0){

					while (temp->getValor()->getDpi()!=valor && i < this->size){
		//cout<<"comparando carnet"<<i<<endl;
								temp=temp->siguiente;
								i++;
								existe=false;
							}

							if(temp->getValor()->getDpi()==valor){
								existe=true;
							}
	}

	return existe;
	
	
	
  	
}


template <typename T>
void Listacirc<T>::printStep(){
	
	Nodo<T>  * temp = this->primero;
	
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
void Listacirc<T>::eliminar(int val){
	Nodo<T> * tmp= this-> primero;
	Nodo<T> * tmp2= this->ultimo;
	int i=0;

	while(i<val){
		tmp=tmp->siguiente;
		i++;
	}
	cout<<"indice a eliminar "<<i<<endl;
	//Eliminando enla cabeza
	if(val==0){
		
		this->primero=tmp->siguiente;
		tmp->siguiente->anterior=this->ultimo;
		this->ultimo->siguiente=tmp->siguiente;
		
		tmp->siguiente=NULL;
		tmp->anterior=NULL;
		delete tmp;
		this->size--;
		cout<<"eliminado el primero"<<endl;


	}

	//eliminando en la cola

	else if(val==this->size-1){

		tmp->anterior->siguiente=this->primero;
		this->primero->anterior=tmp->anterior;
		this->ultimo=tmp->anterior;
		tmp->siguiente=NULL;
		tmp->anterior=NULL;
		delete tmp;
		this->size--;
		cout<<"eliminado el ultimo"<<endl;


	}

	//Eliminando en medio:
	else if(tmp->anterior != NULL|| tmp->siguiente!=NULL){

			tmp->anterior->siguiente = tmp->siguiente;
			tmp->siguiente->anterior = tmp->anterior;
			tmp->siguiente=NULL;
			tmp->anterior=NULL;
			delete tmp;
			cout<<"eliinando en medio"<<endl;
			this->size--;
	}

	


}

template <typename T>
int Listacirc<T>::getSize(){
	
	return this->size;
}


#endif