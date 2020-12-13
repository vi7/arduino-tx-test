// based on the https://gist.github.com/LarsBergqvist/04a78df8f61441339f591c20dd606b39
//
// Depends on the RCSwitch library https://github.com/sui77/rc-switch

#include <Arduino.h>
#include "RCSwitch.h"

/*
 * Unique ID:s (4 bits, 0-15) for each measurement type so that the receiver
 * understands how to interpret the data on arrival
 */
#define TX_ID  0

#define TX_PIN 0                     // <-- corresponds to the P0 on Digispark
#define LED    1

RCSwitch transmitter = RCSwitch();

unsigned long code32BitsToSend(int measurementTypeID, unsigned long data)
{
    unsigned long checkSum = measurementTypeID + data;
    unsigned long byte3 = ((0x0F & measurementTypeID) << 4);
    unsigned long byte2_and_byte_1 = 0xFFFF & data;
    unsigned long byte0 = 0xFF & checkSum;
    unsigned long dataToSend = (byte3 << 24) + (byte2_and_byte_1 << 8) + byte0;

    return dataToSend;
}

void sendSignal()
{
  // use alternating bits for the value for better reliability
  unsigned long valueToSend = 0b0101010;
  unsigned long dataToSend = code32BitsToSend(TX_ID, valueToSend);
  transmitter.send(dataToSend, 32);
}


/**********
 *  MAIN  *
 **********/

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  transmitter.enableTransmit(TX_PIN);
}

void loop()
{
  digitalWrite(LED, HIGH);
  sendSignal();
  digitalWrite(LED, LOW);
  delay(2000);
}
