#ifndef MAINGAME_H
#define MAINGAME_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "gamemap.h"
#include "hero.h"
#include "enemy.h"
#include "physics.h"
#include "bullet.h"
#include "enemybullet.h"
#include "audio.h"
#include "boss.h"
#include "bossbullet.h"
#include <memory>
#include <iostream>

class GameMap;
class Hero;
class Enemy;
class Bullet;
class Hero_HP;
class EnemyBullet;
class Audio;
class Boss;
class BossBullet;

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
    std::shared_ptr<Boss> boss;
    std::vector<Bullet*> bullet;
    std::vector<EnemyBullet*> enbu;
    std::vector<BossBullet*> bb;

    std::vector<Enemy*>::iterator it;
    std::vector<Bullet*>::iterator b_it;
    std::vector<EnemyBullet*>::iterator enbu_it;
    std::vector<BossBullet*>::iterator bb_it;

    void process_events();
    void render();
    void is_collision();
    void shot();
    void shot_collision();
    void enemy_shot();
    void enemy_shot_collision();
    void is_win();

    sf::Clock clock;
    sf::Time time;

    Audio audio;

    float speed_default_val_x = 120;
    float gravity_speed = 120;
    float enShotTime;
    float bossShotTime;


};


#endif
