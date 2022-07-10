/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#include <list>
#include "players.hpp"
#include <vector>
class Game
{
    public:
        Game(int number, int humanoids);
        Game();
        ~Game();
        std::vector<Players*> GetPlayersList();
        void SetPlayersList(std::vector<Players*> playersList);
    private:
        int number;
        int humanoids;
        std::vector<Players*> playersList;

};

#endif /* !GAME_HPP_ */
