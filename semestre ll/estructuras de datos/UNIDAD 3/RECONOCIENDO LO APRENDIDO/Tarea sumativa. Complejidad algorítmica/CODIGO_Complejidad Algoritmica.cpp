#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura base para los datos
struct Estudiante {
    int codigo;
    string nombre;
    double nota;
};

//Estructura, Arbol Binario de busqueda
struct NodoArbol {
    Estudiante dato;
    NodoArbol *izq, *der;
    NodoArbol(Estudiante e) : dato(e), izq(nullptr), der(nullptr) {}
};
NodoArbol* insertarArbol(NodoArbol* raiz, Estudiante e) {
    if (raiz == nullptr) return new NodoArbol(e);
    if (e.codigo < raiz->dato.codigo) raiz->izq = insertarArbol(raiz->izq, e);
    else raiz->der = insertarArbol(raiz->der, e);
    return raiz;
}
Estudiante* buscarArbol(NodoArbol* raiz, int cod) {
    if (raiz == nullptr || raiz->dato.codigo == cod) 
        return (raiz == nullptr) ? nullptr : &(raiz->dato);
    if (cod < raiz->dato.codigo) return buscarArbol(raiz->izq, cod);
    return buscarArbol(raiz->der, cod);
}
//Estructura lista enlazada
struct NodoLista {
    Estudiante dato;
    NodoLista* siguiente;
    NodoLista(Estudiante e) : dato(e), siguiente(nullptr) {}
};
//Clase de Gestion
class SistemaAcademico {
public:
    vector<Estudiante> arreglo;     // Estructura 1
    NodoLista* listaInicio = nullptr; // Estructura 2
    NodoArbol* arbolRaiz = nullptr;  // Estructura 3

    void registrar(int cod, string nom, double nota) {
        Estudiante e = {cod, nom, nota};
        // Insertar en Arreglo
        arreglo.push_back(e);
        // Insertar en Lista al inicio
        NodoLista* nuevo = new NodoLista(e);
        nuevo->siguiente = listaInicio;
        listaInicio = nuevo;
        // Insertar en Arbol
        arbolRaiz = insertarArbol(arbolRaiz, e);
    }
    // Operacion 1 Busqueda Se muestra la del arbol por ser la mas eficiente
    void realizarBusqueda(int cod) {
        cout << "\n Buscando codigo " << cod << " en el Arbol (O(log n))";
        Estudiante* res = buscarArbol(arbolRaiz, cod);
        if (res) cout << "\n Encontrado: " << res->nombre << "   Nota: " << res->nota << endl;
        else cout << "\n Estudiante no encontrado" << endl;
    }
    // Operacion 2: Calcular Promedio Se usa el arreglo por facilidad de recorrido
    double calcularPromedioGeneral() {
        if (arreglo.empty()) return 0;
        double suma = 0;
        for (size_t i = 0; i < arreglo.size(); i++) {
            suma += arreglo[i].nota;
        }
        return suma / arreglo.size();
    }
};
int main() {
    SistemaAcademico sistema;
    int opcion, cod;
    string nom;
    double nota;

    do {
        cout << "\nSistema Academico";
        cout << "\n1. Registrar Estudiante";
        cout << "\n2. Buscar por Codigo Eficiencia Arbol";
        cout << "\n3. Calcular Promedio General Eficiencia Arreglo";
        cout << "\n0. Salir\nSeleccione: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Codigo: "; cin >> cod;
                cout << "Nombre: "; cin >> nom;
                cout << "Nota: "; cin >> nota;
                sistema.registrar(cod, nom, nota);
                break;
            case 2:
                cout << "Ingrese codigo a buscar: "; cin >> cod;
                sistema.realizarBusqueda(cod);
                break;
            case 3:
                cout << "\nPromedio General del Sistema: " << sistema.calcularPromedioGeneral() << endl;
                break;
        }
    } while (opcion != 0);
    return 0;
}
