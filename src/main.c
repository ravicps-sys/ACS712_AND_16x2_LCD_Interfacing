#include <Arduino.h>
#define BAUD_RATE 9600

#if defined (ESP8266)
// 3.3V For ESP8266
float adcReferenceVoltage = 1.0;
#elif defined (ARDUINO_AVR_UNO)
float adcReferenceVoltage = 5;
#endif
int adcMax = 1023;

float offsetCurrent = 2.47; // Voltage
float sensitivity = 0.185;
float adcVoltage = 0;
int adcValue = 0;

float getVoltage(uint16_t adcValue) {
  Serial.println("ADC Value "  + String(adcValue));

  float volt =  (adcValue *  adcReferenceVoltage ) / adcMax ;
  Serial.println("Voltage Value "  + String(volt));
  return volt;
}

float getCurrent(uint16_t adcValue){
  return (getVoltage(adcValue) - offsetCurrent) / sensitivity;
}

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  Serial.println("Current: "+ String(getCurrent(analogRead(A0))));
  delay(700);
}


