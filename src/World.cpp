#include <iostream>
#include "World.hpp"

void World::render(sf::RenderWindow* l_window) {
    for(int i = 0; i < 4; ++i){
        l_window->draw(m_bounds[i]);
    }
    for(int i = 0; i < 15; i++){
        l_window->draw(m_random_bounds[i]);
    }
    l_window->draw(m_appleShape);
}

World::World(sf::Vector2u screenSize) {
    m_blockSize = 24;
    m_screenSize = screenSize;
    generateBounds();
    respawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    for (int i = 0; i < 4; ++i) {
        m_bounds[i].setFillColor(sf::Color(150, 0, 0));
        if (!((i + 1) % 2)) {
            m_bounds[i].setSize(sf::Vector2f(m_screenSize.x, m_blockSize));
        } else {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_screenSize.y));
        }
        if (i < 2) {
            m_bounds[i].setPosition(0, 0);
        } else {
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(sf::Vector2f(m_screenSize));
        }
    }
}

void World::respawnApple() {
    srand(time(NULL));
    int maxX = (m_screenSize.x / m_blockSize) - 2;
    int maxY = (m_screenSize.y / m_blockSize) - 2;
    bool flag = true;
    int result_x;
    int result_y;
    while(flag){
        bool c = false;
        int x = (rand() % maxX + 1);
        int y = (rand() % maxY + 1);

        for(int i = 0; i < 15; i++){
            if(x == m_random_bounds[i].getPosition().x / m_blockSize && y == m_random_bounds[i].getPosition().y / m_blockSize){
                c = true;
            }
        }
        if(!c){
            result_x = x;
            result_y = y;
            m_item = sf::Vector2i(x, y);
            flag = false;
        }
    }
    std::cout << result_x << " " << result_y << std::endl;
    m_appleShape.setPosition(result_x * m_blockSize,result_y * m_blockSize);

}

void World::update(Snake *l_player) {
    if (l_player->getPosition() == m_item) {
        l_player->extend();
        l_player->increaseScore();
        respawnApple();
    }
    int gridSize_x = m_screenSize.x / m_blockSize;
    int gridSize_y = m_screenSize.y / m_blockSize;

    if (l_player->getPosition().x <= 0 ||
            l_player->getPosition().y <= 0 ||
            l_player->getPosition().x >= gridSize_x - 1 ||
            l_player->getPosition().y >= gridSize_y - 1) {
        l_player->lose();
        generateBounds();
        respawnApple();
    }
    for(int i = 0; i < 15; i++){
        if(l_player->getPosition().x  == m_random_bounds[i].    getPosition().x / m_blockSize
            && l_player->getPosition().y == m_random_bounds[i].getPosition().y / m_blockSize){
            l_player->lose();
            generateBounds();
            respawnApple();
        }
    }
}

int World::getBlockSize() {
    return m_blockSize;
}

void World::generateBounds() {
    int gridSize_x = m_screenSize.x / (m_blockSize);
    int gridSize_y = m_screenSize.y / (m_blockSize);
    srand(time(NULL));
    for(int i = 0; i < 15; i++){
        int randX = (rand() % (gridSize_x - 2)) + 1;
        int randY = (rand() % (gridSize_y - 2)) + 1;
        std::cout << randX << " " << randY << std::endl;
        m_random_bounds[i].setFillColor(sf::Color(150, 100, 0));
        m_random_bounds[i].setSize(sf::Vector2f(m_blockSize, m_blockSize));
        m_random_bounds[i].setPosition(sf::Vector2f(randX * m_blockSize, randY * m_blockSize));
    }

}
