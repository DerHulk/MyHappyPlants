
#ifndef commandHandlerTests_H
#include <unity.h>
#endif

#include "commandHandler.h"

using namespace myhappyplants;

CommandHandler* target;

void setUp(void)
{
    target = new CommandHandler();
}

void tearDown(void)
{
    //delete target;
}

void ctor01(void)
{
    //arrange
    //act
    //assert
    TEST_ASSERT_NOT_NULL(target);
}

void Execute01(){
    //arrange
    const char* expected = "20,100%";
    Commands command = Commands::getClimate;
    //act
    const char* result = target->Execute(command);

    //assert
    TEST_ASSERT_EQUAL(*expected, *result);
}

void Foo01(){
    //arrange    
    //act
    List<float>* result = target->foo();

    //assert
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(3,result->Length());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(ctor01);
    RUN_TEST(Execute01);
    RUN_TEST(Foo01);
    UNITY_END();

    return 0;
}