
#include <characteristicCallbacks.h>

namespace myhappyplants
{
    void CharacteristicCallbacks::onWrite(BLECharacteristic *characteristic)
    {
        printf("Received BT request.");
        std::string request = characteristic->getValue();

        if (request.length() == 0)
            return;

        printf("Received BT data.");

        Commands requestCommand = Commands::none;

        if (request == "1")
            requestCommand = Commands::getGroundMoisture;

        if (request == "2")
            requestCommand = Commands::getClimate;

        List<float> *result = this->_Handler->Execute(requestCommand);

        String notification = "";
        String splitter = ";";

        for (int i = 0; i < result->Length(); i++)
        {
            printf("Send BT data.");
            float value = result->Get(i);
            String v = String(value);    
                    
            notification.concat(v);    
            notification.concat(splitter);
        }

        characteristic->setValue(notification.c_str());
        characteristic->notify(true);
    }

} // namespace myhappyplants