#include "Success.hpp"
#include "MainMenu.hpp"
#include <iostream>
#define BOX_SPRITE "assets/images/achievements/achievement_box.png"
#define FONT "assets/fonts/Minecraft.ttf"
#define SFX_SUCCESS "assets/sfx/achieve.ogg"

int next_word_length(char const *beg)
{
    int len = 0;
    for (int i = 0; beg[i] && beg[i] != ' '; len++, i++);
    return len;
}

void init_sound(sf::Sound &s)
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer;

    buffer->loadFromFile(SFX_SUCCESS);
    s.setBuffer(*buffer);
}

void load_text(sf::Text &t, std::string const name)
{
    std::string final_text = "\n    ";
    int line_len = 4;

    for (int i = 0, n = name.size(); i < n; i++) {
        if ((name[i] != ' ' && i && name[i - 1] == ' ') &&
        next_word_length(name.c_str() + i) + line_len > 25) {
            final_text += '\n';
            line_len = 0;
        }
        line_len++;
        final_text += name[i];
    }
    t.setString(final_text);
}

void init_text(sf::Text &t, std::string const name)
{
    sf::Font *font = new sf::Font;

    font->loadFromFile(FONT);
    t.setFont(*font);
    t.setFillColor(sf::Color::White);
    t.setCharacterSize(22);
    t.setString(name);
}

Success::Success(std::string const name, sf::Vector2u const size):
    sf::Clock(),
    has_played(false)
{
    sf::Vector2f pos(size.x * 0.58, size.y * 0.02);
    sprite_from_file(m_box, BOX_SPRITE);
    init_text(m_text, name);
    load_text(m_text, name);
    init_text(m_achiev, "Success unlocked");

    m_achiev.setFillColor(sf::Color::Yellow);
    m_box.setOrigin(0, 0);
    m_achiev.setPosition(pos.x + 20, pos.y + 20);
    m_box.setPosition(pos);
    m_text.setPosition(pos.x + 20, pos.y + 20);
    init_sound(m_sound);
}

void Success::setText(std::string const txt)
{
    reset();
    load_text(m_text, txt);
}

void Success::draw_to(Window &win)
{
    win.draw(m_box);
    win.draw(m_achiev);
    win.draw(m_text);
}

Success::~Success()
{
    delete m_sound.getBuffer();
    delete m_text.getFont();
    delete m_achiev.getFont();
    delete m_box.getTexture();
}
