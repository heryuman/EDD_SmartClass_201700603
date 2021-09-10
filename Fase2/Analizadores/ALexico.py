reservadas={

        'elements':'ELEMENTS',
        'element':'ELEMENT',
        'type':'TYPE',
        'item':'T_ITEM',
        'carnet':'CARNET',
        'nombre':'NOMBRE',
        'descripcion':'DESC',
        'materia':'MATERIA',
        'fecha':'FECHA',
        'hora':'HORA',
        'estado':'ESTADO',
        'dpi':'DPI',
        'carrera':'CARRERA',
        'password':'PASSWORD',
        'credios':'CREDITOS',
        'correo':'CORREO',
        'edad':'EDAD'

}
tokens=[
        'ID',
        'CHAIN',
        'NUMBER',
        'EQUAL',
        'QO',
        'QC',
        'DOLLAR'
]+list(reservadas.values())

t_EQUAL=r'\='
t_QO=r'\¿'
t_QC=r'\?'
t_DOLLAR=r'\$'
t_ignore=' \t \n \r'


def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type=reservadas.get(t.value.lower(),'ID')
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += t.value.count("\n")


def t_CHAIN(t):
    r'\".*?\"'
    t.value=t.value[1:-1]
   # print("la cadena es en chain: ",t.value)
    return t

def t_NUMBER(t):
    r'\d+'
    try:
        t.value=int(t.value)
        print("el numero es: ",t.value)
    except ValueError:
        print("Valor incorrecto",t.value)
    return t
def t_error(t):
     print(f"Lex error at {t.value!r}")


import ply.lex as lex
import re
lexer = lex.lex(reflags=re.IGNORECASE)







