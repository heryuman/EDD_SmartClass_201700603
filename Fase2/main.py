from Analizadores.ASintactico import parser
from Analizadores.ASintactico import lista as datosTXT
from objetos.arbol import tree
from objetos.estudiante import estudiant
from objetos.tarea import task

if __name__ == '__main__':
    f=open('SalidaSmartClass.txt',"r", encoding="utf-8")
    entrada=f.read()
    f.close()
    parser.parse(entrada)
    T_estudiantes= tree()
    T_tareas=tree()

    for i in  range(len(datosTXT)):
        print("task",i+1)
        if datosTXT[i]=='user':
            nEstudiante=estudiant(
                datosTXT[i+1],
                datosTXT[i+2],
                datosTXT[i+3],
                datosTXT[i+4],
                datosTXT[i+5],
                datosTXT[i+6],
                datosTXT[i+7],
                datosTXT[i+8],
                datosTXT[i+9]
            )
            T_estudiantes.insert(nEstudiante)

        elif datosTXT[i]=='task':
         
            nTarea=task(
                datosTXT[i+1],
                datosTXT[i+2],
                datosTXT[i+3],
                datosTXT[i+4],
                datosTXT[i+5],
                datosTXT[i+6],
                datosTXT[i+7]
            )
            T_tareas.insert(nTarea)
    print("Carnets de tareas:")
    T_tareas.EnOrden(T_tareas.root)
    print("Carnet Estudiantes: ")
    T_estudiantes.EnOrden(T_estudiantes.root)
    print("se insertaron los elementos correctamente")





