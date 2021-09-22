import re
from flask.signals import message_flashed
from Estructuras.Lista import LinkedListD

class year(object):
    def __init__(self,year):
        self.numY=year
        self.semestres=LinkedListD()
        self.meses=LinkedListD()
    def getYear(self):
        return self.numY
    def insertMont(self,mont):
        self.meses.push(mont)

    def insertSemes(self,semestre):
        if self.semestres.size()<2:
            self.semestres.push(semestre)
        else:
            print("se ha superado el numero de semestres a ingresar")

    def getMontList(self):
        return self.meses
    
    def getSemestreList(self):
        return self.semest

    def ExistMes(self,mees):
        exist =False
        for i in  range(self.meses.size()):
            if self.meses.getE(i).nombre==mees:
                exist=True
            else:
                print("no se encuentra...")
        return exist

    def getMes(self,m3s):
        exist =None
        for i in  range(self.meses.size()):
            if self.meses.getE(i).nombre==m3s:
                print(self.meses.getE(i).nombre)
                exist=self.meses.getE(i)
        return exist

    def getSemestre(self,semsetre):
        semstre=None
        for i in range(self.semestres.size()):
            if self.semestres.getE(i).numSemestre==semsetre:
                semstre=self.semestres.getE(i)
        return semstre

            


    

