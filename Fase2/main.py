
from re import I
import re
from Estructuras.arbolAVL import AVLTree
from objetos.estudiante import estudiant
from objetos.tarea import task
from Estructuras.arbolB import Arbol_B
from Estructuras.Lista import LinkedListD
from Estructuras.matriz import MatrizD
from objetos.curso import course


 #   f=open('SalidaSmartClass.txt',"r", encoding="utf-8")
 #   entrada=f.read()
 #   f.close()
 #   parser.parse(entrada)
    #T_estudiantes= AVLTree()
    
 

    
    #print("Carnets de tareas:")
    #T_tareas.mostrar(T_tareas.root)
   # print("Carnet Estudiantes: ")
   # T_estudiantes.mostrar(T_estudiantes.root)
    #print("se insertaron los elementos correctamente")
    
    #T_estudiantes.delete(201309035)
    #T_estudiantes.obtenerAlumno(201413927)





#for i in range(1,26):
 #   nuevoB.insertar(i)





#nuevoB.eliminar(12)


"""nuevoB.RecorreNodo()

nuevoB.RecorreNodo()
#nuevoB.eliminar(6)"""
#
#
#nuevoB.eliminar(5)
#nuevoB.eliminar(3)
#nuevoB.RecorreNodo()
#nuevoB.eliminar(1)
#nuevoB.RecorreNodo()
#nuevoB.eliminar(18)
#nuevoB.RecorreNodo()
#nuevoB.Graficar()

"""
nLista=LinkedListD()



for i in range(20):
    
    nEstudiante= estudiant(i,i,"nombre"+str(i),"carrera","correo","pass",i,i,"")
    nLista.push(nEstudiante)
    
print("Estudiante: ",nLista.getE(19).getNombre())"""
#nLista.mostrar()

"""
clase1=course(102,"mate",7,"","si")
clase2=course(40,"mate",7,"","si")
clase3=course(721,"mate",7,"","si")
clase4=course(541,"mate",7,"","si")
clase5=course(101,"mate",7,"","si")
clase6=course(960,"matematica",7,"n","False")
clase7=course(107,"matematica",7,"n","False")
clase8=course(770,"matematica",7,"n","False")
clase9=course(796,"matematica",7,"n","False")
clase11=course(777,"matematica",7,"n","False")
clase10=course(772,"matematica",7,"n","False")
clase12=course(18,"matematica",7,"n","False")
clase13=course(774,"matematica",7,"n","False")
clase14=course(281,"matematica",7,"n","False")
clase15=course(2036,"matematica",7,"n","False")

#arbolB=Arbol_B(5)


#arbolB.RecorreNodo()
#arbolB.Graficar()


matrriz=MatrizD(1)

ntaraea1=task(201700603,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",20,"pendiente")
ntaraea2=task(201700404,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",10,"pendiente")
ntaraea3=task(201700841,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",9,"pendiente")
ntaraea4=task(201701135,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",20,"pendiente")
ntaraea5=task(201700628,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",13,"pendiente")
ntaraea6=task(201701142,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",16,"pendiente")
ntaraea7=task(201700000,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",16,"pendiente")
ntaraea8=task(201700001,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",16,"pendiente")
ntaraea9=task(201700002,"crear grafos ","el estudiante debe crear grafo e la tarea","EDD","18/01/2021",16,"pendiente")

matrriz.insertarenLaListadelespacio(ntaraea7,11,18)
matrriz.insertarenLaListadelespacio(ntaraea5,8,13)
matrriz.insertarenLaListadelespacio(ntaraea1,11,18)
matrriz.insertarenLaListadelespacio(ntaraea2,10,17)
matrriz.insertarenLaListadelespacio(ntaraea3,11,18)
matrriz.insertarenLaListadelespacio(ntaraea9,11,18)
matrriz.insertarenLaListadelespacio(ntaraea4,7,29)

matrriz.insertarenLaListadelespacio(ntaraea6,11,15)
matrriz.insertarenLaListadelespacio(ntaraea8,11,18)"""



