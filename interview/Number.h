#pragma once
#include <iostream>
class Number
{
public:
	//sett stable seed if not defined othervise
	Number(int size, unsigned int seed = 0);
	Number(std::string value, bool negative);
	~Number();
	void printNumber();
	bool getIsNegative();
	std::string getStringValue();
	int getSize();
	void printNumberFirstTen();

	Number operator+(Number next);
	bool operator>(Number next);


private:
	bool isNegative = false;
	int size;
	std::string stringValue;
	int generateRandomDigit();
	std::string string_sum(std::string s1, std::string s2);
	std::string string_subtract(std::string s1, std::string s2);
	std::string removeTrailingZeros(std::string s);
};


