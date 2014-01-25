mf-alarm
========

Multifunctional Arduino based alarm system

System is able to monitor defined array of sensors and operate various alarm devices when neccessary.

Currently in a very alpha stage - some scaffolding code that has only the basic logic parts covered, however tested on real hardware and currently accepting one PIR sensor and one magnetic Reed door switch.

Uses Scoop scheduler: https://code.google.com/p/arduino-scoop-cooperative-scheduler-arm-avr/

TODO:

-Polish functional code with real sensors, seperate sensor logic in seperate objects

-Refactor the library to better fit Scoop logic. Maybe use messaging etc.

-Add confugurable settings file for general adjustments

-Add wiring diagrams and general alarm setup information


For future releases:
-Implement RFID operated lock

-Implement GSM operated lock

-Create ability to easily extend the lib for various sensors and output 

-Web status monitoring / REST service