#matrriz.eliminarEn_el_Espacio(11,15,2)

#matrriz.generarGrafo()
#matrriz.GraficarLista(11,18)
#matrriz.graficar()


pruebaHeads=LinkedListD()

from Estructuras.nods import Head



print()
#---------------------------INICIO DE LA API----------------------------------------

from flask import Flask, json,jsonify,request
from Analizadores.ASintactico import parser
from Analizadores.ASintactico import lista as datosTXT
from objetos.date import the_date
from objetos.año import year
from cryptography.fernet import Fernet
import hashlib


main=Flask(__name__)

BD_Cursos=Arbol_B(5) 
BD_Almumnos=AVLTree()
@main.route('/ping')
def ping():
    return'Pong'

@main.after_request
def after_request(response):
    response.headers["Access-Control-Allow-Origin"] = "*" # <- You can change "*" for a domain for example "http://localhost"
    response.headers["Access-Control-Allow-Credentials"] = "true"
    response.headers["Access-Control-Allow-Methods"] = "POST, GET, OPTIONS, PUT, DELETE"
    response.headers["Access-Control-Allow-Headers"] = "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization"
    return response


@main.route('/carga',methods=['POST'])
def cargar():
    tipo_de_Cargar=request.json['tipo']
#-------------------------------SECCION DE CARGA ESTUDIANTES Y TAREAS-------------------------------------------------
    if tipo_de_Cargar == 'estudiante':
        dirTxt=request.json['path']
        f=open(dirTxt,"r", encoding="utf-8")
        entrada=f.read()
        f.close()
        parser.parse(entrada)
    
        Lestudiantes=[]
        Ltareas=[]
        for i in range(len(datosTXT)):
            if datosTXT[i]=='user' and len(datosTXT[i+1])==9 and len(datosTXT[i+2])==13:
            


                nEstudiante=estudiant(int(datosTXT[i+1]),
                                      datosTXT[i+2],
                                      datosTXT[i+3],
                                      datosTXT[i+4],
                                      datosTXT[i+5],
                                      datosTXT[i+6],
                                      datosTXT[i+7],
                                      datosTXT[i+8])
                Lestudiantes.append(nEstudiante)

            elif datosTXT[i]=='task':
                nTarea=task(int(datosTXT[i+1]),
                            datosTXT[i+2],
                            datosTXT[i+3],
                            datosTXT[i+4],
                            datosTXT[i+5],
                            datosTXT[i+6],
                            datosTXT[i+7])
                Ltareas.append(nTarea)
        i=0
        for tarea in Ltareas:
            i+=1
    
    #  CARGANDO A SUS RESPECTIVAS ESTRUCTURAS, PRIMERO CARGAMOS ESTUDAINTES
    
    for estudiante in Lestudiantes:
        BD_Almumnos.put(estudiante)

    # CARGANDO TAREAS

    for tarea in Ltareas:
        if BD_Almumnos.obtenerAlumno(tarea.getCarnet()) is not None:
            alumno=BD_Almumnos.obtenerAlumno(tarea.getCarnet())
            print("al ",alumno.carnet)
            date=stripDate(tarea)
            filaHora=date.getHour()
            columDia=date.getDay()
            profMes=date.getMonth()
            anio=date.getYear()
            if alumno.anios.size()==0:
                objAnio=year(anio)          #creamos un objeto año para agregarlo a la lista de años del estudiante si está vacío
                
                matrix=MatrizD(profMes)     #creamos la mariz de tareas del correspondiente mes
                matrix.insertarenLaListadelespacio(tarea,filaHora,columDia)
                objAnio.insertMont(matrix)#en la lista de meseses del objeto año agregamos la matriz del mes correspondiente
                alumno.anios.push(objAnio)
            else:
                if alumno.ExistAnio(anio) !=False:
                    elAnio=alumno.getAño(anio)
                    if elAnio.ExistMes(profMes) != False:
                        elMes=elAnio.getMes(profMes)
                        
                        elMes.insertarenLaListadelespacio(tarea,filaHora,columDia)
                    else:
                        #el mes no existe se debe crear una matriz
                        print("se va a una nueva matrix")
                        matrix2=MatrizD(profMes)
                        matrix2.insertarenLaListadelespacio(tarea,filaHora,columDia)
                        elAnio.insertMont(matrix2)
                        print("se omserta la matrix 2")
                else:
                    #no existe el año en la lista de años pero ya existe un año 
                     matrix2=MatrizD(profMes)
                     matrix2.insertarenLaListadelespacio(tarea,filaHora,columDia)
                     objAnio2=year(anio) 
                     objAnio2.insertMont(matrix2)
                     alumno.anios.push(objAnio2)




                    




    return jsonify(
        {
            'status':'ok',
             'msg_c':'CargaExitosa'
        }

    )
