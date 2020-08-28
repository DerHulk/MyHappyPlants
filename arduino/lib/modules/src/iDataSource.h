#ifdef UNIT_TEST
#else
#include <Arduino.h>
#endif
#include <list.h>

#ifndef iDataSource_h
#define iDataSource_h

namespace myhappyplants
{
    class iDataSource
    {
    public:
        virtual List<float>* GetData() = 0;
    };
}
#endif