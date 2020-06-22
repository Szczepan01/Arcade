#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"

class BossBullet:public sf::CircleShape
{
public:
    BossBullet(sf::Vector2f pos);

    void update(const float dt);

    bool limits();

private:
    float vx;
    float distance = 0;
};

#endif // BOSSBULLET_H
