#include <Game.hpp>
#include <fstream>
int main(){
    pb::Game game;
    while(!game.getWindow()->isDone()){
        game.update();
        game.render();
        game.handleInput();
    }

}