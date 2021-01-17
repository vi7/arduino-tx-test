#include <Arduino.h>
#include <Manchester.h>

/*

  Manchester Transmitter example

  In this example transmitter will send 10 bytes array  per transmittion

  try different speeds using this constants, your maximum possible speed will
  depend on various factors like transmitter type, distance, microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7

*/

#define TX_PIN      D0  //pin where your transmitter is connected

uint8_t moo = 1; //last led status
uint8_t data[20] = {11, '1','2', '3', '4', '5', '6', '7', '8', '9','1','2','3','4','5','6','7','8','9'};

void setup() {
  Serial.begin(9600);
  Serial.println("\n***\nTransmitter is up. Hey there!\n***\n");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, moo);
  man.setupTransmit(TX_PIN, MAN_300);
}


uint8_t datalength = 2;   //at least two data

void loop() {
  data[0] = datalength;

  man.transmitArray(datalength, data);
  moo = ++moo % 2;
  digitalWrite(LED_BUILTIN, moo);


  delay(800);
  datalength++;
  if(datalength > 18)
    datalength = 2;
}
