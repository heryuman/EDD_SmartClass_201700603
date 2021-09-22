from _typeshed import Self
from Estructuras.nods import Dispersa

class cabeceras(object):
    def __init__(self):
        self.first=None
        self.last=None
        self.cont=0

    def isEmpty(self):
        if self.first ==None and self.last==None:
            return True
        else:
            return False

    def size(self):
        return self.cont

    def createHead(self,element):
        nElement=Dispersa(element)

        if self.isEmpty():
            self.first=nElement
            self.last=nElement
            self.count+=1
        else:
            self.last.pRight=nElement
            nElement.pLeft=self.last
            self.last=nElement
            self.count+=1

    def getHead(self,index):
        
        i=0
        tmp=self.first
        while i< index :
            tmp= tmp.pRight
            i+=1

        return tmp.getElement()

    