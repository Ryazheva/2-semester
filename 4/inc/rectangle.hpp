#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Rectangle
	{
		float m_width, m_height;
		float m_x, m_y;
		sf::RectangleShape m_shape;

	public:
		Rectangle() = default;

		Rectangle(float x, float y, float width, float height)
		{
			Setup(x, y, width, height);
		}

		void Setup(float x, float y, float width, float height)
		{
			m_x = x;
			m_y = y;
			m_width = width;
			m_height = height;

			m_shape.setSize(sf::Vector2f(m_width, m_height));
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Color(255, 0, 0, 255));
		}

		sf::RectangleShape Get()
		{
			return m_shape;
		}
	};

}