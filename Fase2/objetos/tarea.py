class task:
    def __init__(self,_carnet,_nombre,_desc,_materia,_fecha,_hora,_estado):
        self.carnet=_carnet
        self.nombre=_nombre
        self.desc=_desc
        self.materia=_materia
        self.fecha=_fecha
        self.hora=_hora
        self.estado=_estado
    
    def setCarne(self,carnet):
        self.carnet=carnet
    def setNombre(self,nombre):
        self.nombre=nombre
    def setDes(self,desc):
        self.desc=desc
    def setMateria(self,materia):
        self.materia=materia
    def setFecha(self,fecha):
        self.fecha=fecha
    def setHora(self,hora):
        self.hora=hora
    def setEstado(self,estado):
        self.estado=estado

    def getCarnet(self):
        return self.carnet

    def getNombre(self):
        return self.nombre

    def getDes(self):
        return self.desc

    def getMateria(self):
        return self.materia

    def getFecha(self):
        return self.fecha

    def getHora(self):
        return self.hora

    def getEstado(self):
        return self.estado

