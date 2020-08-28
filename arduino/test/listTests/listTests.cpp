#include <unity.h>
#include "list.h";

using namespace myhappyplants;

void setUp(void)
{
}

void tearDown(void)
{
}

void Length01(void)
{
    //arrange
    int expected = 4;
    int* input = new int[expected] {99,101,3,4};
    List<int> *target = new List<int>(input,expected);    

    //act
    int result = target->Length();

    //assert
    TEST_ASSERT_EQUAL(expected, result);
}

void Length02(void)
{
    //arrange        
    int* input = new int[3]{99,101,3};
    List<int> *target = new List<int>(input, 3);

    //act    
    int first = target->Get(0);
    int middle = target->Get(1);
    int last = target->Get(2);        

    //assert
    TEST_ASSERT_EQUAL(99, first);
    TEST_ASSERT_EQUAL(101, middle);
    TEST_ASSERT_EQUAL(3, last);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();    
    RUN_TEST(Length01);
    RUN_TEST(Length02);
    UNITY_END();

    return 0;
}