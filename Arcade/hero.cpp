#include "hero.h"

Hero::Hero(sf::Vector2f scale, sf::Vector2f pos)
{
    animation_clock.restart();
    this->idle.loadFromFile("Textury/Miss.png");
    this->move_h.loadFromFile("Textury/Miss_move.png");
    this->attack.loadFromFile("Textury/Miss_shot.png");
    this->attack_move.loadFromFile("Textury/Miss_shot_move.png");
    this->sprite.setTexture(idle);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    hp_load();
    hp_texture(hero_HP);

    b_hp_load();
    b_hp_texture(boss_hp);

    this->hp.setPosition(pos.x-250, pos.y-65);
    this->hp.setScale(scale);

    this->b_hp.setPosition(pos.x+214, pos.y-65);
    this->b_hp.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

Hero::Hero(const std::string filename, sf::Vector2f scale,sf::Vector2f pos)
{
    animation_clock.restart();
    this->idle.loadFromFile("Textury/" + filename);
    this->move_h.loadFromFile("Textury/Miss_move.png");
    this->attack.loadFromFile("Textury/Miss_shot.png");
    this->attack_move.loadFromFile("Textury/Miss_shot_move.png");
    this->sprite.setTexture(idle);
    this->sprite.setPosition(pos);
    this->sprite.setScale(scale);

    hp_load();
    hp_texture(hero_HP);

    b_hp_load();
    b_hp_texture(boss_hp);

    this->hp.setPosition(pos.x-250, pos.y-65);
    this->hp.setScale(scale);

    this->b_hp.setPosition(pos.x+214, pos.y-65);
    this->b_hp.setScale(scale);

    this->set_speed(sf::Vector2f(0, 0));
}

void Hero::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sprite);
    window->draw(this->hp);
    window->draw(this->b_hp);
}

sf::Vector2f Hero::hero_get_position()
{
    return this->sprite.getPosition();
}

sf::Vector2f Hero::HP_get_position()
{
    return this->hp.getPosition();
}

sf::Vector2f Hero::Boss_hp_get_position()
{
    return this->b_hp.getPosition();
}

void Hero::update_physics_hp(const float dt)
{
    this->hp_horizontal(dt);
}

void Hero::hp_horizontal(const float dt)
{
    auto pos_hp = hp.getPosition().x;
    auto pos_hero = sprite.getPosition().x;
    hp.setPosition(pos_hero - 250,0);
}

