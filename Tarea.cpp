#ifndef TAREA_H
#define TAREA_H
#include <string>

using namespace std;
class Tarea{
	
	private:
		int idTarea;
		int carnet;
		int dia=0;
		int mes=0;
		string nombreTarea;
		string descripcion;
		string materia;
		string fecha;
		string hora;
		string estado;
		
	public:
		Tarea(int, int, string,string, string, string, string, string,int,int);//Constructor
		Tarea();
		~Tarea();
		//Seters
		void setId(int);
		void setCarnet(int);
		void setNombreTarea(string);
		void setDescripcion(string);
		void setMateria(string);
		void setFecha(string);
		void setHora(string);
		void setEstado(string);
		
		//Getters
		int gettIdTarea();
		int gettCarnet();
		string gettNombreTarea();
		string gettDesc();
		string gettMateria();
		string gettFecha();
		string gettHora();
		string gettEstado();
		int getDia();
		int getMes();
		
		
	
};

//DEFINIENDO EL CONSTRUCTOR
Tarea::Tarea(int _Id, int _carnet,string _nomTarea, string _desc, string _materia, string _fecha, string _hora, string _estado,int dia,int mes){
	
	this->idTarea = _Id;
	this->carnet = _carnet;
	this->nombreTarea = _nomTarea;
	this->descripcion = _desc;
	this->materia = _materia;
	this->fecha = _fecha;
	this->hora = _hora;
	this->estado = _estado;
	this->dia=dia;
	this->mes=mes;
	
}

Tarea::Tarea(){
	
}
Tarea::~Tarea(){
	
	
}
//METODOS SETTERS

void Tarea::setId(int _id){
	
	this->idTarea = _id;
}

void Tarea::setCarnet(int _carnet){
	
	this->carnet = _carnet;
}

void Tarea::setNombreTarea(string _nombre){
	
	this->nombreTarea = _nombre;
}

void Tarea::setDescripcion(string _desc){
	this->descripcion = _desc;
	
}

void Tarea::setMateria(string _materia){
	
	this->materia = _materia;
}

void Tarea::setFecha(string _fecha){
	
	this->fecha = _fecha;
}

void Tarea::setHora(string _hora){
	
	this->hora = _hora;
}

void Tarea::setEstado(string _estado){
	
	this->estado = _estado;
}

//METODOS GETTERS

int Tarea::gettIdTarea(){
	
	return this->idTarea;
}

int Tarea::gettCarnet(){
	
	return this->carnet;
}

int Tarea::getDia(){
	return this->dia;
}

int Tarea::getMes(){
	return this->mes;
}
string Tarea::gettNombreTarea(){
	
	return this->nombreTarea;
}

string Tarea::gettDesc(){
	
	return this->descripcion;
}

string Tarea::gettMateria(){
	
	return this->materia;
}

string Tarea::gettFecha(){
	
	return this->fecha;
}
string Tarea::gettHora(){
	
	return this->hora;
}
string Tarea::gettEstado(){
	
	return this->estado;
}

#endif
