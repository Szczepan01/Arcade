#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"

class EnemyBullet:public sf::CircleShape
{
public:
    EnemyBullet(sf::Vector2f pos);

    void update(const float dt);

    bool limits();

private:
    float vx;
    float distance = 0;
};

#endif // ENEMYBULLET_H
