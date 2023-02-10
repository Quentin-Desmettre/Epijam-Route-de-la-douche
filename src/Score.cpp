#include "Score.hpp"

//void sprite_from_file(sf::Sprite &s, std::string file, sf::IntRect *rect = nullptr);

Score::Score(float x, float y):
    sf::Text()
{
    sf::Font *f = new sf::Font;

    f->loadFromFile("assets/fonts/Minecraft.ttf");
    setPosition(x, y);
    setFont(*f);
    setCharacterSize(35);
    setFillColor(sf::Color::White);
    _score = 0;
    _updateScore();
}

void Score::_updateScore()
{
    std::string txt = std::to_string(_score);
    std::string final_txt = "";

    for (int i = txt.length(); i < 8; i++)
        final_txt += "0";
    final_txt += txt;
    setString(final_txt);
}

void Score::drawTo(Window &win)
{
    _updateScore();
    win.draw(*this);
}
