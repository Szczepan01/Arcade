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

    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(380,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(490,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(800,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1010,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1240,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1510,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1640,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(2000,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(2200,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(3000,0)));

}

void MainGame::run()
{
    sf::Clock clock;
    std::srand(std::time(NULL));

    this->hero->set_vx(0);
    this->hero->set_vy(gravity_speed);

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
        this->hero->update_physics_hp(dt.asSeconds());



        for(auto en : enemies)
        {
            en->update_physics(dt.asSeconds(), this->map);
        }

        for(auto bu : bullet)
        {
            bu->update(dt.asSeconds());
        }
        shot();
        shot_collision();
        main_view.setCenter(this->hero->hero_get_position().x, 90);
        this->ptr_window->setView(main_view);
        render();
        is_collision();
        is_win();
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

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            this->hero->set_vx(speed_default_val_x);

        }
        else if(Keyboard::isKeyPressed(Keyboard::A))
        {
            this->hero->set_vx(-speed_default_val_x);

        }
        if(event.type == Event::KeyReleased)
        {
            if(event.key.code == Keyboard::D || event.key.code == Keyboard::A)
            {
                this->hero->set_vx(0);

            }
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            bullet.emplace_back(new Bullet(hero->sprite.getPosition()));
        }

        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            this->hero->jump(map);
        }
    }
}


void MainGame::render()
{
    ptr_window->clear(sf::Color::Black);
    map->draw_(ptr_window);
    hero->draw(ptr_window);
    for(auto en : enemies)
    {
        ptr_window->draw(en->sprite);
    }
    for(auto bu : bullet)
    {
        ptr_window->draw(*bu);
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
    for ( it = enemies.begin(); it != enemies.end(); )
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
        ++it;
    }
}

void MainGame::is_win()
{
    if(enemies.size() <= 1)
    {
        std::cout<<"!!!     YOU WIN     !!!"<<std::endl;
        std::cout<<"!!! CONGRATULATIONS !!!"<<std::endl;
        ptr_window->close();
    }
}


