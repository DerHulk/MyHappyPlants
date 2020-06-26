#include <Arduino.h>
#include "bluetoothServer.h"

int incoming;
int LED_BUILTIN = 2;

using namespace  myhappyplants;

BluetoothServer* _Server;

void setup()
{   
  printf("Bluetooth Device is Ready to Pair");
  pinMode(LED_BUILTIN, OUTPUT); //Specify that LED pin is output
  _Server = new BluetoothServer();
  _Server->start();

}

void loop()
{  
  if(_Server->isConnected() ){
    printf("Received:");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
  }
  else {    
    printf("No connection");
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }    
}
