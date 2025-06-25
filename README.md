# 🌿 Smart Irrigation System: Automated Water Pumps Using Soil Moisture Sensors

An Arduino-based project that automates irrigation by detecting soil moisture levels and controlling water pumps accordingly. Ideal for optimizing water usage in agriculture and home gardening.

---

## 🔧 Components Used

| Component                        | Quantity |
|----------------------------------|----------|
| Arduino UNO R3                   | 1        |
| Soil Moisture Sensor (resistive) | 3        |
| 5V Relay Module                  | 3        |
| 9V Water Pump                    | 3        |
| 9V Battery                       | 3        |
| Ultrasonic Sensor (HC-SR04)      | 1        |
| Jumper Wires                     | Many     |

---

## 🔌 Circuit Connections

### 🔹 Sensor & Actuator Wiring

- **Soil Moisture Sensors:**
  - Sensor 1 A0 → Arduino A1  
  - Sensor 2 A0 → Arduino A2  
  - Sensor 3 A0 → Arduino A3  
  - VCC → 5V (Arduino)  
  - GND → GND (Arduino)

- **Relay Modules:**
  - Relay 1 IN → Pin 4 (Arduino)  
  - Relay 2 IN → Pin 5 (Arduino)  
  - Relay 3 IN → Pin 6 (Arduino)  
  - VCC → 5V (Arduino)  
  - GND → GND (Arduino)  
  - COM → Positive terminal of respective pump  
  - NO  → Positive terminal of 9V Battery  
  - Pump GND → Battery negative terminal

- **Ultrasonic Sensor (Water Tank Level):**
  - Echo → Pin 7 (Arduino)  
  - Trig → Pin 8 (Arduino)  
  - VCC → 5V (Arduino)  
  - GND → GND (Arduino)

---

## 🧠 Working Principle

1. Soil moisture sensors read moisture percentage of the soil.
2. Ultrasonic sensor checks if the water tank has sufficient water.
3. If soil is dry **and** tank has water:
   - Corresponding pump is activated via relay.
4. Watering duration varies based on how dry the soil is.
5. Status is printed to Serial Monitor for logging.

---

## 🖼️ Circuit Diagram

> ![Circuit Diagram](https://github.com/user-attachments/assets/61486cb5-c8ca-4e1e-91e5-320ce561bfa4)

---

## 🚀 Getting Started

1. Clone this repo or download the `.ino` file.
2. Open the code in Arduino IDE.
3. Upload to your Arduino UNO.
4. Open Serial Monitor (9600 baud) to view sensor readings.
5. Modify threshold values in code if needed for your soil type.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## ✍️ Author

[Naga Saketh V](https://github.com/SAKETHVUNKA)

---