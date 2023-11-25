#include "test.h"


test::test()
{
    std::cout << "test()" << std::endl;
}

test::~test()
{
    std::cout << "~test()" << std::endl;
}



void test::test1()
{
    printf("Hello world!\n");
}