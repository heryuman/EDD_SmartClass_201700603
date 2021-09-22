from Estructuras.arbolB import Arbol_B
class semester(object):
    def __init__(self,numSemstre):
        self.numSemestre=numSemstre
        self.cursos=Arbol_B(5)