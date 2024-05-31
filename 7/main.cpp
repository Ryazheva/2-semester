﻿#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>

int main()
{
    mt::Game game(1280, 720, "Game");


    game.Setup(50);
    game.LifeCycle();

    return 0;
}