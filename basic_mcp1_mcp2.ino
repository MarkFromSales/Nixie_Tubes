/* 
  https://github.com/MarkFromSales/Nixie_Tubes
  More information in the README.MD
*/

#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;
#define addr1 0  // 0 = A2 low , A1 low , A0 low
#define addr2 7  // 7 = A2 high, A1 high, A0 high

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setup Start");
  mcp1.begin(addr1);
  mcp2.begin(addr2);
  
  // Tube 1
  mcp1.pinMode(0, OUTPUT);
  mcp1.pinMode(1, OUTPUT);
  mcp1.pinMode(2, OUTPUT);
  mcp1.pinMode(3, OUTPUT);
  // Tube 2
  mcp1.pinMode(4, OUTPUT);
  mcp1.pinMode(5, OUTPUT);
  mcp1.pinMode(6, OUTPUT);
  mcp1.pinMode(7, OUTPUT);
  // Tube 3
  mcp1.pinMode(8, OUTPUT);
  mcp1.pinMode(9, OUTPUT);
  mcp1.pinMode(10, OUTPUT);
  mcp1.pinMode(11, OUTPUT);
  // Tube 4
  mcp1.pinMode(12, OUTPUT);
  mcp1.pinMode(13, OUTPUT);
  mcp1.pinMode(14, OUTPUT);
  mcp1.pinMode(15, OUTPUT);
  // Tube 5
  mcp2.pinMode(0, OUTPUT);
  mcp2.pinMode(1, OUTPUT);
  mcp2.pinMode(2, OUTPUT);
  mcp2.pinMode(3, OUTPUT);
  // Tube 6
  mcp2.pinMode(4, OUTPUT);
  mcp2.pinMode(5, OUTPUT);
  mcp2.pinMode(6, OUTPUT);
  mcp2.pinMode(7, OUTPUT);
  // Tube 7
  mcp2.pinMode(8, OUTPUT);
  mcp2.pinMode(9, OUTPUT);
  mcp2.pinMode(10, OUTPUT);
  mcp2.pinMode(11, OUTPUT);
  // Tube 8
  mcp2.pinMode(12, OUTPUT);
  mcp2.pinMode(13, OUTPUT);
  mcp2.pinMode(14, OUTPUT);
  mcp2.pinMode(15, OUTPUT);
  
  Serial.println("Setup End");
}

void loop() {
  Serial.println();
  Serial.println("Loop Start");

  // Tube 1
  mcp1.digitalWrite(0, HIGH);  // D
  mcp1.digitalWrite(1, LOW);   // C
  mcp1.digitalWrite(2, LOW);   // B
  mcp1.digitalWrite(3, LOW);   // A
  // Tube 2
  mcp1.digitalWrite(4, LOW);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, LOW);
  mcp1.digitalWrite(7, LOW);
  // Tube 3
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, LOW);
  mcp1.digitalWrite(11, LOW);
  // Tube 4
  mcp1.digitalWrite(12, LOW);
  mcp1.digitalWrite(13, LOW);
  mcp1.digitalWrite(14, HIGH);
  mcp1.digitalWrite(15, LOW);
  // Tube 5
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, LOW);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, LOW);
  // Tube 6
  mcp2.digitalWrite(4, LOW);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, LOW);
  // Tube 7
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);
  mcp2.digitalWrite(11, LOW);
  // Tube 8
  mcp2.digitalWrite(12, LOW);
  mcp2.digitalWrite(13, LOW);
  mcp2.digitalWrite(14, LOW);
  mcp2.digitalWrite(15, HIGH);
  
  delay(2000);
  Serial.println("Loop End");
}
//EOF