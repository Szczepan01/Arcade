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
    this->hero = std::make_shared<Hero>(std::string("Riven.png"),
                                        sf::Vector2f(2.0, 2.0),
                                        sf::Vector2f(70, 65));
}

void MainGame::run()
{
    sf::Clock clock;

    this->hero->set_vx(0);
    this->hero->set_vy(gravity_speed);

    while(ptr_window->isOpen())
    {
        std::cout<<hero->get_speed().x<<std::endl;
        process_events();

        // update_physics physics
        auto dt = clock.getElapsedTime();
        clock.restart();

        this->hero->update_physics(dt.asSeconds(), this->map);

        main_view.setCenter(this->hero->get_position().x, 90);
        this->ptr_window->setView(main_view);
        render();

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
    ptr_window->display();
}


