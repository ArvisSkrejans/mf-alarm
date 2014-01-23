/*
  Alarm.h - Library for controlling alarm ystem and sensorss.
 Created by Arvis Skrejans, 2014.
 */

#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"

class Alarm
{
public:
  Alarm(int pirSensorPin, int magSwitchPin, int buzzerPin, int statusLedPin, int armedPin);
  bool probe();

  void startAlarm();
  void stopAlarm();

  void blinkStatusLed();
  void glowStatusLed();

  void warningBeep();

  bool isArmed();
  void setArmedStatus();
  bool armedStatusChanged();
private:
  int _pirSensorPin;
  int _magSwitchPin;
  int _buzzerPin;
  int _statusLedPin;
  int _armedPin;

};

#endif