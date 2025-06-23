# Conditional Monitoring of GPU

## Smart GPU Cooling System using IoT

This project aims to provide an intelligent, energy-efficient GPU cooling solution that dynamically activates cooling components based on real-time temperature data. By leveraging IoT components such as the ESP32 microcontroller, DHT22 sensor, Peltier module, and relay-controlled fan, the system enhances thermal management and conserves power.

## Problem Statement
Traditional GPU cooling systems rely on static cooling mechanisms that run continuously, regardless of actual GPU workload. This leads to:
- Unnecessary energy consumption
- Ineffective thermal regulation
- Reduced hardware lifespan due to thermal stress
- 
## Proposed Solution
An IoT-based conditional cooling system that:
- Continuously monitors temperature and humidity
- Activates cooling only when GPU temperature exceeds a defined threshold
- Automatically deactivates cooling when safe temperature is restored

## Components Used

| Component        | Description                                |
|------------------|--------------------------------------------|
| ESP32-WROOM      | Microcontroller for processing and control |
| DHT22            | Digital Temperature and Humidity Sensor    |
| Relay Module     | Switches fan and Peltier ON/OFF            |
| Peltier Module   | Provides active cooling                    |
| Cooling Fan      | Helps dissipate heat efficiently           |

## 🔄 System Workflow

1. **Data Collection**: DHT22 collects temperature and humidity.
2. **Processing**: ESP32 compares the temperature against a preset threshold (e.g., 30°C).
3. **Control**:
   - If temperature > threshold → Fan and Peltier turn ON
   - If temperature ≤ threshold → Devices turn OFF
4. **Automation**: All actions are performed in real-time with no manual intervention.
