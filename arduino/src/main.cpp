
#include <Arduino.h>
#include <bluetoothServer.h>
#include <iDataSource.h>
#include <climateDataSource.h>
#include <analogDataSource.h>
#include <simpleDataSource.h>
#include <commandHandler.h>

int LED_BUILTIN = 2;
int DHT_BUILTIN = 4;
int CSMS_BUILTIN = 5;

using namespace myhappyplants;

BluetoothServer *_Server;
CommandHandler *_Handler;

DHT dht(DHT_BUILTIN,DHT22);

void setup()
{
  printf("Bluetooth Device is Ready to Pair");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(CSMS_BUILTIN, INPUT);
  
  iDataSource *climate = new ClimateDataSource(dht);
  iDataSource *groundMoisture = new AnalogDataSource(CSMS_BUILTIN);

  _Handler = new CommandHandler(*groundMoisture, *climate);
  _Server = new BluetoothServer();

  printf("Start dht.");
  dht.begin();  

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
