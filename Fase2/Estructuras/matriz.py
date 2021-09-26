import os
from graphviz.lang import NOHTML
from Estructuras.Lista import LinkedListD
from graphviz import Source

class Nodo(object): 
    def __init__(self, fila, columna): 
        self.fila = fila 
        self.columna = columna 
       
        self.izquierda = None 
        self.derecha = None 
        self.abajo = None 
        self.arriba = None 
        self.taskList=LinkedListD()
       

    def insert(self,dato):
        self.taskList.push(dato)

    def getList(self):
        return self.taskList
        
 
class Encabezado(object): 
    def __init__(self, numero): 
        self.numero = numero 
        self.siguiente = None 
        self.anterior = None 
        #acceso es un puntero al Nodo 
        self.abajo = None
        self.derecha=None 
 
class ListaEncabazado(object): 
    def __init__(self): 
        self.inicio = None 
        self.size = 0 
 
    #metodo insertar EspacioNuevo nodo clase Encabezado 
    def insertar(self, nuevo):
        if self.esVacia()==True: #insertar cuando está VACÍO
            self.inicio = nuevo
            self.size+=1
        else:
            tmp= self.inicio
            while tmp.siguiente != None:
                if nuevo.numero < tmp.numero:
                    break
                tmp=tmp.siguiente

            if tmp.numero > nuevo.numero and nuevo.numero ==0:
                tmp.anterior=nuevo
                nuevo.siguiente=tmp
                self.inicio=nuevo
                self.size+=1
                
            elif tmp.numero > nuevo.numero and tmp.anterior is not None:
                tmp.anterior.siguiente = nuevo
                nuevo.anterior=tmp.anterior
                nuevo.siguiente = tmp
                tmp.anterior=nuevo
                self.size+=1

            elif tmp.numero < nuevo.numero:
                tmp.siguiente = nuevo
                nuevo.anterior= tmp
                self.size+=1

            elif tmp.numero > nuevo.numero and tmp.anterior is None:
                tmp.anterior=nuevo
                nuevo.siguiente = tmp
                self.inicio=nuevo
                self.size+=1




                 
    #metodo obtener en tal posicion 
    def retornarEn(self, numero): 
        temporal = self.inicio         
        while temporal != None: 
            if temporal.numero == numero: 
                return temporal 
            temporal = temporal.siguiente 
         
        return None 
     
    def esVacia(self): 
        if self.inicio == None: 
            return True 
        else: 
            return False 
 
