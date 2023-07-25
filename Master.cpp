#pragma once
#include "Master.hpp"

const char* goblinPath = "C:/Users/Killian/Desktop/RPG/x64/Debug/Sprites/Knight front.png";
Master::Master(Game* game) :_game(game)
{

}

void Master::kill(Character& target)
{
    target.getHit(200);
    std::cout << target._name << " is dead" << std::endl;
}

void Master::spawnGoblin(std::string name)
{
    Goblin goblin(name);
    Sprite gobSprite(_game->getRenderer(),400,400, goblinPath);
    _game->addEnnemy(goblin,gobSprite);
}

void Master::spawnWizard(std::string name)
{

}