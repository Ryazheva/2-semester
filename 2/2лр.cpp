#include <iostream>
#include <cmath>

class Cube
{
	int m_a;

public:

	Cube(int a)
	{
		m_a = a;
	}

	void setA(int a)
	{
		if (a < 0)
			std::cout << "отрицательное число стороны куба" << std::endl;
		m_a = a;
	}

	int Square()
	{
		return 6 * m_a * m_a;
	}

	int Volume()
	{
		return m_a * m_a * m_a;
	}

	float Diagonal()
	{
		return m_a * (sqrt(3));
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int s;
	std::cin >> s;

	Cube p1(s);

	std::cout << "площадь: " << p1.Square() << std::endl;
	std::cout << "объем: " << p1.Volume() << std::endl;
	std::cout << "длина диагонали: " << p1.Diagonal() << std::endl;

	return 0;
}