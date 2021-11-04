from Estructuras.Nodo import  Nodo

class TablaHash:
    def __init__(self, _tamanio):
        self.tamanio = _tamanio
        self.primero = None
        self.factorCarga = 0.0
        self.id = 0

    def insertarHash(self, carnet, nombre):
        #CALCULAMOS EL FACTOR DE CARGA
        self.factorCarga = (self.id / self.tamanio) * 100
        if self.factorCarga < 56 and self.factorCarga >=0: #aun tiene capacidad para almacenar valores
            llv = carnet % self.tamanio #metodo de la division
            self.insertar(carnet, nombre, llv)
            print("antes", carnet,nombre)
        else:#factor de carga ya sobre paso
            #REALIZAR UN REHASH
            self.tamanio += 2 #se aumenta en 2 para que sigua impar
            self.reHash(carnet,nombre)

    def reHash(self,carnet,nombre):
        print("para el rehash", carnet,nombre)
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
        self.insertarHash(carnet,nombre)

    def insertar(self, carnet, nombre, llv):
        nuevo = Nodo(llv,carnet, nombre)
        if self.primero == None: #lista vacia
            self.primero = nuevo
            self.id += 1
            return 
        
        #APLICANDO LA COLICION, PARA SABER SI LA LALVE YA EXISTE
        if self.buscarLlv(llv): #TRUE
            i = 0
            posicion = self.buscarposicion(nuevo, i)
            self.insertar(carnet, nombre, posicion)
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