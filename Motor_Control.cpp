
// Motor include
#include "Motor_Control.h"
#define Pulse 9
#define Dir 8
#define ENG 12

// Arduino specific includes
#include <Arduino.h>


//===============================================
// Class for controling the stepper

//====================================================
double Motor_Control::Step_Time()
{
    return (Seconds_Per_Turn/Steps_Per_Turn)*1000; // in ms
}

//====================================================
void Motor_Control::Set_Steps_Per_Turn(double Steps_Per_Turn_)
{
    Steps_Per_Turn = Steps_Per_Turn_;
}
//====================================================
void Motor_Control::Set_Seconds_Per_Turn(double Seconds_Per_Turn_)
{
    Seconds_Per_Turn = Seconds_Per_Turn_;
}

//====================================================
void Motor_Control::LeftyLoosy(double Turn)
{
    digitalWrite(Dir,LOW);
    for (int i=0; i<Steps_Per_Turn*Turn; i++)
    {
        digitalWrite(Pulse,HIGH);
        delay(Step_Time());
        digitalWrite(Pulse,LOW);
    }
}

//====================================================
void Motor_Control::RightyTighty(double Turn)
{
    digitalWrite(Dir,HIGH);
    for (int i=0; i<Steps_Per_Turn*Turn; i++)
    {
        digitalWrite(Pulse,HIGH);
        delay(Step_Time()); 
        digitalWrite(Pulse,LOW);
    }
}


//====================================================
void Motor_Control::Open_Valve()
{
    LeftyLoosy(1);
    delay(500);
    LeftyLoosy(1);
    delay(500);
    LeftyLoosy(1);
}

//====================================================
void Motor_Control::Close_Valve()
{
    RightyTighty(1);
    delay(500);
    RightyTighty(1);
    delay(500);
    RightyTighty(1);
}

void Motor_Control::TEST_MOTOR()
{
    delay(500);
    LeftyLoosy(1);
    delay(500);
    RightyTighty(1);
}
