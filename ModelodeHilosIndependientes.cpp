#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void ordenarArreglo(vector<int>& datos, string nombre) {
    cout << "🧵 Hilo " << nombre << " comenzó a ordenar " << datos.size() << " elementos" << endl;
    
    // Ordenar de menor a mayor
    sort(datos.begin(), datos.end());
    
    cout << "✅ Hilo " << nombre << " terminó de ordenar" << endl;
}

void mostrarArreglo(vector<int>& datos, string nombre) {
    cout << nombre << ": ";
    for(int num : datos) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "\n=== HILOS INDEPENDIENTES ORDENANDO DATOS ===" << endl;
    
    // Cada hilo trabajará con su propio arreglo (datos independientes)
    vector<int> arreglo1 = {5, 2, 8, 1, 9, 3};
    vector<int> arreglo2 = {15, 12, 18, 11, 19, 13, 17, 14};
    vector<int> arreglo3 = {25, 22, 28, 21};
    vector<int> arreglo4 = {35, 32, 38, 31, 39, 33, 37, 34, 36};
    
    cout << "\n--- Arreglos originales ---" << endl;
    mostrarArreglo(arreglo1, "Arreglo 1");
    mostrarArreglo(arreglo2, "Arreglo 2");
    mostrarArreglo(arreglo3, "Arreglo 3");
    mostrarArreglo(arreglo4, "Arreglo 4");
    
    cout << "\n--- Lanzando hilos independientes ---" << endl;
    
    // Cada hilo trabaja con un arreglo DIFERENTE (no hay conflicto)
    thread hilo1(ordenarArreglo, ref(arreglo1), "A");
    thread hilo2(ordenarArreglo, ref(arreglo2), "B");
    thread hilo3(ordenarArreglo, ref(arreglo3), "C");
    thread hilo4(ordenarArreglo, ref(arreglo4), "D");
    
    // Esperar a que todos terminen
    hilo1.join();
    hilo2.join();
    hilo3.join();
    hilo4.join();
    
    cout << "\n--- Arreglos ordenados ---" << endl;
    mostrarArreglo(arreglo1, "Arreglo 1");
    mostrarArreglo(arreglo2, "Arreglo 2");
    mostrarArreglo(arreglo3, "Arreglo 3");
    mostrarArreglo(arreglo4, "Arreglo 4");
    
    cout << "\n=== TODOS LOS HILOS TERMINARON INDEPENDIENTEMENTE ===" << endl;
    
    return 0;
}