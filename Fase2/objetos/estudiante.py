class estudiant:

    def __init__(self,carnet,dpi,nombre,carrera,correo,psw,creditos, edad,lista):
        self.carnet=carnet
        self.dpi=dpi
        self.nombre=nombre
        self.carrera=carrera
        self.correo=correo
        self.psw=psw
        self.creditos=creditos
        self.edad=edad
        self.lista=lista

    def getCarnet(self):
        return self.carnet

    def getDpi(self):
        return self.dpi

    def getNombre(self):
        return self.nombre

    def getCarrera(self):
        return self.carrera

    def getMail(self):
        return self.correo

    def getCredits(self):
        return self.creditos
    
    def getAge(self):
        return self.edad

    def getList(self):
        return self.lista


      