/****************************************************************************
 * ArduinoServer.ino
 * Version 0.31 - Arduino Custom Command Server demonstration sketch.
 * For use with the Arduino (http://www.arduino.cc/)
 *
 * Created by William North, October 14, 2012.
 * License: GPL
 *****************************************************************************
 * ArduinoServer.ino is a part of the ArduinoServer project at:
 * https://github.com/WilliamNorth/ArduinoServer
 *
 * This is a demo sketch called "AurduinoServer.ino".
 * Configure the Serial Monitor to send a 'Newline' when the [Enter] key is pressed 
 * or the 'Send' button is clicked, and set the rate to 115200 baud.
 ****************************************************************************/

#ifndef ArduinoServer_ino
#define ArduinoServer_ino
#include "Arduino.h"

//Include the ArduinoServer.h module, it contains the getCommand() and runCommand() methods.
#include "ArduinoServer.h"

//Include the application module, it should contain the methods used as commands.
//This example uses the demo application MY_ServerApp.h.
#include "MY_ServerApp.h"

void setup()
{  
  //Serial.begin(9600);  
  Serial.begin(115200);

  //Display splash-screens.
  displayServerSplash();
  displayAppSplash();

  //Notify the host that the server is online and ready.
  Serial.println("Waiting for commands...\n");  
}

void loop () 
{    
  String strCommand;
  int intCommandSucceeded;

  //Get the next command from the serial port buffer.
  strCommand = getCommand();

  //Clean, then execute the command.
  strCommand.toLowerCase();
  intCommandSucceeded = runCommand(strCommand);

  //Report the success of the command's execution.
  if (intCommandSucceeded)
  {
    Serial.println("Command successful\n");
  }
  else
  {
    Serial.println("Command not recognized or unsuccessful\n");
  }
}



#endif  /* ArduinoServer_ino */


