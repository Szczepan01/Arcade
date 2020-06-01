#ifndef MAINGAME_H
#define MAINGAME_H
#include "SFML/Graphics.hpp"
#include <memory>
#include "gamemap.h"
#include "hero.h"

class GameMap;
class Hero;

class MainGame
{
public:
    MainGame();
    void run();

private:
    std::shared_ptr<sf::RenderWindow> ptr_window;
    std::shared_ptr<GameMap> map;
    std::shared_ptr<Hero> hero;

    void process_events();
    void render();
    void draw_objects();
    void update_physics();
};


#endif
