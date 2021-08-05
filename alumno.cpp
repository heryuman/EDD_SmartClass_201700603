

class Alumno{
	
	private:
		int carnet;
		int dpi;
		string nombre;
		string carrera;
		string correo;
		string password;
		int creditos;
		int edad;
		
	public:
		Alumno(int,int,string,string,string,string,int,int);//constructor
		
		//setters
		void setCarnet(int);
		void setDpi(int);
		void setNombre(string);
		void setCarrera(string);
		void setCorreo(string);
		void setPass(string);
		void setCredits(int);
		void setEdad(int);
		
		//getters
		
		int getCarnet();
		int getDpi();
		string getNombre();
		string getCarrera();
		string getCorreo();
		string getPassword();
		int getCredits();
		int getEdad();
		
		
	
	
};

//Definiendo el constructor

Alumno::Alumno(int _carnet,int _dpi, string _nombre, string _carrera, string _correo, string _pass, int _credits, int _edad){
	
	this->carnet= _carnet;
	this->dpi = _dpi;
	this->nombre = _nombre;
	this->carrera = _carrera;
	this->correo = _correo;
	this->password = _pass;
	this->creditos = _credits;
	this->edad = _edad;
}

//Metodos Setters

void Alumno::setCarnet(int _carnet){
	
	this->carnet = _carnet;
}

void Alumno::setDpi(int _cui){
	
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

void Alumno::setCredits(int _credits){
	
	this->creditos = _credits;
}

void Alumno::setEdad(int _edad){
	this->edad = _edad;
}


//	METODOS GETTERS

int Alumno::getCarnet(){
	
	return this->carnet;
}

int Alumno::getDpi(){
	
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

int Alumno::getCredits(){
	
	return this->creditos;
} 

int Alumno::getEdad(){
	
	return this->edad;
}
