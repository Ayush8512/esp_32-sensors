# ESP32 Sensor Interface & Experimentation Lab

[![ESP32](https://img.shields.io/badge/Board-ESP32%20DevKit%20V1-blue.svg)](https://www.espressif.com/)
[![Framework](https://img.shields.io/badge/Framework-Arduino%20%2F%20C%2B%2B-green.svg)](https://www.arduino.cc/)
[![GitHub repo](https://img.shields.io/badge/GitHub-esp__32--sensors-black.svg)](https://github.com/Ayush8512/esp_32-sensors)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A structured and comprehensive repository containing test codes, circuit diagrams, pinout configurations, and modular drivers for interfacing various analog, digital, I2C, and SPI sensors with the **ESP32 microcontroller**.

---

## 📌 Project Overview

This repository acts as a central hub for all ESP32 sensor experiments. Each sensor folder includes:
- **Source Code (`.ino` / `.cpp`)**: Ready-to-flash test codes and clean modular functions.
- **Circuit / Wiring Details**: Pin-to-pin connection table for quick breadboard setup.
- **Required Libraries**: List of third-party libraries needed for compilation.
- **Serial Monitor Output Guide**: Expected readings and calibration tips.

---

## 🗂️ Repository Structure

```text
esp_32-sensors/
├── sensors/
│   ├── temperature_humidity/
│   │   ├── dht11_dht22/
│   │   └── ds18b20/
│   ├── distance_motion/
│   │   ├── hc_sr04_ultrasonic/
│   │   └── pir_motion/
│   ├── motion_orientation/
│   │   └── mpu6050_gyro_accel/
│   ├── environment_gas/
│   │   ├── mq2_gas_smoke/
│   │   └── bmp280_pressure/
│   ├── light_optical/
│   │   └── ldr_photoresistor/
│   └── soil_water/
│       └── soil_moisture/
├── docs/
│   └── esp32_pinout_guide.md
├── .gitignore
└── README.md
```

---

## 📊 Sensor Support Matrix

| Sensor Name | Category | Communication | Operating Voltage | Status |
| :--- | :--- | :--- | :--- | :--- |
| **DHT11 / DHT22** | Temp & Humidity | 1-Wire Digital | 3.3V - 5V | 📋 Planned |
| **HC-SR04** | Ultrasonic Distance | Digital (Trigger / Echo) | 5V (Level Shifter / Divider) | 📋 Planned |
| **MPU6050** | 6-Axis Gyro & Accel | I2C (SDA: 21, SCL: 22) | 3.3V | 📋 Planned |
| **BMP280 / BME280**| Barometric Pressure & Temp | I2C / SPI | 3.3V | 📋 Planned |
| **PIR (HC-SR501)** | Motion Detection | Digital Output | 5V (Output: 3.3V compatible) | 📋 Planned |
| **MQ-2 / MQ-135** | Gas & Smoke | Analog (ADC) / Digital | 5V | 📋 Planned |
| **LDR (Photoresistor)** | Ambient Light | Analog (ADC) | 3.3V | 📋 Planned |
| **Capacitive Soil** | Soil Moisture | Analog (ADC) | 3.3V | 📋 Planned |
| **DS18B20** | Waterproof Temp | 1-Wire Digital | 3.3V - 5V | 📋 Planned |

---

## ⚡ Important ESP32 Pin Guidelines

When interfacing sensors with the ESP32, keep these hardware limitations in mind:

1. **ADC2 & Wi-Fi Conflict**:
   - `ADC2` pins (GPIOs 0, 2, 4, 12-15, 25-27) cannot be used while Wi-Fi is active.
   - For analog sensors, always prefer **`ADC1` pins** (GPIO 32, 33, 34, 35, 36, 39).
2. **Input-Only Pins**:
   - GPIO 34, 35, 36 (VP), and 39 (VN) do not have internal pull-up / pull-down resistors and cannot be used as outputs.
3. **Strapping Pins (Boot Issues)**:
   - Avoid pulling GPIO 0, GPIO 2, or GPIO 12 HIGH/LOW externally during boot time, as they control boot modes.
4. **Default I2C Pins**:
   - `SDA` = GPIO 21
   - `SCL` = GPIO 22

---

## 🚀 Getting Started

### 1. Requirements
- **Hardware**: ESP32 Development Board (30-pin or 38-pin), Breadboard, Jumper wires, USB Cable.
- **Software**: 
  - [Arduino IDE](https://www.arduino.cc/en/software) (or VS Code + PlatformIO)
  - ESP32 Board Package installed via Arduino Board Manager:
    ```text
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    ```

### 2. Clone the Repository
```bash
git clone https://github.com/Ayush8512/esp_32-sensors.git
cd esp_32-sensors
```

### 3. Running an Example
1. Navigate to the desired sensor folder (e.g., `sensors/temperature_humidity/dht11_dht22/`).
2. Open the `.ino` file in Arduino IDE.
3. Select your board (`Tools -> Board -> ESP32 Dev Module`) and COM Port.
4. Wire the sensor as documented in the sketch header / wiring diagram.
5. Click **Upload** and open the **Serial Monitor** at baud rate `115200`.

---

## 🤝 Contributing
Contributions, sensor additions, and bug fixes are welcome! Feel free to open an issue or submit a pull request.

---

## 📜 License
This project is licensed under the [MIT License](LICENSE).
