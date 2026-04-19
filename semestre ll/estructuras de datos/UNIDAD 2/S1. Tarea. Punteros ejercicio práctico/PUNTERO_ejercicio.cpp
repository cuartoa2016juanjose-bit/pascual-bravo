#include <iostream>

using namespace std;

int main() {
    unsigned char edad = 20;       
    int suma = 150;                
    float estatura = 1.75;         
    char inicial = 'A';            
    long identificacion = 1234567; 

    unsigned char* pEdad = &edad;
    int* pSuma = &suma;
    float* pEstatura = &estatura;
    char* pInicial = &inicial;
    long* pIdentificacion = &identificacion;
    
    cout << " Variable EDAD" << endl;
    cout << "Valor original: " << (int)edad << endl;
    cout << "Direccion: " << (void*)pEdad << endl;
    cout << "Valor apuntado: " << (int)*pEdad << "\n" << endl;

    cout << " Variable SUMA" << endl;
    cout << "Valor original: " << suma << endl;
    cout << "Direccion: " << (void*)pSuma << endl;
    cout << "Valor apuntado: " << *pSuma << "\n" << endl;

    cout << " Variable ESTATURA" << endl;
    cout << "Valor original: " << estatura << endl;
    cout << "Direccion: " << (void*)pEstatura << endl;
    cout << "Valor apuntado: " << *pEstatura << "\n" << endl;

    cout << " Vriable INICIAL" << endl;
    cout << "Valor original: " << inicial << endl;
    cout << "Direccion: " << (void*)pInicial << endl;
    cout << "Valor apuntado: " << *pInicial << "\n" << endl;

    cout << "Variable IDENTIFICACION" << endl;
    cout << "Valor original: " << identificacion << endl;
    cout << "Direccion: " << (void*)pIdentificacion << endl;
    cout << "Valor apuntado: " << *pIdentificacion << "\n" << endl;

    return 0;
}
