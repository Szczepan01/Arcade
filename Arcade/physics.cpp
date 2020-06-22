#include "physics.h"

physics::physics()
{

}

void physics::process_horizontal(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->move(sf::Vector2f(speed.x * dt, 0));

    auto pos = sprite.getPosition();
    auto cur_h = 0.0;
    if (speed.x >= 0){
        cur_h = map_ref->check_height(pos.x+ob_w);
    }
    else{
        cur_h = map_ref->check_height(pos.x);
    }

    if (pos.y + ob_h > cur_h){
        this->move(sf::Vector2f(-speed.x*dt, 0));
    }
}

void physics::process_vertical(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->move(sf::Vector2f(0, speed.y * dt));
    auto pos = sprite.getPosition();

    auto max_height = map_ref->check_height(pos.x, pos.x + ob_w);
    if (pos.y+ob_h > max_height)
    {
        sprite.setPosition(pos.x, max_height-ob_h);
    }

    auto gravity = 60;
    auto dg = 100;
    if (this->speed.y < gravity)
    {
        this->speed.y+= dg * dt;
    }
}

void physics::move(const sf::Vector2f d)
{
    sprite.move(d);
}

void physics::jump(std::shared_ptr<GameMap> map_ref)
{
    auto pos = this->sprite.getPosition();
    auto cur_h = pos.y + ob_h;
    auto surface_h = map_ref->check_height(pos.x);

    if(cur_h == surface_h)
    {
        this->speed.y = -120;
    }

}

