#pragma once
#include <iostream>
class Number
{
public:
	Number(int size, unsigned int seed = 0);
	Number(std::string value, bool negative);
	~Number();
	int getSize();
	void printNumber();
	bool getIsNegative();
	std::string getStringValue();
	void printNumberFirstTen();


private:
	bool isNegative = false;
	int size;
	std::string stringValue;
	int generateRandomDigit();
};


