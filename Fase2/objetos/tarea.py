class task:
    def __init__(self,_carnet,_nombre,_desc,_materia,_fecha,_hora,_estado):
        self.carnet=_carnet
        self.nombre=_nombre
        self.desc=_desc
        self.materia=_materia
        self.fecha=_fecha
        self.hora=_hora
        self.estado=_estado

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

