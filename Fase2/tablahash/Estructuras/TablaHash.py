from tablahash.Estructuras.Nodo import  Nodo
from graphviz.files import Source

class TablaHash:
    def __init__(self, _tamanio):
        self.tamanio = _tamanio
        self.primero = None
        self.factorCarga = 0.0
        self.id = 0

    def insertarHash(self, carnet, apunte):
        #CALCULAMOS EL FACTOR DE CARGA
        self.factorCarga = (self.id / self.tamanio) * 100
        if self.factorCarga < 56 and self.factorCarga >=0: #aun tiene capacidad para almacenar valores
            llv = carnet % self.tamanio #metodo de la division

            if self.id==0:# verificamos si el tamaño es cero no hay nodos insertados aun por loq ue el metodo getNOdoHash no funciona aun
                print("se iserta primer nodo")
                self.insertar(carnet, apunte, llv)
            elif self.id>0 and self.getNodoHash(carnet) is None: #en esta validacion ya usamos getNodoHash para saber si existe el carnte 
                                                                 #y vemos que id sea >0 para que entre aqui
                print("se inserta un nodo nuevo")
                self.insertar(carnet, apunte, llv)
            else:#si ninguna de las validaciones anteriores se cumple es porque existe el carnet y por lo tanto se agrega a la lista
                print("se inserta el apunte en un nodo existene")
                elNodo=self.getNodoHash(carnet)
                elNodo.lista_apuntes.append(apunte)

            
        else:#factor de carga ya sobre paso
            #REALIZAR UN REHASH
            self.tamanio += 2 #se aumenta en 2 para que sigua impar
            self.reHash(carnet,apunte)

    def reHash(self,carnet,apunte):
        print("para el rehash", carnet,apunte)
        auxiliar=self.primero
        bandera=False
        self.factorCarga = (self.id / self.tamanio) * 100
        while bandera==False:
            if self.factorCarga < 56 and self.factorCarga >=0:
                llv = auxiliar.carnet % self.tamanio
                posicion = 0
                if self.buscarLlv(llv): #TRUE
                     i = 0
                     posicion = self.buscarposicion(auxiliar, i)
                     auxiliar.llv = posicion
                else:
                    auxiliar.llv = llv
            auxiliar = auxiliar.siguiente
            bandera = True
        if self.factorCarga<56 and self.factorCarga>=0:
            llv=auxiliar.carnet % self.tamanio
            posicion=0
            if self.buscarLlv(llv): #TRUE
                i = 0
                posicion = self.buscarposicion(auxiliar, i)
                auxiliar.llv=posicion
            else:
                auxiliar.llv=llv
        self.insertarHash(carnet,apunte)

    def insertar(self, carnet, apunte, llv):
        nuevo = Nodo(llv,carnet, apunte)
        if self.primero == None: #lista vacia
            self.primero = nuevo
            self.id += 1
            return 
        
        #APLICANDO LA COLICION, PARA SABER SI LA LALVE YA EXISTE
        if self.buscarLlv(llv): #TRUE
            i = 0
            posicion = self.buscarposicion(nuevo, i)
            self.insertar(carnet, apunte, posicion)
        else:
            auxiliar = self.primero
            if nuevo.llv < auxiliar.llv: #INSERSION AL INICIO
                nuevo.siguiente = auxiliar
                self.primero = nuevo
                self.id += 1
            else:
                while auxiliar.siguiente != None: #INSERSION AL MEDIO
                    auxiliar2 = auxiliar.siguiente
                    if nuevo.llv < auxiliar2.llv:
                        auxiliar.siguiente = nuevo
                        nuevo.siguiente = auxiliar2
                        self.id += 1
                        break
                    auxiliar = auxiliar.siguiente
                if auxiliar.siguiente == None: #insertar al final
                    auxiliar.siguiente = nuevo
                    self.id += 1

    def buscarposicion(self, actual, i ):
        # SE USA LA FUNCION S(llv,1) = (llv mod m) * i
        #posicion = (i*i)
        #posicion = (actual.llv + i * i )% size(array)
        posicion = (actual.llv + i*i) % self.tamanio
        if self.buscarLlv(posicion): # LA posicionICION YA ESTA OCUPADA POR LO TANTO SE DEBE BUSCAR OTRA posicionICION
            i += 1
            return self.buscarposicion(actual, i )
        # SI LA posicionICION NO ESTA OCUPADA SE RETORNA posicion
        return posicion

    def buscarLlv(self, llv):
        auxiliar = self.primero
        while auxiliar != None:
            if llv == auxiliar.llv:
                return True
            auxiliar = auxiliar.siguiente
        return False

    def getNodoHash(self,carnet):
        existe=None
        tmp=self.primero

        while tmp is not None:
            if tmp.carnet== carnet:
                existe=tmp
                print("existe")
                return existe
            else:
                tmp= tmp.siguiente
        
        return existe

    def getlistaApuntes(self,carnet):
        existe=None
        tmp=self.primero

        while tmp is not None:
            if tmp.carnet== carnet:
                existe=tmp.lista_apuntes
                print("existe")
                return existe
            else:
                tmp= tmp.siguiente
        
        return existe

    def graficaHash(self):
        acum="digraph G{\n node [shape=box];\n"
        if self.id>0:
            tmp=self.primero
            while tmp is not None:
                acum+='"{}"[label="{}"];\n'.format(str(hash(tmp)),"carnet: "+str(tmp.carnet))
                acum+=' \n { rank=same'
                acum+='"{}"[label="{}"];\n'.format(str(hash(tmp.lista_apuntes[0])),"titulo:"+str(tmp.lista_apuntes[0].title))
                acum+='"{}"-> "{}";\n'.format(str(hash(tmp)),str(hash((tmp.lista_apuntes[0]))))
                for i in range(len(tmp.lista_apuntes)):
                    if i< len(tmp.lista_apuntes)-1:
                        acum+='"{}"[label="{}"];\n'.format(str(hash(tmp.lista_apuntes[i+1])),"titulo:"+str(tmp.lista_apuntes[i+1].title))
                        acum+='"{}"-> "{}";\n'.format(str(hash((tmp.lista_apuntes[i]))),str(hash((tmp.lista_apuntes[i+1]))))
                    
                acum+='\n}'
              
                if tmp.siguiente is not None:
                    acum+='\n rankdir="TB"'
                    acum+='"{}" -> "{}";\n'.format(str(hash(tmp)),str(hash(tmp.siguiente)))
                tmp=tmp.siguiente

        acum+="\n}"

        s=Source(acum,filename="C:\\Users\\ASUS\\Desktop\\Reportes_F2\\AVL_Estudiantes", format="svg")
        s.view()
