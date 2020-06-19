#include "hero.h"

Hero::Hero(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Riven.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

Hero::Hero(const std::string filename, sf::Vector2f scale,sf::Vector2f pos){

    this->texture.loadFromFile("Textury/" + filename);
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

void Hero::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
}

sf::Vector2f Hero::get_position()
{
    return this->sprite.getPosition();
}

void Hero::set_position(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}



