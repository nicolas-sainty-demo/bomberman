/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** explosions
*/

#ifndef EXPLOSIONS_HPP_
#define EXPLOSIONS_HPP_
#include <vector>
#include <raylib.h>

class Explosions
{
    public:
        Explosions();
        Explosions(int x, int y);
        ~Explosions();
        int GetBombs_cooldown() const;
        void SetBombs_cooldown(int bombs_cooldown);
        int GetX() const;
        void SetX(int x);
        int GetY() const;
        void SetY(int y);
    private:
        int cooldown;
        int x;
        int y;
};

#endif /* !EXPLOSIONS_HPP_ */