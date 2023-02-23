#include <Arduino.h>
#include <RCSwitch.h>

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
#define SSR_OUTLET_ON   0x17703
#define SSR_OUTLET_OFF  0x1770C

// Cheap LED strip driver remote
#define BRIGHT_UP 0xC01305

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

#define CODE_01 SSR_OUTLET_ON
#define CODE_02 SSR_OUTLET_OFF

RCSwitch transmitter = RCSwitch();

/**********
 *  MAIN  *
 **********/

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LED_LOW);
  transmitter.enableTransmit(TX_PIN);
  // transmitter.setRepeatTransmit(20);
  transmitter.setProtocol(1);
}

void loop() {
  digitalWrite(LED, LED_HIGH);
  Serial.printf("[%lu] Sending 0x%X\n", millis(), CODE_01);
  transmitter.send(CODE_01, MSG_LENGTH);
  delay(1000);
  digitalWrite(LED, LED_LOW);
  // Serial.printf("[%lu] Sending 0x%X\n", millis(), CODE_02);
  // transmitter.send(CODE_02, MSG_LENGTH);
  delay(2000);
}
