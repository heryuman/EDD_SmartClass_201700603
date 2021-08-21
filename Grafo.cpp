#include <iostream>
#include <sstream>
#include <fstream>
#include "Lista.cpp"
#include "Listacirc.cpp"
#include "Cola.cpp"
#include <string>
using namespace std;

template <typename T>
class Grafo
{
private:
    /* data */
public:
    Grafo(/* args */);
    void generarGrafo(Listacirc<T> *lista);
    void generarGrafoTareas(Lista<T> *lista);
    void generarGrafoErrores(Cola<T> *cola);
    string dirToString(Nodo<T> *valor);
    string valrToString(T valor);
};

template <typename T>
Grafo<T>::Grafo(/* args */)
{

}

template <typename T> 
void Grafo<T>::generarGrafo(Listacirc<T> *lista){
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";
    string carnet="",dpi="",nombre="",pass="",creditos="",edad="",carrera="";



    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != lista->primero){
         carnet=tmp->getValor()->getCarnet();
         dpi=tmp->getValor()->getDpi();
         nombre=tmp->getValor()->getNombre();
         carrera=tmp->getValor()->getCarrera();
         pass=tmp->getValor()->getPassword();
         creditos=tmp->getValor()->getCredits();
         edad=tmp->getValor()->getEdad();
        string hex = dirToString(&*tmp); 
        //cout<<"el valordelgraafo: "+tmp->getValor()->getNumReg()+"\n";
        nodo += "\"" + hex + "\"" + "[label=\"Carnet:" +carnet+"\n dpi "+dpi+"\n nombre:"+nombre+"\n carrera:"+carrera+"\n pass: "+pass+"\n creditos: "+creditos+"\n edad: "+edad+ "\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;
    }
    //estamos en el ulitmo nodo
     carnet=tmp->getValor()->getCarnet();
     dpi=tmp->getValor()->getDpi();
     nombre=tmp->getValor()->getNombre();
     carrera=tmp->getValor()->getCarrera();
     pass=tmp->getValor()->getPassword();
     creditos=tmp->getValor()->getCredits();
     edad=tmp->getValor()->getEdad();
    string hex = dirToString(&*tmp); 
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"Carnet:" +carnet+"\n dpi "+dpi+"\n nombre:"+nombre+"\n carrera:"+carrera+"\n pass: "+pass+"\n creditos: "+creditos+"\n edad: "+edad+ "\"];\n";
    enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
    acum += nodo + enlace + "\n}\n";

    string filename("Alumnos.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if(!file_out.is_open()){
        cout << "Error al abrir el archivo: " <<filename << '\n';
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito" << endl;
    }

    string cmd = "dot -Tpdf Alumnos.dot -o Alumnos.pdf";
    system(cmd.c_str());    
}


template <typename T> 
void Grafo<T>::generarGrafoTareas(Lista<T> *lista){
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";
    string carnet="",nombre="",descripcion="",materia="",fecha="",hora="",estado="";
    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != NULL){
        carnet=to_string(tmp->getValor()->gettCarnet());
        nombre=tmp->getValor()->gettNombreTarea();
        descripcion=tmp->getValor()->gettDesc();
        materia=tmp->getValor()->gettMateria();
        fecha=tmp->getValor()->gettFecha();
        hora=tmp->getValor()->gettHora();
        estado=tmp->getValor()->gettEstado();
        
        string hex = dirToString(&*tmp); 
         

        if(tmp->getValor()->gettIdTarea()!=-1){

        nodo += "\"" + hex + "\"" + "[label=\"Carnet: "+carnet+"\n nombre: "+nombre+"\n descripcio: "+descripcion+"\n materia: "+materia+"\n fecha: "+fecha+"\n hora: "+hora+"\n Estado: "+estado+ "\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;

        }else{

        nodo += "\"" + hex + "\"" + "[label=\"idTarea: -1 \"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;


        }
   
   
    }
    //estamos en el ulitmo nodo
    carnet=to_string(tmp->getValor()->gettCarnet());
    nombre=tmp->getValor()->gettNombreTarea();
    descripcion=tmp->getValor()->gettDesc();
    materia=tmp->getValor()->gettMateria();
    fecha=tmp->getValor()->gettFecha();
    hora=tmp->getValor()->gettHora();
    estado=tmp->getValor()->gettEstado();
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"Carnet: "+carnet+"\n nombre: "+nombre+"\n descripcio: "+descripcion+"\n materia: "+materia+"\n fecha: "+"\n hora: "+hora+"\n Estado: "+estado + "\"];\n";
    
    acum += nodo + enlace + "\n}\n";

    string filename("Tarea.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if(!file_out.is_open()){
        cout << "Error al abrir el archivo: " <<filename << '\n';
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito" << endl;
    }

    string cmd = "dot -Tpdf Tarea.dot -o Tarea.pdf";
    system(cmd.c_str());    
}

template <typename T> 
void Grafo<T>::generarGrafoErrores(Cola<T> *lista){
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";
    string registro="";
    string id="",tipo="",desc="";
    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != NULL){
        
         id=to_string(tmp->getValor()->getId());
         tipo=tmp->getValor()->getTipo();
         desc=tmp->getValor()->getDesc();
         registro=to_string(tmp->getValor()->getNumReg());
        string hex = dirToString(&*tmp); 
        //cout<<"el valordelgraafo: "+tmp->getValor()->getNumReg()+"\n";
        nodo += "\"" + hex + "\"" + "[label=\"idError: " +id+"\n tipo: "+tipo+"\n descripcion: "+desc+"\n NoRegistro: "+registro+"\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\";\n";
        tmp = tmp->siguiente;
    }
    //estamos en el ulitmo nodo
     id=to_string(tmp->getValor()->getId());
     tipo=tmp->getValor()->getTipo();
     desc=tmp->getValor()->getDesc();
     registro=to_string(tmp->getValor()->getNumReg());
    
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"idError: " +id+"\n tipo: "+tipo+"\n descripcion: "+desc+"\n NoRegistro: "+registro+"\"];\n";
  
    acum += nodo + enlace + "\n}\n";

    string filename("Error.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if(!file_out.is_open()){
        cout << "Error al abrir el archivo: " <<filename << '\n';
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito" << endl;
    }

    string cmd = "dot -Tpdf Error.dot -o Error.pdf";
    system(cmd.c_str());    
}



template <typename T> 
string Grafo<T>::dirToString(Nodo<T> *valor){
    stringstream ss; 
    ss << &*valor;
    return ss.str();
}

template <typename T> 
string Grafo<T>::valrToString(T valor){
    stringstream ss; 
    ss << valor;
    return ss.str();
}