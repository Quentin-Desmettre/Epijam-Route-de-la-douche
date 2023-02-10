#include "Enemy.hpp"
#define PLOT_PNG "assets/images/enemies/cone.png"
#define ENTREPRENEUR_PNG "assets/images/enemies/entrepreneur.png"
#define BANANA_PNG "assets/images/enemies/banana.png"

static const sf::Texture *textures[3] = {
    from_file(PLOT_PNG),
    from_file(ENTREPRENEUR_PNG),
    from_file(BANANA_PNG)
};

Enemy::Enemy(int const type, float const x_start):
_type(type)
{
    setTexture(*(textures[type]));
    setPosition(x_start, 0);
}

void Enemy::update_pos(Road &r)
{
    move(0, r.getSpeed() * 1.19);
}
