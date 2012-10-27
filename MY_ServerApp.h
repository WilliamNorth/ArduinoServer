/*
 MY_ServerApp.h version 0.29 - Arduino Custom Command Server (via the virtual serial port).
 For use with the Arduino (http://www.arduino.cc/).
 Created by William North, October 14, 2012.
 Released into the public domain.
 ArduinoServer.ino is a part of the ArduinoServer project at:
 https://github.com/WilliamNorth/ArduinoServer
 
 * This is a sample Arduino Custom Command Server application "MY_ServerApp.h".
 * It should contain the 'displayAppSplash()', 'displayAppHelpScreen()' and
 * a method for each command.
 */

#ifndef MY_ServerApp.h
#define MY_ServerApp.h
#include "Arduino.h"
#include "ArduinoServer.h"

#define APP_NAME       "Arduino Custom Command Server - Demo Application"
#define APP_VERSION    0.29
#define APP_DATE       "2012-10-27"
#define APP_COPYRIGHT  "Copyright (C) 2012 Your Mother"

void displayAppSplash()
{
  Serial.println(APP_NAME);
  Serial.print("Version ");
  Serial.print(APP_VERSION);
  Serial.print(" of ");
  Serial.println(APP_DATE);
  Serial.println(APP_COPYRIGHT);
  Serial.print("\n"); 
  Serial.println("Type 'help' for instructions");  
}

int displayAppHelpScreen() 
{
  int intCommandSucceeded;
  Serial.println("Accepted commands:");
  Serial.println(" what is the meaning of life?");
  Serial.println(" do stuff");
  Serial.println(" help");
  Serial.println("");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int doStuff() 
{
  int intCommandSucceeded;
  Serial.println("OK, I just did some stuff (I printed this message)");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int whatIsMOL() 
{
  int intCommandSucceeded;
  Serial.println("The Meaning of Life is a 1983 movie by Monty Python.");
  Serial.print("See: ");
  Serial.print("http://en.wikipedia.org/wiki/Monty_Python%27s_The_Meaning_of_Life");
  Serial.println(" for more details");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}


int i(String strCommand) 
{
  String strIparameter;
  int intCommandSucceeded;

  strIparameter = strCommand.substring(1);
  strIparameter.trim();

  Serial.print("You ");
  Serial.print(strIparameter);
  Serial.println("?");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int you(String strCommand) 
{
  String strYouParameter;
  int intCommandSucceeded;

  strYouParameter = strCommand.substring(3);
  strYouParameter.trim();

  Serial.print("I ");
  Serial.print(strYouParameter);
  Serial.println("?");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int my(String strCommand) 
{
  String strMyParameter;
  int intCommandSucceeded;

  strMyParameter = strCommand.substring(2);
  strMyParameter.trim();

  Serial.print("Your ");
  Serial.print(strMyParameter);
  Serial.println("?");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int your(String strCommand) 
{
  String strYourParameter;
  int intCommandSucceeded;

  strYourParameter = strCommand.substring(4);
  strYourParameter.trim();

  Serial.print("My ");
  Serial.print(strYourParameter);
  Serial.println("?");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int whoKnows(String strCommand) 
{
  String strWhoKnowsParameter;
  int intCommandSucceeded;

  strWhoKnowsParameter = strCommand;
  strWhoKnowsParameter.trim();

  Serial.print(strWhoKnowsParameter);
  Serial.println("?");
  Serial.println("Who knows???");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int IYSS(String strCommand) 
{
  int intCommandSucceeded;

  Serial.println("If you say so!");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int cleanArea() 
{
  int intCommandSucceeded;

  Serial.println("You should keep that area clean.");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int dont() 
{
  int intCommandSucceeded;

  Serial.println("Please don't.");
  Serial.println("That is highly inappropriate!");

  intCommandSucceeded = true;
  return intCommandSucceeded;
}




#endif


