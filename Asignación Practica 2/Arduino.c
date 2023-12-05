// Definir el pin del LED
int ledPin = 13;

void setup() {
  // Inicializar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Encender el LED
  digitalWrite(ledPin, HIGH);
  // Esperar un segundo
  delay(1000);
  // Apagar el LED
  digitalWrite(ledPin, LOW);
  // Esperar otro segundo
  delay(1000);
}
