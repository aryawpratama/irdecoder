#include <IRremote.h>

IRrecv IR(D3);   /*D8 Arduino Pin defined*/

void setup() {
IR.enableIRIn();    /*IR Communication Enabled*/
Serial.begin(9600); /*Serial Baud Rate defined*/
}
void loop() {
if (IR.decode()) {  /*IR Remote library function to decode remote */
  Serial.print("RAW :");
  Serial.println(IR.decodedIRData.decodedRawData); /*Print HEX value*/
  Serial.print("protocol :");
  Serial.println(IR.decodedIRData.protocol);
  Serial.print("numberOfBits :");
  Serial.println(IR.decodedIRData.numberOfBits);
  Serial.print("command :");
  Serial.println(IR.decodedIRData.command);

  delay(1000);
  IR.resume();   
  }  /*Wait for next input*/
}