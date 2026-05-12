#include "Number.h"

 

//constructor  with default random seed , can be specified for testing
Number::Number(int size, unsigned int seed)
{
    //seed check
    if (seed != 0)
        srand(seed);

    this->size = size;
    //generate random number of size i+1 -> 1 - 50
    for (int i = 0; i < size; i++)
    {
        stringValue += (generateRandomDigit() + '0');
    }
    //check first number of string if 0 generate again
    while (stringValue[0] == '0')
    {
        stringValue[0] = (generateRandomDigit() + '0');
    }
    //generate true false for negative
    if (rand() % 2 == 0)
    {
        isNegative = true;
    }
}
//overloaded constructor for testing and special cases in code where value needs to be defined not generated
Number::Number(std::string value, bool negative)
{
    this->size = value.size();
    this->stringValue = value;
    this->isNegative = negative;
}
//overloading operators for clearer code structure
Number Number::operator+(Number next)
{
    //special behavior for each tipe of sum 
    //positive + positive = num + num and positive sign
    if (!this->isNegative && !next.isNegative)
    {
        return Number(string_sum(this->stringValue, next.stringValue), false);
    }
    //negative + negative = num + num and negative sign
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

//overloading num comparison based on num string no operator
bool Number::operator>(Number next) 
{

    if (stringValue.size() != next.getSize())
    {
        return stringValue.size() > next.getSize();
    }

    return stringValue > next.stringValue;
}
//generation of random Digit
int Number::generateRandomDigit()
{
	return rand() % 10;
}	
//printers
void Number::printNumber()
{
	if (isNegative)
	{
		std::cout << "-";
	}
	std::cout << stringValue << "\n";
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


//helper function for subtraction to remuve all zeroes from back of the string
std::string Number::removeTrailingZeros(std::string s)
{
    while (s.size() > 1 && s.back() == '0')
    {
        s.pop_back();
    }
    return s;
}
//string sum
std::string Number::string_sum(std::string s1, std::string s2)
{
    //get lenght
    int s1lenght = int(s1.size());
    int s2lenght = int(s2.size());


    int remain = 0;
    std::string wholesum = "";
    int ite = 0;
    //reverse strings for better handeling
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());

    //summing eatch digit from begining like suming one digit under other 
    while (ite < s1lenght || ite < s2lenght)
    {
        //adding zeroes in case on digit have smaller size then other
        if (ite >= s1lenght)
        {
            s1 += '0';
        }
        if (ite >= s2lenght)
        {
            s2 += '0';
        }
        //char to int
        int number1 = s1[ite] - '0';
        int number2 = s2[ite] - '0';
        // sum + remain if last sum was above 10
        int sum = number1 + number2 + remain;

        //if sum above 9 remain = 1 
        remain = (sum > 9) ? 1 : 0;
        //adding sum to whole sum if + 10 and more then only add last digit
        wholesum += ((sum % 10) + '0');
        ite += 1;
    }
    //lastly after all digit are acounted for if remain still is there add it
    if (remain)
    {
        wholesum += (remain + '0');
    }
    //reverse
    std::reverse(wholesum.begin(), wholesum.end());

    return wholesum;
}
//basicly same thing 
std::string Number::string_subtract(std::string s1, std::string s2)
{
    //in operator overloading we have made sure that s1.size cant be lover than s2 size becouse of that we will never go unde 0
    int s1lenght = int(s1.size());
    int s2lenght = int(s2.size());


    int remain = 0;
    std::string wholesum = "";
    int ite = 0;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    //iteratig only throu larger string
    while (ite < s1lenght)
    {
        //adding zearoes to smaller string
        if (ite >= s2lenght)
        {
            s2 += '0';
        }
        int number1 = s1[ite] - '0';
        int number2 = s2[ite] - '0';


        int diff = number1 - number2 - remain;
        //remain math
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
//geters
std::string Number::getStringValue()
{
	return stringValue;
}

bool Number:: getIsNegative()
{
	return isNegative;
}


int Number::getSize()
{
	return size;
}
//deconstructor
Number::~Number()
{
}
