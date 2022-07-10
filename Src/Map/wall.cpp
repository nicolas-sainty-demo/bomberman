/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** wall
*/

#include "wall.hpp"


Wall::~Wall()
{
}

Wall::Wall()
{
}

int Wall::GetX() const {
    return this->x;
}

void Wall::SetX(int x) {
    this->x = x;
}

int Wall::GetY() const {
    return this->y;
}
void Wall::SetY(int y) {
    this->y = y;
}
int Wall::GetDestroyable() const {
    return this->destroyable;
}
void Wall::SetDestroyable(int destroyable) {
    this->destroyable = destroyable;
}

Wall::Wall(int x, int y, int destroyable)
{
    this->x = x;
    this->y = y;
    this->destroyable = destroyable;
}