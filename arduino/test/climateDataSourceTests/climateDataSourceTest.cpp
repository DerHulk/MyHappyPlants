#include <unity.h>
#include "climateDataSource.h"
#include "mockDht.h"

using namespace myhappyplants;

ClimateDataSource *target;

void setUp(void)
{   
}

void tearDown(void)
{
    //delete target;
}

void ctor01(void)
{
    //arrange   
    DHT sensorMock = DHT(1, 1, 1);
    target = nullptr;    
    //act
    target = new ClimateDataSource(sensorMock);
    //assert
    TEST_ASSERT_NOT_NULL(target);    
}

void GetData01(void)
{
    //arrange
    float expectedTemperature = 99;
    float expectedHumidity = 101;
    float expectedHeat = 333;

    DHT sensorMock = DHT(1, 1, 1);
    target = new ClimateDataSource(sensorMock);

    sensorMock.setTemperature(expectedTemperature);
    sensorMock.setHumidity(expectedHumidity);
    sensorMock.setHeatIndex(expectedHeat);
        
    // //act
    List<float>* result = target->GetData();    

    // //assert
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(3, result->Length());
    TEST_ASSERT_EQUAL(expectedTemperature,result->Get(0));
    TEST_ASSERT_EQUAL(expectedHumidity,result->Get(1));
    TEST_ASSERT_EQUAL(expectedHeat,result->Get(2)); 
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(ctor01);
    RUN_TEST(GetData01);    
    UNITY_END();

    return 0;
}