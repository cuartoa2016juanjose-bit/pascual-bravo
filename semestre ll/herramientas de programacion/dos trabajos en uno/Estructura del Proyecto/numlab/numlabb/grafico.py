# --- MODULO 4 ---
#visualización con matplotlib
#graficos - FUnciones
#-------------------------------------------

import random
import matplotlib.pyplot as plt

def grafico_linea(datos_y, titulo="Gráfico de Línea de Ventas Mensuales"):
    """
    Toma una lista de datos numéricos y genera un gráfico de línea básico.
    Incluye una línea de regresión de ejemplo para ilustrar el módulo.
    """
    plt.figure(figsize=(10, 6))
    plt.plot(datos_y, marker='o', linestyle='-', color='b')
    plt.title(titulo)
    plt.xlabel("Eje X")
    plt.ylabel("Eje Y")
    plt.grid(True)
    plt.show()


# EJERCICIO 2 (Gráfico de dispersión)
def grafico_dispersion(n_puntos=100, titulo="Gráfico de Dispersión Aleatorio y Correlacionado"):
    """
    Genera 100 puntos aleatorios correlacionados y crea un gráfico de dispersión.
    Toma una cantidad de puntos (por defecto 100).
    """
    x_vals = [random.uniform(0, 100) for _ in range(n_puntos)]
    # Generamos valores correlacionados para que el gráfico sea más interesante
    y_vals = [0.5 * x + random.uniform(-10, 10) for x in x_vals]
    
    plt.figure(figsize=(10, 6))
    plt.scatter(x_vals, y_vals, color='g', alpha=0.6)
    plt.title(titulo)
    plt.xlabel("Eje X")
    plt.ylabel("Eje Y")
    plt.grid(True)
    plt.show()


# EJERCICIO 3 (Histograma)
def grafico_histograma(datos=None, bins=10, titulo="Histograma de Calificaciones de 100 Graduados"):
    """
    Toma una lista de datos numéricos y genera un histograma con 10 bins por defecto.
    Si no se pasan datos, genera 100 calificaciones aleatorias.
    """
    if datos is None:
        datos = [random.randint(1, 100) for _ in range(100)]
    
    plt.figure(figsize=(10, 6))
    plt.hist(datos, bins=bins, color='r', edgecolor='black', alpha=0.7)
    plt.title(titulo)
    plt.xlabel("Rango de Calificaciones")
    plt.ylabel("Frecuencia")
    plt.grid(True)
    plt.show()




