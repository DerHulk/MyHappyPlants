#ifdef UNIT_TEST
#include "mockDht.h"
#else
#include <Arduino.h>
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
        DHT *_Sensor;

    public:
        ClimateDataSource(DHT *sensor)
        {
            _Sensor = sensor;
        };

        ~ClimateDataSource();
        const char *GetData();
    };
} // namespace myhappyplants

#endif