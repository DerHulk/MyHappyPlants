
#ifndef commandHandlerTests_H
#include <unity.h>
#endif

#include <simpleDataSource.h>
#include <commandHandler.h>

using namespace myhappyplants;

CommandHandler *target;

iDataSource *CreateDataSource(List<float>* values)
{    
    SimpleDataSource *source = new SimpleDataSource(*values);            

    return source;
}

iDataSource *CreateDataSource(float v1 = 0, float v2 = 0, float v3 = 0)
{
    float array[3] = {v1, v2, v3};
    List<float> *values = new List<float>(array, 3);    

    return CreateDataSource(values);
}

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
    target = nullptr;
    iDataSource* s1 = CreateDataSource();
    iDataSource* s2 = CreateDataSource();

    //act
    target = new CommandHandler(*s1,*s2);

    //assert
    TEST_ASSERT_NOT_NULL(target);
}

void Execute01()
{
    //arrange
    List<float> *expected = new List<float>(new float[3]{1,2,3},3);
    iDataSource* s1 = CreateDataSource(4,5,6);
    iDataSource* s2 = CreateDataSource(expected);
    target = new CommandHandler(*s1,*s2);

    Commands command = Commands::getClimate;

    //act
    List<float> *result = target->Execute(command);

    //assert
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(expected, result);       
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(ctor01);
    RUN_TEST(Execute01);
    UNITY_END();

    return 0;
}