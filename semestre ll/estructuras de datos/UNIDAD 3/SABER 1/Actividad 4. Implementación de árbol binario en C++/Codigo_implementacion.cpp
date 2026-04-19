#include <iostream>
using namespace std;
struct nodo {
    int dato;
    nodo* izquierdo;
    nodo* derecho;

    nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};
nodo* insertar(nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new nodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}
void preorden(nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
void inorden(nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inorden(raiz->derecho);
    }
}
void postorden(nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

int main() {
    nodo* raiz = nullptr;
    int datos[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(datos) / sizeof(datos[0]);
    for (int i = 0; i < n; i++) {
        raiz = insertar(raiz, datos[i]);
    }
    cout << "recorrido preorden (raiz - izq - der):" << endl;
    preorden(raiz);
    cout << "\n\nrecorrido inorden (izq - raiz - der - salida ordenada):" << endl;
    inorden(raiz);
    cout << "\n\nrecorrido postorden (izq - der - raiz):" << endl;
    postorden(raiz);
    cout << endl;
    return 0;
}
