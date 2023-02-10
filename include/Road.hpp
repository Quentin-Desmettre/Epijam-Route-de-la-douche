
#ifndef ROAD_HPP_
    #define ROAD_HPP_

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "Window.hpp"

class Road {
    private:
        sf::Texture *back_text;

        sf::Sprite road;
        sf::Sprite back_l;
        sf::Sprite back_r;
        sf::Sprite **cones;
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::IntRect _rect;
        float _speed;

    public:
        void move_back();
        bool getCollisionLeft(sf::FloatRect car_hb);
        bool getCollisionRight(sf::FloatRect car_hb);
        // CONSTRUCTOR && DESTRUCTOR
        ~Road();

        // GETTERS && SETTERS
        sf::Sprite getSprite() const {return _sprite;};
        float getSpeed() const {return _speed;}
        void setSpeed(float n) {_speed = n;}

        // METHODS
        void update(Window &win);
        Road(Window &win);

        void draw(Window &win);
};

#endif
