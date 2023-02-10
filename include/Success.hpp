#ifndef SUCCESS_HPP
#define SUCCESS_HPP

#include "Window.hpp"
#include <SFML/Audio.hpp>

class Window;

class Success : public sf::Clock
{
private:
    sf::Sprite m_box;
    sf::Text m_text;
    sf::Text m_achiev;
    sf::Sound m_sound;
    bool has_played;

public:
    Success(std::string const name, sf::Vector2u const win_size);

    sf::Int32 msElapsed() const {return getElapsedTime().asMilliseconds();}

    void draw_to(Window &win);

    void play() {m_sound.play(); has_played = true;}
    void reset() {restart(); has_played = false;};
    bool hasPlayed() const {return has_played;}

    void setText(std::string const txt);

    ~Success();
};

#endif /* SUCCESS_HPP */
