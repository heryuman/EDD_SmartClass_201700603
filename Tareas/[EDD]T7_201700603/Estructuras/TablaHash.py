from Estructuras.Nodo import  Nodo

class TablaHash:
    def __init__(self, _tamanio):
        self.tamanio = _tamanio
        self.primero = None
        self.factorCarga = 0.0
        self.tamActual = 0

    def insertarHash(self, carnet, nombre):
        #CALCULAMOS EL FACTOR DE CARGA
        self.factorCarga = (self.tamActual / self.tamanio) * 100

        if self.factorCarga < 56 and self.factorCarga >=0:
            llv = carnet % self.tamanio
            self.insertar(carnet, nombre, llv)
        else:
            #REALIZAR UN REHASH
            self.tamanio += 2
            self.rehash(carnet,nombre)

    def insertar(self, carnet, nombre, llv):
        nuevo = Nodo(llv,carnet, nombre)

        if self.primero == None:
            self.primero = nuevo
            self.tamActual += 1
            return

        #APLICANDO LA COLICION, PARA SABER SI LA LALVE YA EXISTE
        if self.buscarLlv(llv): #TRUE
            i = 0
            pos = self.buscarPos(nuevo, i)
            self.insertar(carnet, nombre, pos)
        else:
            tmp = self.primero
            if nuevo.llv < tmp.llv: #INSERSION AL INICIO
                nuevo.siguiente = tmp
                self.primero = nuevo
                self.tamActual += 1
            else:
                while tmp.siguiente != None: #INSERSION AL MEDIO
                    tmp2 = tmp.siguiente
                    if nuevo.llv < tmp2.llv:
                        tmp.siguiente = nuevo
                        nuevo.siguiente = tmp2
                        self.tamActual += 1
                        break
                    tmp = tmp.siguiente

                if tmp.siguiente == None: #insertar al final
                    tmp.siguiente = nuevo
                    self.tamActual += 1



    def buscarPos(self, actual, i ):
        # SE USA LA FUNCION S(llv,1) = (llv mod m) * i
       # pos = (actual.llv % self.tamanio) * i
        pos= i*i


        if self.buscarLlv(pos): # LA POSICION YA ESTA OCUPADA POR LO TANTO SE DEBE BUSCAR OTRA POSICION
            i += 1
            return self.buscarPos(actual, i )

        # SI LA POSICION NO ESTA OCUPADA SE RETORNA POS
        return pos

    def buscarLlv(self, llv):
        tmp = self.primero
        while tmp != None:
            if llv == tmp.llv:
                return True
            tmp = tmp.siguiente
        return False

    def rehash(self,carnet,nombre):

        tmp=self.primero
        while tmp.siguiente is not None:
            self.factorCarga=(self.tamActual/self.tamanio)*100
            if self.factorCarga<56 and self.factorCarga>=0:
                llv=tmp.carnet % self.tamanio
                pos=0
                if self.buscarLlv(llv): #TRUE
                     i = 0
                     pos = self.buscarPos(tmp, i)
                     tmp.llv=pos
                else:
                    tmp.llv=llv
            tmp=tmp.siguiente

        self.factorCarga=(self.tamActual/self.tamanio)*100
        if self.factorCarga<56 and self.factorCarga>=0:
            llv=tmp.carnet % self.tamanio
            pos=0
            if self.buscarLlv(llv): #TRUE
                i = 0
                pos = self.buscarPos(tmp, i)
                tmp.llv=pos
            else:
                tmp.llv=llv

        self.insertarHash(carnet,nombre)   
        
        