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

// ATUALIZAR AS DUAS VÁRIAVEIS ABAIXO.
int totalFans = 2;
int fansPins[] = {7, 8};
// ATUALIZAR AS DUAS VARIÁVEIS ACIMA.

int pinSensor = 0;
int count = 0, limiteLoop = 5;
int delayPadrao = 700;
int sensorMinimo = 400, sensorMedio = 800;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < totalFans; i++)
    pinMode(fansPins[i], OUTPUT);
  desligaTodos();
}

void loop() {
  int sensor = analogRead(pinSensor);
  if(sensor < sensorMinimo){
    desligaTodos();
    delay(delayPadrao);
  } else if (sensor < sensorMedio){
    halfWay();
  } else {
    ligaTodos();
    delay(delayPadrao);
  }
  Serial.println(sensor);
}

void halfWay(){
  ligaTodos();
  delay(delayPadrao);
  desligaTodos();
  delay(delayPadrao);  
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
