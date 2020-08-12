#ifdef UNIT_TEST
   
#else    
       
#endif

#ifndef commandHandler_H
#define commandHandler_H

enum Commands{none = 0, getGroundMoisture= 1, getClimate = 2};

namespace myhappyplants
{
    class CommandHandler
    {
    private:
       
    public:
        CommandHandler(){};
        // ~CommandHandler();
        const char* Execute(Commands command);
    };
}

#endif