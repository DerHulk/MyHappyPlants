
#ifndef commandHandlerTests_H
#include <unity.h>
#endif

#include "commandHandler.h"

using namespace myhappyplants;

CommandHandler *target;

void setUp(void)
{
    target = new CommandHandler();
}

void tearDown(void)
{
    delete target;
}

void CommandHandlerTests_ctor01(void)
{
    //arrange
    //act
    //assert
    TEST_ASSERT_NOT_NULL(target);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(CommandHandlerTests_ctor01);
    UNITY_END();

    return 0;
}