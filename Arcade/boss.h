#ifndef BOSS_H
#define BOSS_H
#include "gamemap.h"

#include "physics.h"

#include "SFML/Graphics.hpp"

#include <iostream>

#include <memory>

class Boss:public physics
{
public:
    Boss(sf::Vector2f scale, sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::Vector2f get_position();

    virtual void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);

private:
    sf::Texture texture;
};

#endif // BOSS_H
