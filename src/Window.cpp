#include <Window.hpp>
#include "SFML/Window/Event.hpp"


pb::Window::Window(): m_window(new sf::RenderWindow()){
    setup("Window", sf::Vector2u(640, 480));
}

pb::Window::Window(const std::string &l_title, const sf::Vector2u &l_size):m_window(new sf::RenderWindow()) {
    setup(l_title, l_size);
}

pb::Window::~Window() {
    close();
    delete m_window;
}

bool pb::Window::isFullscreen() {
    return m_isFullscreen;
}

bool pb::Window::isDone() {
    return m_isDone;
}

void pb::Window::beginDraw() {
    m_window->clear(sf::Color::Black);
}

void pb::Window::endDraw() {
    m_window->display();
}

void pb::Window::update() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
            close();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
            toggleFullscreen();
        }
    }
}

sf::Vector2u pb::Window::getWindowSize() {
    return m_windowSize;
}

void pb::Window::toggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    close();
    create();
}

void pb::Window::draw(sf::Drawable &l_drawable) {
    m_window->draw(l_drawable);
}

void pb::Window::setup(const std::string &l_title, const sf::Vector2u &l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isDone = false;
    m_isFullscreen = false;
    create();
}

void pb::Window::close() {
    m_window->close();
}

void pb::Window::create() {
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window -> create({m_windowSize.x, m_windowSize.y, 32},m_windowTitle, style);
    m_window->setFramerateLimit(120);
}


