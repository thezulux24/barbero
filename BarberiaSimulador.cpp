#include "BarberiaSimulador.h"

// Constructor
BarberiaSimulador::BarberiaSimulador(int numSillas) 
    : maximoSillasEspera(numSillas), clienteActual(0), 
      tiempoCorteRestante(0), totalClientesAtendidos(0), 
      totalClientesSeFueron(0), siguienteIdCliente(1), 
      barberoTrabajando(false) {}

void BarberiaSimulador::limpiarPantalla() {
    system("cls");
}

void BarberiaSimulador::mostrarEstado() {
    limpiarPantalla();
    cout << "==========================================\n";
    cout << "          BARBERIA - SIMULACION          \n";
    cout << "==========================================\n\n";
    
    // Estado del barbero
    cout << "BARBERO: ";
    if (barberoTrabajando && tiempoCorteRestante > 0) {
        cout << "CORTANDO CABELLO (Cliente #" << clienteActual << ")";
        cout << " - " << tiempoCorteRestante << "s restantes\n";
    } else if (clientesEsperando.empty()) {
        cout << "DURMIENDO\n";
    } else {
        cout << "LISTO PARA SIGUIENTE CLIENTE\n";
    }
    
    cout << "\n";
    
    // Sala de espera visual
    cout << "SALA DE ESPERA (" << clientesEsperando.size() 
         << "/" << maximoSillasEspera << " sillas ocupadas):\n";
    
    cout << "+";
    for (int i = 0; i < maximoSillasEspera; i++) {
        cout << "-----+";
    }
    cout << "\n|";
    
    // Mostrar clientes en las sillas
    for (int i = 0; i < maximoSillasEspera; i++) {
        if (i < (int)clientesEsperando.size()) {
            cout << " #" << setw(2) << clientesEsperando[i] << " |";
        } else {
            cout << "     |";
        }
    }
    
    cout << "\n+";
    for (int i = 0; i < maximoSillasEspera; i++) {
        cout << "-----+";
    }
    cout << "\n\n";
    
    // Estadisticas
    cout << "ESTADISTICAS:\n";
    cout << "- Clientes atendidos: " << totalClientesAtendidos << "\n";
    cout << "- Clientes que se fueron: " << totalClientesSeFueron << "\n";
    cout << "- Clientes esperando: " << clientesEsperando.size() << "\n";
    cout << "- Proximo cliente ID: " << siguienteIdCliente << "\n\n";
    
    // Leyenda
    cout << "LEYENDA:\n";
    cout << "DURMIENDO = Barbero sin clientes\n";
    cout << "CORTANDO CABELLO = Barbero trabajando\n";
    cout << "LISTO = Barbero esperando siguiente cliente\n";
    cout << "#XX = Cliente con ID XX\n\n";
}

bool BarberiaSimulador::intentarLlegadaCliente(int probabilidad) {
    // Probabilidad configurable de que llegue un cliente
    if (rand() % 100 < probabilidad) {
        if ((int)clientesEsperando.size() < maximoSillasEspera) {
            clientesEsperando.push_back(siguienteIdCliente);
            cout << ">>> Llego cliente #" << siguienteIdCliente << " y se sento a esperar\n";
            siguienteIdCliente++;
            return true;
        } else {
            cout << ">>> Cliente #" << siguienteIdCliente << " se fue (no hay sillas disponibles)\n";
            totalClientesSeFueron++;
            siguienteIdCliente++;
            return true;
        }
    }
    return false;
}

void BarberiaSimulador::agregarClienteManual() {
    if ((int)clientesEsperando.size() < maximoSillasEspera) {
        clientesEsperando.push_back(siguienteIdCliente);
        cout << ">>> Agregaste cliente #" << siguienteIdCliente << "\n";
        siguienteIdCliente++;
    } else {
        cout << ">>> No hay sillas disponibles - Cliente #" << siguienteIdCliente << " se fue\n";
        totalClientesSeFueron++;
        siguienteIdCliente++;
    }
}

void BarberiaSimulador::procesarTiempo() {
    // Si el barbero esta cortando cabello
    if (barberoTrabajando && tiempoCorteRestante > 0) {
        tiempoCorteRestante--;
        
        // Si termino de cortar
        if (tiempoCorteRestante == 0) {
            cout << ">>> Barbero termino de atender al cliente #" << clienteActual << "\n";
            totalClientesAtendidos++;
            clienteActual = 0;
            barberoTrabajando = false;
        }
    }
    
    // Si el barbero esta libre y hay clientes esperando
    if (!barberoTrabajando && !clientesEsperando.empty()) {
        clienteActual = clientesEsperando[0];
        clientesEsperando.erase(clientesEsperando.begin());
        tiempoCorteRestante = 2 + (rand() % 4); // 2-5 segundos
        barberoTrabajando = true;
        cout << ">>> Barbero comenzo a atender al cliente #" << clienteActual << "\n";
    }
}

// Getters para estadisticas
int BarberiaSimulador::obtenerClientesAtendidos() const { 
    return totalClientesAtendidos; 
}

int BarberiaSimulador::obtenerClientesSeFueron() const { 
    return totalClientesSeFueron; 
}

int BarberiaSimulador::obtenerClientesEsperando() const { 
    return clientesEsperando.size(); 
}

double BarberiaSimulador::calcularEficiencia() const {
    int totalClientes = totalClientesAtendidos + totalClientesSeFueron;
    if (totalClientes == 0) return 0.0;
    return (double)totalClientesAtendidos / totalClientes * 100.0;
}

