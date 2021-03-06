#ifndef ENEMY_H
#define ENEMY_H
#include "gamemap.h"

#include "physics.h"

#include "SFML/Graphics.hpp"

#include <iostream>

#include <memory>

class Enemy:public physics
{
public:
    Enemy(sf::Vector2f scale, sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::Vector2f get_position();

    virtual void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);
    void set_position(const sf::Vector2f pos);
    void set_vx(sf::Time t);


private:
    sf::Texture texture;
    float distance;

};

#endif // ENEMY_H
