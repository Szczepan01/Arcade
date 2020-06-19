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

    /*this->enemy = std::make_shared<Enemy>(std::string("Mag.png"),
                                           sf::Vector2f(2.0,2.0)
                                           );*/
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(380,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(800,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1010,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1240,0)));
    enemies.emplace_back(new Enemy(sf::Vector2f(2.0,2.0),sf::Vector2f(1510,0)));

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
        //std::cout<<hero->get_speed().x<<std::endl;
        process_events();

        // update_physics physics
        auto dt = clock.getElapsedTime();
        clock.restart();

        this->hero->update_physics(dt.asSeconds(), this->map);
         //this->enemy->update_physics(dt.asSeconds(), this->map);

        for(auto en : enemies)
        {
            en->update_physics(dt.asSeconds(), this->map);
        }
        main_view.setCenter(this->hero->get_position().x, 90);
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

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            this->hero->set_vx(speed_default_val_x);
        }
        else if(Keyboard::isKeyPressed(Keyboard::A))
        {
            this->hero->set_vx(-speed_default_val_x);
        }
        else if(event.type == Event::KeyReleased)
        {
            if(event.key.code == Keyboard::D || event.key.code == Keyboard::A)
            {
                this->hero->set_vx(0);
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
    ptr_window->clear(sf::Color::Black);
    map->draw_(ptr_window);
    hero->draw(ptr_window);
    for(auto en : enemies)
    {
        ptr_window->draw(en->sprite);
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
            std::cout<<hero->hero_HP<<std::endl;
            if(hero->hero_HP == 0)
            {
                std::cout<<"KONIEC GRY"<<std::endl;
                ptr_window->close();
            }
        }
        else {
            ++it;
        }
    }
}


