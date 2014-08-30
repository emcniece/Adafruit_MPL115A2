/**************************************************************************/
/*!
    @file     Adafruit_MPL115A2.cpp
    @author   E.McNiece (EMC2 Innovation)
    @license  BSD (see license.txt)

    Example for the MPL115A2 barometric pressure sensor

    This is a library for the Adafruit MPL3115A2 breakout
    ----> https://www.adafruit.com/products/992

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0.1 - Ported to Spark Core
    v1.0 - First release
*/
/**************************************************************************/

#include <Adafruit_MPL115A2/Adafruit_MPL115A2.h>

Adafruit_MPL115A2 mpl115a2;

void setup(void) 
{
  Serial.begin(9600);
  while(!Serial.available()) SPARK_WLAN_Loop();	// needed for Spark init
  Serial.println("Hello!");
  
  Serial.println("Getting barometric pressure ...");
  mpl115a2.begin();
}

void loop(void) 
{
  float pressureKPA = 0, temperatureC = 0;    

  mpl115a2.getPT(&pressureKPA,&temperatureC);
  Serial.print("Pressure (kPa): "); Serial.print(pressureKPA, 4); Serial.print(" kPa  ");
  Serial.print("Temp (*C): "); Serial.print(temperatureC, 1); Serial.println(" *C both measured together");
  
  pressureKPA = mpl115a2.getPressure();  
  Serial.print("Pressure (kPa): "); Serial.print(pressureKPA, 4); Serial.println(" kPa");

  temperatureC = mpl115a2.getTemperature();  
  Serial.print("Temp (*C): "); Serial.print(temperatureC, 1); Serial.println(" *C");
  
  delay(1000);
}