#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
using namespace std;

int sumaTotal = 0;
mutex consolaMutex;  // Esto evita que los mensajes se mezclen

void sumarRango(int inicio, int fin, int* resultado, int idHilo) {
    // Bloquear la consola para escribir sin interrupciones
    consolaMutex.lock();
    cout << "  [Hilo " << idHilo << "] ACTIVADO - Voy a sumar de " << inicio << " a " << (fin-1) << endl;
    consolaMutex.unlock();
    
    int suma = 0;
    for(int i = inicio; i < fin; i++) {
        suma += i;
    }
    
    *resultado = suma;
    
    consolaMutex.lock();
    cout << "  [Hilo " << idHilo << "] TERMINÉ - Mi suma parcial es: " << suma << endl;
    consolaMutex.unlock();
}

int main() {
    cout << "\n========================================" << endl;
    cout << "             SUMA DE NÚMEROS" << endl;
    cout << "========================================\n" << endl;
    
    vector<thread> hilos;
    const int NUM_HILOS = 4;
    int resultados[NUM_HILOS];
    
    cout << "Creando " << NUM_HILOS << " hilos..." << endl;
    cout << "Cada hilo sumará 250 números diferentes" << endl;
    cout << "Todos los hilos trabajarán AL MISMO TIEMPO\n" << endl;
    
    cout << "\n--- Suma en Proceso ---\n" << endl;

    for(int i = 0; i < NUM_HILOS; i++) {
        int inicio = i * 250;
        int fin = (i+1) * 250;
        cout << "Lanzando hilo " << (i+1) << " (rango: " << inicio << " - " << (fin-1) << ")" << endl;
        hilos.push_back(thread(sumarRango, inicio, fin, &resultados[i], i+1));
    }
    
    for(auto& h : hilos) {
        h.join();
    }
    
    cout << "\n--- Proceso terminado ---\n" << endl;
    
    for(int i = 0; i < NUM_HILOS; i++) {
        cout << "Resultado del Hilo " << (i+1) << ": " << resultados[i] << endl;
        sumaTotal += resultados[i];
    }
    
    cout << "\n========================================" << endl;
    cout << "SUMA TOTAL: " << sumaTotal << endl;
    cout << "========================================" << endl;
    
    return 0;
}