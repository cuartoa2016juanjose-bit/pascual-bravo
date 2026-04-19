#--- MODULO 1 ---
#divisores, primos, perfectos
#teorias de numeros - Funciones
#-----------------------------------

#EJERCICIO 1
def conteo(n):
    """Entrega la cantidad de divisores enteros positivos de n"""
    divisores = 0
    for i in range(1, n + 1):
        if n % i == 0:
            divisores += 1
    return divisores


#EJERCICIO 2
def primo(n):
    """Determina si n es un número primo"""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


# EJERCICIO 3
def perfecto(n): 
    """Determina si n es un número perfecto"""
    suma_divisores = 0
    for i in range(1, n):
        if n % i == 0:
            suma_divisores += i
    return suma_divisores == n

# EJERCICIO 12
def sumadiv(n):
    """Recibe un número entero n y devuelve la suma de sus divisores"""
    suma = 0
    for i in range(1, n + 1):
        if n % i == 0:
            suma += i
    return suma

# ejercicio 15
def mcd(a, b):
    """Calcula el máximo común divisor entre a y b de forma recursiva"""
    if a == b:
        return a
    elif a > b:
        return mcd(a - b, b)
    else:
        return mcd(a, b - a)



