#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "World.hpp"
#include "Snake.hpp"
#include "TextBox.hpp"

namespace pb{
    class Game{
    public:
        Game();
        ~Game();
        void handleInput();
        void update();
        void render();
        pb::Window* getWindow();
    private:
        pb::Window* m_window;
        TextBox text;
        World m_world;
        Snake m_snake;
        bool hasAlreadyLost;
    };

}
