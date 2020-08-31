double TMP_36_measure(int pin){
  //reads temp from TMP36 temp sensor.
  int dig_input = analogRead(pin);
  double temp = 25-((.75-(dig_input*V_convert_constant))*temp_slope);
  return temp;
}