class MatrizD(object): 
    def __init__(self, mes): 
        self.nombre = mes 
       
        self.encabezadoFilas = ListaEncabazado() 
        self.encabezadoColumnas = ListaEncabazado() 
        self.siguiente = None 
        
 
    # metodo insertar 
    def insertarespacio(self,fila, columna): 
        EspacioNuevo = Nodo(fila,columna) 
        #INSERCIÓN DE FILAS 
        encabezadoFila = self.encabezadoFilas.retornarEn(fila) 
        if encabezadoFila == None: #INSERCION SI NO EXISTE NINGUN ENCABEZADO 
            encabezadoFila = Encabezado(fila) 
            encabezadoFila.derecha = EspacioNuevo 
            self.encabezadoFilas.insertar(encabezadoFila)             
        else:  
            #INSERTAR AL INICIO  
            if int(EspacioNuevo.columna) < int(encabezadoFila.derecha.columna): 
                EspacioNuevo.derecha = encabezadoFila.derecha
                encabezadoFila.derecha.izquierda = EspacioNuevo 
                encabezadoFila.derecha = EspacioNuevo 
            else: 
                temporal = encabezadoFila.derecha 
                while temporal.derecha !=None: 
                    if int(EspacioNuevo.columna) < int(temporal.derecha.columna): #INSERTAR EN MEDIO  
                        EspacioNuevo.derecha = temporal.derecha 
                        temporal.derecha.izquierda = EspacioNuevo 
                        EspacioNuevo.izquierda = temporal 
                        temporal.derecha = EspacioNuevo 
                        break 
                    temporal = temporal.derecha 
                 
                if temporal.derecha == None: #INSERTAR AL FINALs 
                    temporal.derecha = EspacioNuevo 
                    EspacioNuevo.izquierda = temporal 
        #INSERCIÓN DE COLUMNAS 
        encabezadoColumna = self.encabezadoColumnas.retornarEn(columna) 
        if encabezadoColumna == None: # SI NO EXISTE ENCABEZADO SE CREA UNO 
            encabezadoColumna = Encabezado(columna) 
            self.encabezadoColumnas.insertar(encabezadoColumna) 
            encabezadoColumna.abajo = EspacioNuevo 
        else:  
            if int(EspacioNuevo.fila) < int(encabezadoColumna.abajo.fila): #INSERTAR AL INICIO 
                EspacioNuevo.abajo = encabezadoColumna.abajo 
                encabezadoColumna.abajo.arriba = EspacioNuevo 
                encabezadoColumna.abajo = EspacioNuevo 
            else: 
                temporal = encabezadoColumna.abajo 
                while temporal.abajo != None: 
                    if int(EspacioNuevo.fila) < int(temporal.abajo.fila): # INSERTAR EN MEDIO 
                        EspacioNuevo.abajo = temporal.abajo 
                        temporal.abajo.arriba = EspacioNuevo 
                        EspacioNuevo.arriba = temporal 
                        temporal.abajo = EspacioNuevo 
                        break 
                    temporal = temporal.abajo 
                if temporal.abajo == None: #INSERTAR AL FINAL 
                    temporal.abajo = EspacioNuevo 
                    EspacioNuevo.arriba = temporal 
    # metodo recorrer filas  
    def recorrerFilas(self): 
        encabezadoFila = self.encabezadoFilas.inicio 
        print('Recorrido por filas') 
        while(encabezadoFila != None): 
            print('Fila '+str(encabezadoFila.numero)) 
            temporal = encabezadoFila.derecha 
            while(temporal != None): 
                print(temporal.dato+" "+str(temporal.fila)+","+str(temporal.columna)) 
                #if encabezadoFila.siguiente != None or temporal.derecha != None: 
                #    print('->') 
                temporal = temporal.derecha 
            encabezadoFila = encabezadoFila.siguiente 
        print('Fin filas') 
     
    #Retornar nodo por coordenada 
    def retornarNodoEn(self, fila, columna): 
        encabezadoFila = self.encabezadoFilas.inicio 
        while(encabezadoFila != None): 
            temporal = encabezadoFila.derecha 
            while temporal != None: 
                if temporal.fila == fila and temporal.columna == columna: 
                    return temporal 
                temporal = temporal.derecha 
            encabezadoFila = encabezadoFila.siguiente 
    
    def Exist(self, fila, columna): 
        encabezadoFila = self.encabezadoFilas.inicio 
        exist=False
        while(encabezadoFila != None): 
            temporal = encabezadoFila.derecha 
            while temporal != None: 
                if temporal.fila == fila and temporal.columna == columna: 
                    exist=True
                    
                temporal = temporal.derecha 
            encabezadoFila = encabezadoFila.siguiente 
        return exist

    def insertarenLaListadelespacio(self,elemento,fila,columna):
        if self.Exist(fila,columna)!=True:
             self.insertarespacio(fila,columna)
             lista=self.retornarNodoEn(fila,columna)
             lista.insert(elemento)
        else:
            lista=self.retornarNodoEn(fila,columna)
            lista.insert(elemento)




 
    # metodo recorrer columnas   
    def recorrerColumnas(self): 
        encabezadoColumna = self.encabezadoColumnas.inicio 
        print('Recorrido por columnas') 
        while encabezadoColumna != None: 
            temporal = encabezadoColumna.abajo 
            while temporal != None: 
                print(temporal.dato) 
                if encabezadoColumna.siguiente !=None or temporal.abajo != None: 
                    print('->') 
                temporal = temporal.derecha 
            encabezadoColumna = encabezadoColumna.siguiente 
        print('Fin columnas')


    def eliminarEn_el_Espacio(self,fila, columna,index):
        if self.Exist(fila,columna) is True:
            lista=self.retornarNodoEn(fila,columna).getList()
            if index<=lista.size():
            
                lista.delete(index-1)

    def obteneEn_el_Espacio(self, fila,columna,index):
        elemento=None
        if self.Exist(fila,columna) is True:
            lista=self.retornarNodoEn(fila,columna).getList()
            if index<=lista.size():
                elemento=lista.getE(index-1)

        return elemento

    def graficar(self):
        
        acum= "digraph G{\n node [shape=box];\n  rankdir=UD;\n"
        
        
        headCols=self.encabezadoColumnas.inicio
        while headCols is not None:
            
            tmp=headCols.abajo
            acum+='"{}"[label="{}"];\n'.format(str(hash(headCols)),str(hash(headCols.numero)))
            acum+='"{}"-> "{}";\n'.format(str(hash(headCols)),str(hash(tmp)))  
            
            while tmp is not None :
                      
                if tmp.getList().size()>0:
                    acum+='"{}"[label="{}"];\n'.format(str(hash(tmp)),str(hash(tmp.getList().size())))
                    if tmp.derecha is not None:
                        acum+='"{}"-> "{}";\n'.format(str(hash(tmp)),str(hash(tmp.derecha)))
                tmp=tmp.abajo
            headCols=headCols.siguiente



        acum+= "\n}"

        s= Source(acum,filename="matrix", format="png")
        s.view()

    def generarGrafo(self):
        print("Generando Grafo")
        acumInfo = """digraph G{
            node[shape=box, style=filled, color=chartreuse3];
            edge[color=black];
            rankdir=UD;\n"""

        idCabeceraFila = ""
        cabeceraFila = ""

        idCabeceraCol = ""
        cabeceraCol = ""

        alineacionCol = "{rank=min; Matriz;"
        alineacionElementosFila = ""
        alineacionElementosColumna= ""

        cabeceraElementosFila = ""
        enlacesElementosFila = ""

        cabeceraElementosColumna = ""
        enlacesElementosColumna= ""

        # RECORRIDO DE FILAS
        eFila = self.encabezadoFilas.inicio
        if eFila != None:
           
            cabeceraFila += 'Matriz -> "{}";\n'.format(str(hash(eFila)))
            #RECORRER TODAS LAS FILAS DE LA MATRIZ

            while eFila != None:
                #elemntos fila
                alineacionElementosFila += '{{rank=same; {};'.format(str(hash(eFila)))
                infoFilas = self.recorrerFilasMatriz(eFila)
                alineacionElementosFila += infoFilas[0] + "}\n"
                cabeceraElementosFila += infoFilas[1] + "\n"
                enlacesElementosFila += infoFilas[2] + "\n"


                idCabeceraFila += '"{}"[label = "{}"];\n'.format(str(hash(eFila)),"Hora:"+str(eFila.numero))
                if eFila.siguiente != None:
                    #filas
                    cabeceraFila += '"{}" -> "{}";\n'.format(str(hash(eFila)),str(hash(eFila.siguiente)))
                eFila = eFila.siguiente

         



        # RECORRIDO DE COLUMNAS
        eCol = self.encabezadoColumnas.inicio
        if eCol != None:
          
            cabeceraCol += 'Matriz -> "{}";\n'.format(str(hash(eCol)))
            while eCol != None:
              
                
                     infoCols = self.recorrerColumnasMatriz(eCol)
              
                     enlacesElementosColumna += infoCols[2] + "\n"

                #COLUMNAS
             
                     alineacionCol += '"{}";'.format(str(hash(eCol)))
                     idCabeceraCol += '"{}"[label="{}"];\n'.format(str(hash(eCol)),"Dia: "+str(eCol.numero))
                     if eCol.siguiente != None:
                        cabeceraCol += '"{}" -> "{}";\n'.format(str(hash(eCol)),str(hash(eCol.siguiente)))
                     else:
                        alineacionCol += '}\n\n'
                     eCol = eCol.siguiente


        acumInfo += alineacionCol + alineacionElementosFila  + alineacionElementosColumna\
                    + idCabeceraCol + idCabeceraFila  + cabeceraElementosFila +\
                     cabeceraElementosColumna + cabeceraCol + \
                    cabeceraFila +  enlacesElementosFila + \
                    enlacesElementosColumna + "\n}\n"
        s= Source(acumInfo,filename="C:\\Users\\ASUS\\Desktop\\Reportes_F2\\matrixRecordatorios", format="svg")
        s.view()
        #f = open('C:\\Users\\ASUS\\Desktop\\Reportes_F2\\grafo.dot','w')
       # try:
        #    f.write(acumInfo)
        #finally:
        #    f.close()

        #prog = "dot -Tpng  grafo.dot -o matrizRecordatorios.png"
        #os.system(prog)

    def recorrerFilasMatriz(self,nodoFil):
        nodoFila=nodoFil
        rank = ""
        enlaces = ""
        cabeceras = ""
        tmp = nodoFila.derecha
        enlaces += '"{}" -> "{}";\n'.format(str(hash(nodoFila)), str(hash(tmp)))
        while tmp != None:
            rank += '"{}";'.format(str(hash(tmp)))
            cabeceras += '"{}"[label = "{}"];\n'.format(str(hash(tmp)), str(tmp.getList().size()))
            if tmp.derecha != None:
                enlaces += '"{}" -> "{}";\n'.format(str(hash(tmp)), str(hash(tmp.derecha)))
            tmp = tmp.derecha
        # cabeceras += '"{}"[label = "{}"];\n'.format(str(hash(tmp)), str(tmp.getValue()))
        return [rank,cabeceras,enlaces]

    def recorrerColumnasMatriz(self,nodoColu):
        nodoCol=nodoColu
        rank = ""
        enlaces = ""
        cabeceras = ""
        tmp = nodoCol.abajo
        enlaces += '"{}" -> "{}";\n'.format(str(hash(nodoCol)), str(hash(tmp)))
        while tmp != None:
            rank += '"{}";'.format(str(hash(tmp)))
            cabeceras += '"{}"[label = "{}"];\n'.format(str(hash(tmp)), str(tmp.getList().size()))
            if tmp.abajo != None:
                enlaces += '"{}" -> "{}";\n'.format(str(hash(tmp)), str(hash(tmp.abajo)))
            tmp = tmp.abajo
        # cabeceras += '"{}"[label = "{}"];\n'.format(str(hash(tmp)), str(tmp.getValue()))
        return [rank,cabeceras,enlaces]
        
    def GraficarLista(self,fila,columna):
        if self.Exist(fila,columna) is True:
            lista=self.retornarNodoEn(fila,columna).getList()
            lista.Graficar_L_Tareaas()
        else:
            print("NO existe una lista con esas Coordenadas fial: ",fila,"  col:",columna)
    
    
      
           