/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.icm;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

public class ICM {
    // 1. ATRIBUTOS DE CLAVE: Deben ir fuera de los métodos para que todos los hilos los vean
    private static final int CAPACIDAD = 5;
    private static final Queue<String> buffer = new LinkedList<>();

    // SEMÁFOROS para control de concurrencia (Sincronización)
    private static Semaphore vacios = new Semaphore(CAPACIDAD); // Controla espacios libres
    private static Semaphore llenos = new Semaphore(0);        // Controla datos listos
    private static Semaphore mutex = new Semaphore(1);         // Asegura Exclusión Mutua

    // 2. metodo pirncipal
    public static void main(String[] args) {
        System.out.println("sistema de control de trafico siget (concurrente)");
        System.out.println("Optimizando CPU segun guia 'Mantener ocupada la CPU al 100%\n");
        
        // Creamos e iniciamos los hilos 
        new SensorTrafico("Sensor_Norte").start();
        new SensorTrafico("Sensor_Sur").start();
        new ModuloAnalisis("Analizador_Principal").start();
    }

    // 3. CLASES INTERNAS
    // Productor: Simula Sensores de Tráfico
    static class SensorTrafico extends Thread {
        private String id;
        public SensorTrafico(String id) { this.id = id; }

        @Override
        public void run() {
            try {
                while (true) {
                    String dato = "Lectura de " + id + " [" + (int)(Math.random() * 100) + "]";
                    vacios.acquire(); // Espera si el búfer está lleno
                    mutex.acquire();  // Entra en Sección Crítica (Exclusión Mutua)
                    buffer.add(dato);
                    System.out.println("[sensor] " + id + " envio datos.");
                    
                    mutex.release();  // Sale de Sección Crítica
                    llenos.release(); // Indica que hay un dato nuevo para procesar
                    
                    Thread.sleep(1500); 
                }
            } catch (InterruptedException e) {
                System.err.println("Error en hilo sensor: " + e.getMessage());
            }
        }
    }
    // Consumidor: Simula Módulos de Análisis del SIGET
    static class ModuloAnalisis extends Thread {
        private String id;
        public ModuloAnalisis(String id) { this.id = id; }
        @Override
        public void run() {
            try {
                while (true) {
                    llenos.acquire(); // Espera si no hay datos
                    mutex.acquire();  // Bloqueo para lectura segura
                    String dato = buffer.poll();
                    System.out.println("      [modulo " + id + "] Procesando: " + dato);
                    mutex.release();  // Libera el recurso
                    vacios.release(); // Avisa que hay espacio libre
                    Thread.sleep(3000); 
                }
            } catch (InterruptedException e) {
                System.err.println("Error en hilo de analisis: " + e.getMessage());
            }
        }
    }
}