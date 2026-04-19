# --- MODULO 5 ---
# helpers y formateo
#utilidades - Funciones 
#-----------------------------

import math

# EJERCICIO 4
def sumad(n):
    """Entrega la suma de las cifras de un número n"""
    suma = 0
    while n > 0:
        suma += n % 10
        n //= 10
    return suma


#EJERCICIO 5
def cuad(n):
    """Determina si el cuadrado de n es igual a la suma de los primeros n números impares"""
    cuadrado = n * n
    suma_impares = 0
    for i in range(1, n + 1):
        suma_impares += (2 * i - 1)
    return cuadrado == suma_impares

#EJERCICIO 8 
def sim(x):
    """Determina si x es simétrico (capicúa)"""
    s = str(x)
    return s == s[::-1]

#EJERCICIO 11
def fact(n):
    """Recibe un número entero n y devuelve su factorial"""
    if n <= 1:
        return 1
    resultado = 1
    for i in range(2, n + 1):
        resultado *= i
    return resultado


#EJERCICIO 13 
def polar(x, y):
    """Recibe coordenadas cartesianas (x, y) y entrega coordenadas polares (r, t)"""
    r = math.sqrt(x**2 + y**2)
    t = math.atan2(y, x)
    return r, t

def cartesiana(r, t):
    """Recibe coordenadas polares (r, t) y entrega coordenadas cartesianas (x, y)"""
    x = r * math.cos(t)
    y = r * math.sin(t)
    return x, y


# ejercicio 14
def aleatorio(x):
    """Suma los cuadrados de los dígitos del número x"""
    suma = 0
    while x > 0:
        digito = x % 10
        suma += digito ** 2
        x //= 10
    return suma


# ejercicio 16
def nd(n):
    """Determina recursivamente cuántos dígitos tiene un número entero n"""
    if n < 10:
        return 1
    else:
        return 1 + nd(n // 10)


# ejercicio 17
def digitos_impares(n):
    """Calcula recursivamente la cantidad de dígitos impares que contiene un número entero positivo"""
    if n < 10:
        return 1 if n % 2 == 1 else 0
    else:
        digito_actual = n % 10
        es_impar = 1 if digito_actual % 2 == 1 else 0
        return es_impar + digitos_impares(n // 10)