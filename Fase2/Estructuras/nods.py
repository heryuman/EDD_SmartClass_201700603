from objetos.curso import course
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
        self.claves = [course(0,"","","","") for x in range(orden)]
        self.ramas = [Node_B for x in range(orden)]
        self.graficado=False
        #INICIALIZAMOS LAS PAGINAS
        for i in range(orden):
            self.ramas[i] = None

    def NodeB_full(self):
        return self.cuenta == self.m - 1

    def NodeB_mid_full(self):
        return self.cuenta < (self.m / 2)

class linkedNode(object):
    def __init__(self,elemento):
        self.elemento=elemento
        self.pRight=None
        self.pLeft=None
        self.pUp=None
        self.pDown=None
        self.index=None

    def getElement(self):
        return self.elemento
class headsNode(object):
    def __init__(self,_index): 
        self.hRight=None
        self.hLeft=None
        self.hDown=None
        self.hUp=None
        self.celda=None
        self.index=_index

class Dispersa(object):
    def __init__(self):
        self.pRight=None
        self.pLeft=None
        self.pDown=None
        self.pUp=None
        self.pUpDeep=None
        self.taskList=None
        self.row=None
        self.col=None
        self.deep=None





#----------------------------------HORTOGONAL IPC2-----------------------------

    
  
class NodeD(object):
    def __init__(self,elemento,fila,columna):
        self.elemento=elemento
        #puntero que servira para unir a los nodos cuando se construya la lista
        self.pArriba = None
        self.pAbajo= None
        self.pDerecha=None
        self.pIzquierda=None
        self.posX=columna
        self.posY=fila
        self.head=False

    def getElemento(self):
        return self.elemento
    def setElemento(self,elemnt):
        self.elemento=elemnt

    def getPosColumna(self):
        return self.posX

    def getPosFila(self):
        return self.posY
    def getishead(self):
        return self.head
class Head(object):
    def __init__(self,index):
        self.index=index
        self.next=None
        self.last=None




