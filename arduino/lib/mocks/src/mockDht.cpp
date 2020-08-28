#include "mockDht.h"

void DHT::begin(uint8_t usec )
{
}

float DHT::readTemperature(bool S , bool force )
{    
    return 0;
}

float DHT::convertCtoF(float)
{
    return 12;
}

float DHT::convertFtoC(float)
{
    
}

float DHT::computeHeatIndex(bool isFahrenheit )
{
    return 0;
}

float DHT::computeHeatIndex(float temperature, float percentHumidity,
                            bool isFahrenheit)
{
    return 0;
}

float DHT::readHumidity(bool force)
{
    return 0;
}

bool DHT::read(bool force)
{
}

