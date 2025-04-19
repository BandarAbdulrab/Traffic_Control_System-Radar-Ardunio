# Traffic Control System (Radar): Arduino-C++

An Arduino-based Traffic Control System (Radar), built to detect vehicle density on four roads. It dynamically adjusts traffic lights based on vehicle density, giving priority to the road with the least congestion. The code is written in Arduino (C++) and designed to work with an Arduino microcontroller, ultrasonic sensors, and LED traffic lights.

## Overview
This project implements a smart traffic control system using ultrasonic sensors and Arduino. The system monitors the distance of vehicles on four roads and prioritizes the road with the least congestion by turning its traffic light green. The other roads are given a red light to allow smooth traffic flow.

## Components Used
- **Arduino Uno** (or any compatible microcontroller)
- **Ultrasonic Sensors (HC-SR04)** - 4 units
- **LEDs** - Red, Yellow, and Green for each road (12 LEDs total)
- **Resistors** - For LEDs (220Ω or 330Ω)
- **Breadboard and Jumper Wires**

## Pin Configuration
- **Ultrasonic Sensors:**
  - Trig Pins: `2, 4, 6, 8`
  - Echo Pins: `3, 5, 7, 9`
- **Traffic Lights:**
  - Red Pins: `10, 11, 12, 13`
  - Yellow Pins: `A0, A1, A2, A3`
  - Green Pins: `A4, A5, A6, A7`

## How It Works
1. The ultrasonic sensors measure the distance of vehicles on each road.
2. The system calculates the road with the least congestion (maximum distance).
3. The traffic light for the least congested road turns green, while the others turn red.
4. The green light remains active for 10 seconds before re-evaluating the traffic conditions.

## Setup Instructions
1. Connect the ultrasonic sensors and LEDs to the Arduino as per the pin configuration.
2. Upload the `Traffic_Control_System-Radar.ino` code to your Arduino.
3. Power the Arduino and observe the traffic lights adjusting based on vehicle density.

## Project History
This project was originally submitted for my Makerspace 1 class during the second semester of 1st grade at Ishbelia Secondary School.

## License
This project is open source and available for personal and educational use. Feel free to modify and distribute the code as needed for your projects.
