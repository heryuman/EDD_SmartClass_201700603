#include <iostream>
#include "Listacirc.cpp"
#include "Lista.cpp"
#include "Alumno.cpp"
#include <sstream>
#include <fstream>
#include "Tarea.cpp"
#include "Cola.cpp"
#include "Error.cpp"
#include <stdlib.h>
#include <regex>
#include <conio.h>
#include "Grafo.cpp"
Listacirc<Alumno> *L_alumnos = new  Listacirc<Alumno>();
Cola<Error> *ColaErrores = new Cola<Error>();
Lista<Tarea> *L_Tareas= new Lista<Tarea>();




int idErrores=1;
int idRegistros=1;
int idTarea=1;
using namespace std;


//PROTOTIPO DE FUNCIONES
void menu();
void generarArchivoSalida();
void buscarEnlaLinealizada();
void buscarPosicion();
void graficarEstudiantes();
void graficarTareas();
void graficarErrores();
void colaDeErrores();
void mostrarEstudiante();
void menuReportes();
void mostrarTarea();
void eliminarTArea();
void modificarTarea();
void linealizacion();
void cargaManualTareas();
void cargaManualEstudiante();
void modificarEstudiante();
void cargarAlumno();
void eliminarEstudiante();
void cargarTarea();
void seteando();
void corregirTarea(int registro, int posError);
void corregirAlumno(int registro,int posError);
bool validarMail(const string& mail);
int getHora(int);
int getMes(int);

Tarea  *matrixTarea[9][30][5];
int main(){
	
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/Entrada/Estudiantes.csv
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/Entrada/Estudiantes2.csv
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/Entrada/Tareas.csv
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/Entrada/Tareas2.csv
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/entradascalificacion/salida_tareas.csv
	//C:/Users/ASUS/Documents/ProyectosEDDS2021/entradascalificacion/prueba_estudiantes.csv

	menu();


	return 0;
	
}


void menu(){

	int opcion=0;

	while (opcion !=5){

		cout<<"/*/*/*/*/*/*/*/*/*/* MENU */*/*/*/*/*/*/*/*/*/*/*"<<endl;
		cout<<"/*        1.- Carga de Usuarios                /*"<<endl;
		cout<<"/*	  2.- Carga de Tareas                  /*"<<endl;
		cout<<"/*	  3.- Ingreso manual                   /*"<<endl;
		cout<<"/*	  4.- Reportes                         /*"<<endl;
		cout<<"/*	  5.- Salir                            /*"<<endl;
		cout<<"/*/*/*/*/**/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"<<endl;
		cout<<"Elija una opcion:";cin>>opcion;

		if(opcion== 1){

			cout<<"************** CARGA MASIVA DE USUARIOS **************"<<endl;
			cargarAlumno();
		} 

		else if (opcion == 2){

			cout<<"************** CARGA MASIVA DE TAREAS **************"<<endl;
			cargarTarea();

		}

		else if (opcion == 3){

			int op=0;
			cout<<"************** MENU INGRESO MANUAL **************"<<endl;
			cout<<"**  1.- Estudiante                             **"<<endl;
			cout<<"**  2.- Tarea                                  **"<<endl;
			cout<<"*************************************************"<<endl;
			cout<<endl<<"Elija una opcion: "; cin>>op;

			if (op==1){
				int opUser=0;
				while(opUser!=5){

					cout<<"************** MENU DE USUARIOS **************"<<endl;
					cout<<"** 1. Ingresar                              **"<<endl;
					cout<<"** 2. Modificar                             **"<<endl;
					cout<<"** 3. Eliminar                              **"<<endl;
					cout<<"** 4. Mostrar                               **"<<endl;
					cout<<"** 5. Menu principal                        **"<<endl;
					cout<<"**********************************************"<<endl;

					cout<<"Elija una opcion: "; cin>>opUser;

					if(opUser==1){

						cargaManualEstudiante();

					}
					else if(opUser==2){
						modificarEstudiante();

					}

					else if(opUser==3){

						eliminarEstudiante();
					}
					
					else if(opUser==4){

						mostrarEstudiante();

					}
				}
			
			}

			else if (op==2){
				int opTareas=0;
				while (opTareas != 5)
				{
					cout<<"************** MENU DE TAREAS **************"<<endl;
					cout<<"** 1. Ingresar                            **"<<endl;
					cout<<"** 2. Modificar                           **"<<endl;
					cout<<"** 3. Eliminar                            **"<<endl;
					cout<<"** 4. Mostrar                             **"<<endl;
					cout<<"** 5. Menu principal                      **"<<endl;
					cout<<"********************************************"<<endl;
					cout<<"Elija una opcion: "; cin>>opTareas;

					if(opTareas==1){
					 cargaManualTareas();

					}

					else if(opTareas==2){

						modificarTarea();
					}

					else if(opTareas==3){

						 eliminarTArea();
					}
					else if(opTareas==4){

						mostrarTarea();
					}


				}
				
			}

			else{

				cout<<"Error!, opcion invalida..."<<endl;
			}

		}

		else if(opcion == 4){

			menuReportes();

		}

	}
	
}