def stripDate(element):
         date=element.getFecha()

         _date=date.split("/")
         day=_date[0]
         month=_date[1]
         year=_date[2]
         hour=str(element.getHora())
         houra=""
         if len(_date[0])==2 and int(day)<10:
             day=_date[0].strip("0")

         if len(_date[1])==2 and int(month)<10:
             month=_date[1].strip("0")

         if len(hour)==4:
             h=hour.split(":")
             houra=h[0]
         elif len(hour)==5:
             h=hour.split(":")
             houra=h[0]
            
         else:
             houra=hour


         newDate=the_date(int(day),int(month),int(year),int(houra))
         return newDate

#------------------------------CARGA MASIVA DE ESTUDIANTES--------------------------------------------

@main.route('/masivaEstudiantes',methods=['POST'])
def masivaEstudiantes():
    print()
    if request.method == 'POST':
        arrayEstudiantes= request.json["estudiantes"]
        key=b'XHvL5SIbLZWAPq-u0jgwkG6TMJ3ivo6ZbxwrdL6W8K4='
        f=Fernet(key)

        for item in arrayEstudiantes:
            if len(str(item['carnet']))==9:
                if len(str(item['DPI']))==13:
                    carnet=f.encrypt(str(item['carnet']).encode())
                    dpi= f.encrypt(str(item['DPI']).encode())
                    nombre=f.encrypt(str(item['nombre']).encode())
                    carrera=f.encrypt(str(item['carrera']).encode())
                    correo=f.encrypt(str(item['correo']).encode())
                    psw=f.encrypt(hashlib.sha256(str(item['password']).encode()).digest())
                    edad=f.encrypt(str(item['edad']).encode())

                    nEstudiante=estudiant(carnet,dpi,nombre,carrera,correo,psw,"",edad)
                    BD_Almumnos.put(nEstudiante)
                else:
                     return{
                    'status':'error',
                    'result':'el DPI: '+str(item['DPI'])+'no tiene la cantidad de digitos permitida'
                }
            else:
                return{
                    'status':'error',
                    'result':'el carnet: '+str(item['carnet'])+'no tiene la cantidad de digitos permitida'
                }
            
            


        return {
            'msg_masive':'La carga masiva de estudiantes fue exitosa!!',
            'status':'ok'
        }
#------------------------------CARGA MASIVA DE APUNTES---------------------------------------------------------------------------
from tablahash.Estructuras.TablaHash import TablaHash
from objetos.apunte import apunte

hashApuntes= TablaHash(7)
@main.route('/masivaApuntes',methods=['POST'])
def masivaApuntes():
    if request.method=='POST':
    
        for item in request.json['usuarios']:
            for item2 in item['apuntes']:
                if BD_Almumnos.obtenerAlumno(int(item['carnet'])) is not None:
                    print(item['carnet'])
                    print(item2['Título'])
                    print(item2['Contenido'])
                    print('-------------------')
                    hashApuntes.insertarHash(int(item['carnet']),apunte(str(item2['Título']),str(item2['Contenido'])))
                else:
                    return {
                            'status':'error',
                            'result':'No se pudo efectuar la carga porque uno o varios estudiantes no existen'
                    }
                
    return {
        'status':'ok',
         'result':'La Carma masiva de apuntes se realizó con exito'
    }

