
#include <iostream>
using namespace std;

int main() {
    int opcion;
    double num1, num2, resultado;
    char continuar;

    do {
        cout << "\n=== CALCULADORA ===" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        cout << "Ingrese el primer número: ";
        cin >> num1;
        cout << "Ingrese el segundo número: ";
        cin >> num2;

        switch(opcion) {
            case 1:
                resultado = num1 + num2;
                cout << "Resultado: " << resultado << endl;
                break;
            
            case 2:
                resultado = num1 - num2;
                cout << "Resultado: " << resultado << endl;
                break;

            case 3:
                resultado = num1 * num2;
                cout << "Resultado: " << resultado << endl;
                break;

            case 4:
                if(num2 != 0) {
                    resultado = num1 / num2;
                    cout << "Resultado: " << resultado << endl;
                } else {
                    cout << "Error: no se puede dividir entre cero" << endl;
                }
                break;

            default:
                cout << "Opción inválida" << endl;
        }

        cout << "\n¿Desea hacer otra operación matemática? (s/n): ";
        cin >> continuar;

    } while(continuar == 's' || continuar == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}