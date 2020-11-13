#ifndef Motor_Control_h
#define Motor_Control_h 1

//===============================================
// Class for controling the stepper
class Motor_Control
{
private:
    //====================================================
    double Steps_Per_Turn   = 400; // set this on the motor
    double Seconds_Per_Turn = 5;   // (seconds per turn ) noice and slow

    //====================================================
    double Step_Time();

public:
    //====================================================
    void Set_Steps_Per_Turn(double Steps_Per_Turn_);
    //====================================================
    void Set_Seconds_Per_Turn(double Seconds_Per_Turn_);
    //====================================================
    void LeftyLoosy(double Turn);
    //====================================================
    void RightyTighty(double Turn);
    //====================================================
    void Open_Valve();
    //====================================================
    void Close_Valve();
    //====================================================
    void TEST_MOTOR();

  
};

#endif
