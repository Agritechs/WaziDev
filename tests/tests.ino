/********************
 * Program: test
 * Description: sends test values to WaziGate
 ********************/
 
#include <WaziDev.h>

// new WaziDev with node address = 8 
WaziDev wazidev("MyDevice", 8);

void setup()
{
  wazidev.setup();

  // Open serial communications and wait for port to open:
  Serial.begin(38400);
  // Print a start message
  Serial.println(F("Tests of WaziDev communications"));
}

void loop(void)
{
  wazidev.send("\\!UID/MyDevice/GPS/{\"BC\":2230,\"LAT\":-1.34683,\"LGT\":36.70799,\"FXT\":6,\"P\":\"N\"}");
  Serial.print(F("Sending numerical value...\n"));
  wazidev.send("\\!UID/MyDevice/NUM/15");
  delay(1000);
  Serial.print(F("Sending string value...\n"));
  wazidev.send("\\!UID/MyDevice/STR/\"test\"");
  delay(1000);
  Serial.print(F("Sending object value...\n"));
  wazidev.send("\\!UID/MyDevice/OBJ/{\"FLD1\":\"str\", \"FLD2\":16}");
  delay(1000);
  Serial.print(F("Sending array value...\n"));
  wazidev.send("\\!UID/MyDevice/ARR/[1, 2, 3]");
  delay(1000);
  Serial.print(F("Sending null value...\n"));
  wazidev.send("\\!UID/MyDevice/NUL/null");
  delay(1000);
  Serial.print(F("Sending boolean value...\n"));
  wazidev.send("\\!UID/MyDevice/BOL/true");

  delay(3000);
}