#------------------------------------carga de un apunte-----------------------------------------------------------------
@main.route('/apunte', methods=['POST','GET'])
def cargarApunte():
    if request.method =='POST':
        carnet= int(request.json['carnet'])
        titulo=str(request.json['titulo'])
        cont=str(request.json['contenido'])
        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            hashApuntes.insertarHash(carnet,apunte(titulo,cont))
            return {
                'status':'ok',
                'result':'Se ha agregado la nota exitosamente!'
            }

    elif request.method== 'GET':
        print(request.method)
        carnet=request.args()
        print(carnet)
        return 'exito'
    
    return 'fail'

@main.route('/getapunte',methods=['POST'])
def getApuntes():
    if request.method=='POST':
        carnet= int(request.json['carnet'])
        apuntes=hashApuntes.getlistaApuntes(carnet)
        json_data={}
        json_data['apuntes']=[]
        for apunte in apuntes:
            arreglo_json={
                'titulo':str(apunte.title),
                'contenido':str(apunte.content)
            }
            json_data['apuntes'].append(arreglo_json)
        
        #print(json_data['apuntes'])
    
        return jsonify(json_data['apuntes'])

#------------------------------SECCION DE REPORTES--------------------------------------------------------------------------------

@main.route('/reporte',methods=['POST'])
def reportar():
    tipo=request.json['tipo']
    if tipo==0:
        BD_Almumnos.graficar()
        return {
            "status":'ok',
            "result":'Se generó el reporte de estudiantes correctamente'
        }

    elif tipo==5:
        BD_Almumnos.graficarDecript()
        return {
            "status":'ok',
            "msg_r0":'Se generó el reporte de estudiantes correctamente'
        }
    elif tipo==6:
        if hashApuntes.id>0:
            hashApuntes.graficaHash()
            return{"status":'ok',
                   'result':'Se genero el reporte de la TablaHash'
                   }
        else:
            return {"status":'error',
                   'result':'Se produjo un error porque no hay apuntes en la lista'
                   }
        

    elif tipo==1:
        carnet=request.json['carnet']
        anio=request.json['año']
        mes=request.json['mes']
        if BD_Almumnos.obtenerAlumno(int(carnet)) is not None:
            alumno=BD_Almumnos.obtenerAlumno(int (carnet))
            #buscamos que el año exista
            if alumno.ExistAnio(anio) !=False:
                elAnio=alumno.getAño(anio)
                if elAnio.ExistMes(mes) != False:
                    elMes=elAnio.getMes(mes)
                    elMes.generarGrafo()

        return "Grafo generado para el mes"+str(mes)+"del alumno: "+str(carnet)

    elif tipo==2:
        carnet= request.json['carnet']
        anio= request.json['año']
        mes=request.json['mes']
        dia=request.json['dia']
        hora=request.json['hora']
        fecha=str(dia)+"/"+str(mes)+"/"+str(anio)
        unatarea=task("","","","",fecha,hora,"")
        date=stripDate(unatarea)
        lhora=date.getHour()
        if BD_Almumnos.obtenerAlumno(int(carnet)) is not None:
            alumno=BD_Almumnos.obtenerAlumno(int (carnet))
            if alumno.ExistAnio(int(anio)) !=False:
                elAnio=alumno.getAño(int(anio))
                if elAnio.ExistMes(int(mes)) != False:
                    elMes=elAnio.getMes(int(mes))
                    elMes.GraficarLista(int(lhora),int(dia))
                    return "se Generó el grafo de la lista de Tareas"
            else:
                return "NO existen datos con esas Coordenadas"

    elif tipo==3:
        if BD_Cursos.raiz is not None:
            BD_Cursos.Graficar()
            return "Se generó el grafo de Cursos Pensum"
        else:
            return"ERROR!!,No existen cursos Cargados al Arbol"
    
    elif tipo==4:
        carnet=int(request.json['carnet'])
        anio=int(request.json['año'])
        semestre=int(request.json['semestre'])
        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            alumno=BD_Almumnos.obtenerAlumno(carnet)
            if alumno.ExistAnio(int(anio)) !=False:
                elAnio=alumno.getAño(int(anio))
                if elAnio.getSemestre(semestre) is not None:
                    elsemestre=elAnio.getSemestre(semestre)
                    elsemestre.cursos.Graficar()
                    return "se genero la grafica de cursos del alumno: "+str(carnet)+" del "+str(semestre)+" semestre"
                else:
                    return "No se puede generar la grafica porque el semestre no existe"
            else:
                return "NO se puede generar la grafica porque el año no existe"
        else:
            return "No se puede generar la grafica porque el estudiante no Existe"



