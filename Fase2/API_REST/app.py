from flask import Flask
from Estructuras.arbolAVL import AVLTree
from Estructuras.matriz import MatrizD
from Estructuras.arbolB import Arbol_B

app=Flask(__name__)
BD_Almumnos=AVLTree()
BD_Cursos=Arbol_B()

@app.route('/ping')
def ping():
    return'Pong'

@app.root_path('/carga',method='POST')
def cargar():
    return 'cargando archivos!'


if __name__ == '__main__':
    app.run(debug=True,port=3000)
