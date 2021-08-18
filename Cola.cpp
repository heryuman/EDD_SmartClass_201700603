#include<stdlib.h>
#include<iostream>
#include"Nodo.cpp"
#include"Error.cpp"
#ifndef COLA_H
#define	COLA_H
using namespace std;

template <typename T>
class Cola{
	
	
	public:
		int size=0;
		Nodo<T> *primero;
		Nodo<T> *ultimo;
		Cola();
		void enqueue(T *val);
		void dequeue();
		void imprimir();
		int getSize();
		T *getError(int);
		
		
	
};

template <typename T>
Cola<T>::Cola(){
	
	this->primero = NULL;
	this->ultimo =NULL;
}


template <typename T>

void Cola<T>::enqueue(T *val){
	
	Nodo<T> *nuevo = new Nodo<T>(val);
	
	if (this->primero ==NULL){
		
		this->primero = nuevo;
		this->ultimo = nuevo;
		this->size++;
	
	}else{
		
		this->ultimo->siguiente = nuevo;
		this->ultimo = nuevo;
	
		this->size++;
	}
}


template <typename T>
void Cola<T>::dequeue(){
    Nodo<T> * tmp= this->primero;

    this->primero = tmp->siguiente;
    this->size--;
    delete tmp;

}

template <typename T>
T * Cola<T>::getError(int pos){
	
	int iterador=0;
	Nodo<T>  * temp = this->primero;
	
	while (iterador < pos){
		
		
		temp =temp->siguiente;
		
		iterador++;
	}
	
	return temp->getValor();
} 



template <typename T>
void Cola<T>::imprimir(){
	
	Nodo<T> *tmp = this->primero;
	while(tmp != NULL){
		
		cout<<"**********************************************"<<endl;
		cout<<"Id de la tarea:"<<tmp->valor.gettIdTarea()<<endl;
		cout<<"Carnet: "<<tmp->valor.gettCarnet()<<endl;
     	cout<<"Nombre de la tarea: "<<tmp->valor.gettNombreTarea()<<endl;
     	cout<<"Descripcion: "<<tmp->valor.gettDesc()<<endl;
    	cout<<"Materia: "<<tmp->valor.gettMateria()<<endl;
    	cout<<"Fecha: "<<tmp->valor.gettFecha()<<endl;
    	cout<<"Hora: "<<tmp->valor.gettHora()<<endl;
    	cout<<"Estado: "<<tmp->valor.gettEstado()<<endl;
		cout<<"**********************************************"<<endl;
		tmp=tmp->siguiente;
	}
}

template <typename T>
int Cola<T>::getSize(){
	
	return this->size;
}

#endif

