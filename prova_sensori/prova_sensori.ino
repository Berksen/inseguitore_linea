#include <cny70.h>
cny70 cny;
void setup() 
{
  Serial.begin(9600);
  cny.selezionePin(9,10,4,5,6,7);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  cny.outputPin();
  if (digitalRead(4) == HIGH) {
    Serial.print("\tcny1 sul bianco ");
  }else
    Serial.print("\tcny1 sul nero ");
  if (digitalRead(5) == HIGH) {
    Serial.print("\tcny2 sul bianco ");
  }else
    Serial.print("\tcny2 sul nero ");
  if (digitalRead(6) == HIGH){
    Serial.print("\tcny3 sul bianco ");
  }else
    Serial.print("\tcny3 sul nero ");
  if (digitalRead(7) == HIGH) {
    Serial.print("\tcny4 sul bianco \n");
  }else
    Serial.print("\tcny4 sul nero \n");
  delay(500);
}

