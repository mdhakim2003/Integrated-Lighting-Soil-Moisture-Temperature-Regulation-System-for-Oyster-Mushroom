# IoT-Based Oyster Mushroom Cultivation Monitoring System

## 📖 Overview
This project focuses on developing an IoT-enabled oyster mushroom cultivation house that monitors and controls environmental conditions to improve yield and quality. Using ESP32, DS18B20 temperature sensors, soil moisture sensors, and automated fan/light systems, the project ensures optimal growth conditions. Data is transmitted to cloud databases and visualized via dashboards for real-time monitoring.

---

## ✨ Features
- Real-time temperature monitoring (20–32°C range) with DS18B20 sensor  
- Soil moisture detection using YL-69 hygrometer sensor  
- Automated fan control based on ambient temperature changes  
- LED grow lights with automatic ON/OFF scheduling  
- ESP32 microcontroller with Wi-Fi and Bluetooth connectivity  
- Cloud-based data storage (Google Sheets, Node-RED, MQTT)  
- Dashboard visualization for farmers and researchers  
- Mobile app access for remote monitoring  

---

## 🛠️ Hardware Components
- **ESP32** – Microcontroller with Wi-Fi & Bluetooth  
- **DS18B20 Waterproof Temperature Sensor** – Accurate temperature monitoring  
- **YL-69 Soil Moisture Sensor + HC-38 Module** – Soil condition detection  
- **OLED Display (0.96")** – Local temperature display  
- **LED Grow Lights** – Automated lighting system  
- **Relay Module** – Fan and light control  

---

## ⚙️ Software & Tools
- **Arduino IDE** – Programming ESP32 and sensors  
- **Node-RED** – IoT flow management and dashboard visualization  
- **Google Sheets** – Cloud-based data logging  
- **MQTT Protocol** – Lightweight communication for sensor data  
- **HTML5** – Web-based visualization support  

---

## 📊 System Workflow
1. Sensors (temperature, soil moisture, light) collect environmental data.  
2. ESP32 processes sensor readings and controls fan/light systems.  
3. Data is transmitted via Wi-Fi using MQTT.  
4. Node-RED parses data, stores it in cloud databases, and visualizes it on dashboards.  
5. Farmers can monitor conditions remotely via smartphone or web app.  

---

## 🧩 Project Design
- **Design 1:** Closet-based prototype with limited mushroom blocks.  
- **Design 2:** Mushroom house with multiple sensors and higher cost.  
- **Design 3 (Final):** Optimized design with balanced cost, durability, and efficiency.  

---

## 🚀 Benefits
- Improves mushroom yield by maintaining optimal environmental conditions  
- Reduces manual monitoring effort with automation  
- Provides real-time insights for farmers and researchers  
- Enables remote monitoring via smartphones and dashboards  
- Supports data-driven decision-making for agriculture  

---

## 📅 Project Timeline
Development followed a structured Gantt chart across 4 months, including:  
- Title selection & proposal  
- Component research & procurement  
- System design & prototyping  
- Data collection & analysis  
- Final testing & documentation  

---

## 📝 Conclusion
This IoT-based oyster mushroom cultivation monitoring system demonstrates how automation and real-time data can improve agricultural productivity. By integrating ESP32, sensors, and cloud dashboards, the project provides farmers with a reliable, efficient, and scalable solution for mushroom farming.
