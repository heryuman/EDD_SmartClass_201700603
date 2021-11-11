from objetos.curso import course
from graphviz.files import Source
from Estructuras.nods import Node_B

class Arbol_B:
    def __init__(self, _orden):
        self.orden = _orden
        self.raiz = Node_B(5)
        self.encontrado=False
        

    def insertar(self,valor):

                    # [SUBE_ARRIBA, MEDIANA, ND, Pagina]
        array_valores = [False,None,None, None]

        self.empujar(self.raiz, valor, array_valores)

        if array_valores[0]:
            array_valores[3] = Node_B(self.orden)
            array_valores[3].cuenta = 1
            array_valores[3].claves[1] = array_valores[1]
            array_valores[3].ramas[0] = self.raiz
            array_valores[3].ramas[1] = array_valores[2]
            self.raiz = array_valores[3]



    # flag_pagina = [bool sube_arriba, int mediana, pagina nuevo,P)
    def empujar(self, pagina_actual, valor, flag_pagina):
        camino = [0]  # a que rama irse
        if pagina_actual == None:
            flag_pagina[0] = True # sube_arriba
            flag_pagina[1] = valor # mediana
            flag_pagina[2] = None # pagina nuevo
        else:
            esta = self.buscarPagina(pagina_actual, valor, camino)
            if esta:
                print("hay una clave duplicada: " , valor.getCodigo())
                flag_pagina[0] = False
                return
            self.empujar(pagina_actual.ramas[camino[0]], valor, flag_pagina)
            if flag_pagina[0]:
                if pagina_actual.NodeB_full():
                    self.dividirNodo(pagina_actual,flag_pagina[1],(flag_pagina[2]),camino,flag_pagina)
                else:
                    flag_pagina[0] = False
                    self.meterHoja(pagina_actual,flag_pagina[1],flag_pagina[2],camino[0])


    def buscarPagina(self,pagina_actual, valor, camino):
        # Tomar en cuenta que "camino" es la direccion de las ramas por las que puede bajar la busqueda
        encontrado = False
        if  pagina_actual.claves[1].getCodigo()> valor.getCodigo():
            camino[0] = 0   # Indica que bajaremos por la rama 0
            encontrado = False

        else: # Examina las claves del nodo en orden descendente

            camino[0] = pagina_actual.cuenta     #iniciamos desde la clave actual

            # Busacamos una posicion hasta donde el valor deje de ser menor
            # (por si viene un valor a los que hay en le nodo )
            while (valor.getCodigo() < pagina_actual.claves[camino[0]].getCodigo()) and (camino[0] > 1):
                camino[0] = camino[0] - 1
            encontrado = valor.getCodigo() == pagina_actual.claves[camino[0]].getCodigo()
        return encontrado

    def meterHoja(self , actual, valor, rd, k):
        # DESPLAZAR A LA DERECHA LOS ELEMENTOS PARA HACER UN HUECO
        i = actual.cuenta
        while i >= k + 1:
            actual.claves[i + 1] = actual.claves[i]
            actual.ramas[i + 1] = actual.ramas[i]
            i = i-1

        actual.claves[k + 1] = valor
        actual.ramas[k + 1] = rd
        actual.cuenta = actual.cuenta + 1


    def dividirNodo(self, pagina_actual, valor, rd, camino, flag_pagina):
        posMdna = self.orden / 2 if (camino[0] <= self.orden / 2) else self.orden / 2 + 1
        posMdna = int(posMdna)
        flag_pagina[2] = Node_B(5)
        i = posMdna + 1
      

        while i < self.orden:
            # Es desplazada  la mitad drecha al nuevo nodo, la clave mediana se queda en el nodo origen
            flag_pagina[2].claves[i - posMdna] = pagina_actual.claves[i]
            flag_pagina[2].ramas[i - posMdna] = pagina_actual.ramas[i]
            i = i + 1
        flag_pagina[2].cuenta = (self.orden -1) - posMdna #numero de claves en le nuevo nodo
        pagina_actual.cuenta = posMdna # numero de claves en el nodo origen
       
        # Es insertada la clave y rama en el nodo que le corresponde
        if camino[0] <= self.orden / 2: # si el camino[0 es menor al minimo de claves que puede haber en la pagina
            self.meterHoja(pagina_actual,valor,rd,camino[0])
        else:
            self.meterHoja(flag_pagina[2],valor,rd,camino[0]-posMdna)

        # se extrae la clave media del nodo origen
        flag_pagina[1] = pagina_actual.claves[pagina_actual.cuenta]

        # rama 0 del nuevo nodo es la rama de la mediana
        flag_pagina[2].ramas[0] = pagina_actual.ramas[pagina_actual.cuenta]
        pagina_actual.cuenta -=1 

    def RecorreNodo(self):
        print("en los nodos")
        self._recorreNodo(self.raiz,0)

    def _recorreNodo(self, raiz,inicioRama):
        if raiz!=None:
            i=0
            while i<raiz.cuenta:
                self._recorreNodo(raiz.ramas[i],inicioRama+1)
                for j in range(inicioRama):
                    print("   ",end="")
                print(raiz.claves[i+1].getCodigo())
                i+=1
            self._recorreNodo(raiz.ramas[i],inicioRama+1)

    def Graficar(self):
        self.unGrafo(self.raiz)

   

    def unGrafo(self, raiz):

        estructura= "digraph G{\n node [shape=record];\n"
        acum=""
        acumuladores=[estructura,acum]
        if raiz != None:
            self.mostrarArborl(raiz,acumuladores,1)

        acumuladores[0]+=acumuladores[1]+ "\n}"

        s= Source(acumuladores[0],filename="C:\\Users\\ASUS\Desktop\\Reportes_F3\\arbolB_Cursos", format="svg")
        s.view()
        
           
                   
    def mostrarArborl(self,raiz, acum,cont):
     
        
        if raiz != None:
            acum[1]+='{}[shape=record, label=\"'.format(str(hash(raiz)))
            for i in range(1,raiz.cuenta+1):
                if i!=(raiz.cuenta) and raiz.cuenta>1:#para que no dibuje un cuadro en blanco
                   if raiz.claves[i]!=0 :
                        acum[1]+='<'+str(i)+'>{}|'.format("codigo:\\n"+str(raiz.claves[i].getCodigo())+"\\n nombre: \\n"+str(raiz.claves[i].getNombre()))
                else:
                    if raiz.claves[i]!=0:
                        acum[1]+='<'+str(i)+'>{}'.format("codigo:\\n"+str(raiz.claves[i].getCodigo())+"\\n nombre: \\n"+str(raiz.claves[i].getNombre()))
                      
            acum[1]+='\"];\n'
            
            for i in range(raiz.cuenta+1):
                  if raiz.ramas[i] is not None and raiz.graficado==False:
                   
                    acum[1]+='{}->{};\n'.format(str(hash(raiz)),str(hash(raiz.ramas[i])))

                  if i== raiz.cuenta:
                      raiz.graficado=True
                 
                
               
            for i in range (len(raiz.ramas)):
                
                self.mostrarArborl(raiz.ramas[i],acum,cont+1)

    

    def eliminar(self,valor):
        """
        ArrayV[0] encontrado
        arrayV[1] objeto para busqueda de carnet a eliminar

        """
        array_valores=[False,None]
        curso=course(valor,"","","","")

        self.eliminarRegistro(self.raiz,curso,array_valores)
        if array_valores[0]:
            print("Clave eliminada: ", curso.getCodigo())
            if self.raiz.cuenta == 0:
                #raiz vacia, se libera el nodo y se establece la nueva raiz
                array_valores[3]=self.raiz
                self.raiz=self.raiz.ramas[0]
                array_valores[3]=None
        else:
                print("La clave no se encuentra")


    def eliminarRegistro(self, pagina_actual,valor,array_valores):
        camino = [0]# nos sirve para decir por que ruta ir
      
        if pagina_actual!=None:
            array_valores[0] = self.buscarPagina(pagina_actual,valor,camino)
           
            if array_valores[0]:
                if pagina_actual.ramas[camino[0]-1] == None: #es un nodo hoja
                    self.quitar(pagina_actual,camino[0])
                else:
                    self.sucesor(pagina_actual,camino[0]) #se elimina la clave sucesora en su nodo
                    self.eliminarRegistro(pagina_actual.ramas[camino[0]-1],pagina_actual.claves[pagina_actual.cuenta],array_valores)
            else:
                self.eliminarRegistro(pagina_actual.ramas[camino[0]],valor,array_valores)
                #las llamadas recursivas devuelven control a este punto
        
            
            if pagina_actual.ramas[camino[0]]!=None:
                if pagina_actual.ramas[camino[0]].cuenta < int(self.orden/2) :
                    self.restablecer(pagina_actual,camino[0])

            
           

        else:
            self.encontrado=False
    
    def quitar(self,pagina_actual,camino):
        j=camino + 1
        #for j in pagina_actual.cuenta:
        while j<= pagina_actual.cuenta:
            pagina_actual.claves[j-1]=pagina_actual.claves[j]
            pagina_actual.ramas[j-1]=pagina_actual.ramas[j]
            j+=1
        pagina_actual.cuenta -=1
    
    def sucesor(self,pagina_actual,camino):
        q= pagina_actual.ramas[camino-1]
        while q.ramas[q.cuenta] !=None:
            q=q.ramas[q.cuenta]  #q es referencia al nodo hoja
        pagina_actual.claves[camino] = q.claves[q.cuenta]
        
    def restablecer(self, pagina_actual,camino):
        #pagina actual tiene la direccion del nodo antecedente de
        # pagina_actual.ramas[camino] que tiene menos claves que el minimo
        if camino>0: #tiene hermano izquierdo
            if pagina_actual.ramas[camino-1].cuenta >int(self.orden/2):
                self.moverDerecha(pagina_actual,camino)

            elif (camino+1)<=len(pagina_actual.ramas) and pagina_actual.ramas[camino+1].cuenta>int(self.orden/2):#buscar en el hermano derecho agregado hoy 17/09
                
                    self.moverIzquierda(pagina_actual,camino)
            else:
                self.combina(pagina_actual,camino)
        else: #solo tiene un hermano derecho
            if pagina_actual.ramas[1].cuenta > int(self.orden/2):
                self.moverIzquierda(pagina_actual,1)
            else:
                self.combina(pagina_actual,1)
    
    def moverDerecha(self,pagina_actual,camino):
        
        nodoProblema=pagina_actual.ramas[camino]
        nodoIzq = pagina_actual.ramas[camino-1]
        j=nodoProblema.cuenta
        #for j in nodoProblema.cuenta: #deja hueco
        while j>=1:
            nodoProblema.claves[j+1]=nodoProblema.claves[j]
            nodoProblema.ramas[j+1]=nodoProblema.ramas[j]
            j-=1
        nodoProblema.cuenta+=1
        nodoProblema.ramas[1] = nodoProblema.ramas[0] 
        #baja la clave del nodo padre
        nodoProblema.claves[1]=pagina_actual.claves[camino]
        #sube la clave desde el hermano izquierdo al nodo padre, para reemplazar lo que antes bajo
        pagina_actual.claves[camino]= nodoIzq.claves[nodoIzq.cuenta]
        nodoProblema.ramas[0]=nodoIzq.ramas[nodoIzq.cuenta]
        nodoIzq.cuenta-=1
    
    def moverIzquierda(self,pagina_actual,camino):
        j=1
        nodoProblema = pagina_actual.ramas[camino-1]
        nodoDer=pagina_actual.ramas[camino]
        nodoProblema.cuenta+=1
        nodoProblema.claves[nodoProblema.cuenta] = pagina_actual.claves[camino]
        nodoProblema.ramas[nodoProblema.cuenta]=nodoDer.ramas[0]
        """
            sube la clave desde el hermano derecho al nodo padre,
            para remplazar lo que antes bajo
        """
        pagina_actual.claves[camino] = nodoDer.claves[1]
        nodoDer.ramas[1]=nodoDer.ramas[0]
        nodoDer.cuenta-=1
        #for j in nodoDer.cuenta:
        while j <= nodoDer.cuenta:
            nodoDer.claves[j] = nodoDer.claves[j+1]
            nodoDer.ramas[j]=nodoDer.ramas[j+1]
            j+=1
    
    
    def combina(self,pagina_actual,camino):
        j=1
        q= pagina_actual.ramas[camino]
        nodoIzq= pagina_actual.ramas[camino-1]
        #baja clave mediana desde el nodo padre
        nodoIzq.cuenta+=1
        nodoIzq.claves[nodoIzq.cuenta] = pagina_actual.claves[camino]
        nodoIzq.ramas[nodoIzq.cuenta] = q.ramas[0]
        #mueve, claves nodo derecho
        #for j in q.cuenta:
        while j<=q.cuenta:
            nodoIzq.cuenta+=1
            nodoIzq.claves[nodoIzq.cuenta] =q.claves[j]
            nodoIzq.ramas[nodoIzq.cuenta]=q.ramas[j]
            j+=1
        #se ajustan claves y ramas del nodo padre debido a que antes descendio el camino
        j=camino
        while j<= pagina_actual.cuenta -1:
            pagina_actual.claves[j] =pagina_actual.claves[j+1]
            pagina_actual.ramas[j] = pagina_actual.ramas[j+1]
            j+=1
        pagina_actual.cuenta-=1