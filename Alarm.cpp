/*
  Alarm.cpp - Library for controlling alarm system and sensors.
 Created by Arvis Skrejans, 2014.
 */

#include "Arduino.h"
#include "Alarm.h"

int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long blinkInterval = 1000;  //blink interval
bool armedStatus = false; // armed status

/*
Initializes defined pins, sets output modes and pin access
 */
Alarm::Alarm(int pirSensorPin, int magSwitchPin, int buzzerPin, int statusLedPin, int armedPin)
{
  pinMode(pirSensorPin, INPUT);
  pinMode(magSwitchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(statusLedPin, OUTPUT);
  pinMode(armedPin, OUTPUT);

  _pirSensorPin = pirSensorPin;
  _magSwitchPin = magSwitchPin;
  _buzzerPin = buzzerPin;
  _statusLedPin = statusLedPin;
  _armedPin = armedPin;

}
/*
Probes the sensor status and sets alarm if neccessary
 */
bool Alarm::probe(){

  return (digitalRead(_pirSensorPin) == HIGH || digitalRead(_magSwitchPin) == LOW) ? true : false;

}

void Alarm::setArmedStatus(){
  armedStatus = Alarm::isArmed();
}

bool Alarm::isArmed()
{
  return (analogRead(_armedPin) > 30) ? true : false;

}

bool Alarm::armedStatusChanged(){

  if(armedStatus!=Alarm::isArmed()){
    armedStatus = Alarm::isArmed();
    return true;
  }
  else{
    return false;
  }

}

void Alarm::warningBeep(){

  for (int i=0; i <= 2; i++){
    tone(2, 2000); 
    delay(500);
    noTone(2);
    delay(500);
  } 

}

void Alarm::startAlarm(){
  if(digitalRead(_buzzerPin) == LOW){
    digitalWrite(_buzzerPin, HIGH);
  }

}
void Alarm::stopAlarm(){
  if(digitalRead(_buzzerPin) == HIGH){
    digitalWrite(_buzzerPin, LOW);
  }

}

void Alarm::blinkStatusLed(){
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > blinkInterval) {

    previousMillis = currentMillis;   

    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(_statusLedPin, ledState);
  }
}
void Alarm::glowStatusLed(){
  if(digitalRead(_statusLedPin) == LOW){
    digitalWrite(_statusLedPin, HIGH);
  }

}
