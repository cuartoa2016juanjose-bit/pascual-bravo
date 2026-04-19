#--- MODULO 2 --- 
#Fibonacci, Ulam, tribonacci
#secuencias - Funciones
#-----------------------------

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
