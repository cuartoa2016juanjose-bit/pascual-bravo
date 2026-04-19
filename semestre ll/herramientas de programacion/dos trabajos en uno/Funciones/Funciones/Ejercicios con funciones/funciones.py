import random
import math

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
    """Determina si n es un número perfecto"""
    suma_divisores = 0
    for i in range(1, n):
        if n % i == 0:
            suma_divisores += i
    return suma_divisores == n


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


# EJERCICIO 6 
def secuencia1(n):
    """Entrega el n-ésimo término de la secuencia Fibonacci: 1, 1, 2, 3, 5, 8, 13, 21..."""
    if n <= 2:
        return 1
    a, b = 1, 1
    for _ in range(n - 2):
        a, b = b, a + b
    return b


# EJERCICIO 7
def secuencia2(n):
    """Entrega el n-ésimo término de la secuencia Tribonacci: 1, 1, 1, 3, 5, 9, 17, 31, 57..."""
    if n <= 3:
        return 1
    a, b, c = 1, 1, 1
    for _ in range(n - 3):
        a, b, c = b, c, a + b + c
    return c


#EJERCICIO 8 
def sim(x):
    """Determina si x es simétrico (capicúa)"""
    s = str(x)
    return s == s[::-1]


# EJERCICIO 9 
def alfin(n):
    """Entrega la cantidad de veces que debe lanzarse un dado hasta obtener el número n"""
    lanzamientos = 0
    while True:
        lanzamientos += 1
        if random.randint(1, 6) == n:
            return lanzamientos


#EJERCICIO 10
def conteo_serie(x):
    """Determina la cantidad de términos de 1*2*3 + 2*3*4 + 3*4*5 + ... que deben sumarse hasta exceder x"""
    suma = 0
    termino = 1
    while suma <= x:
        producto = termino * (termino + 1) * (termino + 2)
        suma += producto
        termino += 1
    return termino - 1


#EJERCICIO 11
def fact(n):
    """Recibe un número entero n y devuelve su factorial"""
    if n <= 1:
        return 1
    resultado = 1
    for i in range(2, n + 1):
        resultado *= i
    return resultado


# EJERCICIO 12
def sumadiv(n):
    """Recibe un número entero n y devuelve la suma de sus divisores"""
    suma = 0
    for i in range(1, n + 1):
        if n % i == 0:
            suma += i
    return suma


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


# ejercicio 15
def mcd(a, b):
    """Calcula el máximo común divisor entre a y b de forma recursiva"""
    if a == b:
        return a
    elif a > b:
        return mcd(a - b, b)
    else:
        return mcd(a, b - a)


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


# ejercicio 18
def combinaciones(m, n):
    """Calcula recursivamente combinaciones C(m,n) = C(m-1, n-1) + C(m-1, n)"""
    if n == 0 or n == m:
        return 1
    elif n == 1 or n == m - 1:
        return m
    else:
        return combinaciones(m - 1, n - 1) + combinaciones(m - 1, n)


# ejercicio 19
def ulam(valor_inicial, cantidad_terminos):
    """Generadora que produce la secuencia de Ulam"""
    secuencia = [valor_inicial]
    siguiente = valor_inicial + 1
    
    while len(secuencia) < cantidad_terminos:
        formas = 0
        for i in range(len(secuencia)):
            for j in range(i + 1, len(secuencia)):
                if secuencia[i] + secuencia[j] == siguiente:
                    formas += 1
        if formas == 1:
            secuencia.append(siguiente)
        siguiente += 1
    
    return secuencia



if __name__ == "__main__":
    print("PRUEBAS\n")
    
    # Ejercicio 1
    print(f"Ejercicio 1 - conteo(12) = {conteo(12)}")
    
    # Ejercicio 2
    print(f"Ejercicio 2 - primo(17) = {primo(17)}")
    
    # Ejercicio 3
    print(f"Ejercicio 3 - perfecto(28) = {perfecto(28)}")
    
    # Ejercicio 4
    print(f"Ejercicio 4 - sumad(123) = {sumad(123)}")
    
    # Ejercicio 5
    print(f"Ejercicio 5 - cuad(6) = {cuad(6)}")
    
    # Ejercicio 6
    print(f"Ejercicio 6 - secuencia1(7) = {secuencia1(7)}")
    
    # Ejercicio 7
    print(f"Ejercicio 7 - secuencia2(7) = {secuencia2(7)}")
    
    # Ejercicio 8
    print(f"Ejercicio 8 - sim(121) = {sim(121)}")
    
    # Ejercicio 9
    print(f"Ejercicio 9 - alfin(3) = {alfin(3)} lanzamientos")
    
    # Ejercicio 10
    print(f"Ejercicio 10 - conteo_serie(100) = {conteo_serie(100)} términos")
    
    # Ejercicio 11
    print(f"Ejercicio 11 - fact(5) = {fact(5)}")
    
    # Ejercicio 12
    print(f"Ejercicio 12 - sumadiv(12) = {sumadiv(12)}")
    
    # Ejercicio 13
    r, t = polar(3, 4)
    print(f"Ejercicio 13 - polar(3, 4) = ({r:.2f}, {t:.2f})")
    
    # Ejercicio 14
    print(f"Ejercicio 14 - aleatorio(123) = {aleatorio(123)}")
    
    # Ejercicio 15
    print(f"Ejercicio 15 - mcd(48, 18) = {mcd(48, 18)}")
    
    # Ejercicio 16
    print(f"Ejercicio 16 - nd(12345) = {nd(12345)}")
    
    # Ejercicio 17
    print(f"Ejercicio 17 - digitos_impares(2468) = {digitos_impares(2468)}")
    
    # Ejercicio 18
    print(f"Ejercicio 18 - combinaciones(5, 2) = {combinaciones(5, 2)}")
    
    # Ejercicio 19
    print(f"Ejercicio 19 - ulam(1, 15) = {ulam(1, 15)}")