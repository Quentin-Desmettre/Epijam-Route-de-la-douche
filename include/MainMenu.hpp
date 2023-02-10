#ifndef MAIN_MENU_H
    #define MAIN_MENU_H
    #include "Window.hpp"

static const sf::IntRect gori_sprites[5] {
    {5, 0, 39, 48},
    {149, 0, 39, 48},
    {293, 0, 39, 48},
    {437, 0, 39, 48},
    {437, 193, 39, 48}
};

class Window;

class MainMenu
{
private:
    sf::Sprite m_gorille, m_play, m_exit;

    sf::Vector2f m_size;
    sf::Vector2f m_gor_dir;

    int m_sprite_gori;

    void move_gori(Window &win);
public:
    MainMenu(sf::Vector2f win_size);

    void draw_to(Window &win);
    bool is_play(sf::Event const& ev);
    bool is_exit(sf::Event const& ev);
};

sf::Texture *from_file(std::string file);
void sprite_from_file(sf::Sprite &s, std::string file, sf::IntRect *rect = nullptr);

#endif /* MAIN_MENU */
