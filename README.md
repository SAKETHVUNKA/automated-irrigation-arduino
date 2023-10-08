# Smart_Irrigation_System-Automating_Water_Pumps_based_on_Soil_Moisture_Levels
An Arduino based project for automatic irrigation based on soil moisture levels

## SENSORS and COMPONENTS USED :
*	9V Water Pump - 3
*	5V Relay Module - 3
*	Arduino UNO R3 - 1
*	9V Battery - 3
*	SOIL MOISTURE SENSOR(RESISTANCE TYPE) - 3
*	ULTRASONIC SENSOR - 1

## CONNECTIONS :
*	Connect the Vcc of all 3 soil moisture sensors and all 3 relays and ultrasonic sensor to the 5v of the Arduino board 
*	Connect the Gnd of all 3 soil moisture sensors and all 3 relays and ultrasonic sensor to the Gnd of the Arduino  board 
*	Connect the A0 of the Soil moisture sensor 1 to the A1 pin of Arduino 
*	Connect the A0 of the Soil moisture sensor 2 to the A2 pin of Arduino 
*	Connect the A0 of the Soil moisture sensor 3 to the A3 pin of Arduino 
*	Connect the IN pin of the relay 1 to the pin 4 in Arduino board 
*	Connect the IN pin of the relay 2 to the pin 5 in Arduino board 
*	Connect the IN pin of the relay 3 to the pin 6 in Arduino board 
*	Connect the echo pin of the Ultrasonic sensor to the pin 7 in Arduino board and trig pin of the Ultrasonic sensor to  the pin 8 in Arduino board 
*	Connect the COM pin of relay 1 to the positive terminal of the pump 1 
*	Connect the COM pin of relay 2 to the positive terminal of the pump 2 
*	Connect the COM pin of relay 3 to the positive terminal of the pump 3
*	Connect the NO pin of all the 3 relays to the positive terminal of the battery 
*	Connect the negative terminal of all the 3 pumps to the negative terminal of the battery 
