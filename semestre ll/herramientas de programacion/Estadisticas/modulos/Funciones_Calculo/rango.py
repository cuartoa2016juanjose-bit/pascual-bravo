#FUNCIONES RANGO
def obtener_rango(lista):
    if len(lista) == 0:
        return 0
    return max(lista) - min(lista);