#include <wiringPi.h>

#define LED_PIN 17

int main() {
   wiringPiSetupGpio(); // Inicializar WiringPi
   pinMode(LED_PIN, OUTPUT); // Configurar el pin como salida
   while (1) { // Bucle infinito
      digitalWrite(LED_PIN, HIGH); // Encender el LED
      delay(1000); // Esperar 1 segundo
      digitalWrite(LED_PIN, LOW); // Apagar el LED
      delay(1000); // Esperar 1 segundo
   }
   return 0;
}

