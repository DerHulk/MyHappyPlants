 #include "climateDataSource.h"

namespace myhappyplants
{
    // ClimateDataSource::ClimateDataSource(int pintToUse)
    // {
    //     _Sensor = new DHT(pintToUse, DHT22, 1);                        
    // }

    ClimateDataSource::~ClimateDataSource()
    {
        delete _Sensor;
    }

    const char* ClimateDataSource::GetData()
    {                
        //String sepperator = ";";
        float currentTemperature  = ClimateDataSource::_Sensor->readTemperature();
        float currentHymanid = ClimateDataSource::_Sensor->readHumidity();
        float humanidIndex = ClimateDataSource::_Sensor->computeHeatIndex();

        return "";
        //return String(currentTemperature) + sepperator + String(currentHymanid) + sepperator + String(humanidIndex));
    }

}
