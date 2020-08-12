//  #include "climateDataSource.h"

// namespace myhappyplants
// {
//     climateDataSource::climateDataSource(int pintToUse)
//     {
//         _Sensor = new DHT(pintToUse, DHT22, 1);                        
//     }

//     climateDataSource::~climateDataSource()
//     {
//         delete _Sensor;
//     }

//     const char* climateDataSource::GetData()
//     {                
//         //String sepperator = ";";
//         float currentTemperature  = climateDataSource::_Sensor->readTemperature();
//         float currentHymanid = climateDataSource::_Sensor->readHumidity();
//         float humanidIndex = climateDataSource::_Sensor->computeHeatIndex();

//         return "";
//         //return String(currentTemperature) + sepperator + String(currentHymanid) + sepperator + String(humanidIndex));
//     }

// }
