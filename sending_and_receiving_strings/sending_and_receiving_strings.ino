/**
 * @author Aurelio Buarque (abuarquemf@gmail.com)
 * @date 5/26/2016 5:10 PM
 *
 * Seattle, WA
*/

//Used libraries
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

//Object RF24
RF24 myTransceiver(9,10); //CE,CSN

const uint64_t masterToSlavePipe = 0xE8E8F0F0E1LL;
const uint64_t slaveToMasterPipe = 0xE8E8F0F0E2LL;

//Array for send strings
int msgOut[5];

//Array for receive strings
int msgIn[5];

void setup()
{
  //Starting comunication serial with 9600 of baude rate
  Serial.begin(9600);
  Serial.flush();
  
  //NRF24 starting to write on pipe masterPipe
  myTransceiver.openWritingPipe(masterToSlavePipe);
  
  //NRF24 open the pipe to read data
  myTransceiver.openReadingPipe(1, slaveToMasterPipe);
  
  //NRF24 start to listening
  myTransceiver.startListening();
}

/**
* This function send strings on pipeline
*
* @param string to send
*/
void sendMessage(String dataToSend)
{
  const byte delayTime = 1000;
  
  //Fist, NRF24L01 need to stop listening
  myTransceiver.stopListening();
  
  //Getting the message size
  int messageSize = dataToSend.length();
  
  //Array of char to send
  int charToSend[1];
  
  for(int i = 0;i < messageSize;i++)
  {
    charToSend[0] = dataToSend.charAt(i);
    myTransceiver.write(charToSend, 1);
  }
  
  //To finish message
  msgOut[0] = 2; //When receive get 2, it'll know that message is done
  myTransceiver.write(msgOut, 1);
  
  //Restart NRF24
  myTransceiver.powerDown();
  delay(delayTime);
  myTransceiver.powerUp();
  
  //And start listening again 
  myTransceiver.startListening();
}

/**
* This function return available data on pipeline
*
* @return String
*/
String dataEntered()
{
  //If there's something in pipe...
  if(myTransceiver.available())
  {
    bool done = false;
    done = myTransceiver.read(msgIn,1);
    char theChar = msgIn[0];
    String theMessage = NULL;
    if(msgIn[0] != 2)
    {
      theMessage.concat(theChar);
    } else {
      Serial.println();
      theMessage = NULL;
    }
  }
}

/**
 *  It's useful create a function that check pipe line and make something with entered data.Like:
 *  void checkPipeLine(){
 *    if(dataEntered() == "1") {Serial.println("i got 1");}
 *    if(dataEntered() == "2") {Serial.println("i got 2");}
 *  }
 *
*/

void loop()
{
  /* ######   Exemple #########
  
  //ON "FIRST" ARDUINO
  sendMessage("Hi");
  if(dataEntered() == "How are you?")
  {
    Serial.println("I sent a message 'Hi' and got 'How are you?' as answer ");
  }
  
  //ON "SECONDARY" ARDUINO
  if(dataEntered() == "Hi")
  {
    sendMessage("How are you?");
    Serial.println("I got 'Hi' as message and sent 'How are you?' as answer");
  }
  */
  
}
