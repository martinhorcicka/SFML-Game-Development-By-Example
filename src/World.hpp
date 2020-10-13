#pragma once
#include <SFML/Graphics.hpp>

#include "Snake.hpp"
#include "Window.hpp"

class World {
   public:
    World(sf::Vector2u l_windowSize);
    ~World();

    int GetBlockSize();

    void RespawnApple();

    void Update(Snake& l_player);
    void Render(Window& l_window);

   private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};
