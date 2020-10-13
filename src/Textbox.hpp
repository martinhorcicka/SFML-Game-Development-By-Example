#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Window.hpp"

using MessageContainer = std::vector<std::string>;

class Textbox {
   private:
   public:
    Textbox();
    Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    ~Textbox();

    void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    void Add(std::string l_message);
    void Clear();

    void Render(Window &l_window);

   private:
    MessageContainer m_messages;
    int m_numVisible;

    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};
