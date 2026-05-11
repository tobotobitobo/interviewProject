// interview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Number.h"

std::string removeTrailingZeros(std::string s) 
{
    while (s.size() > 1 && s.back() == '0') 
    {
        s.pop_back();
    }
    return s;
}

std::string string_sum(std::string s1, std::string s2)
{

    int s1lenght = int(s1.size());
    int s2lenght = int(s2.size());

    
    int remain = 0;
    std::string wholesum = "";
    int ite = 0;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    while (ite < s1lenght || ite < s2lenght)
    {

        if (ite >= s1lenght)
        {   
            s1 += '0';
        }
        if (ite >= s2lenght)
        {
            s2 += '0';
        }
        int number1 = s1[ite] - '0';
        int number2 = s2[ite] - '0';

        //std::cout << "ite = " << ite << "\n";
        //std::cout << "numbedr1 = " << number1 << "number 2 = " << number2 << "\n";

        int sum = number1 + number2 + remain;

        //std::cout << "sum = " << sum << "remain = " << remain << "\n";

        remain = (sum > 9) ? 1 : 0;
        wholesum += ((sum % 10) + '0');
        ite += 1;
    }
    if (remain)
    {
        wholesum += (remain + '0');
    }
    std::reverse(wholesum.begin(), wholesum.end());

    return wholesum;
}


std::string string_subtract(std::string s1, std::string s2)
{
    
    int s1lenght = int(s1.size());
    int s2lenght = int(s2.size());


    int remain = 0;
    std::string wholesum = "";
    int ite = 0;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    while (ite < s1lenght)
    {
        if (ite >= s2lenght)
        {
            s2 += '0';
        }
        int number1 = s1[ite] - '0';
        int number2 = s2[ite] - '0';

        int diff = number1 - number2 - remain;
        if (diff < 0)
        {
            remain = 1;
            diff = 10 + diff;
        }
        else { remain = 0; }
        wholesum += ((diff) + '0');
        ite += 1;

    }
    wholesum = removeTrailingZeros(wholesum);

    std::reverse(wholesum.begin(), wholesum.end());

    return wholesum;
}


int main()
{
    srand(time(nullptr));
    std::string positiveSum = "0";
	std::string negativeSum = "0";
    for (int i = 0; i < 50; i++)
    {
		Number num(i + 1);
		std::cout << "my number is -> ";
        num.printNumber();
        if (num.getIsNegative())
        {
            negativeSum = string_sum(negativeSum, num.getStringValue());
        }
        else
        {
            positiveSum = string_sum(positiveSum, num.getStringValue());
        }
    }
    Number positive(positiveSum, false);
    Number negative(negativeSum, true);
    bool isnegative = false;
    if (negative.getSize() != positive.getSize())
    {
        if (negative.getSize() > positive.getSize())
        {
            isnegative = true;
        }
    }
    else
    {
        if (negative.getStringValue() > positive.getStringValue())
        {
            isnegative = true;
        }
    }

    std::string finalstr;

    if (isnegative)
    {
        finalstr = string_subtract(negativeSum, positiveSum);
    }
    else
    {
        finalstr = string_subtract(positiveSum, negativeSum);
    }

    Number finalsum(finalstr, isnegative);

    finalsum.printNumberFirstTen();
}
