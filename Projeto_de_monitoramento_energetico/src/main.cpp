#include <Arduino.h>


const int sensibilidade = 100; //em mV/A
int leitura_sensor = 0;
double voltage_read = 0;
double current = 0;
const int ACSoffset = 2500;

void setup() {
  Serial.begin(9600);
  //pinMode(sensor_corrente, INPUT);

}

void loop() {
  leitura_sensor = 0;
 for (int i = 0; i < 1000; i++)
 {
   leitura_sensor += (analogRead(PIN_A0) - 511);
 }
 
   
  int leitura_filtro = leitura_sensor/1000;
  
  voltage_read = (leitura_filtro / 1024.0) * 5000; // em mV

  current = voltage_read / sensibilidade;

  Serial.println("corrente em A: ");
  Serial.println(current);
  //Serial.println(leitura_sensor);
  //Serial.println(voltage_read);

  delay(5000);

}