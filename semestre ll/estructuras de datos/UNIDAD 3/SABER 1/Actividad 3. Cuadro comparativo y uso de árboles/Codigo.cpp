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
    if (raiz == nullptr) return new nodo(valor);
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

bool buscar(nodo* raiz, int valor) {
    if (raiz == nullptr) return false;
    if (raiz->dato == valor) return true;
    
    if (valor < raiz->dato) return buscar(raiz->izquierdo, valor);
    return buscar(raiz->derecho, valor);
}
nodo* obtenerminimo(nodo* raiz) {
    while (raiz && raiz->izquierdo != nullptr) raiz = raiz->izquierdo;
    return raiz;
}

nodo* eliminar(nodo* raiz, int valor) {
    if (raiz == nullptr) return raiz;
    if (valor < raiz->dato) {
        raiz->izquierdo = eliminar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = eliminar(raiz->derecho, valor);
    } else {
        if (raiz->izquierdo == nullptr) {
            nodo* temp = raiz->derecho;
            delete raiz;
            return temp;
        } else if (raiz->derecho == nullptr) {
            nodo* temp = raiz->izquierdo;
            delete raiz;
            return temp;
        }
        nodo* temp = obtenerminimo(raiz->derecho);
        raiz->dato = temp->dato;
        raiz->derecho = eliminar(raiz->derecho, temp->dato);
    }
    return raiz;
}
void inorden(nodo* raiz) {
    if (raiz) {
        inorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inorden(raiz->derecho);
    }
}
void preorden(nodo* raiz) {
    if (raiz) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
void postorden(nodo* raiz) {
    if (raiz) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}
int main() {
    nodo* raiz = nullptr;
    int opcion, valor;
    do {
        cout << "\n menu de arbol bst\n";
        cout << "1. insertar nodo\n";
        cout << "2. buscar elemento\n";
        cout << "3. eliminar nodo\n";
        cout << "4. mostrar recorridos\n";
        cout << "5. salir\n";
        cout << "elija una opcion ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "valor a insertar: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;
            case 2:
                cout << "valor a buscar: ";
                cin >> valor;
                if (buscar(raiz, valor)) cout << "elemento encontrado\n";
                else cout << "no existe en el arbol\n";
                break;
            case 3:
                cout << "valor a eliminar: ";
                cin >> valor;
                raiz = eliminar(raiz, valor);
                break;
            case 4:
                cout << "\ninorden: "; inorden(raiz);
                cout << "\npreorden: "; preorden(raiz);
                cout << "\npostorden: "; postorden(raiz);
                cout << endl;
                break;
        }
    } while (opcion != 5);
    return 0;
}
