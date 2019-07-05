/*
 * Wire - I2C Scanner
 *
 * for example the WeMos D1 Mini I2C bus uses pins:
 * D1 = SCL
 * D2 = SDA
 */

#include <Wire.h>

const int SCLpin = 22;
const int SDApin = 21; // For ESP32 Lolin D32

void setup()
{
  Serial.begin(115200);
  Serial.println("I2C Scanner");
  Serial.println("SDA Pin = "+String(SDA));
  Serial.println("SCL Pin = "+String(SCL));
  Wire.begin(SDApin, SCLpin);
}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    // The i2c scanner uses the return value of Write.endTransmisstion to see if a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("Done.\n");
  }
  delay(2000);
}

