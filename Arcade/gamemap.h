#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "SFML/Graphics.hpp"

#include <memory>




struct Plat
{
    float x1, x2, h;
};

class GameMap:public sf::RectangleShape
{
public:
    GameMap();

    GameMap(const std::string filename);

    void draw_(std::shared_ptr<sf::RenderWindow> window);

    sf::View get_view(sf::Vector2f hero_position);

    float check_height(float x_min,float x_max);
    float check_height(float x);

private:
    sf::Texture texture;
    sf::Sprite map_sprite;
    std::vector<Plat>plat;
};


#endif // GAMEMAP_H
