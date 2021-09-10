from graphviz.files import Source
from nods import hoja

class tree(object):

    def __init__(self):
        self.root=None

    def insert2(self,root,elemento):

        
            if elemento.getCarnet()<root.getElement().getCarnet():
                if root.izquierda is not None:
                    self.insert2(root.izquierda,elemento)
                else:
                    nuevo=hoja(elemento)
                    nuevo.dirPadre="i"
                    root.izquierda=nuevo
            
            elif  elemento.getCarnet()>root.getElement().getCarnet():
                if root.derecha is not None:
                    self.insert2(root.derecha,elemento)
                else:
                    nuevo=hoja(elemento)
                    nuevo.dirPadre="d"
                    root.derecha=nuevo
            

        

    def insert(self,elemento):
       
        if self.root==None:
           nuevo=hoja(elemento)
           self.root=nuevo
         
        else:
            
            tmp=self.root
            self.insert2(tmp,elemento)


        
    

    def EnOrden(self,NuevaRaiz):
        if NuevaRaiz :
                print(NuevaRaiz.getElement().getCarnet())
            
           
                self.EnOrden(NuevaRaiz.derecha)
           
                self.EnOrden(NuevaRaiz.izquierda)
            
            

    def unGrafo(self, raiz):

        estructura= "digraph G{\n node [shape=circle];\n"
        acum=""
        acumuladores=[estructura,acum]
        if raiz != None:
            self.mostrarArborl(raiz,acumuladores)

        acumuladores[0]+=acumuladores[1]+ "\n}"

        s= Source(acumuladores[0],filename="arbolBB", format="png")
        s.view()
           
                   
    def mostrarArborl(self,raiz, acum):

        if raiz:
            acum[1]+='"{}"[label="{}"];\n'.format(str(hash(raiz)),str(raiz.getElement().getCarnet()))
            
            if raiz.izquierda != None:
                acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.izquierda)))

            if raiz.derecha!=None:
                 acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.derecha)))

            self.mostrarArborl(raiz.izquierda,acum)
            self.mostrarArborl(raiz.derecha,acum)

            


    def Eliminar(self,root,id):
           
           print("enel metodo delte")
        
           if id < root.getElement().getCarnet() and id != root.izquierda.getElement().getCarnet() :
                print("buscando en la izq para eliminar, el id acutal: ",root.getElement().getCarnet())
                self.Eliminar(root.izquierda,id)

           if id> root.getElement().getCarnet() and id != root.derecha.getElement().getCarnet()  :
                    print("buscando en la derecha para eliminar, el id actual: ",root.getElement().getCarnet())
                    self.Eliminar(root.derecha,id)
                
               
           if root.izquierda is not None:
               if root.izquierda.dirPadre=="i"and id == root.izquierda.getElement().getCarnet():
                        print("se elimino el:",root.izquierda.getElement().getCarnet())
                        root.izquierda=None
           if root.derecha is not None:
               if root.derecha.dirPadre=="d"and id == root.derecha.getElement().getCarnet():
                        print("se elimino el:",root.derecha.getElement().getCarnet())
                        root.derecha=None

          

               
                


                
            

               

