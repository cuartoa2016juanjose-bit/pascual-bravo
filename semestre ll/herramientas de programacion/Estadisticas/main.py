from modulos.Funciones_Calculo import obtener_promedio, obtener_maximo, obtener_minimo, obtener_rango

def main():
    print("Mini sistema de calculo")
    entrada = input("Ingresa los numeros separados por espacios (ejemplo: 4 7 2 9 1): ")
    try:
        datos = [float(numero) for numero in entrada.split()]
    except ValueError:
        print("Por favor ingresa solo numeros separados por espacios.")
        return

    # Validamos lista no vacia
    if not datos:
        print("No ingresaste ningun dato.")
        return

    # Calculamos y mostramos la salida
    print(f"\nDatos: {datos}")
    print(f"promedio : {obtener_promedio(datos)}")
    print(f"maximo   : {obtener_maximo(datos)}")
    print(f"minimo   : {obtener_minimo(datos)}")
    print(f"rango    : {obtener_rango(datos)}")

if __name__ == "__main__":
    main();