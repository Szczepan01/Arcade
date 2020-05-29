#include "gamemap.h"
#include <iostream>

GameMap::GameMap()
{
    this->texture.loadFromFile("Textury/Mapa.png");
}

GameMap::GameMap(const std::string filename)
{
    this->texture.loadFromFile("Textury/" + filename);
}

void GameMap::draw(std::shared_ptr<sf::RenderWindow> window)
{

}
