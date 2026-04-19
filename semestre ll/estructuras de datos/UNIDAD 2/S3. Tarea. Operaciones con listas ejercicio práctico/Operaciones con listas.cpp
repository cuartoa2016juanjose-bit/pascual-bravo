#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string nombre;
    int edad;
    string motivo;
    string prioridad;
    Nodo* siguiente;
};
Nodo* cabeza = nullptr;
void insertarPaciente(string nombre, int edad, string motivo, string prioridad) {
    Nodo* nuevo = new Nodo{nombre, edad, motivo, prioridad, nullptr};
    if (prioridad == "urgente") {
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        cout << "Paciente urgente agregado al inicio\n";
    } else {
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
        cout << "Paciente agregado a la lista\n";
    }
}
void mostrar() {
    if (!cabeza) { cout << "No hay pacientes en espera\n"; return; }
    Nodo* temp = cabeza;
    int i = 1;
    while (temp) {
        cout << i++ << " " << temp->nombre
             << "  Edad: " << temp->edad
             << "  Motivo: " << temp->motivo
             << "  Prioridad: " << temp->prioridad << "\n";
        temp = temp->siguiente;
    }
}
void eliminarPrimero() {
    if (!cabeza) { cout << "Lista vacia \n"; return; }
    cout << "Paciente atendido: " << cabeza->nombre << "\n";
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
}
void eliminarPorNombre(string nombre) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    while (actual && actual->nombre != nombre) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (!actual) { cout << "Paciente no encontrado.\n"; return; }
    if (!anterior) cabeza = cabeza->siguiente;
    else anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "Paciente " << nombre << " eliminado.\n";
}
void buscar(string nombre) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->nombre == nombre) {
            cout << "Paciente encontrado : "
                 << temp->nombre << "  Edad: " << temp->edad
                 << "  Motivo: " << temp->motivo
                 << "  Prioridad: " << temp->prioridad << "\n";
            return;
        }
        temp = temp->siguiente;
    }
    cout << "Paciente no encontrado \n";
}
int main() {
    int opcion;
    string nombre, motivo, prioridad;
    int edad;

    do {
        cout << "\n CLINICA lista de espera\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Ver lista de espera\n";
        cout << "3. Atender primer paciente\n";
        cout << "4. Eliminar paciente por nombre\n";
        cout << "5. Buscar paciente por nombre\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << "Nombre: ";    getline(cin, nombre);
                cout << "Edad: ";      cin >> edad; cin.ignore();
                cout << "Motivo: ";    getline(cin, motivo);
                cout << "Prioridad normal o urgente: "; getline(cin, prioridad);
                insertarPaciente(nombre, edad, motivo, prioridad);
                break;
            case 2:
                mostrar();
                break;
            case 3:
                eliminarPrimero();
                break;
            case 4:
                cout << "Nombre a eliminar: "; getline(cin, nombre);
                eliminarPorNombre(nombre);
                break;
            case 5:
                cout << "Nombre a buscar: "; getline(cin, nombre);
                buscar(nombre);
                break;
            case 0:
                cout << "Hasta luego \n";
                break;
            default:
                cout << "Opcion invalida \n";
        }
    } while (opcion != 0);

    return 0;
}
