#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pinos
const int led_verde = 9;
const int led_amarelo = 10;
const int led_vermelho = 13;
const int buzzer = 8;
const int trigPin = 7;
const int echoPin = 6;

// Variáveis
long duracao;
int cm;

float A;
float B;
float L;

// Altura máxima da caixa (cm)
const int ALTURA_MAX = 334;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // Disparo do sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH, 30000); // timeout de 30ms

  if (duracao == 0) {
    Serial.println("Sem leitura");
    return;
  }

  cm = microsegundosParaCentimetros(duracao);

  // Cálculo do volume (ajuste conforme o formato real do bueiro)
  A = ALTURA_MAX - cm;
  B = A * 3276;   // área fictícia
  L = B / 1000.0; // litros

  // LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(cm);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Volume: ");
  lcd.print(L, 1);
  lcd.print(" L");

  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.print(" cm | Volume: ");
  Serial.print(L);
  Serial.println(" L");

  // LEDs e buzzer
  if (cm < 6) {
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, LOW);
    tone(buzzer, 220, 500);
  } 
  else if (cm <= 12) {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, LOW);
    tone(buzzer, 220, 200);
  } 
  else {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, HIGH);
    noTone(buzzer);
  }

  delay(500);
}

// Função de conversão
long microsegundosParaCentimetros(long microsegundos) {
  return microsegundos / 29 / 2;
}
