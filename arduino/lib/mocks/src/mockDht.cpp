#include "mockDht.h"

void DHT::begin(uint8_t usec )
{
}

float DHT::readTemperature(bool S , bool force )
{    
    return this->_Temperature;
}

float DHT::convertCtoF(float)
{
    return 999;
}

float DHT::convertFtoC(float)
{
    return 999;
}

float DHT::computeHeatIndex(bool isFahrenheit )
{
    return this->_HeatIndex;
}

float DHT::computeHeatIndex(float temperature, float percentHumidity,
                            bool isFahrenheit)
{
    return this->_HeatIndex;
}

float DHT::readHumidity(bool force)
{
    return this->_Humidity;
}

bool DHT::read(bool force)
{
}

void DHT::setTemperature(float value){
    this->_Temperature = value;
}

void DHT::setHumidity(float value){
    this->_Humidity = value;
}

void DHT::setHeatIndex(float value){
    this->_HeatIndex = value;
}

