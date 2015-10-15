/*
Sinal 1 - Azul
Sinal 2 - Laranja
Positivo - Branco com Azul
Negativo - Branco com Laranja
*/

int pinSensor = 0;
int pin1 = 7;
int pin2 = 8;
int count = 0, limiteLoop = 5;
int delayPadrao = 700;
int sensorMinimo = 400, sensorMedio = 800;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
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

void liga(int pin){
  digitalWrite(pin, HIGH);
}

void desliga(int pin){
  digitalWrite(pin, LOW);
}

void desligaTodos(){
  Serial.println("desligando todos");
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW); 
}

void ligaTodos(){
  Serial.println("ligando todos");
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH); 
}
