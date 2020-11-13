// Motor include
#include "Sensor_Control.h"
#define SensPin_T 7
#define SensPin_B 3

// Arduino specific includes
#include <Arduino.h>

//====================================================
float Sensor_Control::Read_Value_T()
{
    raw = analogRead(SensPin_T);
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    return R2;
}

float Sensor_Control::Read_Value_B()
{
    raw = analogRead(SensPin_B);
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    return R2;
}

//====================================================
float Sensor_Control::Measure_T()
{
    int count = 0;
    float Value = 0.0;
    for (int i=0; i<10; i++)
    {
        count += 1;
        Value += Read_Value_T();
        delay(100);
    }
    Value /= count;
    return Value;
}

float Sensor_Control::Measure_B()
{
    int count = 0;
    float Value = 0.0;
    for (int i=0; i<10; i++)
    {
        count += 1;
        Value += Read_Value_B();
        delay(100);
    }
    Value /= count;
    return Value;
}
