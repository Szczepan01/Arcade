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

    void update_physics_hp(const float dt);
    void hp_horizontal(const float dt);
    void hp_texture(int hero_HP);

    virtual void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);

    int hero_HP = 3;

private:
    sf::Texture texture, t1, t2, t3;
    sf::Sprite hp;
    sf::Vector2f hpSpeed;
};

#endif // HERO_H
