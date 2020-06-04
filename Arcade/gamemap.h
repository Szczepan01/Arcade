#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "maingame.h"
#include "SFML/Graphics.hpp"

class GameMap
{
public:
    GameMap();

    GameMap(const std::string filename);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    sf::View get_view(sf::Vector2f hero_position);

private:
    sf::Texture texture;
    sf::Sprite mapa;
    sf::View view();
};


#endif // GAMEMAP_H
