# Simulador del Problema del Barbero

## Descripcion

Este programa implementa una simulacion interactiva del clasico problema de sincronizacion "El Barbero Dormilon". Es una demostracion educativa de conceptos de sistemas operativos presentada de forma simple y visual.

## Archivos del Proyecto

- `BarberiaSimulador.h` - Archivo de cabeceras con definiciones de clases
- `BarberiaSimulador.cpp` - Implementacion de la logica del simulador
- `main.cpp` - Programa principal con menu y funciones principales
- `README.md` - Esta documentacion

## Compilacion

Compila todos los archivos juntos:

```batch
g++ -o simulador main.cpp BarberiaSimulador.cpp
```

## Ejecucion

```batch
simulador.exe
```

## Modos de Simulacion

### 1. Simulacion Automatica
**Perfecto para demostraciones**
- Configuracion fija (3 sillas de espera)
- Los clientes llegan automaticamente (30% probabilidad por turno)
- Control simple: ENTER para avanzar, 'q' para salir
- **Ideal para**: Ver el funcionamiento basico del problema

### 2. Simulacion Manual  
**Perfecto para aprender paso a paso**
- Configurar numero de sillas (1-8)
- Control total: tu decides cuando llegan clientes
- Comandos:
  - ENTER = Avanzar tiempo
  - 'c' = Agregar cliente
  - 'q' = Salir
- **Ideal para**: Entender cada paso del algoritmo

### 3. Simulacion Personalizada
**Perfecto para experimentos**
- Configurar sillas de espera (1-10)
- Configurar probabilidad de llegada (10-80%)
- Configurar numero de turnos (10-100)
- Simulacion automatica con tus parametros
- **Ideal para**: Analizar diferentes escenarios

## Visualizacion

```
==========================================
          BARBERIA - SIMULACION          
==========================================

BARBERO: CORTANDO CABELLO (Cliente #5) - 3s restantes

SALA DE ESPERA (2/3 sillas ocupadas):
+-----+-----+-----+
| #6  | #7  |     |
+-----+-----+-----+

ESTADISTICAS:
- Clientes atendidos: 4
- Clientes que se fueron: 1
- Clientes esperando: 2
- Proximo cliente ID: 8

LEYENDA:
DURMIENDO = Barbero sin clientes
CORTANDO CABELLO = Barbero trabajando
LISTO = Barbero esperando siguiente cliente
#XX = Cliente con ID XX
```

## Estructura del Codigo

### BarberiaSimulador.h
- Definicion de la clase `BarberiaSimulador`
- Declaraciones de funciones globales
- Includes necesarios

### BarberiaSimulador.cpp
- Implementacion de todos los metodos de la clase
- Logica de simulacion y visualizacion
- Funciones de menu y modos de simulacion

### main.cpp
- Funcion principal del programa
- Inicializacion y bucle principal
- Punto de entrada del ejecutable

## Requisitos

- **Sistema**: Windows
- **Compilador**: g++ (MinGW, Dev-C++, Code::Blocks)
- **Memoria**: Minima
- **Conocimientos**: Basicos de C++

## Conceptos Demostrados

- **Estados del barbero**: Durmiendo, trabajando, listo
- **Cola de espera**: Clientes esperando su turno
- **Capacidad limitada**: Sillas de espera finitas
- **Perdida de clientes**: Cuando no hay espacio
- **Metricas de eficiencia**: Porcentaje de clientes atendidos

## Compilacion en Diferentes Entornos

### MinGW (Linea de comandos)
```batch
g++ -o simulador main.cpp BarberiaSimulador.cpp
```

### Dev-C++
1. Crear nuevo proyecto
2. Agregar los 3 archivos al proyecto
3. Compilar y ejecutar

### Code::Blocks
1. File → New → Project → Console Application
2. Agregar archivos existentes al proyecto
3. Build & Run

### Visual Studio
1. Crear nuevo proyecto de consola
2. Agregar archivos al proyecto
3. Compilar en modo Release

## Solucion de Problemas

### Error de compilacion
```batch
# Verificar compilador
g++ --version

# Compilacion con mas detalles
g++ -v -o simulador main.cpp BarberiaSimulador.cpp
```

### Errores comunes
- **"No such file"**: Verificar que todos los archivos esten en el mismo directorio
- **"Undefined reference"**: Asegurar que estas compilando ambos archivos .cpp
- **Encoding issues**: Guardar archivos con codificacion UTF-8

## Ejemplo de Uso

1. **Compilar**: `g++ -o simulador main.cpp BarberiaSimulador.cpp`
2. **Ejecutar**: `simulador.exe`
3. **Elegir modo 1** (Automatico) para ver funcionamiento
4. **Presionar ENTER** repetidamente para ver la simulacion
5. **Observar** como llegan clientes y el barbero los atiende
6. **Probar modo 2** (Manual) para control total
7. **Experimentar modo 3** (Personalizado) con diferentes configuraciones


