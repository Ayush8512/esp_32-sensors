# IR Obstacle Avoidance Sensor with ESP32

This module demonstrates interfacing a digital Infrared (IR) Obstacle Avoidance / Proximity Sensor with the **ESP32 DevKit**.

---

## 📌 Working Principle

The IR sensor module consists of:
1. **IR Transmitter (Clear LED)**: Emits invisible infrared light beam.
2. **IR Receiver (Black / Photodiode)**: Detects reflected IR light from any object in front of it.
3. **LM393 Comparator IC**: Compares receiver signal with a threshold set by the potentiometer.
4. **Sensitivity Potentiometer**: Used to calibrate the detection range (typically 2 cm to 30 cm).

### 💡 Output Logic (Active LOW):
- **Obstacle Present**: Signal pin `OUT` goes **`LOW` (0V)**. The onboard indicator LED turns **ON**.
- **No Obstacle (Clear Path)**: Signal pin `OUT` stays **`HIGH` (3.3V)**. The onboard indicator LED turns **OFF**.

---

## 🔌 Circuit Connection / Pinout

| IR Sensor Pin | ESP32 Pin | Description |
| :--- | :--- | :--- |
| **VCC** | **3.3V** (or **VIN / 5V**) | Power supply (3.3V recommended for safe logic level) |
| **GND** | **GND** | Common Ground |
| **OUT / DO** | **GPIO 18** | Digital Output signal |

> [!TIP]
> Agar aap VCC ko **5V (VIN)** se connect karte ho, toh check kar lena ki OUT pin 3.3V output de rahi hai ya 5V. ESP32 ke GPIO pins strictly **3.3V tolerant** hote hain. Safe rehne ke liye VCC ko **3.3V** pin se connect karna sabse best hota hai.

---

## 🛠️ Calibration (Sensitivity Tuning)

1. Connect the sensor to the ESP32 and power it up.
2. Place an obstacle at your desired detection distance (e.g., 5-10 cm).
3. If the detection LED on the sensor module does not glow, gently rotate the onboard blue potentiometer **clockwise**.
4. If the detection LED is always ON even with no obstacle, rotate the potentiometer **counter-clockwise** until it turns OFF.
5. Move your hand in and out to verify reliable switching.

---

## 💻 How to Run

1. Open `ir_obstacle_sensor.ino` in **Arduino IDE**.
2. Select **Board**: `Tools -> Board -> ESP32 Arduino -> ESP32 Dev Module`.
3. Select the correct **COM Port**.
4. Click **Upload**.
5. Open **Serial Monitor** at baud rate **`115200`**.
