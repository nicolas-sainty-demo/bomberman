/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** bombs
*/
#include "bombs.hpp"

Bombs::Bombs()
{
}

Bombs::~Bombs()
{
}

void Explode_Up(Bombs* bombs, std::vector<Players*> players, std::vector<Wall*>* walls, std::vector<Explosions*>* explosions)
{
    int breack = 0;
    for (int i = 1; i < 4; i++) {
        for (auto& wall : (*walls)) {
            if (wall->GetX() == bombs->GetX() && wall->GetY() == bombs->GetY() + i && wall->GetDestroyable() == 0) {
                breack = 1;
            }else if (wall->GetX() == bombs->GetX() && wall->GetY() == bombs->GetY() + i  && wall->GetDestroyable() == 1) {
                wall->SetDestroyable(2);
                breack = 2;
            }
        }
        for (auto& player : (players)) {
            if (player->GetX() == bombs->GetX() && player->GetY() == bombs->GetY() + i) {
                player->SetAlive(player->GetAlive() - 1);
            }
        }
        if (breack == 1) {
            break;
        }
        auto it = explosions->begin();
        explosions->insert(it, new Explosions(bombs->GetX(), bombs->GetY() + i));
        if (breack == 2)
            break;
    }
}

void Explode_Down(Bombs* bombs, std::vector<Players*> players, std::vector<Wall*>* walls, std::vector<Explosions*>* explosions)
{
    int breack = 0;
    for (int i = 1; i < 4; i++) {
        for (auto& wall : (*walls)) {
            if (wall->GetX() == bombs->GetX() && wall->GetY() == bombs->GetY() - i && wall->GetDestroyable() == 0) {
                breack = 1;
            } else if (wall->GetX() == bombs->GetX() && wall->GetY() == bombs->GetY() - i && wall->GetDestroyable() == 1) {
                wall->SetDestroyable(2);
                breack = 2;
            }
        }
        for (auto& player : (players)) {
            if (player->GetX() == bombs->GetX() && player->GetY() == bombs->GetY() - i) {
                player->SetAlive(player->GetAlive() - 1);
            }
        }
        if (breack == 1)
            break;
        auto it = explosions->begin();
        explosions->insert(it, new Explosions(bombs->GetX(), bombs->GetY() - i));
        if (breack == 2)
            break;
    }
}

void Explode_Left(Bombs* bombs, std::vector<Players*> players, std::vector<Wall*>* walls, std::vector<Explosions*>* explosions)
{
    int breack = 0;

    for (int i = 1; i < 4; i++) {
        for (auto& wall : (*walls)) {
            if (wall->GetX() == bombs->GetX() - i && wall->GetY() == bombs->GetY() && wall->GetDestroyable() == 0) {
                breack = 1;
            }else if (wall->GetX() == bombs->GetX() - i && wall->GetY() == bombs->GetY() && wall->GetDestroyable() == 1) {
                wall->SetDestroyable(2);
                breack = 2;
            }
        }
        for (auto& player : (players)) {
            if (player->GetX() == bombs->GetX() - i && player->GetY() == bombs->GetY()) {
                player->SetAlive(player->GetAlive() - 1);
            }
        }
        if (breack == 1)
            break;
        auto it = explosions->begin();
        explosions->insert(it, new Explosions(bombs->GetX() - i, bombs->GetY()));
        if (breack == 2)
            break;
    }
}

void Explode_Right(Bombs* bombs, std::vector<Players*> players, std::vector<Wall*>* walls, std::vector<Explosions*>* explosions)
{
    int breack = 0;

    for (int i = 1; i < 4; i++) {
        for (auto& wall : (*walls)) {
            if (wall->GetX() == bombs->GetX() + i && wall->GetY() == bombs->GetY() && wall->GetDestroyable() == 0) {
                breack = 1;
            }else if (wall->GetX() == bombs->GetX() + i && wall->GetY() == bombs->GetY() && wall->GetDestroyable() == 1) {
                wall->SetDestroyable(2);
                breack = 2;
            }
        }
        for (auto& player : (players)) {
            if (player->GetX() == bombs->GetX() + i && player->GetY() == bombs->GetY()) {
                player->SetAlive(player->GetAlive() - 1);
            }
        }
        if (breack == 1)
            break;
        auto it = explosions->begin();
        explosions->insert(it, new Explosions(bombs->GetX() + i, bombs->GetY()));
        if (breack == 2)
            break;
    }
}

void Explode(std::vector<Bombs*>* BombsList, std::vector<Players *> playersList, std::vector<Wall*>* wall, std::vector<Explosions*>* explosion)
{
    for (auto &bomb : (*BombsList)) {
        if (bomb->GetBombs_timer() <= 0) {
            Explode_Up(bomb, playersList, wall, explosion);
            Explode_Down(bomb, playersList, wall, explosion);
            Explode_Left(bomb, playersList, wall, explosion);
            Explode_Right(bomb, playersList, wall, explosion);
            BombsList->pop_back();
            break;
        }
    }
}

std::vector<Bombs*> DrawBombs(std::vector<Bombs*> BombsList)
{
    Vector3 cubePosition;
    for (auto &bomb : BombsList) {
        cubePosition = {(float)(bomb->GetX())*2, (float)(bomb->GetY())*2, 0};
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, VIOLET);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        bomb->SetBombs_timer(bomb->GetBombs_timer() - 0.1f);
    }
    return (BombsList);
}

void popBomb(std::vector<Bombs*>* BombsList, Players *players)
{
    if (IsKeyDown(KEY_SPACE) && players->GetBombs_cooldown() <= 0) {
        auto it = BombsList->begin();
        BombsList->insert(it, new Bombs(players->GetX(), players->GetY()));
        players->SetBombs_cooldown(20);
    }
}

void createBombs(std::vector<Players *> playersList, std::vector<Bombs*>* BombsList)
{
    for(auto players : playersList){
        players->SetBombs_cooldown(players->GetBombs_cooldown() - 0.1f);
        if (players->GetHuman()){
            popBomb(BombsList, players);
        }
    }
}

int Bombs::GetId() const {
    return this->id;
}
void Bombs::SetId(int id) {
    this->id = id;
}
float Bombs::GetBombs_timer() const {
    return this->bomb_timer;
}
void Bombs::SetBombs_timer(float bomb_timer) {
    this->bomb_timer = bomb_timer;
}
int Bombs::GetX() const {
    return this->x;
}
void Bombs::SetX(int x) {
    this->x = x;
}
int Bombs::GetY() const {
    return this->y;
}
void Bombs::SetY(int y) {
    this->y = y;
}

Bombs::Bombs(int x, int y)
{
    SetX(x);
    SetY(y);
    SetBombs_timer(20);
}