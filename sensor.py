import serial
import time

esp32_port = 'COM3'  
baud_rate = 115200

try:
    ser = serial.Serial(esp32_port, baud_rate)
    print("Connected to ESP32! Waiting for data...\n")
    
    while True:
        if ser.in_waiting > 0:
            raw_data = ser.readline().decode('utf-8').strip()
            
            if raw_data == '0':
                print("🔴 ALARM! Object Detected!")
            elif raw_data == '1':
                print("🟢 Clear. No object.")
                
        time.sleep(0.01)

except KeyboardInterrupt:
    print("\nProgram stopped by user.")
    ser.close()
except Exception as e:
    print(f"Error: {e}")
