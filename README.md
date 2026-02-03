# ESP32 DHT11 Temperature & Humidity Monitor with OLED

## Project Overview
This project uses an **ESP32** to read **temperature and humidity** from a **DHT11 sensor** and display the values on an **I²C OLED (SSD1306)** screen.  
The readings are also printed to the **Serial Monitor** for debugging.

---

## Components Used
- ESP32 Dev Board  
- DHT11 Temperature & Humidity Sensor  
- SSD1306 I²C OLED Display 
- Jumper wires  

---

## Wiring

### DHT11 Sensor
| DHT11 Pin | ESP32 Pin |
|---------|-----------|
| **S (Data)** | GPIO 4 (P4) |
| **+ (VCC)** | 5V |
| **– (GND)** | GND |

---

### OLED Display (I²C)
| OLED Pin | ESP32 Pin |
|--------|-----------|
| **VCC** | 3.3V |
| **GND** | GND |
| **SDA** | GPIO 21 |
| **SCL** | GPIO 22 |

 **Important Notes**
- OLED use **3.3V**, not 5V  
- GPIO 21 & 22 are the ESP32 default I²C pins

---

## Libraries
- `DHT sensor library`
- `Adafruit GFX Library`
- `Adafruit SSD1306`

---

