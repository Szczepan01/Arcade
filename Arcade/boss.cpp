#include "boss.h"

Boss::Boss(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Boss.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);
}

void Boss::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
}

sf::Vector2f Boss::get_position()
{
    return this->sprite.getPosition();
}

void Boss::update_physics(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->process_horizontal(dt, map_ref);
    this->process_vertical(dt, map_ref);
}
