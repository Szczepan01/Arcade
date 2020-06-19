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

   // Enemy(const std::string filename,sf::Vector2f scale,sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::Vector2f get_position();
    void set_position(const sf::Vector2f pos);

private:
    sf::Texture texture;

};

#endif // ENEMY_H
