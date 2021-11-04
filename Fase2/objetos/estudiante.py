from Estructuras.Lista import LinkedListD
from cryptography.fernet import Fernet
class estudiant(object):

    def __init__(self,carnet,dpi,nombre,carrera,correo,psw,creditos, edad):
        self.carnet=carnet
        self.dpi=dpi
        self.nombre=nombre
        self.carrera=carrera
        self.correo=correo
        self.psw=psw
        self.creditos=creditos
        self.edad=edad
        self.anios=LinkedListD()

    def setCarnet(self,carnet):
        self.carnet=carnet
    
    def setDpi(self,dpi):
        self.dpi=dpi
    def setNombre(self,nombre):
        self.nombre=nombre
    def setCarrera(self,carrera):
        self.carrera=carrera
    def setMail(self,mail):
        self.correo=mail
    def setPass(self,pas):
        self.psw=pas
    def setCreditos(self,credits):
        self.creditos=credits
    def setEdad(self,edad):
        self.edad=edad

    def getCarnet(self):
        return self.carnet

    def getDpi(self):
        return self.dpi

    def getNombre(self):
        return self.nombre
    def getPass(self):
        return self.psw
    def getCarrera(self):
        return self.carrera

    def getMail(self):
        return self.correo

    def getCredits(self):
        return self.creditos
    
    def getAge(self):
        return self.edad

   

    def ExistAnio(self,anio):
        exist=False
        for i in range(self.anios.size()):
            if self.anios.getE(i).numY==anio:
                exist =True
        return exist


    def getAño(self,anio):
        exist=None
        for i in range(self.anios.size()):
            if self.anios.getE(i).numY==anio:
                exist =self.anios.getE(i)
                print("getAnio",exist.numY)
        return exist

    def getCarnetDecript(self):
        key=b'XHvL5SIbLZWAPq-u0jgwkG6TMJ3ivo6ZbxwrdL6W8K4='
        f=Fernet(key)

        desencriptado=f.decrypt(self.carnet)
        return int(desencriptado)