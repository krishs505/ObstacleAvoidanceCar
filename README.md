# ObstacleAvoidanceCar

This Arduino four-motor robot is equipped with a closed-loop obstacle avoidance system using an ultrasonic sensor mounted on a servo. It detects upcoming obstacles and chooses the optimal direction to turn and avoid collisions.

## Features
- **Forward movement with gradual acceleration** to prevent battery strain.
- **Autonomous obstacle detection control system** using ultrasonic sensor feedback (HC-SR04).
- **Servo-mounted sensor scanning** to check left and right distances.
- **Decision-making** to turn toward the direction with more space.

<img width="500" height="369" alt="image" src="https://github.com/user-attachments/assets/e6501f7b-c327-4f14-899d-bcf9fcb72406" />
<img width="341" height="369" alt="image" src="https://github.com/user-attachments/assets/0d841a02-7eb0-445d-9cca-c2daea90daf0" />

Unfortunately, I forgot to take clearer pictures, sorry about that. These are from a video of an older version of the robot. The hardware remained the same.

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
