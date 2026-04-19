#include <iostream>
#include <string>
using namespace std;

//estructura
struct Nota {
    string asignatura;
    float calificacion;
    Nota* siguiente;
};
struct Estudiante {
    int codigo;
    string nombre;
    Nota* notas;        // lista enlazada de notas
    Estudiante* siguiente;
};
Estudiante* lista = nullptr;
//funciones
Estudiante* buscarEstudiante(int codigo) {
    Estudiante* temp = lista;
    while (temp) {
        if (temp->codigo == codigo) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}
float calcularPromedio(Estudiante* e) {
    if (!e->notas) return 0;
    float suma = 0;
    int count = 0;
    Nota* n = e->notas;
    while (n) {
        suma += n->calificacion;
        count++;
        n = n->siguiente;
    }
    return suma / count;
}
//operacones
void insertarEstudiante(int codigo, string nombre) {
    if (buscarEstudiante(codigo)) {
        cout << "Ya existe un estudiante con ese codigo\n";
        return;
    }
    Estudiante* nuevo = new Estudiante{codigo, nombre, nullptr, nullptr};
    if (!lista) {
        lista = nuevo;
    } else {
        Estudiante* temp = lista;
        while (temp->siguiente) temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
    cout << "Estudiante registrado\n";
}
void agregarNota(int codigo, string asignatura, float calificacion) {
    Estudiante* e = buscarEstudiante(codigo);
    if (!e) { cout << "Estudiante no encontrado\n"; return; }

    Nota* nueva = new Nota{asignatura, calificacion, nullptr};
    if (!e->notas) {
        e->notas = nueva;
    } else {
        Nota* temp = e->notas;
        while (temp->siguiente) temp = temp->siguiente;
        temp->siguiente = nueva;
    }
    cout << "Nota agregada\n";
}
void mostrarTodos() {
    if (!lista) { cout << "No hay estudiantes registrados\n"; return; }
    Estudiante* temp = lista;
    while (temp) {
        float prom = calcularPromedio(temp);
        cout << "\nCodigo: " << temp->codigo << "  Nombre: " << temp->nombre;
        cout << "\n  Asignaturas:\n";
        Nota* n = temp->notas;
        while (n) {
            cout << "    - " << n->asignatura << ": " << n->calificacion;
            if (n->calificacion >= 3.0) cout << " Aprobado";
            else cout << " Reprobado";
            cout << "\n";
            n = n->siguiente;
        }
        cout << "  Promedio: " << prom;
        if (prom >= 3.0) cout << " : aprobadoo\n";
        else cout << " : reprobadoo\n";
        temp = temp->siguiente;
    }
}
void buscarPorNombre(string nombre) {
    Estudiante* temp = lista;
    bool encontrado = false;
    while (temp) {
        if (temp->nombre == nombre) {
            cout << "Codigo: " << temp->codigo
                 << "  Promedio: " << calcularPromedio(temp) << "\n";
            encontrado = true;
        }
        temp = temp->siguiente;
    }
    if (!encontrado) cout << "Estudiante no encontrado\n";
}
void mejorYPeor() {
    if (!lista) { cout << "Lista vacia\n"; return; }
    Estudiante* mejor = lista;
    Estudiante* peor  = lista;
    Estudiante* temp  = lista->siguiente;
    while (temp) {
        if (calcularPromedio(temp) > calcularPromedio(mejor)) mejor = temp;
        if (calcularPromedio(temp) < calcularPromedio(peor))  peor  = temp;
        temp = temp->siguiente;
    }
    cout << "Mejor rendimiento: " << mejor->nombre
         << "  Promedio: " << calcularPromedio(mejor) << "\n";
    cout << "Peor rendimiento:  " << peor->nombre
         << "  Promedio: " << calcularPromedio(peor)  << "\n";
}
void reporteAprobadosReprobados() {
    int aprobados = 0, reprobados = 0;
    Estudiante* temp = lista;
    while (temp) {
        if (calcularPromedio(temp) >= 3.0) aprobados++;
        else reprobados++;
        temp = temp->siguiente;
    }
    cout << "Aprobados:  " << aprobados << "\n";
    cout << "Reprobados: " << reprobados << "\n";
}
void promedioGeneral() {
    if (!lista) { cout << "Lista vacia.\n"; return; }
    float suma = 0;
    int count = 0;
    Estudiante* temp = lista;
    while (temp) {
        suma += calcularPromedio(temp);
        count++;
        temp = temp->siguiente;
    }
    cout << "Promedio general del grupo: " << suma / count << "\n";
}
//menu
int main() {
    int opcion;
    string nombre, asignatura;
    int codigo;
    float nota;
    do {
        cout << "\n Sistema Academico \n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Agregar nota a estudiante\n";
        cout << "3. Mostrar todos los estudiantes\n";
        cout << "4. Buscar estudiante por nombre\n";
        cout << "5. Mejor y peor rendimiento\n";
        cout << "6. Reporte aprobados / reprobados\n";
        cout << "7. Promedio general del grupo\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Codigo: ";  cin >> codigo; cin.ignore();
                cout << "Nombre: ";  getline(cin, nombre);
                insertarEstudiante(codigo, nombre);
                break;
            case 2:
                cout << "Codigo del estudiante: "; cin >> codigo; cin.ignore();
                cout << "Asignatura: ";            getline(cin, asignatura);
                cout << "Nota (0.0 - 5.0): ";      cin >> nota; cin.ignore();
                agregarNota(codigo, asignatura, nota);
                break;
            case 3:
                mostrarTodos();
                break;
            case 4:
                cout << "Nombre a buscar: "; getline(cin, nombre);
                buscarPorNombre(nombre);
                break;
            case 5:
                mejorYPeor();
                break;
            case 6:
                reporteAprobadosReprobados();
                break;
            case 7:
                promedioGeneral();
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

/*
El sistema usa dos listas enlazadas simples anidadas. La lista principal almacena estudiantes con su código y nombre, 
y dentro de cada estudiante hay una segunda lista que guarda sus asignaturas y calificaciones. Esto permite manejar cualquier 
cantidad de materias sin arreglos de tamaño fijo, usando memoria dinámica con new y delete.
Las funciones de inserción recorren cada lista hasta el final para agregar el nuevo nodo. La función calcularPromedio suma 
todas las notas del estudiante y divide entre el total de materias, siendo reutilizada por las demás funciones como el reporte de aprobados, 
el promedio general y la identificación del mejor y peor rendimiento, evitando repetir lógica. El criterio de aprobación es nota mayor o igual a 3.0.
El menú funciona con un ciclo do-while que se repite hasta que el usuario elija salir. Se usa cin.ignore()
 después de cada dato numérico para que getline pueda leer correctamente los nombres y asignaturas con espacios.
*/
