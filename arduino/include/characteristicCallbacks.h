#ifndef CharacteristicCallbacks_H
#define CharacteristicCallbacks_H

#include <bluetoothServer.h>

namespace myhappyplants
{
    class CharacteristicCallbacks : public BLECharacteristicCallbacks
    {
        void onWrite(BLECharacteristic *characteristic);
    };
} // namespace myhappyplants
#endif