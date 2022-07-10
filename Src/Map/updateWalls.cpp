/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** updateWalls
*/
#include "updateWall.hpp"

void checkUp(std::vector<Wall*> wall, Players* players)
{
    for (auto &walls : wall) {
        if(walls->GetY() - 1 == players->GetY() && walls->GetX() == players->GetX()) {
            if (walls->GetDestroyable() != 2) {
                players->SetUp(false);
            } else
                players->SetUp(true);
        }
    }
}

void checkDown(std::vector<Wall*> wall, Players* players)
{
    for (auto &walls : wall) {
        if(walls->GetY() + 1 == players->GetY() && walls->GetX() == players->GetX()) {
            if (walls->GetDestroyable() != 2) {
                players->SetDown(false);
            } else
                players->SetDown(true);
        }
    }
}

void checkRight(std::vector<Wall*> wall, Players* players)
{
    for (auto &walls : wall) {
        if(walls->GetX() - 1 == players->GetX() && walls->GetY() == players->GetY()) {
            if (walls->GetDestroyable() != 2) {
                players->SetRight(false);
            } else
                players->SetRight(true);
        }
    }
}

void checkLeft(std::vector<Wall*> wall, Players* players)
{
    for (auto &walls : wall) {
        if(walls->GetX() + 1 == players->GetX() && walls->GetY() == players->GetY()) {
            if (walls->GetDestroyable() != 2) {
                players->SetLeft(false);
            } else
                players->SetLeft(true);
        }
    }
}

void updateWall(std::vector<Wall*> wall, Players* players)
{
    checkUp(wall, players);
    checkDown(wall, players);
    checkLeft(wall, players);
    checkRight(wall, players);
}