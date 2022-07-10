/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** game
*/
#include "game.hpp"
#include <algorithm>

Game::Game()
{
}

std::vector<Players*> Game::GetPlayersList(){
    return this->playersList;
}

void Game::SetPlayersList(std::vector<Players*> playersList) {

    for(auto player : playersList){
        if (player->GetId() == 1) {
            player->SetX(1);
            player->SetY(1);
        } else if (player->GetId() == 2) {
            player->SetX(1);
            player->SetY(25);
        } else if (player->GetId() == 3) {
            player->SetX(25);
            player->SetY(1);
        } else if (player->GetId() == 4) {
            player->SetX(25);
            player->SetY(25);
        }
    }
}

Game::Game(int number, int humanoids)
{
    this->number = number;
    this->humanoids = humanoids;
    //int i = 0;
    int i = 2;

    //while (i <= this->humanoids) {
        playersList.insert(playersList.begin(), new Players(1, 1));
    //    i++;
    //}
    while (i <= this->number) {
        playersList.insert(playersList.begin(), new Players(i, 0));
        i++;
    }
}

Game::~Game()
{
}