/***************************************************
 * Test code for capacitive soil moisture sensor
 * 
 * Arduino UNO
 * Capacitive soil moisture sensor 
 * 
 * Sensor GND (Black)     -----> GND
 * Sensor VCC (Red)       -----> 3.3V
 * Sensor AOUT (Yellow)   -----> AO
 * 
 * Code to calibrate soil moisture sensor
 * 
 * 2022-08-13
 ****************************************************/


#define moist_pin A0    // Moisture sensor analog pin definition

void setup() 
{
  Serial.begin(9600);
  delay(50);
  Serial.println("Ready.....");
}

void loop() 
{
  int moist_value = analogRead(moist_pin); // read the analog value from sensor

  Serial.println(moist_value);
  delay(1000);
}
