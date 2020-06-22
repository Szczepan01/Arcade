#include "enemybullet.h"

EnemyBullet::EnemyBullet(sf::Vector2f pos)
{
    vx = -300;
    setRadius(2);
    setFillColor(sf::Color(229, 0, 255));
    setPosition(pos.x,pos.y+30);

}

void EnemyBullet::update(const float dt)
{
    move(vx*dt,0);
    distance += vx*dt;
}

bool EnemyBullet::limits()
{
    if(distance <= -200)
    {
        return true;
    }
    return false;
}
