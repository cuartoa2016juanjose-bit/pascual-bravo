#include <iostream>
#include <string>
using namespace std;

//nodo estudiante
struct Estudiante {
    int codigo;
    string nombre;
    string asignatura;
    float nota;
    Estudiante* siguiente;
};
//lista enlazada
Estudiante* lista = nullptr;
void insertarLista(int codigo, string nombre, string asignatura, float nota) {
    Estudiante* nuevo = new Estudiante{codigo, nombre, asignatura, nota, nullptr};
    if (!lista) {
        lista = nuevo;
    } else {
        Estudiante* temp = lista;
        while (temp->siguiente) temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
    cout << "Estudiante registrado en la lista\n";
}
void mostrarLista() {
    if (!lista) { cout << "Lista vacia\n"; return; }
    Estudiante* temp = lista;
    while (temp) {
        cout << "Codigo: " << temp->codigo
             << "  Nombre: " << temp->nombre
             << "  Asignatura: " << temp->asignatura
             << "  Nota: " << temp->nota
             << (temp->nota >= 3.0 ? " Aprobado" : " Reprobado") << "\n";
        temp = temp->siguiente;
    }
}
//cola fifo
Estudiante* frente = nullptr;
Estudiante* finalCola = nullptr;
void encolarEstudiante(int codigo, string nombre, string asignatura, float nota) {
    Estudiante* nuevo = new Estudiante{codigo, nombre, asignatura, nota, nullptr};
    if (!frente) {
        frente = finalCola = nuevo;
    } else {
        finalCola->siguiente = nuevo;
        finalCola = nuevo;
    }
    cout << "Estudiante en cola de atencion\n";
}
void atenderEstudiante() {
    if (!frente) { cout << "No hay estudiantes en cola\n"; return; }
    cout << "Atendiendo: " << frente->nombre
         << "  Asignatura: " << frente->asignatura
         << "  Nota: " << frente->nota << "\n";
    Estudiante* temp = frente;
    frente = frente->siguiente;
    if (!frente) finalCola = nullptr;
    delete temp;
}
void mostrarCola() {
    if (!frente) { cout << "Cola vacia\n"; return; }
    Estudiante* temp = frente;
    cout << "Cola de atencion orden de llegada:\n";
    while (temp) {
        cout << "  : " << temp->nombre << "   " << temp->asignatura << "\n";
        temp = temp->siguiente;
    }
}

//Pila lifo
Estudiante* tope = nullptr;
void apilarEstudiante(int codigo, string nombre, string asignatura, float nota) {
    Estudiante* nuevo = new Estudiante{codigo, nombre, asignatura, nota, tope};
    tope = nuevo;
    cout << "Estudiante registrado en historial\n";
}
void mostrarHistorial() {
    if (!tope) { cout << "Historial vacio\n"; return; }
    Estudiante* temp = tope;
    cout << "Historial ultimo en entrar primero:\n";
    while (temp) {
        cout << "  :  " << temp->nombre
             << "  " << temp->asignatura
             << "  Nota: " << temp->nota << "\n";
        temp = temp->siguiente;
    }
}
void verUltimoIngreso() {
    if (!tope) { cout << "Historial vacio\n"; return; }
    cout << "Ultimo ingreso: " << tope->nombre
         << "  " << tope->asignatura
         << "  Nota: " << tope->nota << "\n";
}
// Menu
int main() {
    int opcion, codigo;
    string nombre, asignatura;
    float nota;
    do {
        cout << "\nSistema academico \n";
        cout << " Lista enlazada \n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << " Cola atencion por llegada \n";
        cout << "3. Agregar estudiante a cola\n";
        cout << "4. Atender siguiente estudiante\n";
        cout << "5. Ver cola actual\n";
        cout << " Pila historial \n";
        cout << "6. Agregar estudiante al historial\n";
        cout << "7. Ver historial completo\n";
        cout << "8. Ver ultimo ingreso\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        if (opcion >= 1 && opcion <= 8 && opcion != 2 && opcion != 4 && opcion != 5 && opcion != 7 && opcion != 8) {
            cout << "Codigo: ";     cin >> codigo;   cin.ignore();
            cout << "Nombre: ";     getline(cin, nombre);
            cout << "Asignatura: "; getline(cin, asignatura);
            cout << "Nota: ";       cin >> nota;     cin.ignore();
        }
        switch (opcion) {
            case 1: insertarLista(codigo, nombre, asignatura, nota);    break;
            case 2: mostrarLista();                                      break;
            case 3: encolarEstudiante(codigo, nombre, asignatura, nota); break;
            case 4: atenderEstudiante();                                 break;
            case 5: mostrarCola();                                       break;
            case 6: apilarEstudiante(codigo, nombre, asignatura, nota);  break;
            case 7: mostrarHistorial();                                  break;
            case 8: verUltimoIngreso();                                  break;
            case 0: cout << "Hasta luego \n";                           break;
            default: cout << "Opcion invalida \n";
        }
    } while (opcion != 0);
    return 0;
}

/*
El sistema combina tres estructuras dinámicas usando el mismo nodo de estudiante con código, nombre, asignatura, nota y puntero al siguiente.
 La lista enlazada guarda el registro general de estudiantes insertando siempre al final. La cola FIFO modela la atención por orden de llegada,
  donde el primero que entra es el primero en ser atendido y eliminado con atenderEstudiante. La pila LIFO funciona como historial, insertando 
  siempre al inicio para que el último estudiante registrado sea el primero en mostrarse. Las tres estructuras son independientes, por lo que un
   mismo estudiante puede registrarse en las tres según el proceso que se quiera simular. El menú controla todo con un ciclo do-while y cin.ignore()
    garantiza la lectura correcta de textos con espacios
*/
