#ifndef AUDIO_H
#define AUDIO_H
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

class Audio
{
public:
    Audio();
    void melody();
    void shot();
    void enemy_shot();
private:
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

#endif // AUDIO_H
