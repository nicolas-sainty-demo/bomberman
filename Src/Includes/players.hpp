/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** players
*/

#ifndef PLAYERS_HPP_
#define PLAYERS_HPP_

class Players
{
    public:
        Players();
        Players(int id, bool human);
        ~Players();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        void Put_bomb();
        int GetId() const;
        void SetId(int id);
        int GetBombs_cooldown() const;
        void SetBombs_cooldown(int bombs_cooldown);
        int GetX() const;
        void SetX(int x);
        int GetY() const;
        void SetY(int y);
        int GetAlive() const;
        void SetAlive(int alive);
        bool GetHuman() const;
        void SetHuman(bool human);
        void SetUp(bool Up);
        bool GetUp() const;
        void SetDown(bool Down);
        bool GetDown() const;
        void SetRight(bool Right);
        bool GetRight() const;
        void SetLeft(bool Left);
        bool GetLeft() const;
    private:
        int id;
        bool human;
        int bombs_cooldown;
        int x;
        int y;
        int alive;
        bool movable_up;
        bool movable_down;
        bool movable_left;
        bool movable_right;
};

#endif /* !PLAYERS_HPP_ */
