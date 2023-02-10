#ifndef A86AF258_F568_4D1A_A9BC_16CB1BA4632E
#define A86AF258_F568_4D1A_A9BC_16CB1BA4632E

#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Score : public sf::Text
{
private:
    int _score;
    sf::Clock _clock;

    void _updateScore();
public:
    Score(float x, float y);

    void addScore(int increment) {_score += increment;}
    void resetScore() {_score = 0;}
    int getScore() {return _score;}
    void drawTo(Window &win);
    sf::Time msElapsed() {return _clock.getElapsedTime();}
    void restartClock() {_clock.restart();}
};

#endif // A86AF258_F568_4D1A_A9BC_16CB1BA4632E
