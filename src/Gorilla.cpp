#include "../include/Window.hpp"
#include "../include/Gorilla.hpp"
#include "../include/MainMenu.hpp"

#define GORILLA "assets/images/enemies/gorillas.png"

void Gorilla::_move(float speed)
{
    if (sprite.getPosition().x <= 270 || sprite.getPosition().x >= 550 || rand() % 45 == 0)
        dir = -dir;
    sprite.move(speed * 0.8 * dir, 0);
}

void Gorilla::draw(Window &win)
{
    win.draw(sprite);
}

void Gorilla::move(Window &win, float speed)
{
    _move(speed);
    if (_place_clock.getElapsedTime() > _time_place) {
        win.addEnemy(rand() % 3, sprite.getPosition().x);
        _time_place = sf::milliseconds(rand() % 750 + 500);
        _place_clock.restart();
    }
}

Gorilla::Gorilla()
{
    dir = rand() % 1;
    dir = dir ? 1 : -1;

    sprite_from_file(sprite, GORILLA, (sf::IntRect*)(gori_sprites));
    sprite.scale(3.3, 3.3);
    sprite.setTextureRect(gori_sprites[4]);
    sprite.setPosition(rand() % 278 + 271, 80);
}