#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <kite.hpp>

namespace mt
{

	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		int m_n;
		sf::RenderWindow m_window;
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;

		Kite m_kite;

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n)
		{
			m_n = n;
			// создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			// загрузка текстуры фона
			sf::Texture texture;
			if (!m_textureBackground.loadFromFile("images\\sky.jpg"))
			{
				std::cout << "Error while loading sky.jpg" << std::endl;
				return false;
			}
			m_spriteBackground.setTexture(m_textureBackground);
			m_spriteBackground.setScale(0.6f, 0.6f);

			// создание змея
			if (!m_kite.Setup(100, 100))
				return false;

			srand(time(0));

			m_c = new mt::Circle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int r = rand() % 100 + 1;
				int x = rand() % (1000 - 2 * r) + r;
				int y = rand() % (600 - 2 * r) + r;
				int v = rand() % 50 + 10;
				float alfa = rand() % 7;
				m_c[i].Setup(x, y, r, v, alfa);
			}
		}
		// ограничение для выхода за границы поля (шариков)
		void TouchBorder(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0)
			{
				obj.Alfa(pi - obj.Alfa());
			}

			if (y + r >= m_height || y - r <= 0)
			{
				obj.Alfa(2 * pi - obj.Alfa());
			}

		}

		void LifeCycle()
		{
			sf::Clock clock;

			float fps = 100;

			while (m_window.isOpen())
			{
				// обработка событий
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				// обработка клавиатуры 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					m_kite.setVelocity(0.001);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					m_kite.setVelocity(-0.001);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					m_kite.Rotate(-1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					m_kite.Rotate(1);
				}

				// логика
				float dt = clock.getElapsedTime().asSeconds();
				if (1 / fps > dt)
				{
					sf::Time t= sf::seconds(1/fps - dt);
					sf::sleep(t);
				}
				dt = clock.getElapsedTime().asSeconds();
				clock.restart();


				// перемещение шарика
				for (int i = 0; i < m_n; i++)
					m_c[i].Move(dt);

				for (int i = 0; i < m_n; i++)
					TouchBorder(m_c[i]);

				// перемещение змея
				m_kite.Move();

				// отображение
				m_window.clear();
				m_window.draw(m_spriteBackground);
				m_window.draw(m_kite.Get());
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_c[i].Get());
				m_window.display();
			}
		}
	};

}
