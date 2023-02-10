
#ifndef WINDOW_HPP
    #define WINDOW_HPP
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "SFML/Audio.hpp"
    #include <string>
    #include "Success.hpp"
    #include <list>
    #include "Enemy.hpp"

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
    void moveEnemies(Road &r);
    void clearEnemies(void) {_enemies.clear();}
    std::vector<Enemy> &getEnemies() {return _enemies;}

    void ferme_ta_gueule(bool ftg) {_ftg = ftg;}

    void playMusic();
    void stopMusic();

    void fart();

    ~Window();
};

#endif
