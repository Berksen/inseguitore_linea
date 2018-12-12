#include <Arduino.h>
//Definizione classe
class cny70 
{
//variabili pubbliche
public:
	void avanti(int servo1,int servo2);
	void stop(int servo1,int servo2);
	void curvaDestra();
	void curvaSinistra();
	void servoavanti();
	void avantiSingolo(int servo);
	void stopSingolo(int servo);
	void dietroSingolo(int servo);
	//funzione per selezionare i pin
	void selezionePin(int s1,int s2,int cn1,int cn2,int cn3,int cn4)
    {
          servo1= s1;
          servo2= s2;
          cny1= cn1;
          cny2= cn2;
          cny3= cn3;
          cny4= cn4;
    }
    //funzione per confermare i pin
    void outputPin()
    {
         Serial.println(servo1);
         Serial.println(servo2);
         Serial.println(cny1);
         Serial.println(cny2);
         Serial.println(cny3);
         Serial.println(cny4);
    }
//variabili private
private:
    int servo1, servo2, cny1, cny2, cny3, cny4, i;
};
