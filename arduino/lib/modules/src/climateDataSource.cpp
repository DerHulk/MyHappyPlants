#include "climateDataSource.h"

namespace myhappyplants
{
    // ClimateDataSource::ClimateDataSource(DHT &sensor):_Sensor(sensor)
    // {
        
    // }
    
    // ClimateDataSource::~ClimateDataSource()
    // {     

    // }

    List<float> *ClimateDataSource::GetData()
    {
        float temperature = _Sensor.readTemperature();
        float humidity = _Sensor.readHumidity();
        float headIndex = _Sensor.computeHeatIndex();

        float *values = new float[3]{
            temperature,
            humidity,
            headIndex};

        return new List<float>(values, 3);
    }

    float ClimateDataSource::getT()
    {
        return _Sensor.readTemperature();
    }

} // namespace myhappyplants
