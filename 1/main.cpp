﻿#include <iostream>
#include "func.hpp"

int main()
{
	std::string fileName = "input.txt";

	Date::Number(fileName);
	Date::Time(fileName);
	std::cout << "All in file" << std::endl;

	return 0;
}