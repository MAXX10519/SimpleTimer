#include <Arduino.h>
#include "../src/SimpleTimer.h"

#define SERIAL SerialUSB
#define INTERVAL_TIME 127

SimpleTimer Interval;

double temp = 0;

void setup(){

    SERIAL.begin(9600);

    Interval.set(INTERVAL_TIME, updateTemp);
}
void loop(){
    temp = 5.0 * cos(PI * (millis() / 80000.0)) + 30.0;
    Interval.check();
}

void updateTemp(){

    if(!SERIAL){
        return;
    }
    SERIAL.print("Xaxis:0 "); // use Serial Plotter
    SERIAL.println("Temp:" + String(temp));
}