#-----------------------------------CARGA CURSOS DEL PENSUM--------------------------------------------------------------------

@main.route('/cursosPensum',methods=['POST'])
def cargaJsonCursos():

    if request.method=='POST':
        for item in request.json['Cursos']:
            print(item['Codigo'])
            print(item['Nombre'])
            print(item['Creditos'])
            print(item['Prerequisitos'])
            print(item['Obligatorio'])
            print("/*/*/*/*/*/*/")
            nCurso=course(int(item['Codigo']),item['Nombre'],item['Creditos'],item['Prerequisitos'],item['Obligatorio'])
            BD_Cursos.insertar(nCurso)

        return "cursos cargados"
          
#---------------------------------------CARGA CURSOS DEL ESTUDIANTE--------------------------------------------------------------------          
from objetos.semestre import semester
@main.route('/cursosEstudiante',methods=['POST'])
def estudiantes():
    if request.method=='POST':
        print("--------------------------------")
        for item in request.json['Estudiantes']:
            for item2 in item['Años']:
                for item3 in item2['Semestres']:
                    for item4 in item3['Cursos']:
                         print("^^^^^^^^^^^^^^^^^^^^^^^^")
                         print("Carnet: ",item['Carnet'])
                         print("Año: ",item2['Año'])
                         print("Semestre: ",item3['Semestre'])
                         print("codigo: ",item4['Codigo'])
                         print("Nombre: ",item4['Nombre'])
                         print("Creditos: ","")
                         print("Prererq: ",item4['Prerequisitos'])
                         print("Oblig: ",item4['Obligatorio'])
                         print("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/")

                         if BD_Almumnos.obtenerAlumno(int(item['Carnet'])) is not None:
                             alumno=BD_Almumnos.obtenerAlumno(int(item['Carnet']))
                             if alumno.ExistAnio(int(item2['Año'])) !=False:
                                 elAnio=alumno.getAño(int(item2['Año']))
                                 if elAnio.semestres.isEmpty()==True:
                                     nSemestre=semester(int(item3['Semestre']))
                                     cursoAlumno=course(int(item4['Codigo']),item4['Nombre'],"",item4['Prerequisitos'],item4['Obligatorio'])
                                     nSemestre.cursos.insertar(cursoAlumno)
                                     elAnio.semestres.push(nSemestre)
                                 else:
                                    if elAnio.getSemestre(int(item3['Semestre'])) is None:
                                        nSemestre=semester(int(item3['Semestre']))
                                        cursoAlumno=course(int(item4['Codigo']),item4['Nombre'],"",item4['Prerequisitos'],item4['Obligatorio'])
                                        nSemestre.cursos.insertar(cursoAlumno)
                                        elAnio.semestres.push(nSemestre)

                                    else:
                                        elsemestre=elAnio.getSemestre(int(item3['Semestre']))
                                        cursoAlumno=course(int(item4['Codigo']),item4['Nombre'],"",item4['Prerequisitos'],item4['Obligatorio'])
                                        elsemestre.cursos.insertar(cursoAlumno)
                             else:
                                 nAnio=year(int(item2['Año']))
                                 nSemestre=semester(int(item3['Semestre']))
                                 cursoAlumno=course(int(item4['Codigo']),item4['Nombre'],"",item4['Prerequisitos'],item4['Obligatorio'])
                                 nSemestre.cursos.insertar(cursoAlumno)
                                 nAnio.semestres.push(nSemestre)
                                 alumno.anios.push(nAnio)
        return "se han cargado los cursos del estudiante: "

                         #hay que crear un archivo de carga para esta prueba

