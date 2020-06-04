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
                                        sf::Vector2f(70, 70));
}

void MainGame::run()
{

    while(ptr_window->isOpen())
    {
        process_events();

        this->hero->move(sf::Vector2f(1,0));
        main_view.setCenter(this->hero->get_position().x, 90);
        this->ptr_window->setView(main_view);
        render();
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
    }
}


void MainGame::render()
{
    ptr_window->clear(sf::Color::Black);
    map->draw(ptr_window);
    hero->draw(ptr_window);
    ptr_window->display();
}

