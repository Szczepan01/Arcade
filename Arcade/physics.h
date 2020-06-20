#ifndef PHYSICS_H
#define PHYSICS_H
#include "gamemap.h"

#include "SFML/Graphics.hpp"

#include <iostream>

#include <memory>


class physics:public sf::Sprite
{
public:
    physics();

    sf::Vector2f get_speed(){return speed;}
    void set_speed(sf::Vector2f v){speed=v;}
    void set_vx(float vx){speed.x=vx;}
    void set_vy(float vy){speed.y=vy;}

    void move(const sf::Vector2f d);
    void jump(std::shared_ptr<GameMap> map_ref);
    void draw(sf::RenderTarget &target, sf::RenderStates states);

    void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);

    sf::Sprite sprite;

private:

    sf::Vector2f speed;

    void process_horizontal(const float dt, std::shared_ptr<GameMap> map_ref);
    void process_vertical(const float dt, std::shared_ptr<GameMap> map_ref);

    const static auto ob_h = 50;
    const static auto ob_w = 40;


};

#endif // PHYSICS_H
