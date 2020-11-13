#define Pulse 9
#define Dir 8
#define ENG 12


#include "Motor_Control.h"
#include "Sensor_Control.h"
#include "Commands.h"

Motor_Control Moto  = Motor_Control();
Sensor_Control Sens = Sensor_Control();
Commands Commander = Commands();

int counter = 0;
int KILL = 100;
unsigned long Arduno_time;
unsigned long Last_time = 1;
unsigned long TimeSinceFill  = 1;

const unsigned long test = 6000;  //the value is a number of milliseconds

const unsigned long OneMinuet = 60000;  //the value is a number of milliseconds
const unsigned long TenMinuet = 600000;  //the value is a number of milliseconds
const unsigned long FortyMinuet = 2400000;  //the value is a number of milliseconds

bool Going_Down = true;
bool At_Bottom = false;
float frac = 0.25;
float SensVal_T = 0;
float SensVal_B = 0;
String incoming = "";   // for incoming serial string data

void setup()
{
  Serial.begin(9600);
  pinMode(Pulse,OUTPUT);
  pinMode(Dir,OUTPUT);
  pinMode(ENG,OUTPUT);
  digitalWrite(Dir,LOW);
  digitalWrite(ENG,LOW);

  Moto.Set_Steps_Per_Turn(5000);
  Moto.Set_Seconds_Per_Turn(5);
}

void loop() {
  // put your main code here, to run repeatedly:

  incoming = Commander.Check_Serial();
  Serial.println(incoming);

  SensVal_T = Sens.Measure_T();
  SensVal_B = Sens.Measure_B();
  Serial.print("Sensor Valuel:\t");  
  Serial.print(SensVal_T);
  Serial.print("\t");
  Serial.print(SensVal_B);
  Serial.println(); 
  Serial.println(counter); 
  

  if (incoming == "up\n")
  {
    // right is up
    Moto.RightyTighty(0.25);
    delay(100);
  }

  else if (incoming == "down\n")
  {
    // left is up
    Moto.LeftyLoosy(0.25);
    delay(100);
  }

  else if (incoming == "start\n")
  {
    if (counter==0)
    {
      delay(test);
      Serial.println("Let_Me_Take_A_Selfie");
      delay(test);
      Going_Down = true;
      At_Bottom=false;
    }
    
    if ( (SensVal_T<20) && (SensVal_B<20) && !(At_Bottom) ) 
    {
      Serial.println("At Rock Bottom");
      Going_Down=false;
      At_Bottom=true;
      delay(test);
    }

    // going down
    if ( Going_Down && (counter<KILL) )
    {
      Serial.println("going down");
      counter += 1;
      Moto.LeftyLoosy(0.25);
    }
    else if ( !(Going_Down) && (counter<KILL) )
    {
      Serial.println("going up");
      counter -= 1;
      // right is up
      Moto.RightyTighty(0.25);
    }

    
    
  }
  

  else {delay(500);}

  

}
