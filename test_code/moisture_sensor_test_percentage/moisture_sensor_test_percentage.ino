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

const int dry_threshold = 530 ;        // Reading in dry soil
const int wet_threshold = 420;         // Reading in wet soil

int soil_moisture_level = 0;      // Calculated as a percentage

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
  soil_moisture_level = map(moist_value, wet_threshold, dry_threshold, 0, 100);
  if (soil_moisture_level >= 100)
  {
    Serial.print("Soil sensor reads, ");
    Serial.print(soil_moisture_level);
    Serial.println("% moisture which means it's dry");
  }
  else if (soil_moisture_level <= 0)
  {
    Serial.print("Soil sensor reads, ");
    Serial.print(soil_moisture_level);
    Serial.println("% moisture which means it's wet");
  }
  else
  {
    Serial.print(soil_moisture_level);
    Serial.println("% moisture means that the soil is neither wet nor dry, it's perfect");
  }
  delay(1000);
}
