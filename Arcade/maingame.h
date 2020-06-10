#ifndef MAINGAME_H
#define MAINGAME_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "gamemap.h"
#include "hero.h"
#include <memory>
#include <iostream>

class GameMap;
class Hero;

class MainGame
{
public:
    MainGame();
    void run();

private:
    std::shared_ptr<sf::RenderWindow> ptr_window;

    sf::View main_view;

    std::shared_ptr<GameMap> map;
    std::shared_ptr<Hero> hero;

    void process_events();
    void render();

    sf::Clock clock;
    sf::Time time;

    float speed_default_val_x = 120;
    float gravity_speed = 60;
};


#endif
