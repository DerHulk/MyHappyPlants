#ifndef CharacteristicCallbacks_H
#define CharacteristicCallbacks_H

#include <bluetoothServer.h>
#include <commandHandler.h>

namespace myhappyplants
{
    class CharacteristicCallbacks : public BLECharacteristicCallbacks
    {

        public:
            CharacteristicCallbacks(CommandHandler* handler) : _Handler(handler) {};
            void onWrite(BLECharacteristic *characteristic);

        private:
            CommandHandler* _Handler;

    };
} // namespace myhappyplants
#endif