#include "gamemap.h"
#include <iostream>
using namespace sf;
GameMap::GameMap()
{
    this->texture.loadFromFile("Textury/Mapa.png");
    mapa.setTexture(texture);
}

GameMap::GameMap(const std::string filename)
{
    this->texture.loadFromFile("Textury/" + filename);
    mapa.setTexture(texture);
}

void GameMap::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(mapa);
}

sf::View GameMap::get_view(sf::Vector2f hero_position)
{
    return sf::View();
}
