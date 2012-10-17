/*
 * Arduino Custom Command Server (via the virtual serial port).
 * License: GPL
 * 
 * This is the sample Arduino Custom Command Server Application sketch "MY_ServerApp.ino".
 * It should contain the 'displayAppSplash()', 'displayAppHelpScreen()' and
 * a method for each command.
 */

#define APP_NAME       "Arduino Custom Command Server - Demo Application"
#define APP_VERSION    0.28
#define APP_DATE       "2012-10-16"
#define APP_COPYRIGHT  "Copyright (C) 2012 William North"

void displayAppSplash()
{
  Serial.print(APP_NAME);
  Serial.print(" version ");
  Serial.print(APP_VERSION);
  Serial.print(" of ");
  Serial.print(APP_DATE);
  Serial.print(" ");
  Serial.println(APP_COPYRIGHT);
  Serial.println("Type 'help' for instructions\n");  
}

int displayAppHelpScreen() 
{
  Serial.println("Accepted commands:");
  Serial.println(" what is the meaning of life?");
  Serial.println(" do stuff");
  Serial.println(" help");
  Serial.println("");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int doStuff(String strCommand) 
{
  Serial.println("OK, I just did some stuff (I printed this message)");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int whatIsMOL(String strCommand) 
{
  Serial.println("The Meaning of Life is a 1983 movie by Monty Python.");
  Serial.print("See: ");
  Serial.print("http://en.wikipedia.org/wiki/Monty_Python%27s_The_Meaning_of_Life");
  Serial.println(" for more details");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}


