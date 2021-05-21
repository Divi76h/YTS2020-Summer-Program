#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int LDRPin = 35;
int LDRValue = 0;

void setup() 
{
  pinMode(LDRPin, INPUT);
  Serial.begin(115200);
  SerialBT.begin("Divi76hs_ESP32");
}

void loop() 
{
  int sensorValue = analogRead(LDRPin);
  SerialBT.println(sensorValue);
  delay(100);
}
