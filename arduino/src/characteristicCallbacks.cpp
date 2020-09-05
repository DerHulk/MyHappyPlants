
#include <characteristicCallbacks.h>

namespace myhappyplants
{
    void CharacteristicCallbacks::onWrite(BLECharacteristic *characteristic)
    {
        std::string commandRequest = characteristic->getValue();
        if (commandRequest.length() > 0)
        {
            printf("Received data.");
            characteristic->setValue("test");
            characteristic->notify(true);
        }
    }

} // namespace myhappyplants