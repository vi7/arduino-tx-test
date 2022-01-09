#include <Arduino.h>
#include "RCSwitch.h"

#define MSG_LENGTH  24

// ORNO OR-AE-13132(GS) power extender
#define OUTLET1_ON  0x15533
#define OUTLET1_OFF 0x1553C
#define OUTLET2_ON  0x155C3
#define OUTLET2_OFF 0x155CC
#define OUTLET3_ON  0x15703
#define OUTLET3_OFF 0x1570C
#define OUTLET4_ON  0x15D03
#define OUTLET4_OFF 0x15D0C
#define OUTLET5_ON  0x17503
#define OUTLET5_OFF 0x1750C


#if defined(ESP8266)
  #define TX_PIN    12  // D6
  #define LED       LED_BUILTIN
  #define LED_HIGH  LOW
  #define LED_LOW   HIGH
#elif defined(ARDUINO)
  #define TX_PIN    3
  #define LED       LED_BUILTIN
  #define LED_HIGH  HIGH
  #define LED_LOW   LOW
#else
  #define TX_PIN    PB2
  #define LED       PB1
  #define LED_HIGH  HIGH
  #define LED_LOW   LOW
#endif

RCSwitch transmitter = RCSwitch();

/**********
 *  MAIN  *
 **********/

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LED_LOW);
  transmitter.enableTransmit(TX_PIN);
  transmitter.setRepeatTransmit(20);
  transmitter.setProtocol(13);
}

void loop() {
  digitalWrite(LED, LED_HIGH);
  transmitter.send(OUTLET1_ON, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  transmitter.send(OUTLET1_OFF, MSG_LENGTH);
  delay(2000);

  digitalWrite(LED, LED_HIGH);
  transmitter.send(OUTLET2_ON, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  transmitter.send(OUTLET2_OFF, MSG_LENGTH);
  delay(2000);

  digitalWrite(LED, LED_HIGH);
  transmitter.send(OUTLET3_ON, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  transmitter.send(OUTLET3_OFF, MSG_LENGTH);
  delay(2000);

  digitalWrite(LED, LED_HIGH);
  transmitter.send(OUTLET4_ON, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  transmitter.send(OUTLET4_OFF, MSG_LENGTH);
  delay(2000);

  digitalWrite(LED, LED_HIGH);
  transmitter.send(OUTLET5_ON, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  transmitter.send(OUTLET5_OFF, MSG_LENGTH);
  delay(2000);

}
