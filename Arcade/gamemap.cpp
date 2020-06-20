#include "gamemap.h"
#include <iostream>

using namespace sf;

GameMap::GameMap()
{
    this->texture.loadFromFile("Textury/Mapa.png");
    map_sprite.setTexture(texture);
}

GameMap::GameMap(const std::string filename)
{
    this->texture.loadFromFile("Textury/" + filename);
    map_sprite.setTexture(texture);

    plat = std::vector<Plat>
    {
        {0,282,115},
        {282,428,144},
        {428,623,65},
        {623,658,95},
        {658,694,119},
        {694,1155,144},
        {1155,1205,122},
        {1205,1351,144},
        {1351,1379,62},
        {1379,1938,144},
        {1938,1976,123},
        {1976,2300,144}
    };
}

void GameMap::draw_(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(map_sprite);
}


float GameMap::check_height(float x_min,float x_max)
{
    for(auto it = plat.begin(); it!=plat.end(); ++it)
    {
        if(x_min>it->x1 && x_max<=it->x2){

            return it->h;
        }
        else if(it!=plat.end()-1)
        {
            if(x_min < it->x2 && x_max >= (it+1)->x1)
            {
                return std::min(it->h, (it+1)->h);
            }
        }
    }
    return 0;
}

float GameMap::check_height(float x)
{
    for(auto it = plat.begin(); it!=plat.end(); ++it)
    {
        if(x>it->x1 && x<=it->x2){
            return it->h;
        }
    }
    return 0;
}

