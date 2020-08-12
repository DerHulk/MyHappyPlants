
#ifndef commandHandlerTests_H
    #include <unity.h>
#endif

#include "commandHandler.h"

using namespace myhappyplants;


void setUp(void) {
// set stuff up here
}

void tearDown(void) {
// clean stuff up here
}

void CommandHandlerTests_ctor01(void)
{
    CommandHandler *handler = new CommandHandler();
    TEST_ASSERT_NOT_NULL(handler);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(CommandHandlerTests_ctor01);
    UNITY_END();

    return 0;
}