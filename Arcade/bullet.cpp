#include "bullet.h"

Bullet::Bullet(sf::Vector2f pos)
{
    vx = 300;
    setRadius(2);
    setFillColor(sf::Color::Yellow);
    setPosition(pos.x+20,pos.y+30);

}

void Bullet::update(const float dt)
{
    move(vx*dt,0);
    distance += vx*dt;
}

bool Bullet::limits()
{
    if(distance >= 200)
    {
        return true;
    }
    return false;
}

