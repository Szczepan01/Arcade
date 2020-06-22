#ifndef HERO_H
#define HERO_H

#include "gamemap.h"

#include "physics.h"

#include "SFML/Graphics.hpp"

#include <iostream>

#include <memory>

class Hero:public physics
{
public:
    Hero(sf::Vector2f scale,sf::Vector2f pos);

    Hero(const std::string filename,sf::Vector2f scale,sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::Vector2f hero_get_position();
    sf::Vector2f HP_get_position();
    sf::Vector2f Boss_hp_get_position();

    void update_physics_hp(const float dt);
    void hp_horizontal(const float dt);
    void hp_load();
    void hp_texture(int hero_HP);

    void update_physics_boss_hp(const float dt);
    void boss_hp_horizontal(const float dt);
    void b_hp_texture(int boss_hp);
    void b_hp_load();

    void set_animation(int animation_number);
    void update_animation();

    virtual void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);

    int hero_HP = 3;
    int boss_hp = 20;
    int current_animation = 0;
    sf::Time animation_time = sf::Time::Zero;

    sf::Clock animation_clock;

private:
    sf::Texture t1, t2, t3;
    sf::Texture b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20;
    sf::Texture idle, move_h, attack, attack_move;
    sf::Sprite hp;
    sf::Sprite b_hp;
};

#endif // HERO_H
