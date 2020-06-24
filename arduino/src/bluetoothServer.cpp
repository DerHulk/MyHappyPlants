#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "bluetoothServer.h";

namespace myhappyplants
{
    class BluetoothServer
    {        
        BLECharacteristic* _characteristicTX; //através desse objeto iremos enviar dados para o client
        BLEServer* _Server;
        BLEService* _Service;
        ServerCallbacks* _Callback;
        CharacteristicCallbacks* _CharacteristicCallbacks;

    public:
        void start()
        {
            BLEDevice::init("ESP32-BLE");

            _Callback = new ServerCallbacks(this);
            _Server = BLEDevice::createServer();
            _Server->setCallbacks(_Callback);
            _CharacteristicCallbacks = new CharacteristicCallbacks();

            _Service = _Server->createService(SERVICE_UUID);

            _characteristicTX = _Service->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            _characteristicTX->addDescriptor(new BLE2902());

            BLECharacteristic *characteristic = _Service->createCharacteristic(CHARACTERISTIC_UUID_RX,BLECharacteristic::PROPERTY_WRITE);
 
            characteristic->setCallbacks(_CharacteristicCallbacks);
     
            _Service->start();             
            _Server->getAdvertising()->start();     
                  
        }

        bool isConnected(){
            return _Callback->isConnected();
        }
    };

    class ServerCallbacks : public BLEServerCallbacks
    {
        BluetoothServer *Server;
        bool deviceConnected = false;

    public:
        ServerCallbacks(BluetoothServer *server)
        {
            this->Server = server;
        }

        void onConnect(BLEServer *pServer)
        {
            deviceConnected = true;
        };

        void onDisconnect(BLEServer *pServer)        
        {
            deviceConnected = false;
        }

        bool isConnected(){
            return deviceConnected;
        }
    };

    class CharacteristicCallbacks : public BLECharacteristicCallbacks
    {
        //we starts reading
        void onWrite(BLECharacteristic *characteristic)
        {                        
            std::string rxValue = characteristic->getValue();         
            if (rxValue.length() > 0)
            {

            }
        }
    };
}

