#include <Game.hpp>
#include <iomanip>
#include <thread>
#include <chrono>

namespace pb{
    Game::Game() : m_window(new pb::Window("Game", sf::Vector2u(800, 600))){

    }

    Game::~Game() {
        delete m_window;
    }

    void Game::handleInput() {

    }

    void Game::update() {
        m_window->update();
    }

    void Game::render() {
        m_window->beginDraw();
        m_window->endDraw();
    }

    pb::Window* Game::getWindow() {
        return m_window;
    }
}

