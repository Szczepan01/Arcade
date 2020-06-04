#ifndef HERO_H
#define HERO_H
#include "maingame.h"
#include "SFML/Graphics.hpp"

class Hero: public sf::Sprite
{
public:
    Hero(sf::Vector2f scale,sf::Vector2f pos);

    Hero(const std::string filename,sf::Vector2f scale,sf::Vector2f pos);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    void set_speed(int vx, int vy){speed_x_ = vx; speed_y_ = vy;}

    sf::Vector2f get_position();
    void set_position(const sf::Vector2f pos);
    void move(const sf::Vector2f d);

private:
    sf::Texture texture;
    sf::Sprite my_hero;

    sf::Vector2f position;

    void speed(int speed_x, int speed_y);
    void animation();

    int speed_x_;
    int speed_y_;
};

#endif // HERO_H
