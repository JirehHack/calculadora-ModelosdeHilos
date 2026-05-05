#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // MODELO SECUENCIAL - Control de inventario y venta
    
    // ===== DECLARACIÓN DE VARIABLES =====
    string nombreProducto;
    int cantidadInicial, cantidadVendida;
    double precioUnitario;
    const double IVA = 0.16;
    
    // ===== ENTRADA DE DATOS =====
    cout << "=== CONTROL DE INVENTARIO ===\n\n";
    
    cout << "Nombre del producto: ";
    getline(cin, nombreProducto);
    
    cout << "Cantidad inicial en stock: ";
    cin >> cantidadInicial;
    
    cout << "Precio unitario (MNX): $";
    cin >> precioUnitario;
    
    cout << "Cantidad vendida hoy: ";
    cin >> cantidadVendida;
    
    // ===== PROCESAMIENTO DE DATOS =====
    // Calcular stock restante
    int stockRestante = cantidadInicial - cantidadVendida;
    
    // Calcular subtotal de la venta
    double subtotal = cantidadVendida * precioUnitario;
    
    // Calcular impuestos
    double impuestos = subtotal * IVA;
    
    // Calcular total de la venta
    double totalVenta = subtotal + impuestos;
    
    // Calcular valor del inventario restante
    double valorInventario = stockRestante * precioUnitario;
    
    // Calcular porcentaje vendido
    double porcentajeVendido = (double)cantidadVendida / cantidadInicial * 100;
    
    // ===== FORMATEO DE SALIDA =====
    cout << fixed << setprecision(2);
    
    // ===== REPORTE DE VENTA =====
    cout << "\n" << string(50, '=') << endl;
    cout << "        REPORTE DE VENTA DEL DÍA" << endl;
    cout << string(50, '=') << endl;
    
    cout << "\nPRODUCTO: " << nombreProducto << endl;
    cout << "----------------------------------------\n";
    
    cout << "Cantidad vendida:       " << setw(8) << cantidadVendida << " unidades" << endl;
    cout << "Precio unitario:        " << setw(8) << "$" << precioUnitario << endl;
    cout << "Subtotal:               " << setw(8) << "$" << subtotal << endl;
    cout << "IVA (16%):              " << setw(8) << "$" << impuestos << endl;
    cout << "TOTAL DE VENTA:         " << setw(8) << "$" << totalVenta << endl;
    
    // ===== REPORTE DE INVENTARIO =====
    cout << "\n" << string(50, '-') << endl;
    cout << "        ESTADO DEL INVENTARIO" << endl;
    cout << string(50, '-') << endl;
    
    cout << "Stock inicial:          " << setw(8) << cantidadInicial << " unidades" << endl;
    cout << "Stock restante:         " << setw(8) << stockRestante << " unidades" << endl;
    cout << "Porcentaje vendido:     " << setw(8) << porcentajeVendido << "%" << endl;
    cout << "Valor en inventario:    " << setw(8) << "$" << valorInventario << endl;
    
    // ===== INDICADORES DE RENDIMIENTO =====
    cout << "\n" << string(50, '-') << endl;
    cout << "        INDICADORES" << endl;
    cout << string(50, '-') << endl;
    
    // Umbral de reorden (si stock restante es menos del 30% del inicial)
    double umbralReorden = cantidadInicial * 0.30;
    cout << "Umbral de reorden:      " << setw(8) << umbralReorden << " unidades" << endl;
    
    if(stockRestante < umbralReorden) {
        cout << "⚠️  ALERTA: Necesita reabastecer inventario" << endl;
    } else {
        cout << "✓  Inventario saludable" << endl;
    }
    
    // Eficiencia de venta
    if(porcentajeVendido >= 50) {
        cout << "✓  Excelente volumen de ventas" << endl;
    } else if(porcentajeVendido >= 20) {
        cout << "✓  Ventas aceptables" << endl;
    } else {
        cout << "⚠️  Ventas bajas, revisar estrategia" << endl;
    }
    
    // ===== CIERRE DEL PROGRAMA =====
    cout << "\n" << string(50, '=') << endl;
    cout << "Reporte generado: " << __DATE__ << " " << __TIME__ << endl;
    cout << "Fin del proceso secuencial" << endl;
    cout << string(50, '=') << endl;
    
    return 0;
}