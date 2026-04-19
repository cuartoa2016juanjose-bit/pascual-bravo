#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "log_siget.txt";

    ofstream outFileInit(filename);
    if (outFileInit.is_open()) {
        outFileInit << "Registro de eventos SIGET - Fecha: 2026-04-06, version: 1.0.0. Este log captura datos cruciales para la optimizacion del trafico.\n";
        outFileInit.close();
    }

    fstream file(filename, ios::in | ios::out);
    string content;
    if (file.is_open()) {
        file.seekg(0, ios::end);
        size_t size = file.tellg();
        content.resize(size);
        file.seekg(0, ios::beg);
        file.read(&content[0], size);
        
        content.insert(10, "ID_SENS_007");

        for (size_t i = 0; i < content.length(); ++i) {
            if (content[i] == 'e') {
                content[i] = '3';
            }
        }

        file.seekp(0, ios::beg);
        file << content;
        file.close();
    }

    ofstream outFileAppend(filename, ios::app);
    if (outFileAppend.is_open()) {
        outFileAppend << "Alerta: Verifique el estado del servidor de optimizacion de rutas. Contacto: soporte@siget.com\n";
        outFileAppend.close();
    }

    cout << "Operaciones de archivo finalizadas en el PC." << endl;
    return 0;
}
