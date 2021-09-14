from graphviz import Digraph
from graphviz.files import Source
from Estructuras.nods import Node
       
class AVLTree(object):
    def __init__(self):
        self.root=None
        self.vacios=0
    def find(self,key):
        if self.root is None:  #si la raiz esta vacia devuelve null  si no usa la recursividad del otro metodo find que envia el tamño de la llave y la raiz
            return None
        else:
            return self._find(key,self.root)
    def _find(self,key,node):
        if node is None: # si el nodo está vacío devuelve null, si no verifica si la key recivida es menor que la key actual si es así usa recursividad  le pasa la key y el nodo en la direccion izq
            return None
        elif key.getCarnet()<node.elemento.getCarnet():
            return self._find(key,self.left)
        elif key.getCarnet()>node.elemento.getCarnet():#si la key es mayor que la key actual usa recursividad y le pasa la nueva key y la direccion derecha del nodo
            return self._find(key,self.right)
        else:
            return node  #si no es ninguno de los casos retorna el nodo, posiblemente no ingrese si la key se está repitiendo
    def findMin(self):# funcion que posiblemente busca un mnimo
        if self.root is None:# si está vacio retorna null
            return None
        else:
            return self._findMin(self.root) #si no usa el segundo metodo buscarmin donde se le pasa la raiz
    def _findMin(self,node): #las funciones min y max al parecer recorren los nodos por la izquiereda o derecha respectivamente y devuelven la direccion del apuntador
        if node.left:
            return self._findMin(node.left)
        else:
            return node
    def findMax(self):
        if self.root is None:
            return None
        else:
            return self._findMax(self.root)
    def _findMax(self,node):
        if node.right:
            return self._findMax(node.right)
        else:
            return node
    def height(self,node):# devuelve -1 en la altura cuando no hay nodo creado y el valor de la altura si ya hay algun nodo
        if node is None:
            return -1
        else:
            return node.height
    #LAS ROTACIONES SE DAN HACIA DONDE HAYA MAS PESO, SI EL PESO ES MAYOR EN LA DERECHA DEL NODO ENTONCES SE REALIZA UNA ROTACION HACIA LA DERECHA DE ESE NODO Y SI POR EL CONTRARIO EL GIRO SERA HACIA LA IZQUIERDA
    def singleLeftRotate(self,node):# funcion que realiza el giro hacia la izquierda
        k1=node.left# la variable k1 toma el valor del apontador hacia la izquierda del nodo que recibe
        node.left=k1.right #el apuntdaor a la izq del nodo apunta al nodo a la derecha de la izq anterior
        k1.right=node
        node.height=max(self.height(node.right),self.height(node.left))+1 # SE OBTIENE EL VALOR MAXIMO DE LAS ALTURAS Y SE SUMA +1 PARA DARLE EL PESO/ALTURA AL NODO
        k1.height=max(self.height(k1.left),node.height)+1# SE LE DA EL NUEVO VALOR DE PESO A LA NUEVA RAIZ
        return k1
    def singleRightRotate(self,node):
        k1=node.right
        node.right=k1.left
        k1.left=node
        node.height=max(self.height(node.right),self.height(node.left))+1
        k1.height=max(self.height(k1.right),node.height)+1
        return k1
    def doubleLeftRotate(self,node):
        node.left=self.singleRightRotate(node.left)
        return self.singleLeftRotate(node)
    def doubleRightRotate(self,node):
        node.right=self.singleLeftRotate(node.right)
        return self.singleRightRotate(node)
    def put(self,element):
        if not self.root:
            self.root=Node(element)
        else:
            self.root=self._put(element,self.root)
    def _put(self,key,node):
        if node is None:
            node=Node(key)
        elif key.getCarnet()<node.elemento.getCarnet():
            node.left=self._put(key,node.left)
            if (self.height(node.left)-self.height(node.right))==2:
                if key.getCarnet()<node.left.elemento.getCarnet():
                    node=self.singleLeftRotate(node)
                else:
                    node=self.doubleLeftRotate(node)
            
        elif key.getCarnet()>node.elemento.getCarnet():
            node.right=self._put(key,node.right)
            if (self.height(node.right)-self.height(node.left))==2:
                if key.getCarnet()<node.right.elemento.getCarnet():
                    node=self.doubleRightRotate(node)
                else:
                    node=self.singleRightRotate(node)
        
        
        node.height=max(self.height(node.right),self.height(node.left))+1
        return node
        
    def delete(self,key):
        self.root=self.remove(key,self.root)

    def remove(self,key,node):
        if node is None:
            raise (KeyError,'Error,key not in tree')
        elif key<node.key:
            node.left=self.remove(key,node.left)
            if (self.height(node.right)-self.height(node.left))==2:
                if self.height(node.right.right)>=self.height(node.right.left):
                    node=self.singleRightRotate(node)
                else:
                    node=self.doubleRightRotate(node)
            node.height=max(self.height(node.left),self.height(node.right))+1
            
                
        elif key>node.key:
            node.right=self.remove(key,node.right)
            if (self.height(node.left)-self.height(node.right))==2:
                if self.height(node.left.left)>=self.height(node.left.right):
                    node=self.singleLeftRotate(node)
                else:
                    node=self.doubleLeftRotate(node)
            node.height=max(self.height(node.left),self.height(node.right))+1
        
        elif node.left and node.right:
            if node.left.height<=node.right.height:
                minNode=self._findMin(node.right)
                node.key=minNode.key
                node.right=self.remove(node.key,node.right)
            else:
                maxNode=self._findMax(node.left)
                node.key=maxNode.key
                node.left=self.remove(node.key,node.left)
            node.height=max(self.height(node.left),self.height(node.right))+1
        else:
            if node.right:
                node=node.right
            else:
                node=node.left
        
        return node
    
        
    def mostrar(self, root):
        if root:
            
            
            self.mostrar(root.left)
            print(root.elemento.getCarnet())
            self.mostrar(root.right)

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
        leftNone=False
        rightNone=False
        if raiz:
            acum[1]+='"{}"[label="{}"];\n'.format(str(hash(raiz)),str(raiz.key))
            
            if raiz.left != None:
                if raiz.right==None:
                    acum[1]+='"'+str(self.vacios)+'"[label="R" style= invis];\n'
                    acum[1]+='"{}" -> "{}"[style=invis];\n'.format(str(hash(raiz)),str(hash(self.vacios)))
                    self.vacios+=1
                    acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.left)))
                else:
                    acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.left)))
                    
            if raiz.right!=None:
                 if raiz.left==None:
                    acum[1]+='"'+str(self.vacios)+'"[label="R" style= invis];\n'
                    acum[1]+='"{}" -> "{}"[style=invis];\n'.format(str(hash(raiz)),str(hash(self.vacios)))
                    self.vacios+=1
                    acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.right)))
                 else:
                     acum[1]+='"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.right)))
                    

            
                
          

            
               
            

            self.mostrarArborl(raiz.left,acum)
            self.mostrarArborl(raiz.right,acum)