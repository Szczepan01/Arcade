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

    sf::Vector2f get_position();
    void set_position(const sf::Vector2f pos);

    int hero_HP = 3;

private:
    sf::Texture texture;



    // sf::Vector2f position;  - usunięcie redundancji - positino wykorzystujemy z sprite'a
};

#endif // HERO_H
