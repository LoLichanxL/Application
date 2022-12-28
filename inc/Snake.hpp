#include <Direction.hpp>
#include <SnakeSegment.hpp>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#pragma once
class Snake{
public:

    Snake(int l_blockSize);
    void setDirection(Direction l_dir);
    Direction getDirection();
    int getLives();
    int getScore();
    int getSpeed();
    bool hasLost();
    sf::Vector2i getPosition();
    void increaseScore();
    void extend();
    void lose();
    void toggleLost();
    void reset();
    void move();
    void tick();
    void cut(int l_segments);
    void render(sf::RenderWindow* l_window);

private:

    void checkCollision();
    int m_size;
    Direction m_dir;
    int m_speed;
    int m_lives;
    int m_score;
    bool m_lost;
    int m_tics = 0;
    std::vector<SnakeSegment> m_snakeBody;
    sf::RectangleShape m_bodyRect;



};

