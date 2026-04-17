# SMART-EXHAUST-WITH-AIR-QUALITY-AND-TEMPERATURE-MONITORING
An IoT-based Smart Exhaust System that monitors air quality, temperature, and humidity in real time using MQ135 and DHT11 sensors. The system automatically activates an exhaust fan when pollution or temperature exceeds safe thresholds and sends alerts via the Blynk platform. 
# 🚀 Smart Exhaust Air Quality & Temperature Monitoring System
 📌 Overview

This project is an IoT-based automation system designed to monitor indoor air quality and temperature in real-time and automatically control an exhaust fan.

It helps maintain a safe and comfortable environment by detecting harmful gases, high temperature, and humidity, and triggering ventilation when needed.


 🎯 Problem Statement

Indoor air pollution in kitchens, labs, and closed spaces often goes unnoticed, leading to:

* Respiratory issues
* Heat discomfort
* Unsafe working environments

Most existing systems are expensive and provide limited functionality.



 💡 Solution

This system:

* Continuously monitors air quality and temperature
* Automatically activates an exhaust fan when thresholds are exceeded
* Sends real-time alerts to the user
* Allows remote monitoring via IoT platform



 ⚙️ Features

* 🌡️ Temperature & Humidity Monitoring
* 🌫️ Air Quality Detection (CO₂, smoke, gases)
* 🔄 Automatic Exhaust Fan Control
* 📱 IoT Dashboard (Real-time data)
* 🔔 Notifications & Alerts
* 🎛️ Manual Control via App



 🧰 Tech Stack

* Microcontroller:NodeMCU ESP8266
* Sensors:

  * MQ135 (Air Quality Sensor)
  * DHT11 (Temperature & Humidity Sensor)
* Motor Driver: L298N
* Platform:Blynk IoT
* Programming: Arduino IDE (C/C++)



 🛠️ Hardware Components

| Component           | Quantity |
| ------------------- | -------- |
| NodeMCU ESP8266     | 1        |
| MQ135 Sensor        | 1        |
| DHT11 Sensor        | 1        |
| L298N Motor Driver  | 1        |
| Exhaust Fan / Motor | 1        |
| Jumper Wires        | -        |
| Power Supply (12V)  | 1        |



## 🔌 System Architecture

1. MQ135 detects gas concentration
2. DHT11 measures temperature & humidity
3. NodeMCU processes sensor data
4. If threshold exceeded:

   * Exhaust fan turns ON automatically
   * Alert is sent via Blynk
5. Data is displayed on IoT dashboard



## 📊 Working Logic

IF (Air Quality > Threshold OR Temperature > Threshold):
    Turn ON Exhaust Fan
    Send Alert Notification
ELSE:
    Turn OFF Exhaust Fan



 📱 Output

* Real-time dashboard (Temperature, Humidity, Air Quality)
* Mobile notifications (High temperature / pollution alerts)
* Email alerts (optional integration)


 💰 Cost Analysis

* Total Cost: ~₹940
* Compared to existing systems (~₹3000–₹3500), this solution is:

  * More affordable
  * More feature-rich
  * IoT-enabled



📍 Applications

* Smart Kitchens
* Laboratories
* Workshops
* Hostels / PG Rooms
* Small Industries



⚠️ Limitations

* Depends on Wi-Fi connectivity
* MQ135 & DHT11 have limited accuracy
* Requires calibration for reliable readings



🔮 Future Improvements

* Use high-accuracy sensors (MQ9, CCS811)
* Add AI-based prediction system
* Multi-room monitoring
* Voice control (Alexa / Google Assistant)
* Mobile app with analytics

---








🧠 Key Learnings

* IoT system design
* Sensor integration & calibration
* Real-time data processing
* Automation logic implementation








