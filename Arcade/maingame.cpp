#include "maingame.h"

using namespace sf;

MainGame::MainGame()
{
    this->ptr_window = std::make_shared<RenderWindow>(VideoMode(1200, 900), "Window");
    this->ptr_window->setFramerateLimit(60);

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
        auto current_view = map->get_view(hero->get_position());

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

