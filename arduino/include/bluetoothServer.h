#ifndef BluetoothServer_H
#define BluetoothServer_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

namespace myhappyplants
{
    //class definition see:
    //common https://stackoverflow.com/questions/3746484/why-am-i-getting-this-redefinition-of-class-error
    //forward definition  https://stackoverflow.com/questions/2133250/x-does-not-name-a-type-error-in-c/2133260;    
    class ServerCallbacks;
    class CharacteristicCallbacks;

    class BluetoothServer
    {
#define SERVICE_UUID "ab0828b1-198e-4351-b779-901fa0e0371e"
#define CHARACTERISTIC_UUID_RX "4ac8a682-9736-4e5d-932b-e9b31405049c"
#define CHARACTERISTIC_UUID_TX "0972EF8C-7613-4075-AD52-756F33D4DA91"

        const int LED = 2;     //LED interno do ESP32 (esse pino pode variar de placa para placa)
        const int BUZZER = 23; //pino d BUZZER

    private:
        BLECharacteristic *_characteristicTX; //através desse objeto iremos enviar dados para o client
        BLEServer *_Server;
        BLEService *_Service;
        ServerCallbacks *_Callback;
        CharacteristicCallbacks *_CharacteristicCallbacks;

    public:
        void start();
        bool isConnected();
    };

} // namespace myhappyplants

#endif
