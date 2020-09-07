#include <bluetoothServer.h>
#include <characteristicCallbacks.h>
#include <serverCallbacks.h>


namespace myhappyplants
{
    void BluetoothServer::start(CommandHandler* handler)
    {
        BLEDevice::init("ESP32-BLE");

        _Callback = new ServerCallbacks(this);
        _Server = BLEDevice::createServer();
        _Server->setCallbacks(_Callback);
        _CharacteristicCallbacks = new CharacteristicCallbacks(handler);

        _Service = _Server->createService(SERVICE_UUID);

        _characteristicTX = _Service->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_READ);
        _characteristicTX->addDescriptor(new BLE2902());       
        _characteristicTX->setCallbacks(_CharacteristicCallbacks);
        
        _Service->start();
        _Server->getAdvertising()->start();
    }

    bool BluetoothServer::isConnected()
    {
        return _Callback->isConnected();
    }

    

   
}
