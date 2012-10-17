/*
 * Arduino Custom Command Server (via the virtual serial port).
 * Version 0.27 Oct 16 2012 - by William North
 * License: GPL
 * Status: Alpha (works somewhat but needs more testing)
 * 
 * This is a demo sketch called "AurduinoServer_Test.ino".
 */

//Include the ArduinoServer.ino sketch, it contains the getCommand() and runCommand() methods.
#include <ArduinoServer.ino>

//Include your application sketch, it should contain the methods used as commands.
#include <MY_ServerApp.ino>

String strCommand;
int intCommandSucceeded;

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
  strCommand = "";
  intCommandSucceeded = 0;
  
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
  
  strCommand = "";
  intCommandSucceeded = 0;
}

