class course(object):
    def __init__(self,codigoCurso  ,nombre,creditos,preRec,oblig):
        self.codigoCurso=codigoCurso
        self.nombreCurso=nombre
        self.creditosCurso=creditos
        self.CursoPrerequisito=preRec
        self.CursoObligatorio=oblig

    def getCodigo(self):
        return self.codigoCurso

    
    def getNombre(self):
        return  self.nombreCurso