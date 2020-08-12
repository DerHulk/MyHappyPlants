#include <unity.h>
#include "climateDataSource.h"
#include "mockDht.h"

using namespace myhappyplants;

ClimateDataSource *target;
DHT* sensorMock;

void setUp(void)
{
    sensorMock = new DHT(1, 1, 1);
    target = new ClimateDataSource(sensorMock);
}

void tearDown(void)
{
    delete target;
}

void ctor01(void)
{
    //arrange
    //act
    //assert
    TEST_ASSERT_NOT_NULL(target);
}

void GetData01(void)
{
    //arrange
    const char *e = "";
    //act
    const char *t = target->GetData();
    //assert
    TEST_ASSERT_EQUAL(*e, *t);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(ctor01);
    RUN_TEST(GetData01);
    UNITY_END();

    return 0;
}