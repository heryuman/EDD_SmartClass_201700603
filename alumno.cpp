#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>
#include <stdlib.h>
using namespace std;
class Alumno{
	
	private:
		int numRegistro;
		string carnet;
		string dpi;
		string nombre;
		string carrera;
		string correo;
		string password;
		string creditos;
		string edad;
		
	public:
		Alumno(int,string,string,string,string,string,string,string,string);//constructor
		Alumno();
		~Alumno();//Destructor
		
		//setters
		void setCarnet(string);
		void setDpi(string);
		void setNombre(string);
		void setCarrera(string);
		void setCorreo(string);
		void setPass(string);
		void setCredits(string);
		void setEdad(string);
		
		//getters
		
		string getCarnet();
		string getDpi();
		string getNombre();
		string getCarrera();
		string getCorreo();
		string getPassword();
		string getCredits();
		string getEdad();
		int getNumReg();
		
		
	
	
};

//Definiendo el constructor

Alumno::Alumno(int reg,string _carnet,string _dpi, string _nombre, string _carrera, string _correo, string _pass, string _credits, string _edad){
	this->numRegistro = reg;
	this->carnet= _carnet;
	this->dpi = _dpi;
	this->nombre = _nombre;
	this->carrera = _carrera;
	this->correo = _correo;
	this->password = _pass;
	this->creditos = _credits;
	this->edad = _edad;
}
Alumno::Alumno(){
	
	
}

Alumno::~Alumno(){
	
	
}

//Metodos Setters

void Alumno::setCarnet(string _carnet){
	
	this->carnet = _carnet;
}

void Alumno::setDpi(string _cui){
	
	this->dpi= _cui;
}

void Alumno::setNombre(string _nombre){
	
	this->nombre = _nombre;
}

void Alumno::setCarrera(string _carrera){
	
	this->carrera = _carrera;
}

void Alumno::setCorreo(string _correo){
	
	this->correo = _correo;
} 

void Alumno::setPass(string _pass){
	
	this->password = _pass;
}

void Alumno::setCredits(string _credits){
	
	this->creditos = _credits;
}

void Alumno::setEdad(string _edad){
	this->edad = _edad;
}


//	METODOS GETTERS

string Alumno::getCarnet(){
	
	return this->carnet;
}

string Alumno::getDpi(){
	
	return this->dpi;
}

string Alumno::getNombre(){
	
	return this->nombre;
}

string Alumno::getCarrera(){
	
	return this->carrera;
}

string Alumno::getCorreo(){
	
	return this->correo;
	
}

string Alumno::getPassword(){
	
	return this->password;
}

string Alumno::getCredits(){
	
	return this->creditos;
} 

string Alumno::getEdad(){
	
	return this->edad;
}

int Alumno::getNumReg(){
	
	return this->numRegistro;
}

#endif
