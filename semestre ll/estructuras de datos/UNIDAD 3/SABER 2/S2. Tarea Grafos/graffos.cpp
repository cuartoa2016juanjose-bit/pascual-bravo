#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
struct Estudiante {
    string nombre;
    int codigo;
    double promedio;
};
class GrafoAcademico {
private:
    // Lista de adyacencia El nombre del estudiante mapea a una lista de sus "compañeros"
    map<string, vector<string>> adyacencia;
    // Mapa para guardar los datos del objeto Estudiante por su nombre
    map<string, Estudiante> datosEstudiantes;

public:
    // Agregar una nueva persona al grafo
    void agregarEstudiante(string nombre, int codigo, double promedio) {
        if (datosEstudiantes.find(nombre) == datosEstudiantes.end()) {
            datosEstudiantes[nombre] = {nombre, codigo, promedio};
            adyacencia[nombre] = vector<string>();
            cout << "Estudiante " << nombre << " registrado \n";
        } else {
            cout << "El estudiante ya existe\n";
        }
    }
    // Establecer una relacion no dirigida: si A conoce a B, B conoce a A
    void establecerRelacion(string a, string b) {
        if (datosEstudiantes.count(a) && datosEstudiantes.count(b)) {
            adyacencia[a].push_back(b);
            adyacencia[b].push_back(a);
            cout << "Relacion academica creada entre " << a << " y " << b << " \n";
        } else {
            cout << "Uno o ambos estudiantes no estan registrados\n";
        }
    }
    //Mostrar la lista de personas y sus conexiones
    void mostrarGrafo() {
        cout << "\n Red Academica \n";
        for (auto const& par : adyacencia) { 
            string nombre = par.first;               // La llave del map es el nombre
            const vector<string>& companeros = par.second; // El valor es la lista de amigos
            cout << nombre << " (Cod: " << datosEstudiantes[nombre].codigo << ")     ";
            for (const string& comp : companeros) {
                cout << comp << " ";
            }
            cout << endl; 
        }
    }
    //Buscar si dos personas estan directamente conectadas
    bool estanConectados(string a, string b) {
        if (adyacencia.count(a)) {
            for (const string& vecino : adyacencia[a]) {
                if (vecino == b) return true;
            }
        }
        return false;
    }
    // Mostrar adyacentes compañeros directos
    void mostrarAdyacentes(string nombre) {
        if (adyacencia.count(nombre)) {
            cout << "Compañeros de " << nombre << ": ";
            for (const string& vecino : adyacencia[nombre]) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }
    //Recorrido en Anchura (BFS)  Visita nivel por nivel
    void recorrerBFS(string inicio) {
        if (datosEstudiantes.find(inicio) == datosEstudiantes.end()) return;
        map<string, bool> visitado;
        queue<string> cola; // El BFS usa una cola
        visitado[inicio] = true;
        cola.push(inicio);
        cout << "recorrido BFS desde " << inicio << ": ";
        while (!cola.empty()) {
            string actual = cola.front();
            cola.pop();
            cout << actual << " ";

            for (const string& vecino : adyacencia[actual]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    cola.push(vecino);
                }
            }
        }
        cout << endl;
    }
    // Opcional osea, persona con mas conexiones Grado del nodo
    void estudianteMasPopular() {
        string popular = "";
        size_t maxConexiones = 0;
        for (auto const& par : adyacencia) {
            if (par.second.size() > maxConexiones) {
                maxConexiones = par.second.size();
                popular = par.first;
            }
        }
        if (!popular.empty()) {
            cout << "El estudiante con mas conexiones es " << popular 
                 << " con " << maxConexiones << " compañeros\n";
        }
    }
};
int main() {
    GrafoAcademico red;
    int opcion;
    string n1, n2;
    int cod;
    double prom;
    do {
        cout << "\n Menu gestion academica con GRAFOS\n";
        cout << "1. Agregar Estudiante\n";
        cout << "2. Establecer Relacion osea Compañeros de curso\n";
        cout << "3. Mostrar Red Completa\n";
        cout << "4. Verificar Conexion Directa\n";
        cout << "5. Ver Compañeros de un Estudiante\n";
        cout << "6. Recorrido BFS Explorar red por niveles\n";
        cout << "7. Ver Estudiante con mas conexiones\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Nombre: "; cin >> n1;
                cout << "Codigo: "; cin >> cod;
                cout << "Promedio: "; cin >> prom;
                red.agregarEstudiante(n1, cod, prom);
                break;
            case 2:
                cout << "Nombre estudiante 1: "; cin >> n1;
                cout << "Nombre estudiante 2: "; cin >> n2;
                red.establecerRelacion(n1, n2);
                break;
            case 3:
                red.mostrarGrafo();
                break;
            case 4:
                cout << "Estudiante A: "; cin >> n1;
                cout << "Estudiante B: "; cin >> n2;
                if (red.estanConectados(n1, n2)) cout << "Estan conectados directamente \n";
                else cout << "No hay conexion directa\n";
                break;
            case 5:
                cout << "Nombre: "; cin >> n1;
                red.mostrarAdyacentes(n1);
                break;
            case 6:
                cout << "Punto de inicio: "; cin >> n1;
                red.recorrerBFS(n1);
                break;
            case 7:
                red.estudianteMasPopular();
                break;
        }
    } while (opcion != 0);
    return 0;
}


/*
El aplicativo se basa en un grafo no dirigido debido a que, en este sistema de gestión académica, 
las relaciones entre estudiantes son recíprocas; es decir, si un estudiante comparte una asignatura con otro,
la conexión es mutua. Para la implementación en C++, se definió una estructura (struct)
que almacena los datos del estudiante y se utilizó un std::map para representar la lista de adyacencia,
lo que permite realizar búsquedas eficientes por nombre y evita la complejidad de manejar índices numéricos.
Finalmente, se integró un recorrido en anchura (BFS) mediante el uso de una cola (queue)
técnica ideal para explorar la red académica por niveles y analizar la cercanía o conectividad entre los distintos nodos del sistema.
*/
