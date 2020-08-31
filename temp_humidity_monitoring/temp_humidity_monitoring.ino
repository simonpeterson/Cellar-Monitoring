/*
 * Code for monitoring temperature and humidity in the cellar of Gwen Holdmann's house
 * written by Simon Peterson
 * 31.08.2020
 * Temp Sensor: TMP 36, https://www.arduino.cc/en/uploads/Main/TemperatureSensor.pdf */

//input pin for the temperature 
int TempPin = 0;
//integer input for analogRead(TempPin)
int T_input_digital = 0;
//temp in celsuis
double temperature_C = 0;
//conversion factor for converting the analog input to mV. This is 5 Volts/1024
double V_convert_constant = 5.0/1024.0;
//slope of temp, C/V, from datasheet
double temp_slope = 100;
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  //get the temperature and print to Serial Monitor
  temperature_C = TMP_36_measure(TempPin);
  Serial.println("The temperature: " + String(temperature_C) + " degrees Celsius");
  delay(1000);
}
