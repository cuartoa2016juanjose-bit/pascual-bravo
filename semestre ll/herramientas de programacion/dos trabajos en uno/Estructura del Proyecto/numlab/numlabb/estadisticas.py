# --- MODULO 3 ---
# análisis estadístico
# estadistica - Funciones
#-------------------------------------

import random

# EJERCICIO 9 
def alfin(n):
    """Entrega la cantidad de veces que debe lanzarse un dado hasta obtener el número n"""
    lanzamientos = 0
    while True:
        lanzamientos += 1
        if random.randint(1, 6) == n:
            return lanzamientos


# ejercicio 18
def combinaciones(m, n):
    """Calcula recursivamente combinaciones C(m,n) = C(m-1, n-1) + C(m-1, n)"""
    if n == 0 or n == m:
        return 1
    elif n == 1 or n == m - 1:
        return m
    else:
        return combinaciones(m - 1, n - 1) + combinaciones(m - 1, n)
    