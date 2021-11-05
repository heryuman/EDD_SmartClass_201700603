class Nodo(object):
    def __init__(self,_llv, _carnet,apunte):
        self.llv = _llv
        self.lista_apuntes =[] 
        self.carnet = _carnet
        self.siguiente = None

        self.lista_apuntes.append(apunte)

    