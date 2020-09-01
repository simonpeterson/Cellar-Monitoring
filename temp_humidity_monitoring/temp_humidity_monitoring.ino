#include <LiquidCrystal.h>

/*
 * Code for monitoring temperature and humidity in the cellar of Gwen Holdmann's house
 * written by Simon Peterson
 * 31.08.2020
 * Temp Sensor: TMP 36, https://www.arduino.cc/en/uploads/Main/TemperatureSensor.pdf 
 * LCD used: JHD 659, 
 */

//input pin for the temperature 
int TempPin = 0;
//integer input for analogRead(TempPin)
int T_input_digital = 0;
//temp in celsuis
double temperature_C = 0;
//conversion factor for converting the analog input to mV. This is 5 Volts/1024
//TODO- make voltage divider to get 2V to use external voltage to read temperature
double V_convert_constant = 5.0/1024.0;
//slope of temp, C/V, from datasheet
double temp_slope = 100;

//LCD pin variables
int DB0 = 0;
int DB1 = 1;
int DB2 = 2;
int DB3 = 3;
int DB4 = 4;
int DB5 = 5;
int DB6 = 6;
int DB7 = 7;
int rs = 8;
int rw = 9;
int enable_pin = 10;


void setup() {
  Serial.begin(9600);
}

void loop() {
  //get the temperature and print to Serial Monitor
  temperature_C = TMP_36_measure(TempPin);
  Serial.println("The temperature: " + String(temperature_C) + " degrees Celsius");
  delay(1000);
}
