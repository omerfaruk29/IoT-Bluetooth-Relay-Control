
# Bluetooth Controlled 220V AC Lamp Automation System

An IoT-based embedded system that enables remote control of high-voltage (220V AC) household lighting via Bluetooth communication. Designed with safety-first power switching principles and standard C++ firmware structure.

---

## Technical Overview

This project demonstrates the integration of low-voltage DC microcontrollers with high-voltage AC mains power. It utilizes an **Active-LOW 5V Relay Module** driven by an **Arduino UNO** to safely isolate and control a 220V AC load using commands sent over **UART (Bluetooth HC-05/06)**.

### Key Features
 **Safe AC Load Switching:** Galvanic isolation between 5V DC control logic and 220V AC mains power.
 **Software Serial Architecture:** Uses `SoftwareSerial` to reserve hardware UART pins (0 & 1) for uninterrupted USB debugging and code deployment.
 **Active-LOW Safety State:** Prevents unwanted relay switching/spikes during initial MCU boot-up.
 **Bi-Directional Feedback:** Provides real-time status output over Bluetooth and USB Serial Monitor.

---

## Hardware Components

| Component | Quantity | Specifications / Purpose |
| :--- | :--- | :--- |
| **Arduino UNO Rev3** | 1 | ATmega328P Microcontroller Board |
| **HC-05 / HC-06 Bluetooth** | 1 | UART Transceiver (9600 Baud) |
| **5V Single-Channel Relay Module** | 1 | 10A 250VAC / 10A 30VDC Rating (Active-LOW) |
| **220V AC Lamp Assembly** | 1 | AC Load connected to COM / NO Terminals |
| **External Power Supply** | 1 | 5V DC Power Source |

---

## Circuit & Wiring Diagram

> **CRITICAL SAFETY NOTICE:** 220V AC mains power presents a severe electrical shock hazard. Disconnect all AC sources before handling relay terminal connections.

[ Arduino UNO ]             [ HC-05 Bluetooth ]
Pin 2 (RX)  <────────────>  TX Pin
Pin 3 (TX)  <────────────>  RX Pin
5V          <────────────>  VCC
GND         <────────────>  GND

[ Arduino UNO ]             [ 5V Relay Module ]
Pin 7       <────────────>  IN
5V          <────────────>  VCC
GND         <────────────>  GND

[ 220V AC Mains ]           [ Relay / Lamp Assembly ]
AC Live (Phase)  ────────>  Relay COM Terminal
Relay NO Terminal ───────>  Lamp Phase
AC Neutral       ────────>  Lamp Neutral


---

## Project Structure

├── firmware/
│   └── IoT_Voice_Relay_Control.ino  # Production Arduino / C++ source code
├── docs/
│   ├── circuit_schematic.png        # Complete wiring diagram
│   └── working_demo.gif             # Video of working prototype
└── README.md                        # Project documentation


---

## Command Set

The system listens for single-byte character commands over Bluetooth:

* `'1'` : Energizes the relay coil (Pulls IN LOW) -> **Turns Light ON**
* `'0'` : De-energizes the relay coil (Pulls IN HIGH) -> **Turns Light OFF**

---

## Enclosure & Physical Design (In Progress)

Custom 3D-printable enclosure designed in **Autodesk Fusion 360** to isolate high-voltage terminals, provide strain relief for AC cables, and house internal PCBs safely.

---

## Author

**[Ömer Faruk YIĞCI]**  
*Mechanical & Industrial Engineering Student*  
[www.linkedin.com/in/ömer-faruk-yiğci-382907344] 
