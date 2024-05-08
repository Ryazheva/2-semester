#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <triangle.hpp>
#include <rectangle.hpp>
#include <line.hpp>


//круги
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    srand(time(0));

    const int n = 4;

    mt::Circle c[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int r = rand() % 100 + 1;
        c[i].Setup(x, y, r);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(c[i].Get());
        window.display();
    }

    return 0;
}

/*
//треугольники
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    srand(time(0));

    const int n = 4;

    mt::Triangle t[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        int y = rand() % 600;
        int r = rand() % 100 + 1;
        t[i].Setup(x, y, r);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(t[i].Get());
        window.display();
    }

    return 0;
}
*/


/*
//прямоугольники
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    srand(time(0));

    const int n = 4;

    mt::Rectangle c[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int width = rand() % 100 + 1;
        int height = rand() % 100 + 1;
        c[i].Setup(x, y, width, height);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(c[i].Get());
        window.display();
    }

    return 0;
}
*/

/*
//линии
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    srand(time(0));

    const int n = 4;

    mt::Line l[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int a = rand() % 800 + 1;
        int b = rand() % 10 + 1;
        l[i].Setup(x, y, a, b);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(l[i].Get());
        window.display();
    }

    return 0;
}
*/