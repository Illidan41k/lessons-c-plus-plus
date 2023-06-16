#include "TestFunctions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>

void exponential(double degree, std::string filename)
{
	std::ofstream out(filename);
	std::cout.rdbuf(out.rdbuf());
	std::cout << std::setprecision(20);

	double e = 2.7182818284;

	double result = pow(e, degree);
	std::cout << result << std::endl;
}

void test_types_operations()
{
	std::cout << std::setprecision(10);
	double PI_double = 3.1415926535;
	float PI_float = 3.1415926535;
	int radius = 3;

	double square = PI_double * radius * radius;
	int bad_calculated_square = PI_double * radius * radius; //never calculates it using int...
	float float_square = PI_float * radius * radius;

	std::cout << "double square is: " << square << std::endl;
	std::cout << "float square is: " << float_square << std::endl;
	std::cout << "int square is: " << bad_calculated_square << std::endl;

}

void test_ifstream(std::string filename)
{
	std::ifstream in(filename);
	std::cin.rdbuf(in.rdbuf());

	int variable;

	std::cin >> variable;

	while (!std::cin.fail())
	{
		std::cout << variable << std::endl;
		std::cin >> variable;
	}
}

void test_stringstream(std::string input)
{
	std::stringstream local_stream;

	local_stream << input;

	float variable;

	local_stream >> variable;

	while (!local_stream.fail())
	{
		std::cout << variable << std::endl;
		local_stream >> variable;
	}
}

void test_conversion(std::string input)
{
	std::string digit_string = input;
	int digit = std::stoi(digit_string);

	std::cout << digit + 10 << " " << std::endl;
}
