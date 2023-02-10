#include "MainMenu.hpp"
#include "Window.hpp"

#define GORILLA "assets/images/enemies/gorillas.png"
#define PLAY "assets/images/main_menu/start.png"
#define EXIT "assets/images/main_menu/quit.png"

sf::Texture *from_file(std::string file)
{
    sf::Texture *t = new sf::Texture;

    t->loadFromFile(file);
    return t;
}

MainMenu::MainMenu(sf::Vector2f win_size):
    m_size(win_size),
    m_gor_dir(10, 10),
    m_sprite_gori(0)
{
    sprite_from_file(m_gorille, GORILLA, (sf::IntRect*)(gori_sprites));
    m_gorille.scale(3.3, 3.3);

    sprite_from_file(m_play, PLAY);
    m_play.setPosition(win_size.x / 2.0, win_size.y * 0.37);
    sprite_from_file(m_exit, EXIT);
    m_exit.setPosition(win_size.x / 2.0, win_size.y * 0.63);
}

void MainMenu::move_gori(Window &win)
{
    auto pos = m_gorille.getPosition();
    sf::Vector2f new_pos(pos.x + m_gor_dir.x, pos.y + m_gor_dir.y);
    bool change_y = new_pos.y > m_size.y || new_pos.y < 0;
    bool change_x = new_pos.x > m_size.x || new_pos.x < 0;

    if (change_x)
        m_gor_dir.x *= -1;
    if (change_y)
        m_gor_dir.y *= -1;
    if (change_x || change_y) {
        win.addSuccess("Gorilla touched the wall");
        m_sprite_gori++;
        if (m_sprite_gori >= 5)
            m_sprite_gori = 0;
        m_gorille.setTextureRect(gori_sprites[m_sprite_gori]);
    }
    m_gorille.move(m_gor_dir);
}

void MainMenu::draw_to(Window &win)
{
    move_gori(win);

    win.draw(m_gorille);
    win.draw(m_play);
    win.draw(m_exit);
}

bool MainMenu::is_play(sf::Event const& ev)
{
    return m_play.getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y);
}

bool MainMenu::is_exit(sf::Event const& ev)
{
    return m_exit.getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y);
}

void sprite_from_file(sf::Sprite &s, std::string file, sf::IntRect *rect)
{
    sf::Texture *t = from_file(file);
    sf::Vector2u size = t->getSize();

    s.setTexture(*t);
    if (rect) {
        s.setTextureRect(*rect);
        s.setOrigin(rect->width / 2.0, rect->height / 2.0);
    } else
        s.setOrigin(sf::Vector2f(size.x / 2.0, size.y / 2.0));
}
