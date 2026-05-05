#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <random>
using namespace std;

mutex pantallaMutex;

// Clase para representar un corredor
class Corredor {
private:
    int id;
    string nombre;
    double velocidad; // segundos por metro
    
public:
    Corredor(int _id, string _nombre, double _velocidad) 
        : id(_id), nombre(_nombre), velocidad(_velocidad) {}
    
    int getId() { return id; }
    string getNombre() { return nombre; }
    double getVelocidad() { return velocidad; }
};

// Función que simula un corredor completando su tramo
void correrTramo(Corredor corredor, int distanciaMetros, int relevoID) {
    double tiempoTotal = distanciaMetros * corredor.getVelocidad();
    int intervalos = 5;
    double tiempoIntervalo = tiempoTotal / intervalos;
    
    pantallaMutex.lock();
    cout << "🏃 " << corredor.getNombre() << " (Relevo " << relevoID 
         << ") comenzó su tramo de " << distanciaMetros << "m" << endl;
    pantallaMutex.unlock();
    
    // Simular el progreso del corredor (dividido en intervalos)
    for(int i = 1; i <= intervalos; i++) {
        this_thread::sleep_for(chrono::milliseconds((int)(tiempoIntervalo * 1000)));
        
        int progreso = (i * 100) / intervalos;
        pantallaMutex.lock();
        cout << "   " << corredor.getNombre() << ": " << progreso << "% completado" << endl;
        pantallaMutex.unlock();
    }
    
    pantallaMutex.lock();
    cout << "✅ " << corredor.getNombre() << " terminó su tramo en " 
         << tiempoTotal << " segundos" << endl;
    pantallaMutex.unlock();
}

int main() {
    cout << "=== SIMULACIÓN DE CARRERA DE RELEVOS ===" << endl;
    cout << "Los 4 relevos corren simultáneamente\n" << endl;
    
    // Crear los corredores (id, nombre, velocidad en seg/m)
    vector<Corredor> equipo = {
        Corredor(1, "Carlos Pérez", 0.8),    // 0.8 seg por metro
        Corredor(2, "María López", 0.7),     // 0.7 seg por metro (más rápida)
        Corredor(3, "Juan García", 0.9),     // 0.9 seg por metro (más lento)
        Corredor(4, "Ana Martínez", 0.75)    // 0.75 seg por metro
    };
    
    int distanciaTramo = 100; // 100 metros cada corredor
    
    // Crear los hilos (cada corredor corre su tramo CONCURRENTEMENTE)
    vector<thread> hilos;
    for(int i = 0; i < equipo.size(); i++) {
        hilos.emplace_back(correrTramo, equipo[i], distanciaTramo, i + 1);
    }
    
    // Esperar a que todos los corredores terminen
    for(auto& hilo : hilos) {
        hilo.join();
    }
    
    cout << "\n=== ¡CARRERA COMPLETADA! ===" << endl;
    cout << "Los 4 relevos corrieron al mismo tiempo." << endl;
    
    return 0;
}