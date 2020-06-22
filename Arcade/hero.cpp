#include "hero.h"

Hero::Hero(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Miss.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->t1.loadFromFile("Textury/3_HP.png");
    this->t2.loadFromFile("Textury/2_HP.png");
    this->t3.loadFromFile("Textury/1_HP.png");
    hp_texture(hero_HP);
    this->hp.setPosition(pos.x-250, pos.y-65);
    this->hp.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

Hero::Hero(const std::string filename, sf::Vector2f scale,sf::Vector2f pos){

    this->texture.loadFromFile("Textury/" + filename);
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    this->t1.loadFromFile("Textury/3_HP.png");
    this->t2.loadFromFile("Textury/2_HP.png");
    this->t3.loadFromFile("Textury/1_HP.png");
    hp_texture(hero_HP);
    this->hp.setPosition(pos.x-250, pos.y-65);
    this->hp.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

void Hero::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
    window->draw(this->hp);
}

sf::Vector2f Hero::hero_get_position()
{
    return this->sprite.getPosition();
}

sf::Vector2f Hero::HP_get_position()
{
    return this->hp.getPosition();
}

void Hero::update_physics_hp(const float dt)
{
    this->hp_horizontal(dt);
}

void Hero::hp_horizontal(const float dt)
{
    this->move(sf::Vector2f(hpSpeed.x * dt, 0));
    auto pos_hp = hp.getPosition().x;
    auto pos_hero = sprite.getPosition().x;
    hp.setPosition(pos_hero - 250,0);
}

void Hero::hp_texture(int hero_HP)
{
    if(hero_HP == 3)
    {
        this->hp.setTexture(t1);
    }
    if(hero_HP == 2)
    {
        this->hp.setTexture(t2);
    }
    if(hero_HP == 1)
    {
        this->hp.setTexture(t3);
    }
}

void Hero::update_physics(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->process_horizontal(dt, map_ref);
    this->process_vertical(dt, map_ref);
}






