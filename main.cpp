#include "BarberiaSimulador.h"

int main() {
    srand((unsigned int)time(NULL));
    
    cout << "Bienvenido al Simulador del Problema del Barbero!\n";
    cout << "Este programa simula el clasico problema de sincronizacion.\n";
    
    int opcion;
    do {
        mostrarMenu();
        opcion = obtenerEntradaValida(1, 4);
        
        switch (opcion) {
            case 1:
                simulacionAutomatica();
                break;
            case 2:
                simulacionManual();
                break;
            case 3:
                simulacionPersonalizada();
                break;
            case 4:
                cout << "Gracias por usar el simulador!\n";
                break;
        }
        
        if (opcion != 4) {
            cout << "\nPresiona ENTER para volver al menu principal...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 4);
    
    return 0;
}