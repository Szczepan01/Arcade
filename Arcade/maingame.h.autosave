#ifndef MAINGAME_H
#define MAINGAME_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "gamemap.h"

class MainGame
{
public:
    MainGame();
    void run();

private:
    std::shared_ptr<sf::RenderWindow> ptr_window;
    std::shared_ptr<GameMap> map;

    void process_events();
    void draw_map();
    void draw_objects();
    void update_physics();
};


#endif
