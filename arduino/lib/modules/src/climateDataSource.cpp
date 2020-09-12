#include "climateDataSource.h"

namespace myhappyplants
{   
    List<float> *ClimateDataSource::GetData()
    {
        float temperature = _Sensor.readTemperature();
        float humidity = _Sensor.readHumidity();
        float headIndex = _Sensor.computeHeatIndex(false);

        float *values = new float[3]{
            temperature,
            humidity,
            headIndex};

        return new List<float>(values, 3);
    }    

} // namespace myhappyplants
