IoT Radio Transmitter test
==========================

433Mhz/315MHz transmitter test with the PlatformIO and Arduino framework

Boards:
* Arduino UNO
* Digispark ATTiny85 USB clone (LED on PB1)
* Wemos D1 Mini (ESP8266)

Radio hardware:
* Preferred: WL101-341 433MHz superheterodyne receiver and WL102-341 transmitter. **WARNING:** WL102 transmitter is 3.3V!!
* Cheapest: MX-RM-5V 433MHz ASK OOK super regenerative receiver and FS1000A transmitter
* RFM83C superheterodyne receiver

Tips to improve transmit/receive distance:
* Consider [coil loaded antenna](https://www.instructables.com/433-MHz-Coil-loaded-antenna/) solution
* FS1000A transmitter can use anything from 3.3V to 12V. Increasing voltage will increase transmit distance. If you are using voltage regulator, attach transmitter directly to the battery. Receivers needs 5V, it doesn't work on 3.3V unless otherwise is mentioned in specs
* For WL101-341 and WL102-341 use bundled antennas (short for TX, long for RX). **WARNING:** WL102-341 transmitter is 3.3V!!

Development
-----------

### UART (Serial)

#### Digispark ATTiny85

[Digistump dtiny core](https://github.com/ArminJo/DigistumpArduino) `TinyDebugSerial` overrides `Serial` and uses:
- `PB3` as TX for CPU frequencies <= 8MHz
- `PB2` as TX for other frequencies

See [TinyDebugSerial.h](https://github.com/ArminJo/DigistumpArduino/blob/master/digistump-avr/cores/tiny/TinyDebugSerial.h) for the details

#### Generic ATtiny85

[SpenceKonde tiny core](https://github.com/SpenceKonde/ATTinyCore/blob/master/avr/extras/ATtiny_x5.md#uart-serial-support) `TinySoftwareSerial` overrides `Serial` and uses:
- `AIN0` (`PB0`) as TX
- `AIN1` (`PB1`) as RX
