/*
  Code by:
 M.Hashir
 
 This is a code that varies speed of fan (DC motor) based on temperature.
 
 Hardware:
  -Arduino
  -DC motor
  -DHT11 sensor
  -5 male to female wires

Connections:
When perforated side (side with holes) of DHT sensor is towards you, the left most leg is pin 1 and right most leg is pin 4
Connect pin 1 of dht11 to pin 5V of Arduino
Connect pin 2 of dht11 to pin 2 of Arduino
Connect pin 4 of dht11 to pin GND of Arduino

Connect one wire of DC motor to pin 9 of Arduino
Connect other wire of DC motor to pin GND of Arduino
*/

#include <dht11.h>                    //Install this library using library manager
int dht_pin= 2;                        //DHT11 is connected to pin 2
int motor=9;
dht11 DHT;

void setup() {

 Serial.begin(9600);              //donot edit this line
 pinMode(motor,OUTPUT);      
 delay(1000);                    //wait for 1 second
}

int PWMval;

void loop() {

    DHT.read(dht_pin);                            //Read Humidity and Temperature value from sensor
    int temperature=DHT.temperature
    Serial.print("Current humidity = ");           //Print this on Serial monitor
    Serial.print(DHT.humidity);                    //Print the value of Humidity on serial monitor
    Serial.print("%  ");                           //donot edit this line
    Serial.print("Temperature = ");                //Print this on Serial monitor
    Serial.print(temperature);                 //Print the value of Temperature on serial monitor
    Serial.print("C, PWMwalue=  ");                         //donot edit this line
    PWMval=map(temperature,15,40,0,255);
    analogWrite(motor,PWMval);
    Serial.println(PWMval);

delay(5000);                                   //Wait for 5 seconds   
  
  }
