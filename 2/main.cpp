#include <iostream>
#include <cmath>

class Cube
{
	int m_a;

public:

	Cube(int a)
	{
		setA(a);
	}

	void setA(int a)
	{
		if (a < 0)
			std::cout << "отрицательное число" << std::endl;
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
	
	int c;
	std::cin >> c;
	Cube s(c);

	std::cout << "площадь: " << s.Square() << std::endl;
	std::cout << "объем: " << s.Volume() << std::endl;
	std::cout << "длина диагонали: " << s.Diagonal() << std::endl;

	return 0;
}
