#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
using namespace std;

queue<string> bandeja;
mutex mtx;
int numeroOrden = 0;

void barista() {
    string bebidas[] = {"Café Americano", "Café Latte", "Cappuccino", "Expresso"};
    
    for(int i = 0; i < 6; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        
        mtx.lock();
        numeroOrden++;
        string cafe = bebidas[numeroOrden % 4] + " #" + to_string(numeroOrden);
        bandeja.push(cafe);
        cout << "BARISTA: " << cafe << " está listo | Cafés en bandeja: " << bandeja.size() << endl;
        mtx.unlock();
    }
}

void cliente() {
    for(int i = 0; i < 6; i++) {
        this_thread::sleep_for(chrono::seconds(2));
        
        mtx.lock();
        if(!bandeja.empty()) {
            string cafe = bandeja.front();
            bandeja.pop();
            cout << "CLIENTE: Tomó su " << cafe << " | Cafés restantes: " << bandeja.size() << endl;
        } else {
            cout << "CLIENTE: No hay cafés, espera..." << endl;
        }
        mtx.unlock();
    }
}

int main() {
    cout << "\n=== CAFETERÍA - PRODUCTOR Y CONSUMIDOR ===" << endl;
    cout << "El barista prepara cafés, los clientes los toman\n" << endl;
    
    thread baristaThread(barista);
    thread clienteThread(cliente);
    
    baristaThread.join();
    clienteThread.join();
    
    cout << "\n=== CAFETERÍA CERRADA ===" << endl;
    
    return 0;
}