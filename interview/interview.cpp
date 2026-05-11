// interview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Number.h"
#include "tests.h"

int main()
{
    runTests();
    srand(time(nullptr));
    Number wholesum("0", false);
    for (int i = 0; i < 50; i++)
    {
        Number num(i + 1);
        //num.printNumber();
        wholesum = wholesum + num;
    }


    std::cout << "result is ";
    wholesum.printNumberFirstTen();
}
