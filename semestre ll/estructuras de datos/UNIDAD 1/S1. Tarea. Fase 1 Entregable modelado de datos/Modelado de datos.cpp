#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Estructura para el Estudiante
struct Estudiante {
    int codigo;
    string nombre;
    double notas[3]; // Arreglo unidimensional
    double promedio;

    // calcular el promedio
    void calcularPromedio() {
        double suma = 0;
        for(int i = 0; i < 3; i++) {
            suma += notas[i];
        }
        promedio = suma / 3;
    }
};

// Estructura del arbol
struct Nodo {
    Estudiante* dato;
    Nodo *izq, *der;
};

// Crear un nuevo nodo en memoria
Nodo* crearNodo(Estudiante* nuevoEst) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = nuevoEst;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
}

// Insertar estudiante en el arbol
Nodo* insertar(Nodo* raiz, Estudiante* nuevoEst) {
    if (raiz == NULL) return crearNodo(nuevoEst);

    if (nuevoEst->codigo < raiz->dato->codigo)
        raiz->izq = insertar(raiz->izq, nuevoEst);
    else if (nuevoEst->codigo > raiz->dato->codigo)
        raiz->der = insertar(raiz->der, nuevoEst);
    
    return raiz;
}

// Buscar estudiante por código
Estudiante* buscar(Nodo* raiz, int cod) {
    if (raiz == NULL) return NULL;
    if (raiz->dato->codigo == cod) return raiz->dato;

    if (cod < raiz->dato->codigo)
        return buscar(raiz->izq, cod);
    else
        return buscar(raiz->der, cod);
}

// Reporte en orden
void reporteOrdenado(Nodo* raiz) {
    if (raiz != NULL) {
        reporteOrdenado(raiz->izq);
        cout << "Cod: " << raiz->dato->codigo << "   nombre " << raiz->dato->nombre 
             << "  Prom: " << raiz->dato->promedio << endl;
        reporteOrdenado(raiz->der);
    }
}

// Reporte de Aprobados y Reprobados
void reporteRendimiento(Nodo* raiz) {
    if (raiz != NULL) {
        string estado = (raiz->dato->promedio >= 3.0) ? "aprobado" : "reprobado (Habilitar)";
        cout << raiz->dato->nombre << " esta " << estado << endl;
        reporteRendimiento(raiz->izq);
        reporteRendimiento(raiz->der);
    }
}

// menú
int main() {
    Nodo* raiz = NULL;
    int opcion, codAux;

    do {
        cout << "\n sistema ";
        cout << "\n1.Registrar Estudiante\n2. Buscar por Codigo\n3. Reporte General\n4. Estado de Notas\n5. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1) {
            Estudiante* e = new Estudiante();
            cout << "codigo: "; cin >> e->codigo;
            cout << "nombre: "; cin.ignore(); getline(cin, e->nombre);
            
            for(int i = 0; i < 3; i++) {
                cout << "nota " << i+1 << ": ";
                cin >> e->notas[i];
            }
            e->calcularPromedio();
            raiz = insertar(raiz, e);
            cout << " estudiante guardado" << endl;

        } else if (opcion == 2) {
            cout << "codigo a buscar: "; cin >> codAux;
            Estudiante* encontrado = buscar(raiz, codAux);
            if (encontrado) cout << "encontrado: " << encontrado->nombre << " - promedio: " << encontrado->promedio << endl;
            else cout << "no encontrado." << endl;

        } else if (opcion == 3) {
            cout << "\n lista ordenada por codigo:" << endl;
            reporteOrdenado(raiz);

        } else if (opcion == 4) {
            cout << "\n estado academico :" << endl;
            reporteRendimiento(raiz);
        }

    } while (opcion != 5);

    return 0;
}
