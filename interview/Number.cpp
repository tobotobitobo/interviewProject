#include "Number.h"


Number::Number(int size)
{
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


Number::~Number()
{
}