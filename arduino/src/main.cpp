
#include <Arduino.h>
#include <bluetoothServer.h>
#include <iDataSource.h>;
#include <climateDataSource.h>;
#include <simpleDataSource.h>
#include <commandHandler.h>

int incoming;
int LED_BUILTIN = 2;

using namespace myhappyplants;

BluetoothServer *_Server;
CommandHandler *_Handler;

void setup()
{
  printf("Bluetooth Device is Ready to Pair");
  pinMode(LED_BUILTIN, OUTPUT); //Specify that LED pin is output

  List<float> *dummyA = new List<float>(new float[1]{1}, 1);
  List<float> *dummyB = new List<float>(new float[2]{2, 1}, 2);

  iDataSource *climate = new SimpleDataSource(*dummyA);
  iDataSource *groundMoisture = new SimpleDataSource(*dummyB);

  _Handler = new CommandHandler(*groundMoisture, *climate);
  _Server = new BluetoothServer();

  _Server->start(_Handler);
  
}

void loop()
{
  if (_Server->isConnected())
  {
    printf("Connected");
    digitalWrite(LED_BUILTIN, HIGH);

    delay(2000);
  }
  else
  {
    printf("No connection");
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }
}
