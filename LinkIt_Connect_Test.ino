#include <LBT.h> 
#include <LBTServer.h>

int ledPin = 13;  //Pin the LED is connected to on the LinkIt ONE
String command;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
LBTServer.begin((uint8_t*)"My_BTServer");
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

if(LBTServer.connected())
{
  Serial.println("Connected");  //If bluetooth is connected print "Connected" in serial port
  }
else
{
  Serial.println("Retrying");   //Else retry
  LBTServer.accept(5);
  }

command = LBTServer.readString();
if (command == "On"){
  digitalWrite(ledPin,HIGH);   //If command is "On", switch LED on
  Serial.println("LED is on");
  LBTServer.write("LED is on");
  }
else if (command == "Off"){
  digitalWrite(ledPin,LOW);   //If command is "Off", switch LED off
  Serial.println("LED is off");
  LBTServer.write("LED is off");
  }
}

