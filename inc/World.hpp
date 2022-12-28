#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "Snake.hpp"

class World{
public:
    World(sf::Vector2u screenSize);
    void render(sf::RenderWindow* l_window);
    void respawnApple();
    void update(Snake* l_player);
    int getBlockSize();

private:
    sf::Vector2u m_screenSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];


};