void cargarAlumno(){
	string dir;
  	cout<<"Ingrese la  direccion del archivo CSV: ";
  	cin>>dir;
  	cout<<endl;
	ifstream archivo(dir.c_str());
	
    
	string linea;
	char delimitador = ',';
	
	getline(archivo,linea);
	
	while(getline(archivo,linea)){
		
		stringstream stream(linea);
		string carnet,dpi,nombre,carrera,pass,creditos,edad, correo;
		
	
	
		getline(stream,carnet, delimitador);
		getline(stream,dpi,delimitador);
		getline(stream,nombre,delimitador);
		getline(stream,carrera,delimitador);
		getline(stream,pass,delimitador);
		getline(stream,creditos,delimitador);
		getline(stream,edad,delimitador);
		getline(stream,correo,delimitador);
		
		//	cout<<"comparando carnet"<<carnet<<" tamlista; "<<L_alumnos->getSize()<<" existe carnet?: "<<L_alumnos->existCarnet(carnet)<<endl;
		
		if(L_alumnos->existCarnet(carnet)!=true && L_alumnos->existDPI(dpi)!=true){
				//cout<<"comparando carnet"<<carnet<<" tamlista; "<<L_alumnos->getSize()<<" existe carnet?: "<<L_alumnos->existCarnet(carnet)<<endl;
				if (carnet.length()==9 && dpi.length()==13 && validarMail(correo)){
			
		    Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
			idRegistros++;
			L_alumnos->insertar(nAlumno);
			cout<<"carnet: "<<carnet<<"cargado exitosamente"<<endl;
		//	arrayPersona[contador]=nAlumno;
			
			
		}
		
		else{
			
			if(carnet.length()!= 9 && dpi.length()==13 && validarMail(correo)==true){
				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				
				Error *unError = new Error(idErrores,"Estudiante","La cantidad de digitos del Carnet es incorrecta",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				
				idRegistros++;
				idErrores++;
			}
			else if(dpi.length()!=13 && carnet.length()==9 && validarMail(correo)==true){
				
				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				
				Error *unError = new Error(idErrores,"Estudiante","La cantidad de digitos del Cui es incorrecta",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				
				idRegistros++;
				idErrores++;
			}

			else if(validarMail(correo)!= true && dpi.length()==13 && carnet.length()==9){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El formato del correo es incorrecto",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;
			}


			else if (carnet.length()!=9 && dpi.length()!=13 && validarMail(correo)==true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","Elcarnet y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			else if (carnet.length()!=9 && dpi.length()==13 && validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El carnet y correo poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			else if (carnet.length()==9 && dpi.length()!=13 and validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","correo y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			

			else if (carnet.length()!=9 && dpi.length()!=13 && validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El correo,carnet y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(3);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}
			
			
		}

	 }else{

		 cout<<"No se puede cargar porque el carnet ya existe"<<endl;
	 }
	

	}
	
	
	archivo.close();

	

	if(ColaErrores->getSize()>0){
		
		cout<<"Registros cargados con error..."<<endl;
	}else{
	
	
	cout<<"Registros cargados Exitosamente..."<<endl;
	
	}


    
	
	



}


bool validarMail(const string& mail){

	const regex expr("[A-Za-z0-9]+(.[A-Za-z0-9]+)*@[a-zA-Z0-9]+(.[a-zA-Z0-9]+)*(.[A-Za-z]{2,4})");
	
	return regex_match(mail,expr);



}

void cargaManualTareas(){
	string mes, dia, hora, carnet, nombre, descripcion,materia, fecha, estado;

	cout<<"********************* INGRESE LOS DATOS DE LA NUEVA TAREA *********************"<<endl;
	cout<<"Ingrese el mes: "<<endl; 
	cin>>mes;
	cout<<"Ingrese el Dia: "<<endl; 
	cin>>dia;
	cout<<"Ingrese la hora: "<<endl; 
	cin>>hora;
	cout<<"Ingrese el carnet: "<<endl; 
	cin>>carnet;
	cout<<"Ingrese el nombre: "<<endl; 
	cin.ignore();
	getline(cin,nombre);
	cout<<"Ingrese la descripcion :"<<endl; 
	getline(cin,descripcion);
	cout<<"Ingrese la Materia: "<<endl; 
	getline(cin,materia);
	cout<<"Ingrese la fecha: "<<endl; 
	getline(cin,fecha);
	cout<<"Ingrese el Estado:"<<endl; 
	getline(cin,estado);


	string fechaConc;

		if (dia.length()==1 && mes.length()==1){

			fechaConc ="2021/0"+mes+"/0"+dia;
		}
		else if(dia.length()==1 && mes.length()==2){
			fechaConc ="2021/"+mes+"/0"+dia;


		}

		else if(dia.length()==2 && mes.length()==1){
			fechaConc ="2021/0"+mes+"/"+dia;


		}
		else if(dia.length()==2 && mes.length()==2){
			//cout<<"dias y meses con2 digitos"<<endl;
			fechaConc="2021/"+mes+"/"+dia;
		}

		int diaConv= atoi(dia.c_str());// j
		int mesConv= atoi(mes.c_str());//k
		int horaConv= atoi(hora.c_str());//i
		int carnetConv= atoi(carnet.c_str());

		if(diaConv>0 && diaConv<31 && mesConv>6 && mesConv<12 && horaConv>7 && horaConv<17){

					
			int pos2=((((diaConv-1)*9)+getHora(horaConv))*5)+getMes(mesConv);

			if(L_Tareas->existNode(pos2)!=true){

				if ( L_alumnos->existCarnet(carnet)==true){
				//cout<<"existe el carnet: "<<carnet<<endl;
				

						if(fechaConc==fecha){
							fechaConc=dia+"/"+mes+"/2021";
							cout<<"tarea con fecha: "<<fechaConc<<"hora "<<horaConv<<endl;
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							//matrixTarea[getHora(horaConv)][diaConv-1][getMes(mesConv)]=nTarea;

							int pos=((((diaConv-1)*9)+getHora(horaConv))*5)+getMes(mesConv);
							L_Tareas->insertIn(nTarea,pos);

							idTarea++;
							cout<<"Tarea cargada exitosamente..."<<endl;
						}else{
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fecha,hora,estado,diaConv,mesConv);
							int pos=((((diaConv-1)*9)+getHora(horaConv))*5)+getMes(mesConv);
							
							L_Tareas->insertIn(nTarea,pos);

							Error *nError = new Error(idErrores,"Tarea","Error, formato de fecha o fecha incorrecta",idTarea);
							nError->setCorregido(1);//agregamos la cantidad de errores que tiene el registro
							ColaErrores->enqueue(nError);
							idTarea++;
							idErrores++;
							cout<<"tarea cargada con error, formato de fecha o fecha incorrecta"<<endl;
						}
				
			
				}
					else {

					if(fechaConc==fecha){
							fechaConc=dia+"/"+mes+"/2021";
							cout<<"tarea con fecha: "<<fechaConc<<"hora "<<horaConv<<endl;
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							

							int pos=((((diaConv-1)*9)+getHora(horaConv))*5)+getMes(mesConv);
							L_Tareas->insertIn(nTarea,pos);

							Error *nError = new Error(idErrores,"Tarea","Error,  carnet inexistente",idTarea);
							nError->setCorregido(1);
							ColaErrores->enqueue(nError);
							idTarea++;
							idErrores++;
							cout<<"Tarea cargada con error, carnet inexistente"<<endl;
						}else{
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							int pos=((((diaConv-1)*9)+getHora(horaConv))*5)+getMes(mesConv);
							
							L_Tareas->insertIn(nTarea,pos);

							Error *nError = new Error(idErrores,"Tarea","Error, formato de fecha o fecha incorrecta y carnet inexistente",idTarea);
							nError->setCorregido(2);
							ColaErrores->enqueue(nError);
							idTarea++;
							idErrores++;
							cout<<"tarea cargada con error, formato de fecha o fecha incorrecta, y carnet inexistente"<<endl;
						}
				
							
				}

				
			}
			
		else{
				cout<<"No se puede ingresar la tarea porque ya esta  ocupado el espacio"<<endl;

			}

		}else{

			cout<<"no se puede cargar la tarea porque el dia, mes u hora estan fuera de rango, verificar por favor"<<endl;
		}



}

void cargaManualEstudiante(){

	string carnet,dpi,nombre,carrera,correo,pass,creditos,edad;
	cout<<"Ingrese el nombre: "<<endl;
	cin.ignore();
	getline(cin,nombre);
	cout<<"Ingrese el carnet:  "<<endl;
	cin>>carnet;
	cout<<"Ingrese el DPI: "<<endl; 
	cin>>dpi;
	cout<<"Ingrese la carrera: "<<endl; 
	cin.ignore();
	getline(cin,carrera);
	cout<<"Ingrese el correo: "<<endl; 
	cin>>correo;
	cout<<"Ingrese el password: "<<endl; 
	cin>>pass;
	cout<<"Ingrese los creditos: "<<endl; 
	cin>>creditos;
	cout<<"Ingrese la edad: "<<endl; 
	cin>>edad;

		
		if(L_alumnos->existCarnet(carnet)!=true && L_alumnos->existDPI(dpi)!=true){

			if (carnet.length()==9 && dpi.length()==13 && validarMail(correo)){
			
		    Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
			idRegistros++;
			L_alumnos->insertar(nAlumno);
		//	arrayPersona[contador]=nAlumno;
			
			
		}else{
			
			if(carnet.length()!= 9 && dpi.length()==13 && validarMail(correo)==true){
				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				
				Error *unError = new Error(idErrores,"Estudiante","La cantidad de digitos del Carnet es incorrecta",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				
				idRegistros++;
				idErrores++;
			}
			else if(dpi.length()!=13 && carnet.length()==9 && validarMail(correo)==true){
				
				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				
				Error *unError = new Error(idErrores,"Estudiante","La cantidad de digitos del Cui es incorrecta",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				
				idRegistros++;
				idErrores++;
			}

			else if(validarMail(correo)!= true && dpi.length()==13 && carnet.length()==9){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El formato del correo es incorrecto",idRegistros);
				unError->setCorregido(1);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;
			}


			else if (carnet.length()!=9 && dpi.length()!=13 && validarMail(correo)==true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","Elcarnet y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			else if (carnet.length()!=9 && dpi.length()==13 && validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El carnet y correo poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			else if (carnet.length()==9 && dpi.length()!=13 and validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","correo y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(2);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}


			

			else if (carnet.length()!=9 && dpi.length()!=13 && validarMail(correo)!=true){

				Alumno *nAlumno = new Alumno(idRegistros,carnet,dpi,nombre,carrera,correo,pass,creditos,edad);
				L_alumnos->insertar(nAlumno);
				Error *unError = new Error(idErrores,"Estudiante","El correo,carnet y dpi poseen valores incorrectos",idRegistros);
				unError->setCorregido(3);
				ColaErrores->enqueue(unError);
				idRegistros++;
				idErrores++;


			}
			
			
		}
		}else{

			cout<<"NO se puede agregar porque el dpi o Carnet se repiten"<<endl;
		}

}

void modificarEstudiante(){

    string dpi;
	cout<<"Ingrese el dpi del Estudiante a modificar: ";cin>>dpi;
	for(int i= 0; i< L_alumnos->getSize();i++){

		if (L_alumnos->getObjeto(i)->getDpi()== dpi)
		{		
			int op=0;

			
				while(op!=9){

					cout<<"<<<<<< ELIJA EL ATRIBUTO A MODIFICAR >>>>>>"<<endl;
					cout<<"<< 1.- Nombre                             >>"<<endl;
					cout<<"<< 2.- Carnet                             >>"<<endl;
					cout<<"<< 3.- DPI                                >>"<<endl;
					cout<<"<< 4.- Carrera                            >>"<<endl;
					cout<<"<< 5.- correo                             >>"<<endl;
					cout<<"<< 6.- password                           >>"<<endl;
					cout<<"<< 7.- creditos                           >>"<<endl;
					cout<<"<< 8.- Edad                               >>"<<endl;
					cout<<"<< 9.- Salir                              >>"<<endl;
					cout<<"<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
					cin>>op;
					string modificador;

					if(op==1){
						cout<<"Nombre Actual: "<<L_alumnos->getObjeto(i)->getNombre()<<endl;
						cout<<"Nuevo Nombre: "; 
						cin.ignore();
						getline(cin,modificador);
						L_alumnos->getObjeto(i)->setNombre(modificador);
						cout<<"Nombre modificado correctamente..."<<endl;

					}

					else if(op==2){
						cout<<"Carnet actual: "<<L_alumnos->getObjeto(i)->getCarnet()<<endl;
						cout<<"Nuevo carnet: ";cin>>modificador;

						if(modificador.length()==9){

								L_alumnos->getObjeto(i)->setCarnet(modificador);
							cout<<"Carnet modificado correctamente..."<<endl;

						}else{

							cout<<"Cantidad de digitos en el carnet incorrectos"<<endl;
						}
					
					}
					else if(op==3){
						cout<<"DPI actual: "<<L_alumnos->getObjeto(i)->getDpi()<<endl;
						cout<<"Nuevo DPI: ";cin>>modificador;
						if(modificador.length()==13){

							L_alumnos->getObjeto(i)->setDpi(modificador);
							cout<<"DPI modificado correctamente..."<<endl;

						}else{

							cout<<"Error, cantidad de digitos en el dpi incorrectos"<<endl;
						}

					}

					else if(op==4){
						cout<<"Carrera actual: "<<L_alumnos->getObjeto(i)->getCarrera()<<endl;
						cout<<"Nueva Carrera: ";
						cin.ignore();
						getline(cin,modificador);
						L_alumnos->getObjeto(i)->setCarrera(modificador);
						cout<<"Carrera modificada correctamente..."<<endl;


					}

					else if(op==5){
						cout<<"Correo Actual: "<<L_alumnos->getObjeto(i)->getCorreo()<<endl;
						cout<<"Nuevo correo: ";cin>>modificador;
						if(validarMail(modificador)){

								L_alumnos->getObjeto(i)->setCorreo(modificador);
								cout<<"Correo modificado correctamente..."<<endl;
						}else{

							cout<<"Error, correo no valido"<<endl;
						}
					

					}

					else if(op==6){
						cout<<"Password: "<<L_alumnos->getObjeto(i)->getPassword()<<endl;
						cout<<"Nuevo password: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setPass(modificador);
						cout<<"contraseña modificada correctamente"<<endl;

					
					}

					else if (op==7){
						cout<<"Creditos actuales: "<<L_alumnos->getObjeto(i)->getCredits()<<endl;
						cout<<"Nuevos Creditos: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setCredits(modificador);
						cout<<"Creditos modificados correctamente"<<endl;

					}

					else if(op==8){
						cout<<"Edad actual: "<<L_alumnos->getObjeto(i)->getEdad()<<endl;
						cout<<"Nueva edad: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setEdad(modificador);
						cout<<"Edad modificada correctamente"<<endl;


					}

				}
		}
		
		
	}
}
void eliminarEstudiante(){
string dpi;
cout<<"Ingrese el DPI del estudiante a eliminar: "; cin>>dpi;
for (int i=0 ; i<L_alumnos->getSize();i++){

	if(L_alumnos->getObjeto(i)->getDpi()==dpi)
	{
		string val;
		cout<<"prsion Y si eestá seguro de eliminar el dpi: "<<dpi<<" "; cin>>val;
		if(val=="Y"|| val=="y"){

			L_alumnos->eliminar(i);
			cout<<"Registro eliminado con exito..."<<endl;
		}

	}else{

		if(i==L_alumnos->getSize()-1){

			cout<<"No existe ninguna coincidencia con el dpi: "<<dpi<<endl;

		}
	}
}
cout<<"nueva lista de alumnos:"<<endl;
for (int i=0 ; i<L_alumnos->getSize();i++){

	cout<<"id: "<<L_alumnos->getObjeto(i)->getNumReg()<<endl;
	}
	


}
void cargarTarea(){
	
	string dir;
	cout<<"Ingrese la  direccion del archivo CSV: ";
  	cin>>dir;
  //	cout<<"la dir es:"<<dir<<endl;
	ifstream archivo(dir.c_str());
	

	string linea;
	char delimitador = ',';
	
	getline(archivo,linea);
	//cout<<"llego abajo del 1er getline"<<endl;
	while(getline(archivo,linea)){
		
		string mes, dia, hora, carnet, nombre, descripcion,materia, fecha, estado;
		stringstream stream(linea);
		
		getline(stream, mes,delimitador);
		getline(stream,dia,delimitador);
		getline(stream,hora,delimitador);
		getline(stream,carnet,delimitador);
		getline(stream,nombre,delimitador);
		getline(stream,descripcion,delimitador);
		getline(stream,materia,delimitador);
		getline(stream,fecha,delimitador);
		getline(stream,estado,delimitador);
		
		cout<<"llego abajo de los getline"<<endl;
		string fechaConc;

		if (dia.length()==1 && mes.length()==1){

			fechaConc ="2021/0"+mes+"/0"+dia;
		}
		else if(dia.length()==1 && mes.length()==2){
			fechaConc ="2021/"+mes+"/0"+dia;


		}

		else if(dia.length()==2 && mes.length()==1){
			fechaConc ="2021/0"+mes+"/"+dia;


		}
		else if(dia.length()==2 && mes.length()==2){
			//cout<<"dias y meses con2 digitos"<<endl;
			fechaConc="2021/"+mes+"/"+dia;
		}

		int diaConv= atoi(dia.c_str());
		int mesConv= atoi(mes.c_str());
		int horaConv= atoi(hora.c_str());
		int carnetConv= atoi(carnet.c_str());

	
	

				if ( L_alumnos->existCarnet(carnet)==true ){
				//cout<<"existe el carnet: "<<carnet<<endl;
				

						if(fechaConc==fecha){
							cout<<"tarea con fecha: "<<fechaConc<<" hora "<<horaConv<<endl;
							fechaConc= dia+"/"+mes+"/2021";
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							matrixTarea[getHora(horaConv)][diaConv-1][getMes(mesConv)]=nTarea;
							idTarea++;
							cout<<"Tarea cargada exitosamente..."<<endl;
						}else{
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							matrixTarea[getHora(horaConv)][diaConv-1][getMes(mesConv)]=nTarea;
							Error *nError = new Error(idErrores,"Tarea","Error, formato de fecha o fecha incorrecta",idTarea);
							nError->setCorregido(1);//ingresamos el numero de erroes que posee el registro
							ColaErrores->enqueue(nError);
							idTarea++;
							idErrores++;
							cout<<"tarea cargada con error, formato de fecha o fecha incorrecta"<<endl;

						}
				
			
			}
			else if(L_alumnos->existCarnet(carnet)==false){
						
						

					if(fechaConc==fecha){
							cout<<"tarea con fecha: "<<fechaConc<<" hora "<<horaConv<<endl;
							fechaConc= dia+"/"+mes+"/2021";
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fechaConc,hora,estado,diaConv,mesConv);
							matrixTarea[getHora(horaConv)][diaConv-1][getMes(mesConv)]=nTarea;
							Error *nError = new Error(idErrores,"Tarea","Error, Carnet inexistente",idTarea);
							nError->setCorregido(1);
							ColaErrores->enqueue(nError);
							idErrores++;
							idTarea++;
							cout<<"Tarea cargada con error, carnet inexistente."<<endl;
						}else{
							Tarea *nTarea = new Tarea(idTarea,carnetConv,nombre,descripcion,materia,fecha,hora,estado,diaConv,mesConv);
							matrixTarea[getHora(horaConv)][diaConv-1][getMes(mesConv)]=nTarea;
							Error *nError = new Error(idErrores,"Tarea","Error, formato de fecha o fecha incorrecta y carnet inexistente",idTarea);
							nError->setCorregido(2);
							ColaErrores->enqueue(nError);
							idTarea++;
							idErrores++;
							cout<<"tarea cargada con error, formato de fecha o fecha incorrecta y carnet inexistente"<<endl;
						}
						

						
						

						}
			
		
	
	
	}
	
	archivo.close();
	linealizacion();

	
	
	
	
	
}

void modificarTarea(){
	int index;

	cout<<"Ingrese el indice de la tarea a modificar:"<<endl;
	cin>>index;
	for (int i = 0; i < L_Tareas->getSize(); i++)
	{
		if(L_Tareas->getNodeIndex(i)==index){

			int op=0;
			while(op!=8){

				
					cout<<"<<<<<< ELIJA EL ATRIBUTO A MODIFICAR >>>>>>>"<<endl;
					cout<<"<< 1.- Carnet                             >>"<<endl;
					cout<<"<< 2.- Nombre                             >>"<<endl;
					cout<<"<< 3.- Descripcion                        >>"<<endl;
					cout<<"<< 4.- materia                            >>"<<endl;
					cout<<"<< 5.- fecha                              >>"<<endl;
					cout<<"<< 6.- hora                               >>"<<endl;
					cout<<"<< 7.- Estado                             >>"<<endl;
					cout<<"<< 8.- Salir                              >>"<<endl;
					cout<<"<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
					cin>>op;
					string modificador;


					if(op==1){
						cout<<"Carnet actual: "<<L_Tareas->getObjeto(i)->gettCarnet()<<endl;
						cout<<"Nuevo Carnet:"<<endl;
						cin>>modificador;
						if(L_alumnos->existCarnet(modificador) && modificador.length()==9){

								

							L_Tareas->getObjeto(i)->setCarnet(atoi(modificador.c_str()));
							cout<<"Carnet modificado con extito..."<<endl;
						


						}else{

							cout<<"El carnet ingresado no existe en la lista de alumnos o su longitud es incorrecta"<<endl;
						}
					

					}

					else if(op==2){
						cout<<"Nombre actual: "<<L_Tareas->getObjeto(i)->gettNombreTarea()<<endl;
						cout<<"Nuevo Nombre: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setNombreTarea(modificador);
						cout<<"Nombre modificado con extito..."<<endl;

					}

					else if(op==3){
						cout<<"Descripcion actual: "<<L_Tareas->getObjeto(i)->gettDesc()<<endl;
						cout<<"Nueva descripcion: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setDescripcion(modificador);
						cout<<"Descripcion modificada con extito..."<<endl;
					}

					else if(op==4){
						cout<<"Materia actual: "<<L_Tareas->getObjeto(i)->gettMateria()<<endl;
						cout<<"Nueva Materia: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setMateria(modificador);
						cout<<"Materia modificada con extito..."<<endl;
						
						
					}

					else if(op==5){
						cout<<"La fecha actual: "<< L_Tareas->getObjeto(i)->gettFecha()<<endl;
						int mes,dia=0;
						cout<<"Nueva Fecha "<<endl;
						cout<<"ingrese el dia"<<endl;
						cin>>dia;
						cout<<"ingrese el mes: "<<endl;
						cin>>mes;

						if(dia>0 && dia<31 && mes>6 &&mes<12 && L_Tareas->getObjeto(i)->getDia()==dia && L_Tareas->getObjeto(i)->getMes()==mes){

										string diaTostring = to_string(dia);
										string mesTostring= to_string(mes);
										 if(diaTostring.length()<2){

											 diaTostring="0"+diaTostring;

										 }

										 else if(mesTostring.length()<2){
											 mesTostring="0"+mesTostring;
										 }
										 modificador=diaTostring+"/"+mesTostring+"/2021";

										L_Tareas->getObjeto(i)->setFecha(modificador);
										
										cout<<"Fecha modificada con extito..."<<endl;
										
						}else{
							cout<<"Rango de fecha invalida"<<endl;
						}
						
					}

					else if(op==6){
						cout<<"Hora actual: "<<	L_Tareas->getObjeto(i)->gettHora()<<endl;
						cout<<"Nueva hora: "<<endl;
						cin>>modificador;
						L_Tareas->getObjeto(i)->setHora(modificador);
						cout<<"Hora modificada con extito..."<<endl;
					}

					else if(op==7){
						cout<<"Estado actual: "<<	L_Tareas->getObjeto(i)->gettEstado()<<endl;
						cout<<"Nuevo Estado: "<<endl;
						cin>>modificador;
						L_Tareas->getObjeto(i)->setEstado(modificador);
						cout<<"Estado modificada con extito..."<<endl;
						
					}
			}


		}
	}
	
}
void eliminarTArea(){

	int index;
	cout<<"Ingrese el indice de la tarea a elimnar: "<<endl;
	cin>>index;

	for (int i = 0; i < L_Tareas->getSize(); i++)
	{
		if(L_Tareas->getNodeIndex(i)==index){
			string ops;
			cout<<"presione Y si esta seguro de eliminar la tarea: "<<index<<endl;
			cin>>ops;
			if(ops=="Y"||ops=="y"){

				L_Tareas->eliminar(i);
				cout<<"Tarea eliminada con exito..."<<endl;

			}


		}
	}
	

}
//los metodos getHora y getMes devuelven una posicon en la lista de horas y meses validos
int getHora(int hora){

	int horas[]={8,9,10,11,12,13,14,15,16};
	for(int i= 0; i<9;i++){

		if(horas[i]==hora){

			return i;
		}
	}
}

int getMes(int mes){

	int meses[]={7,8,9,10,11};
	for (int i =0; i<5; i++){

		if(meses[i]==mes){

			return i;
		}
	}
}

void linealizacion(){


		for(int i=0; i<5;i++){

		for(int j=0; j<9;j++){

			for(int k=0; k<30;k++){

				if(matrixTarea[j][k][i]==NULL){

					Tarea *nullTarea= new Tarea(-1,-1,"-1","-1","-1","-1","-1","-1",-1,-1);
					matrixTarea[j][k][i]=nullTarea;
					cout<<" -1 ";

				}
				else{
					cout<<"|"<<matrixTarea[j][k][i]->gettHora()<<"|";
				}
			}
			cout<<endl;

		}cout<<"***************************************"<<endl;
	}

	cout<<"recorriento matrix[i][j][k]"<<endl;
	for(int i=0; i<9;i++){

			for (int j = 0; j < 30; j++)
			{
				for (int k = 0; k < 5; k++)
				{
				
					if( matrixTarea[i][j][k]->gettCarnet()!= -1){

						//	cout<<"pos["<<i<<"]["<<j<<"]["<<k<<"] "<<matrixTarea[i][j][k]->gettHora()<<" id: "<<matrixTarea[i][j][k]->gettIdTarea()<<"Pos lineal: "<<((((j*9)+i)*5)+k)<<endl;
						int posi=((((j*9)+i)*5)+k);
						L_Tareas->insertIn(matrixTarea[i][j][k],posi);
					


					}
					
				}
				
			}
			


	}

	cout<<"linealizacion exitosa!..."<<endl;

	for (int i = 0; i < L_Tareas->getSize(); i++)
	{
		if(L_Tareas->getObjeto(i)->gettCarnet()!=-1){

			cout<<"linealizado: "<<L_Tareas->getObjeto(i)->gettIdTarea()<<" posLineal: "<<L_Tareas->getNodeIndex(i)<<endl;
		}
	}
	



}
	
void mostrarEstudiante(){

	if(L_alumnos->getSize()>0){

		cout<<"*/*/*/*/*/*/ LISTA DE ESTUDIANTES */*/*/*/*/*/*/*/*"<<endl;
	for (int i = 0; i < L_alumnos->getSize(); i++){
		cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<["<<i+1<<"]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<"Carnet:"<<L_alumnos->getObjeto(i)->getCarnet()<<endl;
		cout<<"Dpi: "<<L_alumnos->getObjeto(i)->getDpi()<<endl;
		cout<<"Nombre: "<<L_alumnos->getObjeto(i)->getNombre()<<endl;
		cout<<"Carrera: "<<L_alumnos->getObjeto(i)->getCarrera()<<endl;
		cout<<"Correo: "<<L_alumnos->getObjeto(i)->getCorreo()<<endl;
		cout<<"Password: "<<L_alumnos->getObjeto(i)->getPassword()<<endl;
		cout<<"creditos: "<<L_alumnos->getObjeto(i)->getCredits()<<endl;
		cout<<"Edad: "<<L_alumnos->getObjeto(i)->getEdad()<<endl;
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
		
	}
	cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"<<endl;
	

	}else{

		cout<<"No se han cargado estudiantes..."<<endl;
	}
}

void mostrarTarea(){

	if(L_Tareas->getSize()>0){

		cout<<"*/*/*/*/*/*/*/*/*/* LISTA DE TAREAS /*/*/*/*/*/*/*/*/*/*/*/"<<endl;
	for (int i = 0; i < L_Tareas->getSize(); i++)
	{
		cout<<">>>>>>>>>>>>>>>>>>>>>>["<<i+1<<"]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
		cout<<"Id Tarea: "<<L_Tareas->getObjeto(i)->gettIdTarea()<<endl;
		cout<<"carnet: "<<L_Tareas->getObjeto(i)->gettCarnet()<<endl;
		cout<<"Nombre: "<<L_Tareas->getObjeto(i)->gettNombreTarea()<<endl;
		cout<<"Materia: "<<L_Tareas->getObjeto(i)->gettMateria()<<endl;
		cout<<"Descripcion: "<<L_Tareas->getObjeto(i)->gettDesc()<<endl;
		cout<<"fecha: "<<L_Tareas->getObjeto(i)->gettFecha()<<endl;
		cout<<"Hora: "<<L_Tareas->getObjeto(i)->gettHora()<<endl;
		cout<<"Estado: "<<L_Tareas->getObjeto(i)->gettEstado()<<endl;
		cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	}

	cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;

	}else{

		cout<<"NO se han cargado Tareas.."<<endl;
	}
	
}
//SECCION DE REPORTES

void menuReportes(){

	int op=0;
	while (op!=7){

		
	cout<<"/*/*/*/*/*/*/* SECCION DE REPORTES/*/*/*/*/*/*/*/*"<<endl;
	cout<<"/* 1.- Graficar Estudiantes                     /*"<<endl;
	cout<<"/* 2.- Graficar Lista de tareas                 /*"<<endl;
	cout<<"/* 3.- Busqueda en lista linealizada            /*"<<endl;
	cout<<"/* 4.- Busqueda por posicion en lista de Tareas /*"<<endl;
	cout<<"/* 5.- Cola de Errores                          /*"<<endl;
	cout<<"/* 6.- Codigo generado de salid                 /*"<<endl;
	cout<<"/* 7.- Salir al menu principal                  /*"<<endl;
	cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"<<endl;
	cout<<"Elija una opcion: ";cin>>op;

	if(op==1){

			if(L_alumnos->getSize()>0){
				graficarEstudiantes();
			}else{
				cout<<"No existen estudiantes en la lista"<<endl;
			}
	}

	else if(op==2){

		if(L_Tareas->getSize()>0){

			graficarTareas();

		}else{
			cout<<"No existen Tareas en la lista"<<endl;
		}

	}

	else if(op==3){
	
		buscarEnlaLinealizada();
		
	}

	else if(op==4){
		buscarPosicion();
	}

	else if(op==5){
		colaDeErrores();
	}

	else if(op==6){

		 generarArchivoSalida();
		
	}


		
	}
	


}

void colaDeErrores(){

	int op=0;
	while (op!=3)
	{
		cout<<" /*/*/*/* OPCIONES DE LA COLA DE ERRORES */*/*/*/"<<endl;
		cout<<"/* 1.- Mostrar los Errores y generar pdf       */"<<endl;
		cout<<"/* 2.- Corregir los errores                     */"<<endl;
		cout<<"/* 3.- Salir                                    */"<<endl;
		cout<<" /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"<<endl;
		cin>>op;
		if(op==1){

			if(ColaErrores->getSize()>0){

						cout<<"*/*/* COLA DE ERRORES /*/*/"<<endl;
						for (int i = 0; i < ColaErrores->getSize(); i++)
						{		cout<<"<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>"<<endl;
								cout<<"id del error: "<<ColaErrores->getError(i)->getId()<<endl;
								cout<<"Tipo de error: "<<ColaErrores->getError(i)->getTipo()<<endl;
								cout<<"Descripcion: "<<ColaErrores->getError(i)->getDesc()<<endl;
								cout<<"Id del Registro con error:"<<ColaErrores->getError(i)->getNumReg()<<endl;
								cout<<"Cantidad de errores en el registro: "<<ColaErrores->getError(i)->getCorregido()<<endl;
								cout<<"<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>"<<endl;
						}
						graficarErrores();

			}else{

				cout<<"No hay errores en la cola!"<<endl;

			}
		
		}

		else if(op==2){

			for (int i = 0; i < ColaErrores->getSize(); i++)
			{
				if(ColaErrores->getError(i)->getCorregido() != 0){
					
					string ops;
					cout<<"id del error: "<<ColaErrores->getError(i)->getId()<<endl;
					cout<<"Tipo de error: "<<ColaErrores->getError(i)->getTipo()<<endl;
					cout<<"Descripcion: "<<ColaErrores->getError(i)->getDesc()<<endl;
					cout<<"Id del Registro con error:"<<ColaErrores->getError(i)->getNumReg()<<endl;
					cout<<"Desea corregirlo? presione Y,o N para continuar: "<<endl;
					cin>>ops;



					if(ops=="y"||ops=="Y"){

						if(ColaErrores->getError(i)->getTipo()=="Estudiante"){

							 corregirAlumno(ColaErrores->getError(i)->getNumReg(),i);
							

						}
						else if(ColaErrores->getError(i)->getTipo()=="Tarea"){
							 corregirTarea(ColaErrores->getError(i)->getNumReg(),i);
							
						}

					}



				}

			



			}	
			
		}


		}
	
	}
	

void corregirAlumno(int registro, int  posError){
	int cantErrores=ColaErrores->getError(posError)->getCorregido();
	cout<<"Registro a modificar: "<<registro<<endl;
	for(int i= 0; i< L_alumnos->getSize();i++){

		if (L_alumnos->getObjeto(i)->getNumReg()== registro)
		{		
			int op=0;

			
				while(cantErrores!=0){

					cout<<"<<<<<< ELIJA EL ATRIBUTO A MODIFICAR >>>>>>"<<endl;
					cout<<"<< 1.- Nombre                             >>"<<endl;
					cout<<"<< 2.- Carnet                             >>"<<endl;
					cout<<"<< 3.- DPI                                >>"<<endl;
					cout<<"<< 4.- Carrera                            >>"<<endl;
					cout<<"<< 5.- correo                             >>"<<endl;
					cout<<"<< 6.- password                           >>"<<endl;
					cout<<"<< 7.- creditos                           >>"<<endl;
					cout<<"<< 8.- Edad                               >>"<<endl;
					cout<<"<< 9.- Salir                              >>"<<endl;
					cout<<"<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
					cin>>op;
					string modificador;

					if(op==1){
						cout<<"Nombre acual: "<<L_alumnos->getObjeto(i)->getNombre()<<endl;
						cout<<"Nuevo Nombre: "; 
						cin.ignore();
						getline(cin,modificador);
						L_alumnos->getObjeto(i)->setNombre(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						
						cout<<"Nombre modificado correctamente..."<<endl;
						cantErrores--;
						cout<<"Errores en el registro: "<<cantErrores<<endl;

					}

					else if(op==2){
						cout<<"Carnet actual: "<<L_alumnos->getObjeto(i)->getCarnet()<<endl;
						cout<<"Nuevo carnet: ";cin>>modificador;

						if(modificador.length()==9){

								L_alumnos->getObjeto(i)->setCarnet(modificador);
								ColaErrores->getError(posError)->setCorregido(cantErrores-1);
								cout<<"Carnet modificado correctamente..."<<endl;
								cantErrores--;
							cout<<"Errores en el registro: "<<cantErrores<<endl;

						}else{

							cout<<"Cantidad de digitos en el carnet incorrectos"<<endl;
						}
					
					}
					else if(op==3){
						cout<<"DPI actual: "<<L_alumnos->getObjeto(i)->getDpi()<<endl;
						cout<<"Nuevo DPI: ";cin>>modificador;
						if(modificador.length()==13){

							L_alumnos->getObjeto(i)->setDpi(modificador);
							ColaErrores->getError(posError)->setCorregido(cantErrores-1);
							cout<<"DPI modificado correctamente..."<<endl;
							cantErrores--;
							cout<<"Errores en el registro: "<<cantErrores<<endl;

						}else{

							cout<<"Error, cantidad de digitos en el dpi incorrectos"<<endl;
						}

					}

					else if(op==4){
						cout<<"Carrera actual: "<<L_alumnos->getObjeto(i)->getCarrera()<<endl;
						cout<<"Nueva Carrera: ";
						cin.ignore();
						getline(cin,modificador);
						L_alumnos->getObjeto(i)->setCarrera(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cantErrores--;
						cout<<"Errores en el registro: "<<cantErrores<<endl;
						cout<<"Carrera modificada correctamente..."<<endl;


					}

					else if(op==5){
						cout<<"Correo actual: "<<L_alumnos->getObjeto(i)->getCorreo()<<endl;
						cout<<"Nuevo correo: ";cin>>modificador;
						if(validarMail(modificador)){

								L_alumnos->getObjeto(i)->setCorreo(modificador);
								ColaErrores->getError(posError)->setCorregido(cantErrores-1);
								cout<<"Correo modificado correctamente..."<<endl;
								cantErrores--;
								cout<<"Errores en el registro: "<<cantErrores<<endl;
						}else{

							cout<<"Error, correo no valido"<<endl;
						}
					

					}

					else if(op==6){
						cout<<"Password actual: "<<L_alumnos->getObjeto(i)->getPassword()<<endl;
						cout<<"Nuevo password: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setPass(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cout<<"contraseña modificada correctamente"<<endl;
						cantErrores--;
						cout<<"Errores en el registro: "<<cantErrores<<endl;

					
					}

					else if (op==7){
						cout<<"Creditos actual: "<<L_alumnos->getObjeto(i)->getCredits()<<endl;
						cout<<"Nuevos Creditos: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setCredits(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cout<<"Creditos modificados correctamente"<<endl;
						cantErrores--;
						cout<<"Errores en el registro: "<<cantErrores<<endl;

					}

					else if(op==8){
						cout<<"Edad actual: "<<L_alumnos->getObjeto(i)->getEdad()<<endl;
						cout<<"Nueva edad: "; cin>>modificador;
						L_alumnos->getObjeto(i)->setEdad(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cout<<"Edad modificada correctamente"<<endl;
						cantErrores--;
						cout<<"Errores en el registro: "<<cantErrores<<endl;


					}

				}
		}
		
		
	}
}

void corregirTarea(int registro,int posError){
int cantErrores = ColaErrores->getError(posError)->getCorregido();
cout<<"Registro a modificar:"<<registro<<endl;
	
	for (int i = 0; i < L_Tareas->getSize(); i++)
	{
		if(L_Tareas->getObjeto(i)->gettIdTarea()==registro){

			int op=0;
			while(cantErrores!=0){

				
					cout<<"<<<<<< ELIJA EL ATRIBUTO A MODIFICAR >>>>>>>"<<endl;
					cout<<"<< 1.- Carnet                             >>"<<endl;
					cout<<"<< 2.- Nombre                             >>"<<endl;
					cout<<"<< 3.- Descripcion                        >>"<<endl;
					cout<<"<< 4.- materia                            >>"<<endl;
					cout<<"<< 5.- fecha                              >>"<<endl;
					cout<<"<< 6.- hora                               >>"<<endl;
					cout<<"<< 7.- Estado                             >>"<<endl;
					cout<<"<< 8.- Salir                              >>"<<endl;
					cout<<"<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
					cin>>op;
					string modificador;


					if(op==1){
						cout<<"Carnet Actual: "<<L_Tareas->getObjeto(i)->gettCarnet()<<endl;
						cout<<"Nuevo Carnet:"<<endl;
						cin>>modificador;
						if(modificador.length()==9 && L_alumnos->existCarnet(modificador)){

							L_Tareas->getObjeto(i)->setCarnet(atoi(modificador.c_str()));
							ColaErrores->getError(posError)->setCorregido(cantErrores-1);
							cout<<"Carnet modificado con extito..."<<endl;
							cantErrores--;
						}else{
							cout<<"El carnet no existe o su longitud es incorrecta"<<endl;
						}
					

					}

					else if(op==2){
						cout<<"Nombre actual: "<<L_Tareas->getObjeto(i)->gettNombreTarea()<<endl;
						cout<<"Nuevo Nombre: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setNombreTarea(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cantErrores--;
						cout<<"Nombre modificado con extito..."<<endl;

					}

					else if(op==3){
						cout<<"Descripcion actual: "<<L_Tareas->getObjeto(i)->gettDesc()<<endl;
						cout<<"Nueva descripcion: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setDescripcion(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cantErrores--;
						cout<<"Descripcion modificada con extito..."<<endl;
					}

					else if(op==4){
						cout<<"Materia actual: "<<L_Tareas->getObjeto(i)->gettMateria()<<endl;
						cout<<"Nueva Materia: "<<endl;
						cin.ignore();
						getline(cin,modificador);
						L_Tareas->getObjeto(i)->setMateria(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cantErrores--;
						cout<<"Materia modificada con extito..."<<endl;
						
						
					}

					else if(op==5){
						cout<<"los datos en el registro son, dia: "<< L_Tareas->getObjeto(i)->getDia()<<" mes: "<< L_Tareas->getObjeto(i)->getMes()<<endl;
						int mes,dia=0;
						cout<<"Nueva Fecha "<<endl;
						cout<<"ingrese el dia"<<endl;
						cin>>dia;
						cout<<"ingrese el mes: "<<endl;
						cin>>mes;

						if(dia>0 && dia<31 && mes>6 &&mes<12 && L_Tareas->getObjeto(i)->getDia()==dia && L_Tareas->getObjeto(i)->getMes()==mes){

										string diaTostring = to_string(dia);
										string mesTostring= to_string(mes);
										 if(diaTostring.length()<2){

											 diaTostring="0"+diaTostring;

										 }

										 else if(mesTostring.length()<2){
											 mesTostring="0"+mesTostring;
										 }
										 modificador=diaTostring+"/"+mesTostring+"/2021";

										L_Tareas->getObjeto(i)->setFecha(modificador);
										ColaErrores->getError(posError)->setCorregido(cantErrores-1);
										cout<<"Fecha modificada con extito..."<<endl;
										cantErrores--;
						}else{
							cout<<"Rango de fecha invalida"<<endl;
						}
						
					}

					else if(op==6){
						cout<<"Hora actual "<<L_Tareas->getObjeto(i)->gettHora()<<endl;
						cout<<"Nueva hora: "<<endl;
						cin>>modificador;
						L_Tareas->getObjeto(i)->setHora(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cout<<"Hora modificada con extito..."<<endl;
						cantErrores--;
					}

					else if(op==7){
						cout<<"Estado actual: "<<L_Tareas->getObjeto(i)->gettEstado()<<endl;
						cout<<"Nuevo Estado: "<<endl;
						cin>>modificador;
						L_Tareas->getObjeto(i)->setEstado(modificador);
						ColaErrores->getError(posError)->setCorregido(cantErrores-1);
						cout<<"Estado modificada con extito..."<<endl;
						cantErrores--;
					}
			}


		}
	}


}

void graficarEstudiantes(){

	Grafo<Alumno> *unGrafo = new Grafo<Alumno>();
	unGrafo->generarGrafo(&*L_alumnos);
	cout<<"Grafo generado con exito..."<<endl;

}

void graficarTareas(){



	Grafo<Tarea> *unGrafo =new Grafo<Tarea>();
	unGrafo->generarGrafoTareas(&*L_Tareas);
	cout<<"Grafo generado con exito..."<<endl;
}

void graficarErrores(){

	Grafo<Error> *unGrafo =new Grafo<Error>();
	unGrafo->generarGrafoErrores(&*ColaErrores);
	cout<<"Grafo de errores generado conexito"<<endl;
}

void buscarEnlaLinealizada(){

		//   
		//   i     j k     columnM= (j*tamfila + i)*profund + k
		int hora,dia,mes,pos;
		cout<<" PARA BUSCAR EN LA LISTA TAREAS INGRESE: "<<endl;
		cout<<"La hora "<<endl;
		cin>>hora;
		cout<<"El dia: "<<endl;
		cin>>dia;
		cout<<"El mes: "<<endl;
		cin>>mes;
		pos=(((dia*9)+hora)*5)+mes;
		
		for(int i=0; i<L_Tareas->getSize();i++){

			if(L_Tareas->getNodeIndex(i)==pos){

				cout<<"/*/*/*/*/*/*/*/ TAREA */*/*/*/*/*/*/*/"<<endl;
				cout<<"idTarea: "<<L_Tareas->getObjeto(i)->gettIdTarea()<<endl;
				cout<<"carnet: "<<L_Tareas->getObjeto(i)->gettCarnet()<<endl;
				cout<<"nombre: "<<L_Tareas->getObjeto(i)->gettNombreTarea()<<endl;
				cout<<"descripcion: "<<L_Tareas->getObjeto(i)->gettDesc()<<endl;
				cout<<"materia: "<<L_Tareas->getObjeto(i)->gettMateria()<<endl;
				cout<<"fecha: "<<L_Tareas->getObjeto(i)->gettFecha()<<endl;
				cout<<"hora: "<<L_Tareas->getObjeto(i)->gettHora()<<endl;
				cout<<"estado: "<<L_Tareas->getObjeto(i)->gettEstado()<<endl;
				cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"<<endl;

			}


		}
}

void buscarPosicion(){

	int hora,dia,mes,pos;
	cout<<"/*/*/*/ INGRESE LOS SIGUIENTES VALORES PARA CALCULAR LA POSICION /*/*/*/"<<endl;
	cout<<"hora:"<<endl;
	cin>>hora;
	cout<<"dia: "<<endl;
	cin>>dia;
	cout<<"Mes:"<<endl;
	cin>>mes;

	pos=(( (dia*9)+hora)*5)+mes;

	cout<<"La posicion de los datos ingresados en la lista es: "<<pos<<endl;






}

void generarArchivoSalida(){

	int setError=0;//contador que verifica si los errores dentro de la cola están corregidos

	for (int i=0; i<ColaErrores->getSize();i++){

		if(ColaErrores->getError(i)->getCorregido()==0){

			setError++;
			cout<<"verificando si se setearon los errores"<<endl;
		}else{ cout<<"existen: "<<ColaErrores->getError(i)->getCorregido()<<" errores en el registro: "<<ColaErrores->getError(i)->getNumReg()<<endl;;}
	}

	cout<<"tam setError: "<<setError<<" size cola: "<<ColaErrores->getSize()<<endl;;
	if(setError==ColaErrores->getSize()){

		cout<<"se empieza a crear el archivo"<<endl;
		ofstream archivo;
		archivo.open("SalidaSmartClass.txt",ios::out);
		if(archivo.fail()){

			cout<<"No se pudo crear el fichero!"<<endl;
			exit(1);

		}

		archivo<<"¿Elements?"<<endl;
		for (int i = 0; i < L_alumnos->getSize(); i++)
		{
			
			archivo<<"	¿element type=\"user\"?"<<endl;
			archivo<<"		¿item Carnet = "<<"\""<<L_alumnos->getObjeto(i)->getCarnet()<<"\" $?"<<endl;
			archivo<<"		¿item DPI = "<<"\""<<L_alumnos->getObjeto(i)->getDpi()<<"\" $?"<<endl;
			archivo<<"		¿item Nombre = "<<"\""<<L_alumnos->getObjeto(i)->getNombre()<<"\""<<endl;
			archivo<<"		¿item Carrera = "<<"\""<<L_alumnos->getObjeto(i)->getCarrera()<<"\" $?"<<endl;
			archivo<<"		¿item Password = "<<"\""<<L_alumnos->getObjeto(i)->getPassword()<<"\" $?"<<endl;
			archivo<<"		¿item Creditos = "<<"\""<<L_alumnos->getObjeto(i)->getCredits()<<"\" $?"<<endl;
			archivo<<"		¿item Edad = "<<"\""<<L_alumnos->getObjeto(i)->getEdad()<<"\" $?"<<endl;
			archivo<<"	¿$element?"<<endl;
		
		}

		for(int i=0; i<L_Tareas->getSize();i++){

				if(L_Tareas->getObjeto(i)->gettCarnet()!=-1){

						archivo<<"	¿element type=\"task\"?"<<endl;
						archivo<<"		¿item Carnet = "<<"\""<<L_Tareas->getObjeto(i)->gettCarnet()<<"\" $?"<<endl;
						archivo<<"		¿item Nombre = "<<"\""<<L_Tareas->getObjeto(i)->gettNombreTarea()<<"\" $?"<<endl;
						archivo<<"		¿item Descripcion = "<<"\""<<L_Tareas->getObjeto(i)->gettDesc()<<"\" $?"<<endl;
						archivo<<"		¿item Materia = "<<"\""<<L_Tareas->getObjeto(i)->gettMateria()<<"\" $?"<<endl;
						archivo<<"		¿item Fecha = "<<"\""<<L_Tareas->getObjeto(i)->gettFecha()<<"\" $?"<<endl;
						archivo<<"		¿item Hora = "<<"\""<<L_Tareas->getObjeto(i)->gettHora()<<"\" $?"<<endl;
						archivo<<"		¿item Estado = "<<"\""<<L_Tareas->getObjeto(i)->gettEstado()<<"\" $?"<<endl;
						archivo<<"	¿$element?"<<endl;

				}

		
		}


		archivo<<"¿$Elements?";
		

		archivo.close();
		cout<<"salida SmartClass gtenerado con exito!"<<endl;

	}



	
}