#------------------------------CRUD ESTUDIANTE---------------------------------------  
                      
@main.route('/estudiante',methods=['GET','POST','PUT','DELETE'])
def CRUD_ESTUDIANTES():
    
    if request.method == 'POST':#--------------login
        carnet=int(request.json['usuario'])
        pswd= str(request.json['password'])



        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            elAlumno=BD_Almumnos.obtenerAlumno(carnet)
            pswhash=hashlib.sha256(pswd.encode())
            key=b'XHvL5SIbLZWAPq-u0jgwkG6TMJ3ivo6ZbxwrdL6W8K4='
            f=Fernet(key)
            passAlumno=f.decrypt(elAlumno.getPass())
            print(passAlumno)
            print(pswhash.digest())

            if pswhash.digest() == passAlumno:
                print
                return jsonify( {
                   'status':'200',
                    'result':{
                    "carnet":str(elAlumno.getCarnetDecript()),
                    "dpi":str(elAlumno.getDpi()),
                    "nombre":str(elAlumno.getNombre()),
                    "carrera":str(elAlumno.getCarrera()),
                    "edad":str(elAlumno.getAge())
                 }
                })
            else:
                return jsonify(
                    {
                        'status':'error',
                         'error_msg':'Contraseña Incorrecta'
                    }
                            )


            
        else:
            return jsonify(
                    {
                        'status':'error',
                         'error_msg':'el estuadiante con carnet: '+str(carnet)+' no existe'
                    }
                            )



    elif request.method=='DELETE':
        carnet=int(request.json['carnet'])
        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            BD_Almumnos.delete(carnet)
            return "Alumno: "+str(carnet)+"Eliminado con Exito"
        else:
            return "El "+str(carnet)+" no existe!"

    elif request.method=='PUT':
        carnet=int(request.json['carnet'])
        dpi=int(request.json['DPI'])
        nombre=request.json['nombre']
        carrera=request.json['carrera']
        mail=request.json['correo']
        psw=request.json['password']
        credits=int(request.json['creditos'])
        edad=int(request.json['edad'])
        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            elAlumno=BD_Almumnos.obtenerAlumno(carnet)
            elAlumno.setCarnet(carnet)
            elAlumno.setDpi(dpi)
            elAlumno.setNombre(nombre)
            elAlumno.setCarrera(carrera)
            elAlumno.setMail(mail)
            elAlumno.setPass(psw)
            elAlumno.setCreditos(credits)
            elAlumno.setEdad(edad)

            return "El alumno: "+nombre+" se ha actualizado correctamente!"
        else:
            return "El Alumno: "+str(carnet)+ " no existe!!"

@main.route('/registro',methods=['GET','POST','PUT','DELETE'])
def regEstudiante():

       if request.method=='POST':
           if len(request.json['carnet'])==9:
               if len(request.json['dpi'])==13:
                   carnet=str(request.json['carnet'])
                   dpi=str(request.json['dpi'])
                   nombre=str(request.json['nombre'])
                   carrera=str(request.json['carrera'])
                   mail=str(request.json['correo'])
                   psw=str(request.json['password'])
    #credits=int(request.json['creditos'])
                   edad=(str(request.json['edad']))

    #---------ENCRIPTAMOS LOS DATOS----------
                   key=b'XHvL5SIbLZWAPq-u0jgwkG6TMJ3ivo6ZbxwrdL6W8K4='
                   f=Fernet(key)
                   carnetEnc=f.encrypt(carnet.encode())
                   dpiEnc=f.encrypt(dpi.encode())
                   nombreEnc=f.encrypt(nombre.encode())
                   carreraEnc=f.encrypt(carrera.encode())
                   mailEnc=f.encrypt(mail.encode())
                   pswhash=hashlib.sha256(psw.encode())
                   pswEnc=f.encrypt(pswhash.digest())
                   edadEnc=f.encrypt(edad.encode())
                   nEstudiante=estudiant(carnetEnc,dpiEnc,nombreEnc,carreraEnc,mailEnc,pswEnc,"",edadEnc)
                   BD_Almumnos.put(nEstudiante)
                   print()
                   return jsonify(
                    {
                        'status':'ok',
                         'result':'el estuadiante con carnet: '+str(carnet)+' se ingresó con exito!'
                    }
                            )
               else:
                    return jsonify(
                    {
                        'status':'error',
                         'result':'el DPI que se ingreso no tiene la cantidad correcta de digitos!'
                    }
                            )
           else:
                    return jsonify(
                    {
                        'status':'error',
                         'result':'el carnet que se ingreso no tiene la cantidad correcta de digitos!'
                    }
                            )
