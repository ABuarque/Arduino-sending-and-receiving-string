# Arduino-sending_and_receiving_strings
It's an experience which shows how to make a simple communication between Arduino boards using the NRF24L01 transceiver.

To the code work, you should add the library on udes_libraries folder on libraries folder of your Arduino IDE. 

HARDWARE SETTINGS

The most common version of NRF24L01 has eight pins, but you'll use only seven. 
Before to conect it on your Arduino board, you should find the SPI pins of your board. In Arduino UNO (and similars) these pins are 11 (MOSI), 12 (MISO), 13 (SCK).
If you are using a UNO board (or similar) make the conections below: 

NRF24L01      Arduino 
GND           GND
3.3v          3.3v
CE            9
CSN           10
MISO          11
MOSI          12
SCK           13

