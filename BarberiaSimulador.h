#ifndef BARBERIA_SIMULADOR_H
#define BARBERIA_SIMULADOR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

// Simulador del Problema del Barbero
class BarberiaSimulador {
private:
    vector<int> clientesEsperando;
    int maximoSillasEspera;
    int clienteActual;
    int tiempoCorteRestante;
    int totalClientesAtendidos;
    int totalClientesSeFueron;
    int siguienteIdCliente;
    bool barberoTrabajando;

public:
    // Constructor
    BarberiaSimulador(int numSillas);
    
    // Funciones principales
    void limpiarPantalla();
    void mostrarEstado();
    bool intentarLlegadaCliente(int probabilidad = 30);
    void agregarClienteManual();
    void procesarTiempo();
    
    // Funciones para obtener estadisticas
    int obtenerClientesAtendidos() const;
    int obtenerClientesSeFueron() const;
    int obtenerClientesEsperando() const;
    double calcularEficiencia() const;
};

// Funciones globales del programa
void mostrarMenu();
int obtenerEntradaValida(int min, int max);
void simulacionAutomatica();
void simulacionManual();
void simulacionPersonalizada();

#endif