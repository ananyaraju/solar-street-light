#include <Servo.h> 

Servo servo; 
int position = 120; 
int LDR1 = A0; 
int LDR2 = A1; 
int servopin = 10; 

int min = 50; 
int threshold = 600; 

int calibrationTime = 30; 

long unsigned int lowIn; //the time when the sensor outputs a low impulse 
long unsigned int pause = 5000; //the amount of milliseconds the sensor has to be low before we assume all motion has stopped 

boolean lockLow = true; 
boolean takeLowTime; 

int pirPin = 2; //the digital pin connected to the PIR sensor's output 
int ledPin = 13; 

void setup() 
{ 
    Serial.begin(9600); 
    servo.attach(servopin); 

    pinMode(LDR1, INPUT); 
    pinMode(LDR2, INPUT); 
    pinMode(13, OUTPUT); 

    servo.write(position); 

    pinMode(pirPin, INPUT); 
    pinMode(ledPin, OUTPUT); 

    digitalWrite(pirPin, LOW);

    Serial.print("calibrating sensor "); 
    for(int i = 0; i < calibrationTime; i++) { 
        Serial.print("."); 
        delay(1000); 
    } 

    Serial.println(" done"); 
    Serial.println("SENSOR ACTIVE"); 

    delay(50); 
} 

void loop() 
{ 
    int R1 = analogRead(LDR1); 
    int R2 = analogRead(LDR2); 

    int diff = abs(R1-R2); 

    if ((R1>threshold) || (R2>threshold)) { 
        Serial.println("It is sunny outside - street light is never turned on"); 
        digitalWrite(13, LOW); 
        if ( diff > min ) { 
            if (R1 > R2) { 
                position = --position; 
            } 
            if (R1 < R2) { 
                position = ++position; 
            } 
            Serial.println("Servo motor is rotating"); 
        } 
    } 

    servo.write(position); 
    delay(50); 

    if ((R1<threshold) && (R2<threshold)) { 
        Serial.println("It is dark outside"); 
        if(digitalRead(pirPin) == HIGH) { 
            digitalWrite(ledPin, HIGH); //the led visualizes the sensors output pin state 
            if(lockLow) { 
                //makes sure we wait for a transition to LOW before any further output is made: 
                lockLow = false; 
                Serial.println("---"); 
                Serial.print("motion detected at "); 
                Serial.print(millis()/1000); 
                Serial.println(" sec"); 
                delay(50); 
            } 
            takeLowTime = true; 
        } 
        if(digitalRead(pirPin) == LOW) { 
            digitalWrite(ledPin, LOW); //the led visualizes the sensors output pin state 
            if(takeLowTime) { 
                lowIn = millis(); //save the time of the transition from high to LOW 
                takeLowTime = false; //make sure this is only done at the start of a LOW phase 
            } 
            //if the sensor is low for more than the given pause,  
            //we assume that no more motion is going to happen 
            if(!lockLow && millis() - lowIn > pause) { 
                //makes sure this block of code is only executed again after 
                //a new motion sequence has been detected 
                lockLow = true; 
                Serial.print("motion ended at "); //output 
                Serial.print((millis() - pause)/1000); 
                Serial.println(" sec"); 
                delay(500); 
            } 
        } 
    } 

    servo.write(position); 
    delay(10); 
}