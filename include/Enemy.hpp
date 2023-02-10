#ifndef C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911
#define C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911

#define PLOT 0
#define ENTREPRENEUR 1
#define BANANA 2

#include "MainMenu.hpp"
#include "Road.hpp"

class Road;

class Enemy : public sf::Sprite
{
private:
    int _type;
public:
    Enemy(int const type, float const x_start);

    void update_pos(Road &r);
    int getType() const {return _type;}
};

#endif /* C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911 */
