#include <SoftwareSerial.h>

// Definição dos pinos
#define ledPin 12        // LED conectado ao pino digital 12
SoftwareSerial ArduinoMaster(10, 11); // Comunicação serial com o Mestre

String receivedData = "";             // Armazena os dados recebidos

void setup() {
  pinMode(ledPin, OUTPUT);          // Configura o pino do LED como saída
  digitalWrite(ledPin, LOW);        // Garante que o LED comece desligado
  Serial.begin(9600);               // Comunicação serial com o monitor serial
  ArduinoMaster.begin(9600);        // Comunicação serial com o Mestre
  Serial.println("Escravo iniciado.");
}

void loop() {
  // Lê os dados enviados pelo Mestre
  while (ArduinoMaster.available()) {
    char c = ArduinoMaster.read(); // Lê um caractere por vez
    if (c == '\n') {               // Processa a mensagem completa ao encontrar '\n'
      processReceivedData();       // Processa os dados recebidos
      receivedData = "";           // Limpa a string para a próxima mensagem
    } else {
      receivedData += c;           // Concatena os caracteres recebidos
    }
  }
}

void processReceivedData() {
  Serial.print("MASTER SENT: ");
  Serial.println(receivedData); // Exibe o comando recebido no formato esperado
  
  int spaceIndex = receivedData.indexOf(' '); // Localiza o espaço separador
  if (spaceIndex != -1) {
    // Extrai os valores de buttonState e luminosityValue
    bool buttonState = receivedData.substring(0, spaceIndex).toInt();
    int luminosityValue = receivedData.substring(spaceIndex + 1).toInt();

    // Verifica o estado do botão
    if (buttonState == 1) { 
      // Botão pressionado: LED ajustado proporcionalmente à luminosidade
      int ledIntensity = map(luminosityValue, 0, 1023, 0, 255);
      analogWrite(ledPin, ledIntensity);
    } else {
      // Botão não pressionado: LED desligado
      digitalWrite(ledPin, LOW);
    }

    // Exibe o valor PWM do LED no Monitor Serial
    Serial.print("Slave LED PWM value: ");
    Serial.println(buttonState == 1 ? map(luminosityValue, 0, 1023, 0, 255) : 0);
  }
}
