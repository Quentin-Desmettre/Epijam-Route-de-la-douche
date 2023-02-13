/*
** EPITECH PROJECT, 2022
** Gameover.cpp
** File description:
** Gameover
*/

#include "../include/Window.hpp"

void init_text(sf::Text &t, std::string const name);

void load_text(sf::Text &t, std::string const name);

#define NB_QUOTE 10

static const char *quotes[NB_QUOTE] =
{"Qui a péte ?",
"Never (gonna) give (you) up",
"Le mardi Kfc est pas bien passe >(",
"Be you, be proud of you, because you can be do what we want to do.",
"slide 7 du diapo, 'prenez des douches' ",
"c'est pas drole les gars ca pue !!!",
"Pourquoi j'ai pas le covid :'(",
"ca pue trop je me casse",
"J'ai couru mais l'odeur m'as rattrappé.",
"La pomme ne tombe jamais loin du pommier"};

void draw_game_over(Window &win, int reset)
{
    static int num = rand() % NB_QUOTE;
    sf::Text over;
    sf::Text mot_quote;
    sf::Vector2u pos = win.getSize();

    win.addSuccess("Ended a game");
    if (reset) {
        num = rand() % NB_QUOTE;
        return;
    }
    pos.x /= 2;
    pos.y /= 2;

    win.addSuccess(quotes[num]);
    init_text(over, "Game over");
    load_text(over, "Game over");

    init_text(mot_quote, quotes[num]);
    load_text(mot_quote, quotes[num]);

    sf::FloatRect size = mot_quote.getGlobalBounds();
    pos.x -= size.width / 2;
    pos.y -= size.height / 2;
    pos.y += 30;

    mot_quote.setPosition(pos.x, pos.y);

    pos = win.getSize();
    over.setCharacterSize(50);
    size = over.getGlobalBounds();

    pos.x /= 2;
    pos.y /= 2;
    pos.x -= size.width / 2;
    pos.y -= size.height / 2;
    pos.x -= 30;
    pos.y -= 100;

    over.setPosition(pos.x, pos.y);

    win.draw(mot_quote);
    win.draw(over);
}