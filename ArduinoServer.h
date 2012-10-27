/*
 ArduinoServer.h version 0.29 - Arduino Custom Command Server (via the virtual serial port).
 For use with the Arduino (http://www.arduino.cc/).
 Created by William North, October 14, 2012.
 Released into the public domain.
 ArduinoServer.h is a part of the ArduinoServer project at:
 https://github.com/WilliamNorth/ArduinoServer
 
 * This is the ArduinoServer module "ArduinoServer.h".
 * Configure the Serial Monitor to send a 'Newline' when the [Enter] key is pressed 
 * or the 'Send' button is clicked, and set the rate to 115200 baud.
 */

#ifndef ArduinoServer_h
#define ArduinoServer_h
#include "Arduino.h"
#include "MY_ServerApp.h"

#define SERVER_NAME       "Arduino Custom Command Server"
#define SERVER_VERSION    0.29
#define SERVER_DATE       "2012-10-27"
#define SERVER_COPYRIGHT  "Copyright (C) 2012 My Mother"

void displayServerSplash()
{
  Serial.println(SERVER_NAME);
  Serial.print("Version ");
  Serial.print(SERVER_VERSION);
  Serial.print(" of ");
  Serial.println(SERVER_DATE);
  Serial.println(SERVER_COPYRIGHT); 
  Serial.print("\n");
}

int displayServerHelpScreen() 
{
  int intCommandSucceeded;

  Serial.println("Type a command (case insensitive), then press [Enter].");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int displayAllHelpScreens() 
{
  int intCommandSucceeded;

  displayServerHelpScreen(); 
  displayAppHelpScreen(); 
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

String getCommand()
{
  int intReadByte = 0;
  String strReadData = "";

  //As long as the byte just read is not a line-feed or CR...
  while ((intReadByte != 10) && (intReadByte != 13))
  {
    //...and the serial port buffer has data, read a byte from it.
    if (Serial.available()) 
    {
      intReadByte = Serial.read(); 

      //If the byte just read is not a line-feed or CR...
      if ((intReadByte != 10) && (intReadByte != 13))
      {
        //...then add it to the string.
        strReadData.concat(char(intReadByte)); 
      }
    }
  }

  //Return the string
  return strReadData;
}

int runCommand(String strCommand)
{
  int intCommandSucceeded;

  Serial.print("Executing command: ");
  Serial.println(strCommand);

  if (strCommand.equals("help")) {
    intCommandSucceeded = displayAllHelpScreens();
  }
  else if (strCommand.startsWith("what?")) {
    intCommandSucceeded = displayAllHelpScreens();
  }
  else if (strCommand.startsWith("do stuff")) {
    intCommandSucceeded = doStuff();
  }
  else if (strCommand.startsWith("what is the meaning of life")) {
    intCommandSucceeded = whatIsMOL();
  }
  else if (strCommand.startsWith("i ")) {
    intCommandSucceeded = i(strCommand);
  }
  else if (strCommand.startsWith("you ")) {
    intCommandSucceeded = you(strCommand);
  }
  else if (strCommand.startsWith("my ")) {
    intCommandSucceeded = my(strCommand);
  }
  else if (strCommand.startsWith("your ")) {
    intCommandSucceeded = your(strCommand);
  }
  else if (strCommand.startsWith("what ")) {
    intCommandSucceeded = whoKnows(strCommand);
  }
  else if (strCommand.startsWith("why ")) {
    intCommandSucceeded = whoKnows(strCommand);
  }
  else if (strCommand.startsWith("where ")) {
    intCommandSucceeded = whoKnows(strCommand);
  }
  else if (strCommand.startsWith("when ")) {
    intCommandSucceeded = whoKnows(strCommand);
  }
  else if (strCommand.startsWith("how ")) {
    intCommandSucceeded = whoKnows(strCommand);
  }
  else if (strCommand.substring(0) == "=") {
    intCommandSucceeded = IYSS(strCommand);
  }
  else if ((strCommand.substring(0) == "butt") || (strCommand.substring(0) == "ass")) {
    intCommandSucceeded = cleanArea();
  }
  else if (strCommand.substring(0) == "fuck") {
    intCommandSucceeded = dont();
  }
  else if (strCommand.substring(0) == "shit") {
    intCommandSucceeded = dont();
  }
  else if (strCommand.substring(0) == "bitch") {
    intCommandSucceeded = dont();
  }
  else {
    intCommandSucceeded = false;
  }

  //Return the success or failure of this command.
  return intCommandSucceeded;
}

#endif



