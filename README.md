IoT Radio Transmitter test
==========================

433Mhz/315MHz transmitter test with the PlatformIO and Arduino framework

Boards:
* Arduino UNO
* Digispark ATTiny85 USB clone (LED on PB1)

Transmitters:
* FS1000A 433MHz ASK


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


TODO
----

Evaluate https://mchr3k.github.io/arduino-libs-manchester/ library for data transmission with 315/433MHz transmitter/receiver
