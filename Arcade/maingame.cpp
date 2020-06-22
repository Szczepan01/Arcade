#include "maingame.h"

using namespace sf;

MainGame::MainGame()
{

    this->ptr_window = std::make_shared<RenderWindow>(VideoMode(500, 180), "Window");
    this->ptr_window->setFramerateLimit(60);
    this->ptr_window->setSize(sf::Vector2u(1366, 760));
    this->ptr_window->setPosition(sf::Vector2i(280, 130));

    main_view = this->ptr_window->getDefaultView();
    this->ptr_window->setView(main_view);

    this->map = std::make_shared<GameMap>("Mapa.png");
    this->hero = std::make_shared<Hero>(std::string("Miss.png"),
                                        sf::Vector2f(2.0, 2.0),
                                        sf::Vector2f(70, 65));
    this->hero->set_animation(0);


    this->boss = std::make_shared<Boss>(sf::Vector2f(2.0, 2.0),
                                        sf::Vector2f(2250,0));

    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(380,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(540,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(800,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1010,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1240,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1510,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1640,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(2000,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(3000,0)));

    enShotTime = 0;
    bossShotTime = 0;
}

void MainGame::run()
{
    sf::Clock clock;

    audio.melody();
    this->hero->set_vx(0);
    this->hero->set_vy(gravity_speed);
    this->boss->set_vx(0);
    this->boss->set_vy(gravity_speed);


    for(auto en : enemies)
    {
        en->set_vy(gravity_speed);
    }

    while(ptr_window->isOpen())
    {

        process_events();


        auto dt = clock.getElapsedTime();
        clock.restart();

        this->hero->update_physics(dt.asSeconds(), this->map);
        this->boss->update_physics(dt.asSeconds(), this->map);
        this->hero->update_physics_hp(dt.asSeconds());
        this->hero->update_physics_boss_hp(dt.asSeconds());

        this->hero->update_animation();

        for(auto en : enemies)
        {
            en->set_vx(dt);
        }
        for(auto en : enemies)
        {
            en->update_physics(dt.asSeconds(), this->map);
        }

        for(auto bu : bullet)
        {
            bu->update(dt.asSeconds());
        }

        for(auto bu : enbu)
        {
            bu->update(dt.asSeconds());
        }
        for(auto b : bb)
        {
            b->update(dt.asSeconds());
        }

        shot();
        shot_collision();
        enemy_shot();
        enemy_shot_collision();
        main_view.setCenter(this->hero->hero_get_position().x, 90);
        this->ptr_window->setView(main_view);
        render();
        is_collision();
        if(!ptr_window->isOpen())
        {
            break;
        }
    }
}



void MainGame::process_events()
{
    Event event;

    while(ptr_window->pollEvent(event))
    {
        if(event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape)))
        {
            ptr_window->close();
        }


        if(event.type == Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Enter)
            {
                this->hero->set_animation(3);
                if(bullet.size() <= 1)
                {
                bullet.emplace_back(new Bullet(hero->sprite.getPosition()));
                audio.shot();
                }

            }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            this->hero->set_vx(speed_default_val_x);
            this->hero->set_animation(1);

        }
        else if(Keyboard::isKeyPressed(Keyboard::A))
        {
            this->hero->set_vx(-speed_default_val_x);
            this->hero->set_animation(2);
        }

        if((Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A)) && Keyboard::isKeyPressed(Keyboard::Enter))
        {
            this->hero->set_animation(4);
            if(bullet.size() <= 1)
            {
            bullet.emplace_back(new Bullet(hero->sprite.getPosition()));
            audio.shot();
            }

        }

        if(event.type == Event::KeyReleased)
        {
            if(event.key.code == Keyboard::D || event.key.code == Keyboard::A)
            {
                this->hero->set_vx(0);
                this->hero->set_animation(0);
            }
            if(event.key.code == Keyboard::Enter)
            {
                if(Keyboard::isKeyPressed(Keyboard::D))
                {
                    this->hero->set_animation(1);
                }
                else if(Keyboard::isKeyPressed(Keyboard::A))
                {
                    this->hero->set_animation(2);
                }
                else
                {
                    this->hero->set_animation(0);
                }

            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            this->hero->jump(map);
        }
    }
}


void MainGame::render()
{
    ptr_window->clear(sf::Color(29, 204,231));
    map->draw_(ptr_window);
    hero->draw(ptr_window);
    boss->draw(ptr_window);
    for(auto en : enemies)
    {
        ptr_window->draw(en->sprite);
    }
    for(auto bu : bullet)
    {
        ptr_window->draw(*bu);
    }
    for(auto eb : enbu)
    {
        ptr_window->draw(*eb);
    }
    for(auto b : bb)
    {
        ptr_window->draw(*b);
    }
    ptr_window->display();
}

