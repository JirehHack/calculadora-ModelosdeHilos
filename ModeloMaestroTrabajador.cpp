#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx;

void trabajador(int id, int inicio, int fin, int& resultado) {
    int suma = 0;
    for(int i = inicio; i <= fin; i++) {
        suma += i;
    }
    resultado = suma;
    
    mtx.lock();
    cout << "Hilo " << id << " sumó del " << inicio << " al " << fin << " = " << suma << endl;
    mtx.unlock();
}

int main() {
    mtx.lock();
    cout << "\n=== MAESTRO REPARTE TRABAJO ===" << endl;
    cout << "Maestro: Tengo que sumar del 1 al 100" << endl;
    mtx.unlock();
    
    const int NUM_HILOS = 4;
    int resultados[4];
    vector<thread> hilos;
    
    for(int i = 0; i < NUM_HILOS; i++) {
        int inicio = i * 25 + 1;
        int fin = (i + 1) * 25;
        
        mtx.lock();
        cout << "Maestro: Hilo " << i+1 << " suma del " << inicio << " al " << fin << endl;
        mtx.unlock();
        
        hilos.push_back(thread(trabajador, i+1, inicio, fin, ref(resultados[i])));
    }
    
    for(auto& h : hilos) {
        h.join();
    }
    
    int total = 0;
    for(int i = 0; i < NUM_HILOS; i++) {
        total += resultados[i];
    }
    
    mtx.lock();
    cout << "\nMaestro: Resultado final = " << total << endl;
    mtx.unlock();
    
    return 0;
}