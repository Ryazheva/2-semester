#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <bullet.hpp>
#include <list>

namespace mt
{
    class Ship
    {
        const int m_bulletR = 10;
        float m_v_bullet = 200;

        float m_x, m_y;
        float m_alpha;
        float m_v;
        float m_r;
        sf::Texture m_textureShip;
        sf::Sprite m_spriteShip;
        float m_scaleFactor = 0.2f;

        std::list<Bullet> m_bullets;
        std::chrono::steady_clock::time_point m_lastShotTime; // ���������� ��� ������������ ������� ���������� ��������
        float m_shotInterval = 0.3f; // ����������� �������� ����� ���������� � ��������

    public:
        Ship() = default;

        Ship(float x, float y)
        {
            m_x = x;
            m_y = y;
        }

        bool Setup(float x, float y)
        {
            m_x = x;
            m_y = y;
            m_alpha = 0;
            m_v = 0;

            if (!m_textureShip.loadFromFile("/Users/507015t/Desktop/2023_1pm_mo/basic/lecture21_bullet/assets/falcon.png"))
            {
                std::cout << "Error while loading falcon.png" << std::endl;
            }

            m_spriteShip.setTexture(m_textureShip);
            m_spriteShip.setScale(m_scaleFactor, m_scaleFactor);
            m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
            m_spriteShip.setPosition(m_x, m_y);
            m_spriteShip.setRotation(m_alpha);

            if (m_textureShip.getSize().x > m_textureShip.getSize().y)
                m_r = m_scaleFactor * m_textureShip.getSize().x / 2;
            else
                m_r = m_scaleFactor * m_textureShip.getSize().y / 2;

            return true;
        }

        void Attack()
        {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - m_lastShotTime).count();
            if (elapsedTime < m_shotInterval) {
                return; // ���� �� ������ ���������� �������, ������� �� ������ ��� ��������
            }
            float alphaRad = acos(-1) * m_alpha / 180;

            m_bullets.push_back(Bullet(m_x, m_y, m_bulletR, (m_v + m_v_bullet) * cos(alphaRad), (m_v + m_v_bullet) * sin(alphaRad)));
            // ��������� ����� ���������� ��������
            m_lastShotTime = currentTime;
        }

        void setVelocity(float dv)
        {
            m_v += dv;
        }

        float V() { return m_v; }

        void Move(float dt)
        {
            for (auto& bullet : m_bullets)
            {
                bullet.Move(dt);
            }

            float alphaRad = acos(-1) * m_alpha / 180;
            m_x += m_v * cos(alphaRad) * dt;
            m_y += m_v * sin(alphaRad) * dt;
            m_spriteShip.setPosition(m_x, m_y);
        }

        float R() { return m_r; }
        float X() { return m_x; }
        float Y() { return m_y; }

        void Rotate(float dalpha)
        {
            m_alpha += dalpha;
            m_spriteShip.setRotation(m_alpha);
        }

        sf::Sprite Get()
        {
            return m_spriteShip;
        }

        std::list<Bullet>& GetBullets()
        {
            return m_bullets;
        }
    };
}