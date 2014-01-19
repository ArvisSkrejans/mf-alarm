#include <Alarm.h>

//set initial setup values
bool alarmStatus = false;
static unsigned int alarmTimeout = 60;
//initialize alarm library
Alarm alarm(0, 1, 2, 13, 3, 4);

void setup() {

}

void loop() {

  if(alarm.isArmed()){
    alarmStatus = alarm.probe();
    alarm.glowStatusLed();
  }
  else{
    alarmStatus = false;
    alarm.blinkStatusLed();
  }

  (alarmStatus == true) ? alarm.startAlarm() : alarm.stopAlarm();


}


