#include "commandHandler.h"

namespace myhappyplants
{
    List<float>*CommandHandler::Execute(Commands command)
    {
        List<float>* result;

        switch (command)
        {
        case none:
            result = new List<float>(nullptr,0);
            break;
        case getGroundMoisture:
            result = this->_GroundMoisture.GetData();
            break;
        case getClimate:
            result = this->_Climate.GetData();
            break;

        default:
            result = new List<float>(nullptr,0);
            break;
        }

        return result;
    }    
} // namespace myhappyplants