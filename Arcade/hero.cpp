#include "hero.h"

Hero::Hero(sf::Vector2f scale, sf::Vector2f pos)
{
    this->texture.loadFromFile("Textury/Riven.png");
    my_hero.setTexture(texture);
    my_hero.setPosition(pos);
    my_hero.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

Hero::Hero(const std::string filename,sf::Vector2f scale,sf::Vector2f pos){

    this->texture.loadFromFile("Textury/" + filename);
    my_hero.setTexture(texture);
    my_hero.setPosition(pos);
    my_hero.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

void Hero::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(my_hero);
}

sf::Vector2f Hero::get_position()
{
    return my_hero.getPosition();
}

void Hero::set_position(const sf::Vector2f pos)
{
    my_hero.setPosition(pos);
}

void Hero::move(const sf::Vector2f d)
{
    my_hero.move(d);
}

void Hero::jump(std::shared_ptr<GameMap> map_ref)
{
    auto pos = this->my_hero.getPosition();
    auto cur_h = pos.y + hero_h; // bottom edge of the hero
    auto surface_h = map_ref->check_height(pos.x);

    if(cur_h == surface_h)
    {
        this->speed.y = -120; // zasięg skoku
    }

}

void Hero::update_physics(const float dt, std::shared_ptr<GameMap> map_ref)
{

    this->process_horizontal(dt, map_ref);
    this->process_vertical(dt, map_ref);
}

void Hero::process_horizontal(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->move(sf::Vector2f(speed.x * dt, 0));
    const auto current_y = my_hero.getPosition().y + hero_h;


    auto pos = my_hero.getPosition();
    auto cur_h = 0.0;
    if (speed.x >= 0){
        cur_h = map_ref->check_height(pos.x+hero_w);
    }
    else{
        cur_h = map_ref->check_height(pos.x);
    }

    if (pos.y + hero_h > cur_h){
        this->move(sf::Vector2f(-speed.x*dt, 0));
    }
}

void Hero::process_vertical(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->move(sf::Vector2f(0, speed.y * dt));
    auto pos = my_hero.getPosition();


    auto max_height = map_ref->check_height(pos.x, pos.x + hero_w);
    if (pos.y+hero_h > max_height)
    {
        my_hero.setPosition(pos.x, max_height-hero_h);
    }



    auto gravity = 60;
    auto dg = 100;
    if (this->speed.y < gravity)
    {
        this->speed.y+= dg * dt;
    }
}

