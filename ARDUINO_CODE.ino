#define RELAY_PIN_1    4  
#define RELAY_PIN_2    5
#define RELAY_PIN_3    6
#define MOISTURE_PIN_1 A1 
#define MOISTURE_PIN_2 A2 
#define MOISTURE_PIN_3 A3
#define echoPin        7
#define trigPin        8

int THRESHOLD_1_u = 100;
int THRESHOLD_2_u = 100;
int THRESHOLD_3_u = 100;

int THRESHOLD_1_l = 60;
int THRESHOLD_2_l = 60;
int THRESHOLD_3_l = 20;

int pump_1 = 1;
int pump_2 = 1;
int pump_3 = 1;

float moisture_percentage_1;
float moisture_percentage_2;
float moisture_percentage_3;

int sensor_analog_1;
int sensor_analog_2;
int sensor_analog_3;

int maximumRange = 5;
long duration, distance;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(MOISTURE_PIN_1, INPUT);
  pinMode(MOISTURE_PIN_2, INPUT);
  pinMode(MOISTURE_PIN_3, INPUT);
}

void loop() {
  Serial.println("-------------------------------------------------------------------");

  int okay = 1;

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;  // distance in cm

  Serial.println(distance);

  if (distance >= maximumRange) {
    okay = 0;
  }

  // Default state: all pumps OFF
  digitalWrite(RELAY_PIN_1, HIGH);    
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);

  if (okay == 1) {
    if (pump_1 == 1) {
      sensor_analog_1 = analogRead(MOISTURE_PIN_1);
      moisture_percentage_1 = 100 - ((sensor_analog_1 / 1023.00) * 100); 

      if (moisture_percentage_1 < THRESHOLD_1_l) {
        Serial.println("Soil 1 is DRY");
        digitalWrite(RELAY_PIN_1, LOW);
        delay(750);
        digitalWrite(RELAY_PIN_1, HIGH);
      } else if (moisture_percentage_1 < THRESHOLD_1_u) {
        digitalWrite(RELAY_PIN_1, LOW);
        delay(250);
        digitalWrite(RELAY_PIN_1, HIGH);
      } else {
        Serial.println("Soil 1 is WET");
      }

      Serial.print("Value 1: ");
      Serial.println(moisture_percentage_1);
    }

    if (pump_2 == 1) {
      sensor_analog_2 = analogRead(MOISTURE_PIN_2);
      moisture_percentage_2 = 100 - ((sensor_analog_2 / 1023.00) * 100); 

      if (moisture_percentage_2 < THRESHOLD_2_l) {
        Serial.println("Soil 2 is DRY");
        digitalWrite(RELAY_PIN_2, LOW);
        delay(750);
        digitalWrite(RELAY_PIN_2, HIGH);
      } else if (moisture_percentage_2 < THRESHOLD_2_u) {
        digitalWrite(RELAY_PIN_2, LOW);
        delay(250);
        digitalWrite(RELAY_PIN_2, HIGH);
      } else {
        Serial.println("Soil 2 is WET");
      }

      Serial.print("Value 2: ");
      Serial.println(moisture_percentage_2);
    }

    if (pump_3 == 1) {
      sensor_analog_3 = analogRead(MOISTURE_PIN_3);
      moisture_percentage_3 = 100 - ((sensor_analog_3 / 1023.00) * 100); 

      if (moisture_percentage_3 < THRESHOLD_3_l) {
        Serial.println("Soil 3 is DRY");
        digitalWrite(RELAY_PIN_3, LOW);
        delay(750);
        digitalWrite(RELAY_PIN_3, HIGH);
      } else if (moisture_percentage_3 < THRESHOLD_3_u) {
        digitalWrite(RELAY_PIN_3, LOW);
        delay(250);
        digitalWrite(RELAY_PIN_3, HIGH);
      } else {
        Serial.println("Soil 3 is WET");
      }

      Serial.print("Value 3: ");
      Serial.println(moisture_percentage_3);
    }
  } else {
    Serial.println("Water container is empty.");
  }

  Serial.println("-------------------------------------------------------------------");
  delay(30000); // Delay 30 seconds between readings
}