// Funciones globales del programa

void mostrarMenu() {
    cout << "\n==========================================\n";
    cout << "       SIMULADOR DEL PROBLEMA DEL BARBERO\n";
    cout << "==========================================\n";
    cout << "1. Simulacion Automatica\n";
    cout << "2. Simulacion Manual\n";
    cout << "3. Simulacion Personalizada\n";
    cout << "4. Salir\n";
    cout << "==========================================\n";
    cout << "Seleccione una opcion (1-4): ";
}

int obtenerEntradaValida(int min, int max) {
    int entrada;
    while (!(cin >> entrada) || entrada < min || entrada > max) {
        cout << "Por favor ingrese un numero entre " << min << " y " << max << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return entrada;
}

void simulacionAutomatica() {
    cout << "\n=== SIMULACION AUTOMATICA ===\n";
    cout << "Configuracion:\n";
    cout << "- 3 sillas de espera\n";
    cout << "- 30% probabilidad de llegada por turno\n";
    cout << "- Tiempo de corte: 2-5 turnos\n\n";
    
    BarberiaSimulador barberia(3);
    
    cout << "Presiona ENTER para avanzar turnos, 'q' + ENTER para salir\n\n";
    
    string input;
    cin.ignore(); // Limpiar buffer
    
    do {
        barberia.mostrarEstado();
        
        // Procesar eventos automaticos
        bool huboLlegada = barberia.intentarLlegadaCliente(30);
        barberia.procesarTiempo();
        
        if (huboLlegada) {
            Sleep(1500); // Pausa para ver el evento
        }
        
        cout << "Presiona ENTER para continuar (o 'q' + ENTER para salir): ";
        getline(cin, input);
        
    } while (input != "q" && input != "quit");
    
    // Mostrar resumen final
    cout << "\n=== RESUMEN FINAL ===\n";
    cout << "Clientes atendidos: " << barberia.obtenerClientesAtendidos() << "\n";
    cout << "Clientes que se fueron: " << barberia.obtenerClientesSeFueron() << "\n";
    cout << "Eficiencia: " << fixed << setprecision(1) << barberia.calcularEficiencia() << "%\n";
}

void simulacionManual() {
    cout << "\n=== SIMULACION MANUAL ===\n";
    cout << "Cuantas sillas de espera desea? (1-8): ";
    int sillas = obtenerEntradaValida(1, 8);
    
    BarberiaSimulador barberia(sillas);
    
    cout << "\nComandos:\n";
    cout << "- ENTER: Avanzar tiempo\n";
    cout << "- 'c' + ENTER: Agregar cliente\n";
    cout << "- 'q' + ENTER: Salir\n\n";
    
    string input;
    cin.ignore(); // Limpiar buffer
    
    do {
        barberia.mostrarEstado();
        
        cout << "Comando (ENTER/c/q): ";
        getline(cin, input);
        
        if (input == "c") {
            barberia.agregarClienteManual();
        } else if (input != "q" && input != "quit") {
            barberia.procesarTiempo();
        }
        
        if (input != "q" && input != "quit") {
            Sleep(500);
        }
        
    } while (input != "q" && input != "quit");
    
    // Mostrar resumen final
    cout << "\n=== RESUMEN FINAL ===\n";
    cout << "Clientes atendidos: " << barberia.obtenerClientesAtendidos() << "\n";
    cout << "Clientes que se fueron: " << barberia.obtenerClientesSeFueron() << "\n";
    cout << "Eficiencia: " << fixed << setprecision(1) << barberia.calcularEficiencia() << "%\n";
}

void simulacionPersonalizada() {
    cout << "\n=== SIMULACION PERSONALIZADA ===\n";
    
    cout << "Cuantas sillas de espera? (1-10): ";
    int sillas = obtenerEntradaValida(1, 10);
    
    cout << "Probabilidad de llegada de clientes (10-80%): ";
    int probabilidad = obtenerEntradaValida(10, 80);
    
    cout << "Numero de turnos a simular (10-100): ";
    int turnos = obtenerEntradaValida(10, 100);
    
    BarberiaSimulador barberia(sillas);
    
    cout << "\nSimulando " << turnos << " turnos...\n";
    cout << "Presiona ENTER para comenzar\n";
    cin.ignore();
    cin.get();
    
    for (int i = 1; i <= turnos; i++) {
        barberia.mostrarEstado();
        cout << "TURNO " << i << " de " << turnos << "\n";
        
        barberia.intentarLlegadaCliente(probabilidad);
        barberia.procesarTiempo();
        
        Sleep(800);
    }
    
    // Mostrar resumen final detallado
    cout << "\n=== RESUMEN FINAL DETALLADO ===\n";
    cout << "Configuracion usada:\n";
    cout << "- Sillas de espera: " << sillas << "\n";
    cout << "- Probabilidad de llegada: " << probabilidad << "%\n";
    cout << "- Turnos simulados: " << turnos << "\n\n";
    
    cout << "Resultados:\n";
    cout << "- Clientes atendidos: " << barberia.obtenerClientesAtendidos() << "\n";
    cout << "- Clientes que se fueron: " << barberia.obtenerClientesSeFueron() << "\n";
    cout << "- Clientes aun esperando: " << barberia.obtenerClientesEsperando() << "\n";
    cout << "- Eficiencia de la barberia: " << fixed << setprecision(1) 
         << barberia.calcularEficiencia() << "%\n";
}