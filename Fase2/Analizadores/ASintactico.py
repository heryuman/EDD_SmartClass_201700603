from Analizadores.ALexico import tokens

#diccionario de nombres
lista=[]



def p_statement_group(t):
    'INICIO : QO ELEMENTS QC elementos QO DOLLAR ELEMENTS QC'
    print('Ok')

def p_elementos_group(t):
    """elementos : elementos elemento
                 | elemento    
                 """
    
def p_elemento(t):
    #            ¿ element  type =    "cade" ?  ITEMS ¿      $     element  ? 
    'elemento : QO ELEMENT tip_elem QC items  QO DOLLAR ELEMENT QC'
    
    

def p_tip_elem(t):
    'tip_elem : TYPE EQUAL CHAIN'
    printTipo(t[3])



def p_items_group(t):
    """items : items item
             | item
             """
    
    

def p_item(t):
    """item : QO T_ITEM tipoItem EQUAL valorItem DOLLAR QC
    """
   # print(t[3].value)
    
    

def p_valorItem(t):
    """valorItem : CHAIN
                 | NUMBER
                 """
    printValor(t[1])
    
    return t[1]
def p_tipoItem(t):
    """tipoItem : CARNET
                | DPI
                | NOMBRE
                | CARRERA
                | PASSWORD
                | CREDITOS
                | EDAD
                | CORREO
                | DESC
                | MATERIA
                | FECHA
                | HORA
                | ESTADO
                | ID
                """
    
    


def printValor(valor):
  #  print("El valor: ",valor)
    lista.append(valor)

def printItem(item):
   # print("el item:",item)
    lista.append(item)

def printTipo(tip):
   # print("el tipo: ",tip)
    lista.append(tip)



import ply.yacc as yacc
parser=yacc.yacc()