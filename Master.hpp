#pragma once
#include "Game.hpp"

class Master
{
public:
    Master(Game* game);
    void kill(Character& target);
    void spawnGoblin(std::string name);
    void spawnWizard(std::string name);
private:
    Game* _game;
};