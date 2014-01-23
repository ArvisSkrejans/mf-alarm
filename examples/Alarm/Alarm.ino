#include <Alarm.h>

//set initial setup values
bool alarmStatus = false;
static unsigned int alarmTimeout = 60;
//initialize alarm library
Alarm alarm(0, 1, 2, 13, A0);

void setup() {
  alarm.setArmedStatus();
}

void loop() {

  if(alarm.isArmed()){
    alarmStatus = alarm.probe();
    alarm.glowStatusLed();
    if(alarm.armedStatusChanged()){
      alarm.warningBeep();
    }

  }
  else{
    alarmStatus = false;
    alarm.blinkStatusLed();
    if(alarm.armedStatusChanged()){
      alarm.warningBeep();
    }
  }

  (alarmStatus == true) ? alarm.startAlarm() : alarm.stopAlarm();


}



