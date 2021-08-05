#include<iostream>
#include "Listacirc.cpp"
#include "Lista.cpp"
#include "alumno.cpp"




using namespace std;

int main(){
	
/*	Listacirc<int> *lst =new Listacirc<int>();
	lst->insertar(1);
	lst->insertar(2);
	lst->insertar(3);
	lst->insertar(4);
	lst->insertar(5);
	lst->insertar(6);
	lst->insertar(7);
	lst->insertar(8);

	
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
	
	*/
	
	Alumno Nalumno = Alumno(201700603,2112217590301,"selvin Hernandez","ingenieria ","charlyyuman@gmail.com","1234tatatan",200,29);
	
	
	cout<<"el  carnet del alumno es: "<<Nalumno.getCarnet()<<endl;
	
	Nalumno.setCarnet(201700628);
	
	cout<<"el cambio de carnet es:"<<Nalumno.getCarnet()<<endl;
	cout<<"el nombre del alumno es: "<<Nalumno.getNombre()<<endl;
	
	system("pause");
	
	
	
	return 0;
	
}


