#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mt
{
	class Kite
	{
		float m_x, m_y;
		float m_alpha;
		float m_v;
		sf::Texture m_textureKite;
		sf::Sprite m_spriteKite;

	public:
		Kite() = default;

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_alpha = 0;
			m_v = 0;

			// загрузка текстуры фона
			sf::Texture texture;
			if (!m_textureKite.loadFromFile("images\\kite.png"))
			{
				std::cout << "Error while loading kite.png" << std::endl;
				return false;
			}
			m_spriteKite.setTexture(m_textureKite);

			m_spriteKite.setScale(0.03f, 0.03f);
			m_spriteKite.setOrigin(m_textureKite.getSize().x / 2, m_textureKite.getSize().y / 2);
			m_spriteKite.setPosition(m_x, m_y);
			m_spriteKite.setRotation(m_alpha);
		}

		void setVelocity(float dv)
		{
			m_v += dv;
		}

		void Move()
		{
			float alphaRad = acos(-1) * m_alpha / 180;
			m_x += m_v * cos(alphaRad);
			m_y += m_v * sin(alphaRad);
			m_spriteKite.setPosition(m_x, m_y);
		}

		void Rotate(float dalpha)
		{
			m_alpha += dalpha;
			m_spriteKite.setRotation(m_alpha);

		}

		sf::Sprite Get()
		{
			return m_spriteKite;
		}
	};
}
