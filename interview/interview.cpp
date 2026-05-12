// interview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Number.h"
#include "tests.h"

int main()
{
    //run tests
    runTests();
    //random
    srand(time(nullptr));
    //initialize wholesum
    Number wholesum("0", false);
    for (int i = 0; i < 50; i++)
    {
        //initialize num of size i+1
        Number num(i + 1);
        //num.printNumber();
        wholesum = wholesum + num; //add to wholesum
    }


    std::cout << "result is ";
    wholesum.printNumberFirstTen();
}
