#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "maingame.h"

class GameMap
{
    GameMap();

    GameMap(const std::string filename);

    void draw(std::shared_ptr<sf::RenderWindow> window);

private:
    sf::Texture texture;
};


#endif // GAMEMAP_H
