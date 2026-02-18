# Hardware-in-the-Loop (HIL) Greenhouse Temperature Control

This repository contains the implementation of a **Hardware-in-the-Loop (HIL)** control system for a greenhouse environment. The project integrates **MATLAB/Simulink** (as the controller) with an **ESP32 microcontroller** (as the plant/hardware interface) using **TCP/IP over Wi-Fi**.

## 🚀 Project Overview
The system maintains a setpoint temperature by switching between a heating element (Red LED) and a cooling fan (Blue LED). It features a **Digital Twin** approach, allowing the user to switch between a virtual mathematical model and real-world sensors in real-time.

### Key Features
- **Closed-Loop PID Control:** Implemented in Simulink.
- **Dual Operation Modes:**
  1.  **Virtual Mode:** Uses a First-Order Transfer Function (`5 / 20s+1`) to simulate thermal dynamics.
  2.  **Real-World Mode:** Uses a DHT22 sensor and ESP32 via Wi-Fi (TCP/IP).
- **Hybrid Communication:** Demonstrates both Serial (UART) monitoring and TCP/IP control.
- **Fail-Safe Networking:** Non-blocking TCP server implementation on ESP32 to handle Simulink's real-time constraints.

## 🛠️ Hardware Requirements
- **Microcontroller:** ESP32 Development Board
- **Sensor:** DHT22 (Temperature & Humidity)
- **Actuators (Simulated):**
  - Red LED (Heater)
  - Blue LED (Cooler/Fan)
- **Other:** 2x Resistors (220Ω), Breadboard, Jumper wires

### 🔌 Pinout Configuration
| Component | ESP32 Pin | Description |
|-----------|-----------|-------------|
| DHT22     | GPIO 4    | Data Pin    |
| Red LED   | GPIO 5    | Heater      |
| Blue LED  | GPIO 18   | Fan/Cooler  |

## 💻 Software Requirements
- **MATLAB & Simulink** (R2025b or compatible)
- **Simulink Desktop Real-Time / Instrument Control Toolbox**
- **Arduino IDE** (with ESP32 board manager installed)
- **Required Libraries:** `DHT sensor library` by Adafruit

## ⚙️ How to Run

### 1. ESP32 Setup
1. Open the `.ino` file located in the `Arduino_Code` folder.
2. Install the required libraries in Arduino IDE.
3. Upload the code to your ESP32.
4. Open the Serial Monitor to verify the IP Address (Default: `192.168.4.1`).
5. Connect your PC to the ESP32 Wi-Fi Access Point (`HIL_Project_WiFi`).

### 2. Simulink Setup
1. Open `HIL_Control_System.slx` in MATLAB.
2. Ensure the TCP/IP blocks are configured to IP `192.168.4.1` (Port 80).
3. **Simulation Pacing:** Enable pacing to match wall-clock time (1:1).
4. Run the simulation.

### 3. Usage
- Use the **Manual Switch** block to toggle between the Virtual Plant and the Real Sensor.
- Adjust the **Setpoint** constant to see the PID response.
- Observe the LEDs on the hardware reacting to the Simulink commands.

## 📄 Documentation
For detailed explanation, circuit diagrams, and mathematical modeling, please refer to the [Project Report](Documentation/Project_Report.pdf).

## 🎥 Demo
A video demonstration of the HIL system in action can be found in the `Video_Demo` folder.

---
