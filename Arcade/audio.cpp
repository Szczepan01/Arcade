#include "audio.h"

Audio::Audio()
{

}

void Audio::melody()
{
    if(!music.openFromFile("Music/Music.ogg"))
    {
        std::cout<<"brak audio"<<std::endl;
    }
    music.setVolume(30);
    music.play();
}

void Audio::shot()
{
    if(!buffer.loadFromFile("Music/shot.ogg"))
    {
        std::cout<<"brak audio"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.setVolume(40);
    sound.play();
}

void Audio::enemy_shot()
{
    if(!buffer.loadFromFile("Music/laser.wav"))
    {
        std::cout<<"brak audio"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.setVolume(40);
    sound.play();
}
