#include "DHT.h";
#include "climateDataSource.h";
#include <Arduino.h>

namespace myhappyplants
{
    climateDataSource::climateDataSource(int pintToUse)
    {
        _Sensor = new DHT(pintToUse, DHT22, 1);
    }

    climateDataSource::~climateDataSource()
    {
        delete _Sensor;
    }

    String climateDataSource::GetData()
    {
        return "test";
    }

} // namespace myhappyplants
