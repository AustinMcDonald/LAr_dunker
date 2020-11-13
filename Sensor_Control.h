#ifndef Sensor_Control_h
#define Sensor_Control_h 1

//===============================================
// Class for controling the sensor
class Sensor_Control
{
private:
    //====================================================
    int raw = 0;
    int Vin = 5;
    float Vout = 0;
    float R1 = 160;
    float R2 = 0;
    float buffer = 0;
    
public:
    //====================================================
    float Read_Value_T();
    float Measure_T();
    float Read_Value_B();
    float Measure_B();

};

#endif
