#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"


class Bullet:public sf::CircleShape
{
public:
    Bullet(sf::Vector2f pos);

    void update(const float dt);

    bool limits();

private:
    float vx;
    float distance = 0;
};

#endif // BULLET_H
