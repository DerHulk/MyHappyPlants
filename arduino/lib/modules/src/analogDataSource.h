#include "iDataSource.h"

#ifndef simpleDataSource_H
#define simpleDataSource_H

namespace myhappyplants
{
    class AnalogDataSource : public iDataSource
    {
    private:
        uint8_t _PinToUse;

    public:        
        AnalogDataSource(uint8_t pinToUse):_PinToUse(pinToUse) {};
         
        List<float> *GetData();
    };
} // namespace myhappyplants

#endif