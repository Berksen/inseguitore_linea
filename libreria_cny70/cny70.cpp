#include "cny70.h"

void cny70::avanti(int servo1, int servo2) 
{
	digitalWrite(servo1, HIGH);
    delay(0.5);
    digitalWrite(servo1, LOW);
    delay(20);
    digitalWrite(servo2, HIGH);
    delay(2);
    digitalWrite(servo2, LOW);
    delay(20);
}

void cny70::stop(int servo1,int servo2)
{
	digitalWrite(servo1, HIGH);
	delay(1.5);
	digitalWrite(servo1, LOW);
	delay(20);
	digitalWrite(servo2, HIGH);
	delay(1.5);
	digitalWrite(servo2, LOW);
	delay(20);
}

void cny70::avantiSingolo(int servo)
{
    digitalWrite(servo, HIGH);
    delay(0.5);
    digitalWrite(servo, LOW);
    delay(20);     
}

void cny70::stopSingolo(int servo)
{
    digitalWrite(servo, HIGH);
	delay(1.5);
	digitalWrite(servo, LOW);
	delay(20);   
}

void cny70::dietroSingolo(int servo)
{
    digitalWrite(servo2, HIGH);
    delay(2);
    digitalWrite(servo2, LOW);
    delay(20);     
}


void cny70::servoavanti()
{
//BIANCO ALTO NERO BASSO
	if(digitalRead(cny1) == HIGH && digitalRead(cny2) == LOW && digitalRead(cny3) == LOW && digitalRead(cny4) == HIGH)
	{
		avanti(servo1,servo2);
		Serial.println("attuando servoAvanti");
	}
	//rientro automatico verso sinistra
	while(digitalRead(cny1) == HIGH && digitalRead(cny2) == LOW && digitalRead(cny3) == HIGH && digitalRead(cny4) == HIGH)
	{
        stopSingolo(servo2);
		avantiSingolo(servo1);                  
    }
    //rientro automatico verso destra
    while(digitalRead(cny1) == HIGH && digitalRead(cny2) == HIGH && digitalRead(cny3) == LOW && digitalRead(cny4) == HIGH)
    {
        stopSingolo(servo1);
		dietroSingolo(servo2);                                        
    }
	if(digitalRead(cny1) == HIGH && digitalRead(cny2) == HIGH && digitalRead(cny3) == HIGH && digitalRead(cny4) == HIGH)
    {
        stop(servo1,servo2);  
    }
}

//curva angolo retto verso sinistra
void cny70::curvaSinistra()
{
     if(digitalRead(cny1) == LOW && digitalRead(cny2) == LOW && digitalRead(cny3) == LOW && digitalRead(cny4) == HIGH)
     {
        Serial.println("attuando curva sinistra");
        delay(300);
        for(i=0;i<5;i++)
        {
        stopSingolo(servo2);
		avantiSingolo(servo1);               
        }
        //rientro automatico
        while(digitalRead(cny2) == HIGH || digitalRead(cny3) == HIGH)
        {
        stopSingolo(servo2);
		avantiSingolo(servo1);
        }
        delay(300);
     }
}

//curva angolo retto verso destra
void cny70::curvaDestra()
{
	if(digitalRead(cny1) == HIGH && digitalRead(cny2) == LOW && digitalRead(cny3) == LOW && digitalRead(cny4) == LOW)
     {
        Serial.println("attuando curva destra");
        delay(300);
        for(i=0;i<5;i++)
        {
        stopSingolo(servo1);
		dietroSingolo(servo2);               
        }
        //rientro automatico
        while(digitalRead(cny2) == HIGH || digitalRead(cny3) == HIGH)
        {
        stopSingolo(servo1);
		dietroSingolo(servo2);
        }
        delay(300);
     }
}
