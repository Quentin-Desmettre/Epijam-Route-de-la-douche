#include "Window.hpp"
#include "MainMenu.hpp"
#include "Car.hpp"

#define DAMAGE_SFX "assets/sfx/crash.ogg"
#define CRASH_SFX "assets/sfx/final_crash.ogg"

void soundFromFile(sf::Sound &s, std::string const file)
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer;

    buffer->loadFromFile(file);
    s.setBuffer(*buffer);
}

Car::Car():
    speed_r(0),
    speed_l(0),
    _state(0)
{
    sf::Texture *t = new sf::Texture;
    t->loadFromFile("assets/images/car/car.png");
    sf::Vector2u size = t->getSize();

    m_car.setTexture(*t);
    t->setRepeated(true);
    m_car.setOrigin(sf::Vector2f(size.x / 8.0, size.y / 2.0));
    m_car.setPosition(sf::Vector2f(400, 500));
    m_car.setTextureRect(sf::IntRect(0, 0, 27, 46));
    m_car.scale(2, 2);
    soundFromFile(_damage_sfx, DAMAGE_SFX);
    soundFromFile(_crash_sfx, CRASH_SFX);
}

void Car::move_left(Window &win)
{
    int press = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        press = 1;
        win.addSuccess("Moved left");
    } else
        press = 0;
    sf::Vector2f pos = m_car.getPosition();
    if (press && speed_l < 15)
        speed_l += 1;
    if (!press && speed_l > 0)
        speed_l -= 3;
    if (!press && speed_l < 0)
        speed_l = 0;
    pos.x -= speed_l;
    if (press)
        m_car.setRotation(-20);
    if ((speed_l == 0 && speed_r == 0) || (speed_l == 15 && speed_r == 15))
        m_car.setRotation(0);
    m_car.setPosition(pos);
}

void Car::move_right(Window &win)
{
    int press = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        press = 1;
        win.addSuccess("Moved right");
    } else
        press = 0;
    sf::Vector2f pos = m_car.getPosition();
    if (press && speed_r < 15)
        speed_r += 1;
    if (!press && speed_r > 0)
        speed_r -= 3;
    if (!press && speed_r < 0)
        speed_r = 0;
    pos.x += speed_r;
    if (press)
        m_car.setRotation(20);
    m_car.setPosition(pos);
}

void Car::draw_to(Window &win)
{
    win.draw(m_car);
}

void Car::stop_sound()
{
    _crash_sfx.stop();
    _damage_sfx.stop();
}

void Car::resetDamage()
{
    sf::IntRect r = m_car.getTextureRect();

    r.left = 0;
    m_car.setTextureRect(r);
    m_car.setPosition(400, 500);
    _state = 0;
}

void Car::takeDamage()
{
    if (_state >= 4)
        return;
    if (_state == 3)
        _crash_sfx.play();
    else
        _damage_sfx.play();
    _state += 1;
    sf::IntRect r = m_car.getTextureRect();

    r.left += r.width;
    m_car.setTextureRect(r);
}

Car::~Car()
{
    delete _crash_sfx.getBuffer();
    delete _damage_sfx.getBuffer();
}