#------------------------------------CRUD RECORDATORIOS---------------------------------------------------------------------
@main.route('/recordatorios',methods=['GET','POST','PUT','DELETE'])
def CRUD_RECORDATORIOS():
    if request.method== 'POST':
        carnet=int(request.json['Carnet'])
        nombre=request.json['Nombre']
        desc=request.json['Descripcion']
        materia=request.json['Materia']
        fecha=request.json['Fecha']
        hora=request.json['Hora']
        estado=request.json['Estado']
        if BD_Almumnos.obtenerAlumno(carnet) is not None:
            alumno=BD_Almumnos.obtenerAlumno(carnet)
            tarea=task(carnet,nombre,desc,materia,fecha,hora,estado)
            date=stripDate(tarea)
            filaHora=date.getHour()
            columDia=date.getDay()
            profMes=date.getMonth()
            anio=date.getYear()
            if alumno.anios.size()==0:
                objAnio=year(anio)          #creamos un objeto año para agregarlo a la lista de años del estudiante si está vacío
                
                matrix=MatrizD(profMes)     #creamos la mariz de tareas del correspondiente mes
                matrix.insertarenLaListadelespacio(tarea,filaHora,columDia)
                objAnio.insertMont(matrix)#en la lista de meseses del objeto año agregamos la matriz del mes correspondiente
                alumno.anios.push(objAnio)
                return "se ha cargado la tarea correctamente"
            else:
                if alumno.ExistAnio(anio) !=False:
                    elAnio=alumno.getAño(anio)
                    if elAnio.ExistMes(profMes) != False:
                        elMes=elAnio.getMes(profMes)
                        
                        elMes.insertarenLaListadelespacio(tarea,filaHora,columDia)
                        return "se ha cargado la tarea correctamente"
                    else:
                        #el mes no existe se debe crear una matriz
                        print("se va a una nueva matrix")
                        matrix2=MatrizD(profMes)
                        matrix2.insertarenLaListadelespacio(tarea,filaHora,columDia)
                        elAnio.insertMont(matrix2)
                        print("se omserta la matrix 2")
                        return "se ha cargado la tarea correctamente"
                else:
                    #no existe el año en la lista de años pero ya existe un año 
                     matrix2=MatrizD(profMes)
                     matrix2.insertarenLaListadelespacio(tarea,filaHora,columDia)
                    
                     objAnio2=year(anio) 
                     objAnio2.insertMont(matrix2)
                     alumno.anios.push(objAnio2)
                     return "se ha cargado la tarea correctamente"
        else:
            return "No se ha cargado la tarea porque el estudiante no existe"
    elif request.method=='GET':
        fecha=request.json['Fecha']
        hora =request.json['Hora']
        pos=request.json['Posicion']
        carnet=request.json['Carnet']

        tarea=task("","","","",fecha,hora,"")
        date=stripDate(tarea)
        filaHora=date.getHour()
        columDia=date.getDay()
        profMes=date.getMonth()
        anio=date.getYear()

        if BD_Almumnos.obtenerAlumno(int(carnet)) is not None:
            alumno=BD_Almumnos.obtenerAlumno(int (carnet))
            if alumno.ExistAnio(int(anio)) !=False:
                elAnio=alumno.getAño(int(anio))
                if elAnio.ExistMes(int(profMes)) != False:
                    elMes=elAnio.getMes(int(profMes))
                    if elMes.obteneEn_el_Espacio(int(filaHora),int(columDia),int(pos)) is not None:
                        tarea=elMes.obteneEn_el_Espacio(int(filaHora),int(columDia),int(pos))
                        
                        return jsonify({
                            "Carnet":tarea.getCarnet(),
                            "Nombre":tarea.getNombre(),
                            "Descripcion:":tarea.getDes(),
                            "Materia":tarea.getMateria(),
                            "Fecha":tarea.getFecha(),
                            "Hora":tarea.getHora(),
                            "Estado":tarea.getEstado()
                        })
                    else:
                        return "No existe tarea en las coordenadas indicadas"
                else:
                    return "no existe el mes de la tarea indicada"
            else:
                return "No existe el año de la tarea indicada"
        else:
            return "no existe el alumno de la tarea indicada"
    
    elif request.method== 'DELETE':
        fecha=request.json['Fecha']
        hora =request.json['Hora']
        pos=request.json['Posicion']
        carnet=request.json['Carnet']    

        tarea=task("","","","",fecha,hora,"")
        date=stripDate(tarea)
        filaHora=date.getHour()
        columDia=date.getDay()
        profMes=date.getMonth()
        anio=date.getYear()

        if BD_Almumnos.obtenerAlumno(int(carnet)) is not None:
            alumno=BD_Almumnos.obtenerAlumno(int (carnet))
            if alumno.ExistAnio(int(anio)) !=False:
                elAnio=alumno.getAño(int(anio))
                if elAnio.ExistMes(int(profMes)) != False:
                    elMes=elAnio.getMes(int(profMes))
                    if elMes.obteneEn_el_Espacio(int(filaHora),int(columDia),int(pos)) is not None:
                        elMes.eliminarEn_el_Espacio(int(filaHora),int(columDia),int(pos))
                        return "la tarea ha sido eliminada exitosamente"
                        
                    else:
                        return "No existe tarea en las coordenadas indicadas"
                else:
                    return "no existe el mes de la tarea indicada"
            else:
                return "No existe el año de la tarea indicada"
        else:
            return "no existe el alumno de la tarea indicada"
    elif request.method=='PUT':

        carnet=int(request.json['Carnet'])
        nombre=request.json['Nombre']
        desc=request.json['Descripcion']
        materia=request.json['Materia']
        fecha=request.json['Fecha']
        hora=request.json['Hora']
        estado=request.json['Estado']
        pos=request.json['Posicion']

        tarea=task("","","","",fecha,hora,"")
        date=stripDate(tarea)
        filaHora=date.getHour()
        columDia=date.getDay()
        profMes=date.getMonth()
        anio=date.getYear()
        if BD_Almumnos.obtenerAlumno(int(carnet)) is not None:
            alumno=BD_Almumnos.obtenerAlumno(int (carnet))
            if alumno.ExistAnio(int(anio)) !=False:
                elAnio=alumno.getAño(int(anio))
                if elAnio.ExistMes(int(profMes)) != False:
                    elMes=elAnio.getMes(int(profMes))
                    if elMes.obteneEn_el_Espacio(int(filaHora),int(columDia),int(pos)) is not None:
                        tarea=elMes.obteneEn_el_Espacio(int(filaHora),int(columDia),int(pos))
                        tarea.setCarne(carnet)
                        tarea.setNombre(nombre)
                        tarea.setDes(desc)
                        tarea.setMateria(materia)
                        tarea.setEstado(estado)
                        
                        return "tarea modificada Exitosamete!!"
                    else:
                        return "No existe tarea en las coordenadas indicadas"
                else:
                    return "no existe el mes de la tarea indicada"
            else:
                return "No existe el año de la tarea indicada"
        else:
            return "no existe el alumno de la tarea indicada"











if __name__ == '__main__':
    main.run(debug=True,port=3000)
