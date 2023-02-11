
#ifndef WINDOW_HPP
    #define WINDOW_HPP
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "../include/SFML/Audio.hpp"
    #include <string>
    #include "../include/Success.hpp"
    #include <list>
    #include "../include/Enemy.hpp"
    #include "../include/Car.hpp"


class Hearts;

typedef enum {MAIN_MENU, PLAY} win_mode;

class Success;
class Road;
class Enemy;

class Window : public sf::RenderWindow
{
private:
    win_mode m_mode;
    std::list<Success*> m_sc;
    std::vector<std::string> m_viewed_sc;
    sf::RectangleShape dark;
    sf::Sound *m_sound ;
    sf::SoundBuffer *m_buffer;

    std::vector<Enemy> _enemies;
    bool _ftg;

    sf::Music _music;
public:
    int stop;
    void draw_dark();
    Window(sf::VideoMode mode, std::string name, sf::Uint8 style);
    win_mode getMode(void) {return m_mode;}
    void setMode(win_mode new_mode) {m_mode = new_mode;}

    void addSuccess(std::string const what);
    void popSuccess();
    Success *curSuccess(void);
    std::size_t nbSuccess(void) const {return m_sc.size();}

    void addEnemy(int type, float x_start);
    void drawEnemies(void);
    void moveEnemies(Road &r, Hearts &heart, Car &car);
    void clearEnemies(void) {_enemies.clear();}
    std::vector<Enemy> &getEnemies() {return _enemies;}

    void ferme_ta_gueule(bool ftg) {_ftg = ftg;}

    void playMusic();
    void stopMusic();

    void fart();

    ~Window();
};


class Hearts {
public:
    Hearts() {
        _nbHearts = 4;
        _heart.loadFromFile("assets/heart.png");
        _heartSprite.setTexture(_heart);
        _emptyHeart.loadFromFile("assets/empty_heart.png");
        _emptyHeartSprite.setTexture(_emptyHeart);

        _heartSprite.setScale(0.23, 0.23);
        _emptyHeartSprite.setScale(0.23, 0.23);
    }
    ~Hearts() = default;

    void drawTo(Window &win) {
        for (int j = 0; j < 4; j++) {
            if (j < _nbHearts) {
                _heartSprite.setPosition(10 + j * 50, 10);
                win.draw(_heartSprite);
            } else {
                _emptyHeartSprite.setPosition(10 + j * 50, 10);
                win.draw(_emptyHeartSprite);
            }
        }
    }
    void loseHeart() {
        _nbHearts--;
        if (_nbHearts < 0)
            _nbHearts = 0;
    }
    void addHeart() {
        _nbHearts++;
        if (_nbHearts > 4)
            _nbHearts = 4;
    }
    void reset() {
        _nbHearts = 4;
    }
    int getNbHearts() const {
        return _nbHearts;
    }

private:
    int _nbHearts;
    sf::Texture _heart, _emptyHeart;
    sf::Sprite _heartSprite;
    sf::Sprite _emptyHeartSprite;
};

#endif
