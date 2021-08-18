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

    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != lista->primero){
        string hex = dirToString(&*tmp); 
        //cout<<"el valordelgraafo: "+tmp->getValor()->getNumReg()+"\n";
        nodo += "\"" + hex + "\"" + "[label=\"id:" +tmp->getValor()->getNombre()+ "\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;
    }
    //estamos en el ulitmo nodo
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"" + tmp->getValor()->getNombre() + "\"];\n";
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

    string cmd = "dot -Tpng Alumnos.dot -o Alumnos.png";
    system(cmd.c_str());    
}


template <typename T> 
void Grafo<T>::generarGrafoTareas(Lista<T> *lista){
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";
    string str="";
    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != NULL){
        
        str=to_string(tmp->getIndex());
        string hex = dirToString(&*tmp); 
         

        if(tmp->getValor()->gettIdTarea()!=-1){

      
        //cout<<"el valordelgraafo: "+tmp->getValor()->getNumReg()+"\n";
        nodo += "\"" + hex + "\"" + "[label=\"idTarea: " +str+ "\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;

        }else{

        nodo += "\"" + hex + "\"" + "[label=\"idTarea: -1 \"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;


        }
   
   
    }
    //estamos en el ulitmo nodo
    //tmp = tmp->siguiente;
    str=to_string(tmp->getIndex());
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"idTarea: " +str + "\"];\n";
    //enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
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
    string str="";
    string desc="";
    Nodo<T> *tmp = lista->primero;
    while(tmp->siguiente != NULL){
      
         str=to_string(tmp->getValor()->getId());
         desc=tmp->getValor()->getTipo();
        string hex = dirToString(&*tmp); 
        //cout<<"el valordelgraafo: "+tmp->getValor()->getNumReg()+"\n";
        nodo += "\"" + hex + "\"" + "[label=\"idError: " +str+" desc: "+desc+ "\"];\n";
        enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
        tmp = tmp->siguiente;
    }
    //estamos en el ulitmo nodo
    //tmp = tmp->siguiente;
    str=to_string(tmp->getValor()->getId());
    desc=tmp->getValor()->getTipo();
    nodo += "\"" + dirToString(&*tmp) + "\"[label=\"idError: " + str + " desc: "+desc+"\"];\n";
    //enlace += "\"" +  dirToString(&*tmp) + "\" -> \"" + dirToString(&*(tmp->siguiente)) + "\"[dir=\"both\"];\n";
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

    string cmd = "dot -Tpng Error.dot -o Error.png";
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