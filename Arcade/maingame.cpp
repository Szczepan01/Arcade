#include "maingame.h"

using namespace sf;

MainGame::MainGame()
{
    this->ptr_window = std::make_shared<RenderWindow>(VideoMode(1200, 900), "Window");
    this->ptr_window->setFramerateLimit(60);

    this->map = std::make_shared<GameMap>("Mapa.png");
}

void MainGame::run()
{

    while(ptr_window->isOpen())
    {
        process_events();
        draw_map();
        ptr_window->display();
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

void MainGame::draw_map()
{



}
