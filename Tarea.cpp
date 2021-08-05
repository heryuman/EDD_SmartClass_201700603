class Tarea{
	
	private:
		int idTarea;
		int carnet;
		string nombreTarea;
		string descripcion;
		string materia;
		string fecha;
		string hora;
		string estado;
		
	public:
		Tarea(int, int, string,string, string, string, string, string);//Constructor
		
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
		
		
	
};

//DEFINIENDO EL CONSTRUCTOR
Tarea::Tarea(int _Id, int _carnet,string _nomTarea, string _desc, string _materia, string _fecha, string _hora, string _estado){
	
	this->idTarea = _Id;
	this->carnet = _carnet;
	this->nombreTarea = _nomTarea;
	this->descripcion = desc;
	this->materia = _materia;
	this->fecha = _fecha;
	this->hora = hora;
	this->estado = _estado;
	
}

//METODOS SETTERS

Tarea::setId(int _id){
	
	this->idTarea = _id;
}

Tarea::setCarnet(int _carnet){
	
	this->carnet = _carnet;
}

Tarea::setNombreTarea(string _nombre){
	
	this->nombreTarea = _nombre;
}

Tarea::setDescripcion(string _desc){
	this->descripcion = _desc;
	
}

Tarea::setMateria(string _materia){
	
	this->materia = _materia;
}

Tarea::setFecha(string _fecha){
	
	this->fecha = _fecha;
}

Tarea::setHora(string _hora){
	
	this->hora = _hora;
}

Tarea::setEstado(string _estado){
	
	this->estado = _estado;
}

//METODOS GETTERS

int Tarea::gettIdTarea(){
	
	return this->idTarea;
}

int Tarea::gettCarnet(){
	
	return this->carnet;
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

string Tarea::gettEstado(){
	
	return this->estado;
}
