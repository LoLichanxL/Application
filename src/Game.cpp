#include <Game.hpp>
#include <iomanip>
#include <thread>
#include <chrono>

namespace pb{
    Game::Game() : m_window(new pb::Window("Game", sf::Vector2u(800, 600))), m_snake(16), m_world(sf::Vector2u(800, 600)){

    }

    Game::~Game() {
        delete m_window;
    }

    void Game::handleInput() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
           && m_snake.getDirection() != Direction::Down)
        {
            m_snake.setDirection(Direction::Up);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                  && m_snake.getDirection() != Direction::Up)
        {
            m_snake.setDirection(Direction::Down);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                  && m_snake.getDirection() != Direction::Right)
        {
            m_snake.setDirection(Direction::Left);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                  && m_snake.getDirection() != Direction::Left)
        {
            m_snake.setDirection(Direction::Right);
        }
    }

    void Game::update() {
        m_snake.tick();
        m_world.update(&m_snake);
        if(m_snake.hasLost()){
            hasAlreadyLost = true;
            text.clear();
            text.add("Game over!");
            m_snake.reset();
        }else{
            if(m_snake.getDirection() == Direction::None && hasAlreadyLost == true){
                text.clear();
                text.add("Game over!");
            }else if (m_snake.getDirection() != Direction::None){
                std::string lives = "Current Lives:" + std::to_string(m_snake.getLives());
                std::string score = "Current Score:" + std::to_string(m_snake.getScore());
                text.clear();
                text.add(lives);
                text.add(score);
            }
        }
        m_window->update();
    }

    void Game::render() {
        m_window->beginDraw();
        m_world.render((*m_window).getRenderWindow());
        m_snake.render((*m_window).getRenderWindow());
        text.render((*m_window).getRenderWindow());
        m_window->endDraw();
    }

    pb::Window* Game::getWindow() {
        return m_window;
    }
}

