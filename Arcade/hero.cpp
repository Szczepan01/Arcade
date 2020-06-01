#include "hero.h"

Hero::Hero(sf::Vector2f scale,sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Riven.png");
    my_hero.setTexture(texture);
    my_hero.setPosition(pos);
    my_hero.setScale(scale);
}

Hero::Hero(const std::string filename,sf::Vector2f scale,sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/" + filename);
    my_hero.setTexture(texture);
    my_hero.setPosition(pos);
    my_hero.setScale(scale);

    speed_x_ = 0;
    speed_y_ = 0;

    this->position = pos;
}

void Hero::speed(int speed_x, int speed_y)
{
    speed_x_ = speed_x;
    speed_y_ = speed_y;
}

void Hero::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(my_hero);
}
