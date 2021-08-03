#include<iostream>
#include "Listacirc.cpp"
#include"Lista.cpp"




using namespace std;

int main(){
	
	Listacirc<int> *lst =new Listacirc<int>();
	lst->insertar(1);
	lst->insertar(2);
	lst->insertar(3);
	lst->insertar(4);
	lst->insertar(5);
	lst->insertar(6);
	lst->insertar(7);
	lst->insertar(8);
/*	lst->imprimir();
	
	lst->eliminar(5);
	
	lst->eliminar(2);
	
	lst->imprimir();*/
	
	lst->printStep();
	
	
	Lista<int> *lst2 =new Lista<int>();
	lst2->insertar(10);
	lst2->insertar(11);
	lst2->insertar(12);
	lst2->insertar(13);
	lst2->insertar(14);
	lst2->insertar(15);
	
	lst2->imprimir();
	
	
	lst2->eliminar(13);
	
	lst2->imprimir();
	
	
	
	system("pause");
	
	
	
	return 0;
	
}


