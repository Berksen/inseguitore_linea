#include <cny70.h>

cny70 cny;

void setup()
{
     Serial.begin(9600);
     cny.selezionePin(9,10,4,5,6,7);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);
     pinMode(4, INPUT);
     pinMode(5, INPUT);
     pinMode(6, INPUT);
     pinMode(7, INPUT);
}

void loop()
{
  cny.servoavanti();
  cny.curvaDestra();
  cny.curvaSinistra();
}