void Hero::hp_load()
{
    this->t1.loadFromFile("Textury/3_HP.png");
    this->t2.loadFromFile("Textury/2_HP.png");
    this->t3.loadFromFile("Textury/1_HP.png");
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

void Hero::update_physics_boss_hp(const float dt)
{
    this->boss_hp_horizontal(dt);
}

void Hero::boss_hp_horizontal(const float dt)
{
    auto pos_boss_hp = b_hp.getPosition().x;
    auto pos_hero = sprite.getPosition().x;
    b_hp.setPosition(pos_hero +214,0);
}

void Hero::b_hp_texture(int boss_hp)
{
    if(boss_hp == 1){this->b_hp.setTexture(b1);}
    if(boss_hp == 2){this->b_hp.setTexture(b2);}
    if(boss_hp == 3){this->b_hp.setTexture(b3);}
    if(boss_hp == 4){this->b_hp.setTexture(b4);}
    if(boss_hp == 5){this->b_hp.setTexture(b5);}
    if(boss_hp == 6){this->b_hp.setTexture(b6);}
    if(boss_hp == 7){this->b_hp.setTexture(b7);}
    if(boss_hp == 8){this->b_hp.setTexture(b8);}
    if(boss_hp == 9){this->b_hp.setTexture(b9);}
    if(boss_hp == 10){this->b_hp.setTexture(b10);}
    if(boss_hp == 11){this->b_hp.setTexture(b11);}
    if(boss_hp == 12){this->b_hp.setTexture(b12);}
    if(boss_hp == 13){this->b_hp.setTexture(b13);}
    if(boss_hp == 14){this->b_hp.setTexture(b14);}
    if(boss_hp == 15){this->b_hp.setTexture(b15);}
    if(boss_hp == 16){this->b_hp.setTexture(b16);}
    if(boss_hp == 17){this->b_hp.setTexture(b17);}
    if(boss_hp == 18){this->b_hp.setTexture(b18);}
    if(boss_hp == 19){this->b_hp.setTexture(b19);}
    if(boss_hp == 20){this->b_hp.setTexture(b20);}
}

void Hero::b_hp_load()
{
    this->b1.loadFromFile("Textury/01.png");
    this->b2.loadFromFile("Textury/02.png");
    this->b3.loadFromFile("Textury/03.png");
    this->b4.loadFromFile("Textury/04.png");
    this->b5.loadFromFile("Textury/05.png");
    this->b6.loadFromFile("Textury/06.png");
    this->b7.loadFromFile("Textury/07.png");
    this->b8.loadFromFile("Textury/08.png");
    this->b9.loadFromFile("Textury/09.png");
    this->b10.loadFromFile("Textury/10.png");
    this->b11.loadFromFile("Textury/11.png");
    this->b12.loadFromFile("Textury/12.png");
    this->b13.loadFromFile("Textury/13.png");
    this->b14.loadFromFile("Textury/14.png");
    this->b15.loadFromFile("Textury/15.png");
    this->b16.loadFromFile("Textury/16.png");
    this->b17.loadFromFile("Textury/17.png");
    this->b18.loadFromFile("Textury/18.png");
    this->b19.loadFromFile("Textury/19.png");
    this->b20.loadFromFile("Textury/20.png");
}

void Hero::set_animation(int animation_number)
{
    if(animation_number >= 0 && animation_number <= 4)
    {
        this->current_animation = animation_number;
    }
    else
    {
        this->current_animation = 0;
    }
    animation_clock.restart();

    if(current_animation == 0)
    {
        this->sprite.setTexture(idle);
    }
    else if(current_animation == 1 || current_animation == 2)
    {
        this->sprite.setTexture(move_h);
    }
    else if(current_animation == 3)
    {
        this->sprite.setTexture(attack);
    }
    else if(current_animation == 4)
    {
        this->sprite.setTexture(attack_move);
    }
    this->sprite.setTextureRect(sf::Rect(0,0,20,25));
}

void Hero::update_animation()
{
    animation_time += animation_clock.restart();
    float move_frame_time = 0.05f;
    float attack_frame_time = 0.15f;
    float move_attack_frame_time = 0.05f;
    int current_frame = 0;

    if(current_animation == 1 || current_animation == 2)
    {
        if(animation_time.asSeconds() > move_frame_time*move_h.getSize().x/20)
        {
            animation_time = sf::Time::Zero;
        }
        current_frame = animation_time.asSeconds()/move_frame_time;
        if(current_frame >= move_h.getSize().x/20)
        {
            current_frame = 0;

        }
    }
    else if(current_animation == 3)
    {
        if(animation_time.asSeconds() > attack_frame_time*attack.getSize().x/20)
        {
            animation_time = sf::Time::Zero;
        }
        current_frame = animation_time.asSeconds()/attack_frame_time;
        if(current_frame >= attack.getSize().x/20)
        {
            current_frame = 0;
        }
    }
    else if(current_animation == 4)
    {
        if(animation_time.asSeconds() > move_attack_frame_time*attack_move.getSize().x/20)
        {
            animation_time = sf::Time::Zero;
        }
        current_frame = animation_time.asSeconds()/move_attack_frame_time;
        if(current_frame >= attack_move.getSize().x/20)
        {
            current_frame = 0;
        }
    }
    if(current_animation != 2)
    {
         this->sprite.setTextureRect(sf::Rect(current_frame*20,0,20,25));
    }
    else
    {
         this->sprite.setTextureRect(sf::Rect((current_frame+1)*20,0,-20,25));
    }
}

void Hero::update_physics(const float dt, std::shared_ptr<GameMap> map_ref)
{
    this->process_horizontal(dt, map_ref);
    this->process_vertical(dt, map_ref);
}






