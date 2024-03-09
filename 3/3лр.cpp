#include <iostream>
#include <cstring>

class Stroka
{
private:
	char* str;

public:
	Stroka(const char* s = "")
	{
		str = new char[strlen(s) + 1];
		std::strcpy(str, s);
	}

    Stroka(const Stroka& other)  
    {
        str = new char[strlen(other.str) + 1];
        std::strcpy(str, other.str);
    }

    Stroka& operator=(const Stroka& other) 
    {
        if (this != &other) 
        {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    ~Stroka()
    {
        delete[] str;
    }

    void print()
    {
        std::cout << str << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Stroka str1("копирование");
    Stroka str2 = str1;
    Stroka str3 = str1;

    std::cout << "str1: ";
    str1.print();
    std::cout << "str2: ";
    str2.print();
    std::cout << "str3: ";
    str3.print();

    return 0;
};