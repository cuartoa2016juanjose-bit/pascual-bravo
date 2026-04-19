#include <iostream>
#include <string>

using namespace std;

// la estructura de datos
struct Pais {
    string nombre;
    float temperaturas[3]; // Arreglo para los 3 meses
    float promedioTrimestral;
};

int main() {
    // Declaramos un arreglo de 4 países
    Pais paises[4];
    
    // Variables para encontrar el mayor
    float maxPromedio = -1.0;
    string paisCaluroso = "";

    cout << " registro de temperatura" << endl;

    // Carga de datos por teclado
    for (int i = 0; i < 4; i++) {
        cout << "\nIngrese el nombre del pais " << (i + 1) << ": ";
        cin.ignore(); // Limpia el buffer para evitar errores con el nombre
        getline(cin, paises[i].nombre);

        float suma = 0;
        for (int j = 0; j < 3; j++) {
            cout << "  - Temperatura mes " << (j + 1) << ": ";
            cin >> paises[i].temperaturas[j];
            suma += paises[i].temperaturas[j];
        }

        // Calcular el promedio trimestral
        paises[i].promedioTrimestral = suma / 3.0;

        // Lógica para identificar el mayor promedio de una vez
        if (paises[i].promedioTrimestral > maxPromedio) {
            maxPromedio = paises[i].promedioTrimestral;
            paisCaluroso = paises[i].nombre;
        }
    }

    // Imprimir reportes
    cout << " reporte de resultados" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Pais: " << paises[i].nombre << endl;
        cout << "Temperaturas mensuales: " 
             << paises[i].temperaturas[0] << ", " 
             << paises[i].temperaturas[1] << ", " 
             << paises[i].temperaturas[2] << "" << endl;
        cout << "Promedio Trimestral: " << paises[i].promedioTrimestral << " c" << endl;
    }

    // Imprimir el país con mayor temperatura promedio
    cout << "\n Pais mas caluroso del semestre es : " << paisCaluroso 
         << " con " << maxPromedio << " C de promedio." << endl;

    return 0;
}
