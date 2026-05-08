#pragma once
#include <iostream>
class Number
{
public:
	Number(int size);
	~Number();
	int getSize();
	void printNumber();


private:
	bool isNegative = false;
	int size;
	std::string stringValue;
	int generateRandomDigit();
};


