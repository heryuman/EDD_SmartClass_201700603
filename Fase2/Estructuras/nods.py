class hoja(object):

    def __init__ (self, elemento):
        
        self.izquierda=None
        self.derecha=None
        self.elemnt= elemento#key
        self.dirPadre=""
        self.height=0
        

    def getElement(self):
        return self.elemnt

    def setElement(self,elemnt):
        self.elemnt=elemnt

class Node(object):
    def __init__(self,elemento):
        
        self.elemento=elemento

        self.left=None
        self.right=None
        self.height=0

class Node_B:
    def __init__(self, orden):
        self.cuenta = 0
        self.m = orden
        self.claves = [0 for x in range(orden)]
        self.ramas = [Node_B for x in range(orden)]
        self.graficado=False
        #INICIALIZAMOS LAS PAGINAS
        for i in range(orden):
            self.ramas[i] = None

    def NodeB_full(self):
        return self.cuenta == self.m - 1

    def NodeB_mid_full(self):
        return self.cuenta < self.m / 2
        
    


