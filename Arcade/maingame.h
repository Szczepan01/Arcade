#ifndef MAINGAME_H
#define MAINGAME_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "gamemap.h"
#include "hero.h"
#include "enemy.h"
#include "physics.h"
#include "bullet.h"
#include <memory>
#include <iostream>

class GameMap;
class Hero;
class Enemy;
class Bullet;
class Hero_HP;

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
    std::shared_ptr<Enemy> enemy;
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullet;

    std::vector<Enemy*>::iterator it;
    std::vector<Bullet*>::iterator b_it;

    void process_events();
    void render();
    void is_collision();
    void shot();
    void shot_collision();
    void is_win();

    sf::Clock clock;
    sf::Time time;

    float speed_default_val_x = 120;
    float gravity_speed = 60;


};


#endif
