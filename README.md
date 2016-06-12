# Arduino-sending_and_receiving_strings
It's an experience which shows how to make a simple communication between Arduino boards using the NRF24L01 transceiver.

To the code work, you should add the library on used_libraries folder on libraries folder of your Arduino IDE. 

HARDWARE SETTINGS

The most common version of NRF24L01 has eight pins, but you'll use only seven. 
Before to conect it on your Arduino board, you should find the SPI pins of your board. In Arduino UNO (and similars) these pins are 11 (MOSI), 12 (MISO), 13 (SCK).
If you are using a UNO board (or similar) conect the CE to 9, CSN to 10, MISO to 11, MOSI to 12, SCK to 13, GND to GND and 3.3V to 3.3V.

