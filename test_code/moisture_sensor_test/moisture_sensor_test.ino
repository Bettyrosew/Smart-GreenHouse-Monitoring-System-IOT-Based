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
 * Code to test soil moisture sensor
 * 
 * Threshold is determined using the calibration code and is the point at which the soil 
 * is considered wet or dry
 * 
 * 2022-08-13
 ****************************************************/


#define moist_pin A0    // Moisture sensor analog pin definition
#define dry_threshold 500     //Reading in dry soil
#define wet_threshold 400     // Reading in wer soil

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
  if (moist_value > dry_threshold)
  {
    Serial.print("Soil sensor reads, ");
    Serial.print(moist_value);
    Serial.println(" which means it's dry");
  }
  else if (moist_value < wet_threshold)
  {
    Serial.print("Soil sensor reads, ");
    Serial.print(moist_value);
    Serial.println(" which means it's wet");
  }
  else
  {
    Serial.println("Soil is neither wet nor dry, it's perfect");
  }
  delay(1000);
}
