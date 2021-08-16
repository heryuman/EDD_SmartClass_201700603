#include<stdlib.h>
#include<iostream>
#include"Nodo.cpp"
using namespace std;

template <typename T>
class Lista{
	public:
		int size=0;
		Nodo<T> * primero;
		Nodo<T> * ultimo;
		Lista();
		void insertar(T *val);
		void imprimir();
		void eliminar(int val);
		void insertIn(T *val,int pos);
		int getSize();
		T * getObjeto(int pos);
		int getNodeIndex(int pos);
		bool existNode(int pos);
};

template <typename T>

Lista<T>::Lista(){
	
	this->primero=NULL;
	this->ultimo=NULL;
	
}


template <typename T>
void Lista<T>::insertar(T *val){
	
	Nodo<T> * nuevo = new Nodo<T>(val);
	
	
	if(this->primero==NULL){
		
		this->primero=nuevo;
		this->ultimo=nuevo;
		nuevo->anterior=NULL;
		this->size++;
	}else{
		
		this->ultimo->siguiente =nuevo;
		nuevo->anterior = this->ultimo;
		this->ultimo =nuevo;
		this->size++;
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
void Lista<T>::insertIn(T *val, int pos){
	int ite=0;
	Nodo<T> * nuevo = new Nodo<T>(val);
	Nodo<T> *tmp =this->primero;
	
	if(this->primero==NULL){
		cout<<"se agregor primero"<<endl;
		this->primero=nuevo;
		this->ultimo=nuevo;
		nuevo->setIndex(pos);
		this->size++;
	}else{
		
		// se inserta en la primera posicion cuando ya existe un nodo 
		while (tmp->siguiente != NULL)
		{
			if(pos<tmp->getIndex()){

				break;

			}
			tmp=tmp->siguiente;
		
		}

		if(tmp->getIndex()>pos && pos == 0){

			tmp->anterior=nuevo;
			nuevo->siguiente=tmp;
			this->primero=nuevo;
			nuevo->setIndex(pos);
			this->size++;


		}else if(tmp->getIndex()>pos && tmp->anterior!=NULL){


			tmp->anterior->siguiente=nuevo;
			nuevo->anterior=tmp->anterior;
			nuevo->siguiente=tmp;
			tmp->anterior=nuevo;
			nuevo->setIndex(pos);
			this->size++;



			
		}

		else if (tmp->getIndex()<pos){

			tmp->siguiente=nuevo;
			nuevo->anterior=tmp;
			this->ultimo=nuevo;
			nuevo->setIndex(pos);
			this->size++;

		}
		else if (tmp->getIndex()>pos && tmp->anterior ==NULL ){

				tmp->anterior=nuevo;
				nuevo->siguiente=tmp;
				this->primero=nuevo;
				nuevo->setIndex(pos);
				this->size++;
		}

		
	}
}


template <typename T>
void Lista<T>::eliminar(int val){
	Nodo<T> * tmp= this-> primero;
	int i=0;
	if (tmp !=NULL && val>0 && val != (this->size-1)){
		
		while (i<val)
	{
		cout<<"en el while"<<endl;
		tmp=tmp->siguiente;
		i++;
	}
	//elimina en medio
	if(tmp->anterior != NULL|| tmp->siguiente!=NULL){

			tmp->anterior->siguiente = tmp->siguiente;
			tmp->siguiente->anterior = tmp->anterior;
			tmp->siguiente=NULL;
			tmp->anterior=NULL;
			delete tmp;
			this->size--;
	}
	
	}
	
	//eliminando al principio 
	else if (val==0){
			
			this->primero=tmp->siguiente;
			tmp->siguiente->anterior=NULL;
			tmp->siguiente=NULL;
			this->size--;
			delete tmp;
	}

	//eliminando al final
	else if (val==(this->size)-1){
		
		while(tmp->siguiente !=NULL)
	{
		tmp=tmp->siguiente;
		i++;
	}

		this->ultimo=tmp->anterior;
		tmp->anterior->siguiente=NULL;
		tmp->anterior=NULL;
		this->size--;
		delete tmp;

	}

}

template <typename T>
int Lista<T>::getSize(){

	return this->size;

}

template <typename T>
T * Lista<T>::getObjeto(int pos){

	Nodo<T> * tmp= this-> primero;
	if(this->primero != NULL){
		int i=0;
		while (i< pos)
		{
			tmp=tmp->siguiente;
			i++;
		}

	}

	return tmp->getValor();

	
}

template <typename T>
int Lista<T>::getNodeIndex(int pos){

	Nodo<T> * tmp= this-> primero;
	if(this->primero != NULL){
		int i=0;
		while (i< pos)
		{
			tmp=tmp->siguiente;
			i++;
		}

	}

	return tmp->getIndex();

	
}

template <typename T>
bool Lista<T>::existNode(int pos){

	Nodo<T> * tmp= this->primero;
	while (tmp !=NULL)
	{
		if(tmp->getIndex()== pos){

			return true;
			break;
		}else{

			tmp=tmp->siguiente;
		}
	}
	

}
