#ifndef dhtDataSource_H
#define dhtDataSource_H

#include "DHT.h";
#include "iDataSource.h";

namespace myhappyplants
{
    class climateDataSource : public iDataSource
    {
    private:
        DHT *_Sensor;

    public:
        climateDataSource(int pintToUse);
        ~climateDataSource();
        String GetData();
    };
} // namespace myhappyplants

#endif