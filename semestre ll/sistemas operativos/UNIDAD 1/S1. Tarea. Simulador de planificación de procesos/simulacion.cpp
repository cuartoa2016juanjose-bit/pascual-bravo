#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Para la funcion Sleep

using namespace std;

struct Proceso {
    string nombre;
    int tiempoEjecucion;
    int prioridad; // 1 es Maxima, 3 es Minima
    string estado;
};

// Funcion para mostrar el tablero de control
void mostrarSistema(Proceso p[], int n) {
    system("cls"); 
    cout << " simulador de planificador cpu - siget" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "proceso\t\tprioridad\testado" << endl;
    for(int i = 0; i < n; i++) {
        cout << p[i].nombre << "\t\t" << p[i].prioridad << "\t\t[" << p[i].estado << "]" << endl;
    }
    cout << "---------------------------------------------" << endl;
}

void simularFIFO(Proceso p[], int n) {
    cout << "\nIniciando Planificacion FIFO (Orden de llegada)" << endl;
    Sleep(2000);

    for(int i = 0; i < n; i++) {
        p[i].estado = "en ejecucion";
        mostrarSistema(p, n);
        Sleep(1000 * p[i].tiempoEjecucion); // 
        
        p[i].estado = "terminado";
        mostrarSistema(p, n);
    }
    cout << "\n>>> Algoritmo fifo completado" << endl;
}

int main() {
    // Definimos 3 procesos con diferentes atributos
    Proceso tareas[3] = {
        {"Bus Rutina", 4, 3, "listo"},    // Tarda 4s
        {"Camara Int", 2, 2, "listo"},    // Tarda 2s
        {"EMERGENCIA", 1, 1, "listo"}     // Tarda 1s
    };

    int op;
    cout << "Seleccione Algoritmo:\n1. fifo\n2. Prioridad Emergencias\nOpcion: ";
    cin >> op;

    if(op == 1) {
        simularFIFO(tareas, 3);
    } else if(op == 2) {
        // Logica simple de prioridad: Ordenamos el arreglo por prioridad antes de ejecutar
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2 - i; j++) {
                if(tareas[j].prioridad > tareas[j+1].prioridad) {
                    Proceso aux = tareas[j];
                    tareas[j] = tareas[j+1];
                    tareas[j+1] = aux;
                }
            }
        }
        cout << "\nPrioridad reconfigurada para emergencias siget" << endl;
        simularFIFO(tareas, 3); 
    }

    return 0;
}
