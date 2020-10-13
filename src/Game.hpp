#pragma once
#include "Snake.hpp"
#include "Textbox.hpp"
#include "Window.hpp"
#include "World.hpp"

class Game {
   public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

    void RestartClock();
    sf::Time GetElapsed();

   private:
    Window m_window;
    World m_world;
    Snake m_snake;
    // Textbox m_textbox;

    sf::Clock m_clock;
    sf::Time m_elapsed;
};
