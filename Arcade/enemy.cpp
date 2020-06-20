#include "enemy.h"

Enemy::Enemy(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Mag.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

void Enemy::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
}

sf::Vector2f Enemy::get_position()
{
    return this->sprite.getPosition();
}

void Enemy::set_position(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

