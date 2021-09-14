from Analizadores.ASintactico import parser
from Analizadores.ASintactico import lista as datosTXT
from Estructuras.arbolAVL import AVLTree
from objetos.estudiante import estudiant
from objetos.tarea import task
from Estructuras.arbolB import Arbol_B

if __name__ == '__main__':
    f=open('SalidaSmartClass.txt',"r", encoding="utf-8")
    entrada=f.read()
    f.close()
    parser.parse(entrada)
    T_estudiantes= AVLTree()
    T_tareas=AVLTree()

    for i in  range(len(datosTXT)):
        
        if datosTXT[i]=='user':
            """print("carnet user: ",datosTXT[i+1],
            "dpi: ",datosTXT[i+2],
            "nombre: ",datosTXT[i+3],
            "carrera: ",datosTXT[i+4],
            "correo: ",datosTXT[i+5],
            "pass: ",datosTXT[i+6],
            "creditos: ",datosTXT[i+7],
            "edad: ", datosTXT[i+8]
            )"""
            nEstudiante=estudiant(
                int(datosTXT[i+1]),
                datosTXT[i+2],
                datosTXT[i+3],
                datosTXT[i+4],
                datosTXT[i+5],
                datosTXT[i+6],
                datosTXT[i+7],
                datosTXT[i+8],
                ""
            )
            T_estudiantes.put(nEstudiante)

       

        if datosTXT[i]=='task':
            
            """print("carnet task: ",datosTXT[i+1],
            "nombre: ",datosTXT[i+2],
            "desc: ",datosTXT[i+3],
            "materia: ",datosTXT[i+4],
            "fecha: ",datosTXT[i+5],
            "hora: ",datosTXT[i+6],
            "estado: ",datosTXT[i+7]
            )"""
            nTarea=task(
                int(datosTXT[i+1]),
                datosTXT[i+2],
                datosTXT[i+3],
                datosTXT[i+4],
                datosTXT[i+5],
                datosTXT[i+6],
                datosTXT[i+7]
            )
            T_tareas.put(nTarea)
    #print("Carnets de tareas:")
    #T_tareas.mostrar(T_tareas.root)
   # print("Carnet Estudiantes: ")
   # T_estudiantes.mostrar(T_estudiantes.root)
    #print("se insertaron los elementos correctamente")


nuevoB=Arbol_B(5)

for i in range(1,51):
    nuevoB.insertar(i)


nuevoB.Graficar()







