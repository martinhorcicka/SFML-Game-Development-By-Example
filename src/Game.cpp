#include "Game.hpp"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
               m_snake(m_world.GetBlockSize()),
               m_world(sf::Vector2u(800, 600)) {
    // m_textbox.Setup(5, 14, 350, sf::Vector2f(225, 0));
    // m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

Game::~Game() {}

void Game::HandleInput() {
    auto snakeDir = m_snake.GetPhysicalDirection();
    Direction newDir = snakeDir;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snakeDir != Direction::Down)
        newDir = Direction::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snakeDir != Direction::Up)
        newDir = Direction::Down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snakeDir != Direction::Right)
        newDir = Direction::Left;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snakeDir != Direction::Left)
        newDir = Direction::Right;
    m_snake.SetDirection(newDir);
}

void Game::Update() {
    m_window.Update();

    float timeStep = 1.0f / m_snake.GetSpeed();

    if (m_elapsed.asSeconds() >= timeStep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= sf::seconds(timeStep);
        if (m_snake.HasLost())
            m_snake.Reset();
    }
}

void Game::Render() {
    m_window.BeginDraw();
    m_world.Render(m_window);
    m_snake.Render(m_window);
    // m_textbox.Render(m_window);
    m_window.EndDraw();
}

Window *Game::GetWindow() {
    return &m_window;
}

void Game::RestartClock() {
    m_elapsed += m_clock.restart();
}

sf::Time Game::GetElapsed() {
    return m_elapsed;
}
