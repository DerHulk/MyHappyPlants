#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "bluetoothServer.h"

namespace myhappyplants
{
    void BluetoothServer::start()
    {
        BLEDevice::init("ESP32-BLE");

        _Callback = new ServerCallbacks(this);
        _Server = BLEDevice::createServer();
        _Server->setCallbacks(_Callback);
        _CharacteristicCallbacks = new CharacteristicCallbacks();

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

    ServerCallbacks::ServerCallbacks(BluetoothServer *server)
    {
        this->Server = server;
    }

    void ServerCallbacks::onConnect(BLEServer *pServer)
    {
        deviceConnected = true;
    };

    void ServerCallbacks::onDisconnect(BLEServer *pServer)
    {
        deviceConnected = false;
    }

    bool ServerCallbacks::isConnected()
    {
        return deviceConnected;
    }

    void CharacteristicCallbacks::onWrite(BLECharacteristic *characteristic)
    {
        std::string rxValue = characteristic->getValue();
        if (rxValue.length() > 0)
        {
             printf("Received data.");
             characteristic->setValue("test");
             characteristic->notify(true);
        }
    }
} // namespace myhappyplants
