#include "Number.h"

 
Number::Number(int size, unsigned int seed)
{

	if (seed != 0)
		srand(seed);

	this->size = size;
	for (int i = 0; i < size; i++)
	{
		stringValue += (generateRandomDigit() + '0');
	}
	while (stringValue[0] == '0')
	{
		stringValue[0] = (generateRandomDigit() + '0');
	}
	if (rand() % 2 == 0)
	{
		isNegative = true;
	}
}
Number::Number(std::string value,  bool negative)
{
	this->size = value.size();
	this->stringValue = value;
	this->isNegative = negative;
}

Number Number::operator+(Number next)
{
    if (!this->isNegative && !next.isNegative)
    {
        return Number(string_sum(this->stringValue, next.stringValue),false);
    }
    if (this->isNegative && next.isNegative)
    {
        return Number(string_sum(this->stringValue, next.stringValue), true);
    }
    if (*this > next)
    {
        return Number(string_subtract(stringValue, next.stringValue), isNegative);
    }
    else 
    {
        return Number(string_subtract(next.getStringValue(), this->stringValue), next.getIsNegative());
    }


}

bool Number::operator>(Number next) 
{

    if (stringValue.size() != next.getSize())
    {
        return stringValue.size() > next.getSize();
    }

    return stringValue > next.stringValue;
}

void Number::printNumberFirstTen()
{
	if(this->isNegative)
	{
		std::cout << "-";
	}
	if (this->getSize() <= 10)
	{
		this->printNumber();
	}
	std::cout << this->getStringValue().substr(0, 10) << "\n";
}

std::string Number::getStringValue()
{
	return stringValue;
}

bool Number:: getIsNegative()
{
	return isNegative;
}

int Number::generateRandomDigit()
{
	return rand() % 10;
}	

int Number::getSize()
{
	return size;
}

void Number::printNumber()
{
	if (isNegative)
	{
		std::cout << "-";
	}
	std::cout << stringValue << "\n";
}

std::string Number::removeTrailingZeros(std::string s)
{
    while (s.size() > 1 && s.back() == '0')
    {
        s.pop_back();
    }
    return s;
}

std::string Number::string_sum(std::string s1, std::string s2)
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

std::string Number::string_subtract(std::string s1, std::string s2)
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
        wholesum += ((diff)+'0');
        ite += 1;

    }
    wholesum = removeTrailingZeros(wholesum);

    std::reverse(wholesum.begin(), wholesum.end());

    return wholesum;
}

Number::~Number()
{
}