#include "Road.hpp"
#include "Car.hpp"

void check_wall_col(Road &road, Car &car)
{
    static bool left_col = false;
    static bool right_col = false;

    if (road.getCollisionLeft(car.getSprite().getGlobalBounds())) {
        if (!left_col) {
            car.takeDamage();
            left_col = true;
        }
    } else if (car.getSprite().getPosition().x > 275)
        left_col = false;
    if (road.getCollisionRight(car.getSprite().getGlobalBounds())) {
        if (!right_col) {
            car.takeDamage();
            right_col = true;
        }
    } else if (car.getSprite().getPosition().x < 525)
        right_col = false;
}

void add_enemy_success(int type, Window &win)
{
    std::string s = "Got hit by ";
    if (type == 0)
        s += "a cone";
    else if (type == 1)
        s += "an entrepreneur";
    else
        s += "a banana";
    win.addSuccess(s);
}

void check_enemy_col(Window &win, Car &car)
{
    std::vector<Enemy> &en = win.getEnemies();
    for (std::vector<Enemy>::iterator it = en.begin();
    it != en.end(); it++) {
        if (it->getGlobalBounds().intersects(car.getSprite().getGlobalBounds())) {
            car.takeDamage();
            add_enemy_success(it->getType(), win);
            en.erase(it);
            break;
        }
    }
}

void add_crash_success(Window &win, Car &car)
{
    std::string s;
    if (car.isGameOver())
        s = "Crashed the car";
    else
        s = "Got hit " + std::to_string(car.getState()) + " time";
    if (!car.isGameOver() && car.getState() > 1)
        s += 's';
    win.addSuccess(s);
}

void check_car_collision(Road &road, Car &car, Window &win)
{
    check_wall_col(road, car);
    check_enemy_col(win, car);

    if (car.getState() == 0)
        return;
    add_crash_success(win, car);
}
