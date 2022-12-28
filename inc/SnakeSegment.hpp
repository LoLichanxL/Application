#include "SFML/System/Vector2.hpp"
#pragma once
class SnakeSegment{
public:
    SnakeSegment(int x, int y);
    sf::Vector2i position;
};