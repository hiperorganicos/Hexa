/*
 * Developed by: George Rappel.
 * george.concei@hotmail.com
 */

/* PINS E CORES
 * Sinal 1 - Azul
 * Sinal 2 - Laranja
 * Positivo - Branco com Azul
 * Negativo - Branco com Laranja
*/

// ATUALIZAR AS VÁRIAVEIS ABAIXO.
int totalFans = 6;
int fansPins[] = {22, 24, 26, 28, 30, 32};
int sensoresPins[] = {0, 1, 2, 3, 4, 5};
int sensor;
// ATUALIZAR AS VARIÁVEIS ACIMA.

int count = 0, limiteLoop = 5;
int delayPadrao = 100;
int sensorMinimo = 400, sensorMedio = 800;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < totalFans; i++)
    pinMode(fansPins[i], OUTPUT);
  desligaTodos();
}

void loop() {
  for(int i = 0; i < totalFans; i++){
    sensor = analogRead(sensoresPins[i]);
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
}

void halfWay(int pin){
  liga(pin);
  delay(delayPadrao);
  desliga(pin);
  delay(delayPadrao);
}

void liga(int pin){
  digitalWrite(pin, HIGH);
}

void desliga(int pin){
  digitalWrite(pin, LOW); 
}

void desligaTodos(){
  Serial.println("desligando todos");
  for(int i = 0; i < totalFans; i++)
    digitalWrite(fansPins[i], LOW);
}

void ligaTodos(){
  Serial.println("ligando todos");
  for(int i = 0; i < totalFans; i++)
    digitalWrite(fansPins[i], HIGH);
}
