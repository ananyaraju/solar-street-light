# Automated Motion-Detecting Solar-Tracking Street Light System

## Description

The automated motion-detecting solar-tracking street light system aims to maximise the light energy falling on the solar panel attached to a street light as well as minimise the electrical energy utilized by the street light at any given point in time. With the help of this project, the direction of the solar panel adjusts to where maximum sunlight is incident on it. Moreover, it aims to minimise power utilization by automatically dimming the street light when there is no vehicle or object movement detected.
This is a smart system that switches on and off depending on the day time. The system will be capable of adjusting itself to amplify solar energy generation on its own. To increase efficiency, the system shall dim the street light whenever there no motion detection near the street light. 

<div align="center">
  <img src="https://github.com/ananyaraju/solar-street-light/blob/main/public/hardware.jpg" height="250" />
</div>

## Design

The street light system is designed on an Arduino microprocessor, using 2 Light-Dependent Resistors, an SG90 Servo Motor, a Solar Panel, a Passive Infra-Red Detector, a rechargeable Ni-Mh bettery and an LED bulb.

### Working

During the day, when there is enough sunlight on the roads, the only function of the system is to change the angle of the servo motor such that it remains perpendicular to the sun rays at any given point in time. This is done with the help of LDRs, which measure the difference between the amount of sunlight falling on each LDR. The servo motor rotates until this difference is equal. Once the sun sets, the servo motor stops rotating and the street light is automatically turned on to 50% output capacity. The PIR sensor is now active and looks for any motion detection in its proximity. Once an object has been detected, the street light glows at 100% capacity for 5 seconds, and then returns to its previous state. This process continues every single time motion has been detected. 

### Block Diagram

<img src="https://github.com/ananyaraju/solar-street-light/blob/main/public/block-diagram.jpg" height="250" />

### Circuit Diagram

<img src="https://github.com/ananyaraju/solar-street-light/blob/main/public/circuit-diagram.jpg" height="250" />

### Simulation

[Tinkercad simulation](https://www.tinkercad.com/things/6ZpcbpP0eCZ-automated-solar-tracking) of the street light system

<img src="https://github.com/ananyaraju/solar-street-light/blob/main/public/simulation-ss.jpg" width="350" />

## Contributors

* [Ananya Raju](https://github.com/ananyaraju)
* [Nishanth Pilli](https://github.com/dr4g0n7ly)
