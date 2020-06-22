#include "enemy.h"

Enemy::Enemy(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Mag.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->set_speed(sf::Vector2f(-50, 0));
    distance = 0;
}

void Enemy::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
}

sf::Vector2f Enemy::get_position()
{
    return this->sprite.getPosition();
}

void Enemy::update_physics(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->process_horizontal(dt, map_ref);
    this->process_vertical(dt, map_ref);
}

void Enemy::set_position(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

void Enemy::set_vx(sf::Time t)
{
    this->distance += speed.x*t.asSeconds();
    if(distance > 100 || distance < -100)
    {
        this->distance = 0;
        speed.x = -speed.x;
    }
}

