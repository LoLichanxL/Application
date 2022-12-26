#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

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
    };

}
