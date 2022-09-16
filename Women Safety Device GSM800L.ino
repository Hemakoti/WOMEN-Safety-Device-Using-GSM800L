#include <SoftwareSerial.h>
SoftwareSerial ForCommunication(3,4);//{(3-Tx, 4-Rx)- On GSM Module}
const int Grid_1 = A0 ;
void setup ()
{
pinMode ( Grid_1 , INPUT);

ForCommunication.begin (9600);
Serial.begin (9600);
delay (100);
}
void loop()
{
 {
  int Grid_1_Status = analogRead (Grid_1);
  float Grid_1_Supply = (Grid_1_Status / 1023)*5 ;
  Serial.println(Grid_1_Supply);
  if (Grid_1_Supply > 3)
  ForCommunication.begin ( "S" );
      ForCommunication.println("AT+CMGF=1");
     delay(100);  
     ForCommunication.println("AT+CMGS=\"+919966123105\"\r");
     delay(1000);
     ForCommunication.println("I'm In Danger/Being Absued By Someone, These Are My Co-Ordinates: https://goo.gl/maps/LpBDXmhAoGmyhWdv8");
     delay(100);
     ForCommunication.println((char)26);
     delay(10000);
 }
}
