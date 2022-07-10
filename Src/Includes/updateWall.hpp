/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** updateWall
*/

#ifndef UPDATEWALL_HPP_
#define UPDATEWALL_HPP_

#include "players.hpp"
#include <list>
#include "game.hpp"
#include "wall.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
void updateWall(std::vector<Wall*> wall, Players* players);
void checkLeft(std::vector<Wall*> wall, Players* players);
void checkRight(std::vector<Wall*> wall, Players* players);
void checkUp(std::vector<Wall*> wall, Players* players);
void checkDown(std::vector<Wall*> wall, Players* players);
#endif /* !UPDATEWALL_HPP_ */
