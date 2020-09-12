
#include <Arduino.h>
#include <bluetoothServer.h>
#include <iDataSource.h>;
#include <climateDataSource.h>;
#include <simpleDataSource.h>
#include <commandHandler.h>

int LED_BUILTIN = 2;
int DHT_BUILTIN = 4;

using namespace myhappyplants;

BluetoothServer *_Server;
CommandHandler *_Handler;

DHT dht(DHT_BUILTIN,DHT22);

void setup()
{
  printf("Bluetooth Device is Ready to Pair");
  pinMode(LED_BUILTIN, OUTPUT);

  List<float> *dummyA = new List<float>(new float[1]{1}, 1);
  List<float> *dummyB = new List<float>(new float[2]{2, 1}, 2);

  iDataSource *climate = new ClimateDataSource(dht);
  iDataSource *groundMoisture = new SimpleDataSource(*dummyB);

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