void MainGame::is_collision()
{

    for ( it = enemies.begin(); it != enemies.end(); )
    {
        if(hero->sprite.getGlobalBounds().intersects((*it)->sprite.getGlobalBounds()))
        {
            it = enemies.erase(it);
            hero->hero_HP = hero->hero_HP -1;
            if(hero->hero_HP == 0)
            {
                std::cout<<"GAME OVER"<<std::endl;
                ptr_window->close();
            }
            this->hero->hp_texture(hero->hero_HP);
        }
        else {
            ++it;
        }
    }
    if(hero->sprite.getGlobalBounds().intersects(boss->sprite.getGlobalBounds()))
    {
        std::cout<<"GAME OVER"<<std::endl;
        ptr_window->close();
    }
}

void MainGame::shot()
{
    for ( b_it = bullet.begin(); b_it != bullet.end(); )
    {
        if((*b_it)->limits())
        {
            b_it = bullet.erase(b_it);
        }
        else {
            ++b_it;
        }
    }
}

void MainGame::shot_collision()
{
    for ( it = enemies.begin(); it != enemies.end();++it)
    {
        for( b_it = bullet.begin(); b_it != bullet.end();)
        {
            if((*b_it)->getGlobalBounds().intersects((*it)->sprite.getGlobalBounds()))
            {
                it = enemies.erase(it);
                b_it = bullet.erase(b_it);
            }
            else {
                ++b_it;
            }
        }
    }
    for(b_it = bullet.begin(); b_it != bullet.end();)
    {
        if((*b_it)->getGlobalBounds().intersects(boss->sprite.getGlobalBounds()))
        {
            b_it = bullet.erase(b_it);
            hero->boss_hp = hero->boss_hp - 1;
            if(hero->boss_hp <= 0)
            {
                is_win();
            }
            this->hero->b_hp_texture(hero->boss_hp);
        }
        else
        {
            ++b_it;
        }
    }
}

void MainGame::enemy_shot()
{
    for ( enbu_it = enbu.begin(); enbu_it != enbu.end(); )
    {
        if((*enbu_it)->limits())
        {
            enbu_it = enbu.erase(enbu_it);
        }
        else {
            ++enbu_it;
        }
    }
    if(enShotTime >100)
    {
        enShotTime = 0;
        for( it = enemies.begin(); it != enemies.end();it++)
        {
            enbu.emplace_back(new EnemyBullet((*it)->sprite.getPosition()));
            audio.enemy_shot();
        }
    }
    this->enShotTime++;

    for ( bb_it = bb.begin(); bb_it != bb.end(); )
    {
        if((*bb_it)->limits())
        {
            bb_it = bb.erase(bb_it);
        }
        else {
            ++bb_it;
        }
    }
    if(bossShotTime > 50)
    {
        bossShotTime = 0;
        bb.emplace_back(new BossBullet(boss->sprite.getPosition()));
        audio.enemy_shot();
    }
    this->bossShotTime++;
}

void MainGame::enemy_shot_collision()
{
    for(enbu_it = enbu.begin(); enbu_it != enbu.end();++enbu_it)
    {
        if((*enbu_it)->getGlobalBounds().intersects(hero->sprite.getGlobalBounds()))
        {
            enbu_it = enbu.erase(enbu_it);
            hero->hero_HP = hero->hero_HP -1;
            if(hero->hero_HP == 0)
            {
                std::cout<<"GAME OVER"<<std::endl;
                ptr_window->close();
            }
            this->hero->hp_texture(hero->hero_HP);
        }
    }

    for(bb_it = bb.begin(); bb_it != bb.end();++bb_it)
    {
        if((*bb_it)->getGlobalBounds().intersects(hero->sprite.getGlobalBounds()))
        {
            bb_it = bb.erase(bb_it);
            hero->hero_HP = hero->hero_HP -1;
            std::cout<<hero->hero_HP<<std::endl;
            if(hero->hero_HP == 0)
            {
                std::cout<<"GAME OVER"<<std::endl;
                ptr_window->close();
            }
            this->hero->hp_texture(hero->hero_HP);
        }
    }
}

void MainGame::is_win()
{
    std::cout<<"!!!     YOU WIN     !!!"<<std::endl;
    std::cout<<"!!! CONGRATULATIONS !!!"<<std::endl;
    ptr_window->close();
}



