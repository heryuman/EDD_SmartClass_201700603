#ifndef EERROR_H
#define EERROR_H
#include <string>
using namespace std;
class Error{
	
	private:
		int id;
		string tipo;
		string desc;
		bool corregido=false;
		int numReg;
		
		
	public:
		 Error(int,string,string,int);
		 Error();
		 ~Error();
		 
		 void setId(int);
		 void setTipo(string);
		 void setDesc(string);
		 void setCorregido(bool);
		 
		 int getId();
		 string getTipo();
		 string getDesc();
		 bool  getCorregido();
		 int getNumReg();
		 
};

Error::Error(int _id, string _Tipo, string _Desc,int reg){
	
	
	this->id = _id;
	this->tipo = _Tipo;
	this->desc = _Desc;
	this->numReg = reg;
}

Error::Error(){
	
	
}

Error::~Error(){
	
	
}

void Error::setId( int id){
	
	this->id = id;
}

void Error::setTipo(string tipo){
	
	this->tipo = tipo;
}

void Error::setDesc(string desc){
	
	this->desc = desc;
}
void Error::setCorregido(bool val){

	this->corregido=val;
}

bool Error::getCorregido(){

	return  this->corregido;
}
int Error::getId(){
	
	return this->id;
}

string Error::getTipo(){
	
	
	return this->tipo;
}

string Error::getDesc(){
	
	return this->desc;
}

int Error::getNumReg(){
	
	return this->numReg;
}


#endif
