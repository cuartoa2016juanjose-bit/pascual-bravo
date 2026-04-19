#main 
from numlabb import estadisticas, grafico, secuencia, teoria_numeros, utilidades;

print("BATERIA DE PRUEBAS NUMLABB")
print("MODULO: ESTADISTICAS ")
lanzamientos = estadisticas.alfin(6)
print(f" Lanzamientos hasta sacar un 6: {lanzamientos}")
print(f" Combinaciones (10, 2): {estadisticas.combinaciones(10, 2)}\n")

print("MODULO: TEORIA DE NUMEROS")
n_teoria = 28
print(f" Divisores de {n_teoria}: {teoria_numeros.conteo(n_teoria)}")
print(f" {n_teoria} es primo?: {teoria_numeros.primo(n_teoria)}")
print(f" {n_teoria} es perfecto?: {teoria_numeros.perfecto(n_teoria)}")
print(f" Suma de los divisores de {n_teoria}: {teoria_numeros.sumadiv(n_teoria)}")
print(f" MCD entre 48 y 18: {teoria_numeros.mcd(48, 18)}\n")

print("MODULO SECUENCIAS")
print(f" Termino 8 de Fibonacci: {secuencia.secuencia1(8)}")
print(f" Termino 8 de Tribonacci: {secuencia.secuencia2(8)}")
print(f" Terminos de la serie 1*2*3... para exceder 500: {secuencia.conteo_serie(500)}")

# Guardamos la secuencia de Ulam en una variable para usarla luego en el gráfico
secuencia_generada = secuencia.ulam(1, 15)
print(f" Secuencia de Ulam (15 terminos): {secuencia_generada}\n")

print("MODO UTILIDADES")
n_util = 13531
print(f" Suma de cifras de {n_util}: {utilidades.sumad(n_util)}")
print(f" Cuadrado de 5 igual a suma de primeros 5 impares?: {utilidades.cuad(5)}")
print(f" {n_util} es simetrico?{utilidades.sim(n_util)}")
print(f" Factorial de 6: {utilidades.fact(6)}")

# Coordenadas
r, t = utilidades.polar(3, 4)
x, y = utilidades.cartesiana(r, t)
print(f" Polar de (3, 4) -> radio: {r:.2f}, angulo: {t:.2f}")
print(f" Cartesiana de (r, t) -> x: {x:.2f}, y: {y:.2f}")
print(f" Suma de cuadrados de digitos de 45: {utilidades.aleatorio(45)}")
print(f" Cantidad de digitos de {n_util}: {utilidades.nd(n_util)}")
print(f" Cantidad de digitos impares de {n_util}: {utilidades.digitos_impares(n_util)}\n")

print("MODULO GRAFICO")
grafico.grafico_linea(secuencia_generada, titulo="Linea: Crecimiento de Ulam")

grafico.grafico_dispersion(n_puntos=50, titulo="Dispersion Aleatoria (50 puntos)")

datos_histograma = [secuencia.secuencia1(i) for i in range(1, 12)]
grafico.grafico_histograma(datos=datos_histograma, bins=5, titulo="Histograma: Valores de Fibonacci")

print("ya")