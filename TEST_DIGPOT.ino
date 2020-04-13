#include <SPI.h>

int cspin = 5;   // MOSI Pin 23, SPI CLK Pin 18, CS pin user defined
int value1 = 0;
float volt1 = 0;  
int digipot = 35; // ADC pin 32,33,35

void setup() {

  SPI.begin();
  Serial.begin(115200);              
  pinMode(cspin, OUTPUT);
  digitalWrite(cspin,LOW);   

}

void loop() {

   for (int i=0; i <=128; i++)
   {
      
    SPI.transfer(0);   
    SPI.transfer(i);
    value1 = analogRead(digipot);
    volt1 = (3.3/4096.0) * value1;
    Serial.println(volt1);
    delay(300);

   }

   for (int i=128; i >=0; i--)
   {
   
    SPI.transfer(0);   
    SPI.transfer(i);
    value1 = analogRead(digipot);
    volt1 = (3.3/4096.0) * value1;
    Serial.println(volt1);
    delay(300);
    

   }
   
  
 
}


/* 
 * SPI transfer from 0 - 128
 */
