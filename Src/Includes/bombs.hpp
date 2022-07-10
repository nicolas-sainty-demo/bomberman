/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** bombs
*/

#ifndef BOMBS_HPP_
#define BOMBS_HPP_
#include <list>
#include "players.hpp"
#include <vector>
#include "raylib.h"
#include <iostream>
#include <string>
#include "wall.hpp"
#include "explosions.hpp"

class Bombs
{
    public:
        Bombs();
        Bombs(int x, int y);
        ~Bombs();
        int GetId() const;
        void SetId(int id);
        float GetBombs_timer() const;
        void SetBombs_timer(float bomb_timer);
        int GetX() const;
        void SetX(int x);
        int GetY() const;
        void SetY(int y);
    private:
        int id;
        float bomb_timer;
        int x;
        int y;
};
std::vector<Bombs*> DrawBombs(std::vector<Bombs*> BombsList);
void popBomb(std::vector<Bombs*>* BombsList);
void createBombs(std::vector<Players *> playersList, std::vector<Bombs*>* BombsList);
void Explode(std::vector<Bombs*>* BombsList, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion);
std::list<Players *>::iterator touchPlayer(std::list<Players *>::iterator it2, std::vector<Bombs*>::iterator it);
//void touchWalls(Wall* walls, Bombs *Bomb);
void Explode_Up(Bombs* bomb, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion);
void Explode_Down(Bombs* bomb, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion);
void Explode_Left(Bombs* bomb, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion);
void Explode_Right(Bombs* bomb, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion);

#endif /* !BOMBS_HPP_ */