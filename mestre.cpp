#include <SoftwareSerial.h>

// Definição dos pinos
#define buttonPin 8         // Botão conectado ao pino digital 8
#define lightSensorPin A0   // Sensor de luminosidade no pino analógico A0
SoftwareSerial ArduinoSlave(10, 11); // Comunicação serial com o Escravo

void setup() {
  pinMode(buttonPin, INPUT);       // Configura o botão como entrada
  Serial.begin(9600);              // Comunicação com o monitor serial
  ArduinoSlave.begin(9600);        // Comunicação serial com o Escravo
  Serial.println("Mestre iniciado.");
}

void loop() {
  int buttonState = digitalRead(buttonPin);   // Lê o estado do botão (1 = pressionado, 0 = não pressionado)
  int lightValue = analogRead(lightSensorPin); // Lê o valor do sensor de luminosidade
  
  // Concatena o estado do botão e o valor do sensor e envia para o Escravo
  String message = String(buttonState) + " " + String(lightValue) + "\n";
  ArduinoSlave.print(message);

  // Exibe os dados enviados no monitor serial
  Serial.print("MASTER SENT: ");
  Serial.println(message);

  delay(500); // Aguarda 500 ms para enviar os próximos dados
}
