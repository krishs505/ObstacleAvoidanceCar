# ObstacleAvoidanceCar

This Arduino project controls a four-motor robot equipped with an ultrasonic sensor mounted on a servo.  
The robot detects obstacles, chooses the best direction to turn, and moves forward while avoiding collisions.

## Features
- **Forward movement with gradual acceleration** to prevent battery strain.
- **Automatic obstacle detection** using an ultrasonic sensor (HC-SR04).
- **Servo-mounted sensor scanning** to check left and right distances.
- **Decision-making** to turn toward the direction with more space.
- **Basic movement functions**: forward, backward, left, right, stop.
- **Motor test mode** for debugging.

## Hardware Requirements
- Arduino Uno
- L298N motor driver
- 4 DC motors with wheels
- HC-SR04 ultrasonic distance sensor
- Servo motor
- Chassis with battery pack

## Pin Configuration
| Component        | Arduino Pin |
|------------------|-------------|
| Right motor ENA  | 3           |
| Right motor IN1  | 4           |
| Right motor IN2  | 5           |
| Left motor ENB   | 6           |
| Left motor IN3   | 8           |
| Left motor IN4   | 7           |
| Ultrasonic Trig  | A0          |
| Ultrasonic Echo  | A1          |
| Servo Signal     | 9           |

## How It Works
1. The robot continuously measures distance ahead.
2. If an obstacle is detected within ~18 cm:
   - Stop, move backward briefly, and scan left/right.
   - Turn toward the side with more space.
3. If the path is clear, keep moving forward.

## Setup
1. Wire all components according to the pin configuration table.
2. Upload the provided code to your Arduino.
3. Power the robot and watch it navigate autonomously.
