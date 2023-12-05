#include <Reg51.h>

void delay(unsigned int time) {
    while(time--) {
        TMOD = 0x01; // Modo 1 del temporizador
        TH0 = 0xFC; // Valor inicial del temporizador (para un retardo de 1ms)
        TL0 = 0x66;
        TR0 = 1; // Iniciar el temporizador
        while(!TF0); // Esperar a que el temporizador se desborde
        TR0 = 0; // Detener el temporizador
        TF0 = 0; // Limpiar la bandera de desbordamiento del temporizador
    }
}

void main() {
    while(1) {
        P1 = 0xFF; // Encender todos los LEDs conectados al puerto P1
        delay(1000); // Esperar 1 segundo

        P1 = 0x00; // Apagar todos los LEDs conectados al puerto P1
        delay(1000); // Esperar 1 segundo
    }
}

