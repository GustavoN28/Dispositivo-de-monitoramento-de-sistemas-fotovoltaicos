#include <Arduino.h>


long leitura_sensor_voltage;
int Value_div_tensao = 5;
double voltage_sensor = 0.0;
double voltage_real = 0.0;




//----------------------current---------------------------------------------------------------
const int sensibilidade = 100; //em mV/A
int leitura_sensor_current;
double voltage_read = 0;
double current = 0;
const int ACSoffset = 511;
//-----------------------------------------------------------------------------------------------------
void setup() {

  Serial.begin(9600);

}

void loop() {


  //-------------------Current---------------------------------------------------------------------
  leitura_sensor_current = 0;
  for (int i = 0; i < 1000; i++)
  {
    leitura_sensor_current += (analogRead(PIN_A0) - ACSoffset);
  }
 
   
  int leitura_filtro = leitura_sensor_current/1000;
  
  voltage_read = (leitura_filtro / 1024.0) * 5000; // em mV

  current = voltage_read / sensibilidade;


  //-----------------------------------------------------------------------------------------------------
  //-------------------------------Voltage----------------------------------------------------------------
 
  leitura_sensor_voltage = 0;

  for (int i=0; i < 1000; i++)
  {
    leitura_sensor_voltage += analogRead(PIN_A1);
    delay(1);
  }

  //leitura_sensor_voltage = analogRead(PIN_A2);
  int filtro_voltage = leitura_sensor_voltage/1000;
  voltage_sensor = (filtro_voltage / 1024.0) * 5;
  voltage_real = voltage_sensor * 5;

 //-------------------------------------------------------------------------------------------------------
 //---------------------------------------printfs--------------------------------------------------------

  Serial.println("corrente em A: ");
  Serial.println(current);
  Serial.println("Tensao em V:");
  Serial.println(voltage_real);
  




  delay(5000);

}