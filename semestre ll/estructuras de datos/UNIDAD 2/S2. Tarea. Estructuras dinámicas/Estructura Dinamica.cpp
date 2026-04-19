#include <iostream>
using namespace std;

struct Nodo {
    float dato;
    Nodo* siguiente;
};


Nodo* tope = nullptr;

void push(float valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Se apilo: " << valor << endl;
}

void pop() {
    if (tope == nullptr) {
        cout << "La pila esta vacia\n";
        return;
    }
    cout << "Se desapilo: " << tope->dato << endl;
    Nodo* temp = tope;
    tope = tope->siguiente;
    delete temp;
}

void top() {
    if (tope == nullptr)
        cout << "La pila esta vacia\n";
    else
        cout << "Tope de la pila: " << tope->dato << endl;
}

Nodo* frente = nullptr;
Nodo* final_cola = nullptr;

void enqueue(float valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (frente == nullptr) {
        frente = final_cola = nuevo;
    } else {
        final_cola->siguiente = nuevo;
        final_cola = nuevo;
    }
    cout << "Se encolo: " << valor << endl;
}

void dequeue() {
    if (frente == nullptr) {
        cout << "La cola esta vacia\n";
        return;
    }
    cout << "Se desencolo: " << frente->dato << endl;
    Nodo* temp = frente;
    frente = frente->siguiente;
    delete temp;
    if (frente == nullptr) final_cola = nullptr;
}

void front() {
    if (frente == nullptr)
        cout << "La cola esta vacia\n";
    else
        cout << "Frente de la cola: " << frente->dato << endl;
}

void menuPila() {
    int opcion;
    float valor;
    do {
        cout << "\n MENU PILA float\n";
        cout << "1. Push  apilar\n";
        cout << "2. Pop   desapilar\n";
        cout << "3. Top   ver tope\n";
        cout << "0. Volver al menu principal\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor float: ";
                cin >> valor;
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 0:
                cout << "Volviendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}
void menuCola() {
    int opcion;
    float valor;
    do {
        cout << "\n MENU COLA float\n";
        cout << "1. Enqueue encolar\n";
        cout << "2. Dequeue desencolar\n";
        cout << "3. Front   ver frente\n";
        cout << "0. Volver al menu principal\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingresa el valor float: ";
                cin >> valor;
                enqueue(valor);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
                break;
            case 0:
                cout << "Volviendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

int main() {
    int opcion;
    do {
        cout << "\n MENU PRINCIPAL \n";
        cout << "1. Trabajar con la Pila\n";
        cout << "2. Trabajar con la Cola\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                menuPila();
                break;
            case 2:
                menuCola();
                break;
            case 0:
                cout << "Hasta luego\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 0);

    return 0;
}
