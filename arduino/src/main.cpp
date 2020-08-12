
#include <Arduino.h>
#include "bluetoothServer.h"
#include "iDataSource.h";
#include "climateDataSource.h";


int incoming;
int LED_BUILTIN = 2;

using namespace  myhappyplants;

BluetoothServer* _Server;
iDataSource* _Source;

void setup()
{   
  printf("Bluetooth Device is Ready to Pair");
  pinMode(LED_BUILTIN, OUTPUT); //Specify that LED pin is output
  _Server = new BluetoothServer();
  _Server->start();
  
  //todo add class to read sensor data -> temp/humanid
  //connect Callback-Liste with server

}

void loop()
{  
  if(_Server->isConnected() ){
    printf("Connected");
    digitalWrite(LED_BUILTIN, HIGH);    

    delay(2000);
  }
  else {    
    printf("No connection");
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }    
}
