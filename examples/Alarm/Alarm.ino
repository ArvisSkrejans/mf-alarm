#include <SCoop.h>
#include <Alarm.h>

Alarm alarm(A0, A1, 2, 13, 7);

volatile bool alarmStatus = false;

defineTask(Task1)

void Task1::setup() { 

};
void Task1::loop() {
  alarm.setArmedStatus();

  (alarmStatus == true) ? alarm.warningBeep() : alarm.stopAlarm();
  yield(); 
};

defineTask(Task2)

void::Task2::setup()

{ 

}

void Task2::loop(){
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
  yield(); 
}
void setup() {  

  mySCoop.start(); 
}
void loop() { 


  yield(); 
}

