#ifdef UNIT_TEST
#include "mockDht.h"
#else
#include "DHT.h"
#endif

#include "iDataSource.h"

#ifndef dhtDataSource_H
#define dhtDataSource_H

namespace myhappyplants
{
    class ClimateDataSource  : public iDataSource
    {
    private:
         DHT& _Sensor;

    public:        
        ClimateDataSource(DHT& s) :_Sensor(s) {};                

        ~ClimateDataSource();
        List<float>* GetData();        
    };
} // namespace myhappyplants

#endif