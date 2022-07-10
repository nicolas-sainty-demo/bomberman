/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** explosions
*/

#include "explosions.hpp"

Explosions::Explosions()
{
}

Explosions::Explosions(int x, int y)
{
    this->x = x;
    this->y = y;
    this->cooldown = 100;
}

Explosions::~Explosions()
{
}

int Explosions::GetBombs_cooldown() const
{
    return this->cooldown;
}

void Explosions::SetBombs_cooldown(int bombs_cooldown)
{
    this->cooldown = bombs_cooldown;
}

int Explosions::GetX() const
{
    return this->x;
}

void Explosions::SetX(int x)
{
    this->x = x;
}

int Explosions::GetY() const
{
    return this->y;
}

void Explosions::SetY(int y)
{
    this->y = y;
}