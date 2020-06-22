#include "bossbullet.h"

BossBullet::BossBullet(sf::Vector2f pos)
{
    vx = -150;
    setRadius(5);
    setFillColor(sf::Color(229, 0, 255));
    setPosition(pos.x,pos.y+30);
}

void BossBullet::update(const float dt)
{
    move(vx*dt,0);
    distance += vx*dt;
}

bool BossBullet::limits()
{
    if(distance <= -200)
    {
        return true;
    }
    return false;
}
