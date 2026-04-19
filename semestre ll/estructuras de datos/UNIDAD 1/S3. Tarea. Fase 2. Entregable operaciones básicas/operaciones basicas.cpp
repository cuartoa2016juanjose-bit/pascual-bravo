#include <iostream>
#include <string>
#include <algorithm> // Para el ordenamiento

using namespace std;

const int MAX = 50; // Capacidad máxima del sistema 

struct Estudiante {
    int codigo;
    string nombre;
    float nota;
    bool activo = false; // Para manejo de eliminación lógica
};

// funciones
void menu();
void insertar(Estudiante lista[], int &tam);
void consultarTodo(Estudiante lista[], int tam);
void buscar(Estudiante lista[], int tam);
void actualizar(Estudiante lista[], int tam);
void eliminar(Estudiante lista[], int &tam);
void ordenar(Estudiante lista[], int tam);
void calcularEstadisticas(Estudiante lista[], int tam);

int main() {
    Estudiante alumnos[MAX];
    int cantidad = 0;
    int opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1: insertar(alumnos, cantidad); break;
            case 2: consultarTodo(alumnos, cantidad); break;
            case 3: buscar(alumnos, cantidad); break;
            case 4: actualizar(alumnos, cantidad); break;
            case 5: eliminar(alumnos, cantidad); break;
            case 6: ordenar(alumnos, cantidad); break;
            case 7: calcularEstadisticas(alumnos, cantidad); break;
            case 8: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 8);

    return 0;
}

void menu() {
    cout << "\n gestion academica" << endl;
    cout << "1. Insertar estudiante" << endl;
    cout << "2. Consultar todos" << endl;
    cout << "3. Buscar por codigo" << endl;
    cout << "4. Actualizar nota" << endl;
    cout << "5. Eliminar estudiante" << endl;
    cout << "6. Ordenar por codigo" << endl;
    cout << "7. Ver estadisticas " << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// INSERTAR
void insertar(Estudiante lista[], int &tam) {
    if (tam < MAX) {
        cout << "Codigo: "; cin >> lista[tam].codigo;
        cout << "Nombre: "; cin.ignore(); getline(cin, lista[tam].nombre);
        cout << "Nota: "; cin >> lista[tam].nota;
        lista[tam].activo = true;
        tam++;
        cout << "Registrado con exito." << endl;
    } else {
        cout << "Error: Memoria estatica llena." << endl;
    }
}

// CONSULTAR TODO
void consultarTodo(Estudiante lista[], int tam) {
    cout << "\nlistado de estudiantes:" << endl;
    for (int i = 0; i < tam; i++) {
        if (lista[i].activo) {
            cout << "Cod: " << lista[i].codigo << "  Nombre: " << lista[i].nombre << "  Nota: " << lista[i].nota << endl;
        }
    }
}

// BUSCAR
void buscar(Estudiante lista[], int tam) {
    int cod;
    cout << "Codigo a buscar: "; cin >> cod;
    for (int i = 0; i < tam; i++) {
        if (lista[i].activo && lista[i].codigo == cod) {
            cout << "Encontrado: " << lista[i].nombre << "  Nota: " << lista[i].nota << endl;
            return;
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

// ACTUALIZAR
void actualizar(Estudiante lista[], int tam) {
    int cod;
    cout << "Codigo del estudiante a modificar: "; cin >> cod;
    for (int i = 0; i < tam; i++) {
        if (lista[i].activo && lista[i].codigo == cod) {
            cout << "Nueva Nota: "; cin >> lista[i].nota;
            cout << "Actualizado." << endl;
            return;
        }
    }
    cout << "No encontrado." << endl;
}

// ELIMINAR
void eliminar(Estudiante lista[], int &tam) {
    int cod;
    cout << "Codigo a eliminar: "; cin >> cod;
    for (int i = 0; i < tam; i++) {
        if (lista[i].activo && lista[i].codigo == cod) {
            lista[i].activo = false; 
            cout << "Estudiante eliminado." << endl;
            return;
        }
    }
}

// ORDENAR
void ordenar(Estudiante lista[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (lista[j].codigo > lista[j+1].codigo) {
                Estudiante aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
    cout << "Arreglo ordenado por codigo." << endl;
}

// OPERACIONES 
void calcularEstadisticas(Estudiante lista[], int tam) {
    if (tam == 0) return;
    float suma = 0, mayor = -1, menor = 11;
    int cont = 0;

    for (int i = 0; i < tam; i++) {
        if (lista[i].activo) {
            suma += lista[i].nota;
            if (lista[i].nota > mayor) mayor = lista[i].nota;
            if (lista[i].nota < menor) menor = lista[i].nota;
            cont++;
        }
    }

    if (cont > 0) {
        cout << "\nEstadisticas" << endl;
        cout << "Promedio Grupal: " << (suma / cont) << endl;
        cout << "Nota mas Alta: " << mayor << endl;
        cout << "Nota mas Baja: " << menor << endl;
    }
}
