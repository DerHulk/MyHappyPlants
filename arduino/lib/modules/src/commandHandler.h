#ifdef UNIT_TEST
   
#else    
       
#endif

#ifndef commandHandler_H
#define commandHandler_H

#include <list.h>
#include <iDataSource.h>

enum Commands{none = 0, getGroundMoisture= 1, getClimate = 2};

namespace myhappyplants
{
    class CommandHandler
    {                       
        private: 
            iDataSource& _GroundMoisture;
            iDataSource& _Climate;

    public:
        CommandHandler(iDataSource &groundMoisture, iDataSource &climate): _GroundMoisture(groundMoisture), _Climate(climate) {};
        ~CommandHandler() {};
        List<float>* Execute(Commands command);                
    };
}

#endif