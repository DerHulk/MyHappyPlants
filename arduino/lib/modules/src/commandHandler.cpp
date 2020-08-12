#include "commandHandler.h"

namespace myhappyplants
{
    const char *CommandHandler::Execute(Commands command)
    {
        switch (command)
        {
        case none:
            return "";
            break;
        case getGroundMoisture:
            return "100%";
            break;
        case getClimate:
            return "20,100%";
            break;

        default:
            return "";
            break;
        }
    }
} // namespace myhappyplants