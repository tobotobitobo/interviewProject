// interview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


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

        std::cout << "ite = " << ite << "\n";
        std::cout << "number1 = " << number1 << "number 2 = " << number2 << "\n";

        int sum = number1 + number2 + remain;

        std::cout << "sum = " << sum << "remain = " << remain << "\n";

        remain = (sum > 9) ? 1 : 0;
        wholesum += ((sum % 10) + '0');
        ite += 1;
    }
    if (remain)
    {
        wholesum += (remain + '0');
    }
    std::reverse(wholesum.begin(), wholesum.end());


    //for (int i = 0; i < s1lenght; i++)
    //{
    //    int number1 = s1[i] - '0';
    //    int number2 = s2[i] - '0';
    //    int sum = number1 + number2 + remain;

    //    if (sum > 9)
    //    {
    //        remain = 1;
    //    }
    //    else
    //    {
    //        remain = 0;
    //    }
    //    wholesum += ((sum % 10)  + '0');

    //}
    //wholesum += (remain + '0');
    //std::reverse(wholesum.begin(), wholesum.end());
    //std::cout << wholesum;

    return wholesum;
}

int main()
{
    std::cout << string_sum("12345", "1");
}
