# ALNAQI - Advanced Leakage Notification Alert Quality Air Intelligence

A low-cost, real-time gas leak detection and safety system built with Arduino Uno and an MQ-2 gas sensor. ALNAQI continuously monitors air quality and, upon detecting hazardous gas levels, immediately triggers an audible alarm, a visual LED warning, and automatic exhaust ventilation — kept running long enough to fully clear the area, not just until the sensor reads "safe."

This project was developed as part of an Electronics and Communications Engineering course at King Abdulaziz University.

## 🎯 Project Overview

Gas leaks are a serious hazard in kitchens, factories, labs, and parking garages, where delayed detection can be dangerous or fatal. ALNAQI addresses this with a complete, affordable safety pipeline: detect → alert → ventilate — built for under $45 in components, making it a practical, low-cost solution for real-world safety applications.

## ⚙️ How It Works

The system continuously reads the MQ-2 sensor's digital output. The sensor outputs **0** when combustible gas exceeds the safety threshold, and **1** in clean air.

**Gas Detected (sensorValue == 0):**
- Green LED turns OFF
- Relay 1 (Fan) → ON immediately
- Relay 2 (Buzzer) → ON immediately
- Red LED blinks rapidly (50ms interval) using a non-blocking `millis()` timer

**Gas Cleared (sensorValue == 1):**
- Buzzer turns OFF instantly
- Red LED stops, Green LED turns ON
- Fan continues running for **7 additional seconds** before shutting off automatically — ensuring full ventilation instead of stopping the moment the sensor reads "safe"

**Startup Sequence:**
- On power-up, all outputs initialize to a safe state (relays off, green LED on)
- A 20-second warm-up delay allows the MQ-2's heating element to stabilize before readings begin

## 🛠️ Components & Cost

| # | Component | Qty | Cost | Notes |
|---|-----------|-----|------|-------|
| 1 | Arduino Uno R3 | 1 | $12.00 | Microcontroller |
| 2 | MQ-2 Gas Sensor | 1 | $9.00 | Digital output used |
| 3 | 5V Relay Module (2-ch) | 1 | $4.80 | Fan + Buzzer control |
| 4 | DC Fan | 1 | $2.70 | Gas exhaust |
| 5 | Active Buzzer | 1 | $3.50 | Audio alert |
| 6 | RGB LED | 1 | $3.20 | Danger/Safe indicator |
| 7 | Mini Breadboard | 1 | $2.00 | Prototyping |
| 8 | 9V Battery | 1 | $1.50 | External power |
| 9 | Jumper Wires | 20 | $4.00 | Connections |
| | **Total** | | **$42.70** | |

## 📌 Pin Assignment

| Pin | Component | Type | Description |
|-----|-----------|------|--------------|
| D2 | Green LED | Digital Out | Safe indicator — HIGH = ON |
| D3 | Red LED | Digital Out | Danger — blinks every 50ms |
| D4 | MQ-2 Sensor | Digital In | 0 = gas detected / 1 = safe |
| D5 | Relay (Buzzer) | Digital Out | LOW = buzzer ON (active-low) |
| D6 | Relay (Fan) | Digital Out | LOW = fan ON (active-low) |
| 5V | MQ-2 / Relays | Power | VCC supply for all modules |
| GND | All Modules | Ground | Common ground reference |

## 🧩 3D Component Models

Component models were designed in SolidWorks prior to assembly, covering the Arduino Uno, 2-channel relay module, RGB LED module, mini breadboard, DC exhaust fan, active buzzer, and MQ-2 gas sensor.

## 🚦 Applications & Use Cases

| Environment | Use Case | Risk Level |
|---|---|---|
| Kitchens | LPG leak from stoves & gas cylinders | HIGH |
| Industrial Factories | Combustible gases near heavy machinery | CRITICAL |
| Parking Garages | CO / exhaust fume accumulation | MEDIUM |
| Labs & Hospitals | Gas supply room safety monitoring | CRITICAL |
| Restaurants | Restaurant fire prevention & compliance | HIGH |

## 📸 Demo

▶️ [Watch the project demo on YouTube](https://youtube.com/shorts/HBp4_bjixfA)

**Safe mode — Green LED active**

<img src="https://github.com/user-attachments/assets/dde4b742-d2d5-49f0-9f09-e96dc0d03795" width="450">

**Alert mode — Red LED active, fan and buzzer triggered**

<img src="https://github.com/user-attachments/assets/b378e53d-cd7f-4881-8a35-2b4f2846d6d1" width="450">

**Circuit wiring diagram (simulated in Wokwi)**

<img src="https://github.com/user-attachments/assets/373192ca-da01-4ff4-adda-be336e862be6" width="450">

## 💡 Conclusion

The Gas Detector System proves that life-saving technology doesn't require expensive hardware. At under $45, it delivers real-time detection, instant multi-modal alerts, and intelligent ventilation — a complete safety pipeline on a breadboard. The 7-second fan delay is the standout design decision: systems that shut off the moment a sensor reads "safe" risk leaving residual gas behind. This system doesn't.

The use of non-blocking `millis()` timers is the key firmware insight: simultaneous red LED blinking and fan countdown run in real time, with no processor freezing and no missed detections.

## 🚀 Future Improvements

- **LCD / OLED Display:** Show live gas readings and system status on screen
- **Wi-Fi Alert (ESP32):** SMS/push notifications for remote monitoring
- **Multi-Sensor Array:** Add MQ-7 (CO) + MQ-4 (Methane) for broader gas coverage
- **Custom PCB:** Replace breadboard with a sealed production enclosure

## 👥 Team

- Anas Al-Saedi
- Abdulaziz Al-Qahtani
- Abdulsalam Al-Ghamdi
- Abdullah Al-Ghamdi
- Salah Al-Mansouri
- Wesam Al-Ghamdi

---
**Author:** Abdulaziz S. Alqahtani
