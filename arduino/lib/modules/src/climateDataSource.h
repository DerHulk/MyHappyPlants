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
    class ClimateDataSource : iDataSource
    {
    private:
         DHT _Sensor;

    public:
        ClimateDataSource(int pin) : _Sensor(pin, DHT22, 1){};

        ~ClimateDataSource();
        List<float>* GetData();
    };
} // namespace myhappyplants

#endif