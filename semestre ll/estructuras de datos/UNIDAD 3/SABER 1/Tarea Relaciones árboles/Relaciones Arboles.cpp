#include <iostream>
#include <string>

using namespace std;
struct nodo {
    int codigo;
    string nombre;
    string asignatura;
    float nota;
    nodo* izquierdo;
    nodo* derecho;
    nodo(int c, string nom, string asig, float n) {
        codigo = c;
        nombre = nom;
        asignatura = asig;
        nota = n;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};
nodo* insertar(nodo* raiz, int c, string nom, string asig, float n) {
    if (raiz == nullptr) return new nodo(c, nom, asig, n);
    if (c < raiz->codigo) raiz->izquierdo = insertar(raiz->izquierdo, c, nom, asig, n);
    else if (c > raiz->codigo) raiz->derecho = insertar(raiz->derecho, c, nom, asig, n);
    return raiz;
}
void inorden(nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo);
        cout << raiz->codigo << "    " << raiz->nombre << "    " << raiz->nota << "\n";
        inorden(raiz->derecho);
    }
}
void preorden(nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->codigo << "    " << raiz->nombre << "    " << raiz->nota << "\n";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
void postorden(nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->codigo << "   " << raiz->nombre << "   " << raiz->nota << "\n";
    }
}
void procesar_datos(nodo* raiz, float &suma, int &total, float &maxima, float &minima, int &aprobados, int &reprobados) {
    if (raiz != nullptr) {
        suma += raiz->nota;
        total++;
        if (raiz->nota > maxima) maxima = raiz->nota;
        if (raiz->nota < minima) minima = raiz->nota;
        if (raiz->nota >= 3.0) aprobados++;
        else reprobados++;
        
        procesar_datos(raiz->izquierdo, suma, total, maxima, minima, aprobados, reprobados);
        procesar_datos(raiz->derecho, suma, total, maxima, minima, aprobados, reprobados);
    }
}
int main() {
    nodo* raiz = nullptr;
    int opcion, codigo;
    string nombre, asignatura;
    float nota;
    do {
        cout << "\n1 registrar estudiante\n2 mostrar inorden\n3 mostrar preorden\n4 mostrar postorden\n5 ver estadisticas\n6 salir\nopcion: ";
        cin >> opcion;
        if (opcion == 1) {
            cout << "codigo: "; cin >> codigo;
            cout << "nombre: "; cin >> nombre;
            cout << "asignatura: "; cin >> asignatura;
            cout << "nota: "; cin >> nota;
            raiz = insertar(raiz, codigo, nombre, asignatura, nota);
        } else if (opcion == 2) {
            inorden(raiz);
        } else if (opcion == 3) {
            preorden(raiz);
        } else if (opcion == 4) {
            postorden(raiz);
        } else if (opcion == 5) {
            if (raiz == nullptr) {
                cout << "no hay datos\n";
            } else {
                float suma = 0, maxima = -1, minima = 6;
                int total = 0, aprobados = 0, reprobados = 0;
                procesar_datos(raiz, suma, total, maxima, minima, aprobados, reprobados);
                cout << "total estudiantes: " << total << "\n";
                cout << "promedio general: " << (suma / total) << "\n";
                cout << "nota maxima: " << maxima << "\n";
                cout << "nota minima: " << minima << "\n";
                cout << "aprobados: " << aprobados << "\n";
                cout << "reprobados: " << reprobados << "\n";
            }
        }
    } while (opcion != 6);
    return 0;
}
