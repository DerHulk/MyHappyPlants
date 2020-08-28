#include <unity.h>
#include "climateDataSource.h"
#include "mockDht.h"

using namespace myhappyplants;

ClimateDataSource *target;
DHT* sensorMock;

void setUp(void)
{
    // sensorMock = new DHT(1, 1, 1);
    //target = new ClimateDataSource(1);
    //target = new ClimateDataSource();
}

void tearDown(void)
{
    //delete target;
}

void ctor01(void)
{
    //arrange
    target = nullptr;    
    //act
    target = new ClimateDataSource(1);
    //assert
    TEST_ASSERT_NOT_NULL(target);
}

void GetData01(void)
{
    //arrange
    target = new ClimateDataSource(1);
    // //act
    List<float>* result = target->GetData();    

    // //assert
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(3, result->Length());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(ctor01);
    RUN_TEST(GetData01);    
    UNITY_END();

    return 0;
}