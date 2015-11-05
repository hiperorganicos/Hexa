/*
 * Developed by: George Rappel.
 * george.concei@hotmail.com
 *
 * PINS E CORES
 * Sinal 1 - Azul
 * Sinal 2 - Laranja
 * Positivo - Branco com Azul
 * Negativo - Branco com Laranja
 */

// ATUALIZAR ABAIXO COM O TOTAL DE SENSORES E FANS
int totalFans = 6;
int fansPins[] = {22, 24, 26, 28, 30, 32}; // DIGITAIS
int sensoresPins[] = {0, 1, 2, 3, 4, 5}; // ANALOGICOS
int sensor = 0;
// ATUALIZAR AS VARIÁVEIS ACIMA.

int limiteLoop = 5;
int delayPadrao = 10;
int delayHalfWay = 100;
int sensorMinimo = 400, sensorMedio = 700;
int incremento = 4;

void setup() {
  for(int i = 0; i < totalFans; i++)
    pinMode(fansPins[i], OUTPUT);
  desligaTodos();
}

void loop() {
  for(int i = 0; i < totalFans; i++){
    //sensor = analogRead(sensoresPins[i]);
    sensor = sensor + incremento;
    if(sensor < sensorMinimo){
      desliga(fansPins[i]);
      delay(delayPadrao);
    } else if (sensor < sensorMedio){
      halfWay(fansPins[i]);
    } else {
      liga(fansPins[i]);
      delay(delayPadrao);
    }
  }
  if(sensor > 1000){
    incremento = -4;
  } else if(sensor < 10){
    incremento = 4;
  }
}

void halfWay(int pin){
  liga(pin);
  delay(delayHalfWay);
  desliga(pin);
  delay(delayHalfWay);
}

void liga(int pin){
  digitalWrite(pin, HIGH);
}

void desliga(int pin){
  digitalWrite(pin, LOW); 
}

void desligaTodos(){
  for(int i = 0; i < totalFans; i++)
    digitalWrite(fansPins[i], LOW);
}

void ligaTodos(){
  for(int i = 0; i < totalFans; i++)
    digitalWrite(fansPins[i], HIGH);
}
