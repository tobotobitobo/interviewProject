#include "tests.h"
#include "Number.h"
#include <iostream>
#include <vector>


bool test(std::string testName, Number a, Number b, Number c) {
	Number result = a + b;
	std::cout << " \ntesting: " << testName << "\n";
	a.printNumber();
	std::cout << "+";
	b.printNumber();
	std::cout << "\n";
	c.printNumber();
	result.printNumber();
	if ((result.getStringValue() == c.getStringValue()) && result.getIsNegative() == c.getIsNegative())
	{
		std::cout << "test succesfull\n";
		std::cout << "--------------------------------------------------------------------------\n";
		return true;
	}
	else
	{
		std::cout << "test unsuccesfull \n";
		std::cout << "--------------------------------------------------------------------------\n";
		return false;
	}
}

void test_generation()
{
	std::cout << "testing 50 number generator \n ";
	for (int i = 0; i < 50; i++)
	{
		Number num(i+1);
		num.printNumber();
		std::cout << "number lenght =" << num.getSize() << " number negative = " << num.getIsNegative() << "\n";

	}
	std::cout << "\n";
}



void runTests() {
	test_generation();
	std::vector<bool> tests
	{
		test("kladne + zaporne", Number("2345", false), Number("1278", true), Number("1067", false)),
		test("kladne + kladne", Number("123", false), Number("877", false), Number("1000", false)),
		test("zaporne + zaporne", Number("500", true), Number("200", true), Number("700", true)),
		test("daco", Number("999", false), Number("1", false), Number("1000", false)),
		test("nuly", Number("0", false), Number("0", false), Number("0", false)),
		test("kladne + zaporne vecie", Number("10", false), Number("100", true), Number("90", true)),
		test("deveeeed", Number("999999", true), Number("10000", false), Number("989999", true)),
	};
	int cnt = count(tests.begin(), tests.end(), false);
	std::cout << "cout of failed tests = " << cnt << "\n";
}