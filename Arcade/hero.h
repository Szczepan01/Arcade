#ifndef HERO_H
#define HERO_H

#include "gamemap.h"

#include "SFML/Graphics.hpp"

#include <iostream>

#include <memory>


class Hero: public sf::Sprite
{
public:
    Hero(sf::Vector2f scale,sf::Vector2f pos);

    Hero(const std::string filename,sf::Vector2f scale,sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::Vector2f get_speed(){return speed;}
    void set_speed(sf::Vector2f v){speed=v;}
    void set_vx(float vx){speed.x=vx;}
    void set_vy(float vy){speed.y=vy;}

    sf::Vector2f get_position();
    void set_position(const sf::Vector2f pos);
    void move(const sf::Vector2f d);
    void jump(std::shared_ptr<GameMap> map_ref);

    void update_physics(const float dt, std::shared_ptr<GameMap> map_ref);

private:
    sf::Texture texture;
    sf::Sprite my_hero;
    sf::Vector2f speed;

    const static auto hero_h = 50;
    const static auto hero_w = 40;

    void process_horizontal(const float dt, std::shared_ptr<GameMap> map_ref);
    void process_vertical(const float dt, std::shared_ptr<GameMap> map_ref);
};

#endif // HERO_H
