
from Estructuras.nods import linkedNode
from Estructuras.nods import Head
from graphviz import Source

class LinkedListD(object):
    def __init__(self):
        self.first=None
        self.last=None
        self.count=0


    def isEmpty(self):
        if self.first is None and self.last is None:
            return True
        else:
            return False
    
    def size(self):
        return self.count

    def push(self,elemento):
        nElement=linkedNode(elemento)
        if self.isEmpty():
            self.first=nElement
            self.last=nElement

            self.count+=1

        else:
            self.last.pRight=nElement
            nElement.pLeft=self.last
            self.last=nElement
            self.count+=1

    def getE(self,index):
        i=0
        tmp=self.first
        while i< index :
            tmp= tmp.pRight
            i+=1

        return tmp.getElement()

    def mostrar(self):
        tmp=self.first
        while tmp.pRight is not None:
            print("Nobmre: ",tmp.getElement().getNombre())
            tmp=tmp.pRight

    def delete(self,index):
       
        i=0
        tmp=self.first 
        while i< index and index <= self.count-1:

            tmp=tmp.pRight
            i+=1
        
        #Elimando el primero
        if tmp==self.first and self.count>1:
            self.first=tmp.pRight
            tmp.pRight.pLeft=None
            tmp=None
            self.count-=1
        if tmp== self.first and self.count==1:
            self.first=None
            self.last=None
            self.count-=1
           
        #Eliminando el ultimo
        elif tmp==self.last:
            self.last=tmp.pLeft
            tmp.pLeft.pRight=None
            tmp=None
            self.count-=1
            

        else:
            tmp.pLeft.pRight=tmp.pRight
            tmp.pRight.pLeft=tmp.pLeft
            tmp=None
            self.count-=1
            
   

    def clearList(self):
        self.first=None
        self.last=None
        self.count=0

 





    def insertarCabezeras(self,index):
        head=Head(index)
        tmp= self.first
        if self.isEmpty() == True:
            self.first=head
            self.last=head
            self.count+=1

        else:
           while tmp.next != None:
               if index < tmp.index:
                   break
               tmp=tmp.next

           if tmp.index > index and index==0:
                tmp.last=head
                head.next=tmp
                self.first=head
                self.count+=1

           elif tmp.index > index and tmp.last is not None:
                tmp.last.next=head
                head.last=tmp.last
                head.next=tmp
                tmp.last=head
                self.count+=1

           elif tmp.index < index:
               tmp.next=head
               head.last=tmp
               self.last=head
               self.count+=1

           elif tmp.index > index and tmp.last is None:
               tmp.last=head
               head.next=tmp
               self.first=head
               self.count+=1

    def Graficar_L_Tareaas(self):
        tmp=self.first
        acum= "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n"
        while tmp.pRight is not None:
            acum+='"{}"[label="{}"];\n'.format(str(hash(tmp)),'carnet:'+str(hash(tmp.getElement().getCarnet()))+'\n Nombre: '+str(hash(tmp.getElement().getNombre()))+'\n Descripcion: '+str(hash(tmp.getElement().getDes()))+'\n Materia: '+str(hash(tmp.getElement().getMateria()))+'\n Fecha: '+str(hash(tmp.getElement().getFecha()))+'\n Hora: '+str(hash(tmp.getElement().getHora()))+'\n Estado: '+str(hash(tmp.getElement().getEstado())))            
            acum+='"{}"->{} [dir=\"both\"]; \n'.format(str(hash(tmp)),str(hash(tmp.pRight)))
            tmp=tmp.pRight
        acum+='"{}"[label="{}"];\n'.format(str(hash(tmp)),'carnet:'+str(hash(tmp.getElement().getCarnet()))+'\n Nombre: '+str((tmp.getElement().getNombre()))+'\n Descripcion: '+str((tmp.getElement().getDes()))+'\n Materia: '+str((tmp.getElement().getMateria()))+'\n Fecha: '+str((tmp.getElement().getFecha()))+'\n Hora: '+str((tmp.getElement().getHora()))+'\n Estado: '+str((tmp.getElement().getEstado())))
        acum+='\n } \n'

        s= Source(acum,filename="C:\\Users\\ASUS\Desktop\\Reportes_F2\\Grafica_tareas", format="svg")
        s.view()

       
            

    
