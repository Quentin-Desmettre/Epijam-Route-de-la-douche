#ifndef GORILLA_HPP_
    #define GORILLA_HPP_

    #include "../include/Window.hpp"

class Gorilla {
    private:
        int dir;

        sf::Sprite sprite;

        sf::Clock _place_clock;
        sf::Time _time_place;
        void _move(float speed);
    public:
        Gorilla();

        void add_enemy();
        void move(Window &win, float speed);
        void draw(Window &win);
        void resetClock() {_place_clock.restart();}
};

#endif
