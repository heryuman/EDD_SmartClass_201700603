class hoja(object):

    def __init__ (self, elemento):

        self.izquierda=None
        self.derecha=None
        self.elemnt= elemento
        self.dirPadre=""

    def getElement(self):
        return self.elemnt

    def setElement(self,elemnt):
        self.elemnt=elemnt



