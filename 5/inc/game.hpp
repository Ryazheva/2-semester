#pragma once
#include <string>
#include <thread>
#include <SFML/Graphics.hpp>


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

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

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


		void CheckCollision(mt::Circle& obj1, mt::Circle& obj2)
		{
			float dx = obj1.X() - obj2.X();
			float dy = obj1.Y() - obj2.Y();
			float distance = sqrt(dx * dx + dy * dy);
			float minDistance = obj1.R() + obj2.R();

			if (distance < minDistance)
			{
				float angle = atan2(dy, dx);
				float vx1 = obj1.V() * cos(obj1.Alfa());
				float vy1 = obj1.V() * sin(obj1.Alfa());
				float vx2 = obj2.V() * cos(obj2.Alfa());
				float vy2 = obj2.V() * sin(obj2.Alfa());

				float v1AlongNormal = vx1 * cos(angle) + vy1 * sin(angle);
				float v2AlongNormal = vx2 * cos(angle) + vy2 * sin(angle);

				float v1AfterCollision = (v1AlongNormal * (obj1.R() - obj2.R()) + 2 * obj2.R() * v2AlongNormal) / (obj1.R() + obj2.R());
				float v2AfterCollision = (v2AlongNormal * (obj2.R() - obj1.R()) + 2 * obj1.R() * v1AlongNormal) / (obj1.R() + obj2.R());

				obj1.Alfa(obj1.Alfa() + (v1AfterCollision - v1AlongNormal));
				obj2.Alfa(obj2.Alfa() + (v2AfterCollision - v2AlongNormal));
			}
		}

		void CheckCollisions()
		{
			for (int i = 0; i < m_n; ++i) {
				for (int j = i + 1; j < m_n; ++j) {
					CheckCollision(m_c[i], m_c[j]);
				}
			}
		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				for (int i = 0; i < m_n; i++) {
					m_c[i].Move(dt);
					TouchBorder(m_c[i]);
				}

				CheckCollisions();

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_c[i].Get());
				m_window.display();
			}
		}
	};

}