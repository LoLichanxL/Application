#pragma once

#include <string>
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

class TextBox{
public:
    ~TextBox();
    TextBox();
    TextBox(int l_visible, int l_charSize,int l_width, sf::Vector2f l_screenPos);
    void setup(int l_visible, int l_charSize,int l_width, sf::Vector2f l_screenPos);
    void add(std::string l_message);
    void clear();
    void render(sf::RenderWindow* l_window);
private:
    std::vector<std::string> m_messages;
    sf::RectangleShape m_backdrop;
    sf::Text m_content;
    sf::Font m_font;
    int m_numVisible;
};