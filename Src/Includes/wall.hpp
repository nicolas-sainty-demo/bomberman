/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_
#include <cstddef>
#include <vector>
#include "players.hpp"
#include <raylib.h>

class Wall
{
    public:
        Wall();
        Wall(int x, int y, int destroyable);
        ~Wall();
        Wall* Next_Wall = NULL;
        int GetX() const;
        void SetX(int x);
        int GetY() const;
        void SetY(int y);
        int GetDestroyable() const;
        void SetDestroyable(int destroyable);
    private:
        int x;
        int y;
        int destroyable;
};
#endif /* !WALL_HPP_ */
