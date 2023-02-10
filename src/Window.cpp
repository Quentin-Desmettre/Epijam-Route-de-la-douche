#include "Window.hpp"
#include <iostream>

Window::Window(sf::VideoMode mode, std::string name, sf::Uint8 style):
    sf::RenderWindow(mode, name, style),
    m_mode(MAIN_MENU),
    _ftg(false),
    stop(0)
{
    dark.setFillColor(sf::Color(0, 0, 0, 100));
    dark.setSize(sf::Vector2f(800, 600));
    setFramerateLimit(60);

    m_buffer = new sf::SoundBuffer;
    m_sound = new sf::Sound;
    m_buffer->loadFromFile("assets/sfx/fart.ogg");
    m_sound->setBuffer(*m_buffer);
    m_sound->setVolume(50);
}

void Window::addSuccess(std::string const what)
{
    if (_ftg)
        return;
    if (std::find(m_viewed_sc.begin(), m_viewed_sc.end(), what) != m_viewed_sc.end())
        return;
    m_sc.push_back(new Success(what, getSize()));
    m_viewed_sc.push_back(what);
}

void Window::popSuccess()
{
    if (nbSuccess()) {
        delete m_sc.front();
        m_sc.pop_front();
    }
}

void Window::draw_dark()
{
    draw(dark);
}

Success *Window::curSuccess(void)
{
    if (!nbSuccess())
        return nullptr;
    return m_sc.front();
}

void Window::fart()
{
    m_sound->play();
}

void Window::addEnemy(int type, float x_start)
{
    _enemies.push_back(Enemy(type, x_start));
    fart();
}

void Window::drawEnemies(void)
{
    for (Enemy i: _enemies)
        draw(i);
}

void Window::moveEnemies(Road &r)
{
    std::vector<std::vector<Enemy>::iterator> to_remove;
    for (std::vector<Enemy>::iterator it = _enemies.begin();
    it != _enemies.end(); it++) {
        (*it).update_pos(r);
        if ((*it).getPosition().y > getSize().y)
            to_remove.push_back(it);
    }
    for (int i = 0, n = to_remove.size(); i < n; i++)
        _enemies.erase(to_remove[i]);
}

void Window::playMusic(void)
{
    _music.openFromFile("assets/musics/coconut_mall.ogg");
    _music.setLoop(true);
    _music.play();
}

void Window::stopMusic(void)
{
    _music.stop();
}

Window::~Window()
{
    while (m_sc.size())
        popSuccess();
    if (_music.getStatus() != 0)
        _music.stop();
    delete m_buffer;
    delete m_sound;
}
