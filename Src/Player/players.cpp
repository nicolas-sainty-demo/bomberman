/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** players
*/

#include "players.hpp"

Players::Players()
{
}

Players::~Players()
{
}

void Players::moveDown()
{
    this->y -= 1;
}
void Players::moveUp()
{
    this->y += 1;
}
void Players::moveLeft()
{
    this->x -= 1;
}
void Players::moveRight()
{
    this->x += 1;
}
int Players::GetId() const {
    return this->id;
}
void Players::SetId(int id) {
    this->id = id;
}
int Players::GetBombs_cooldown() const {
    return this->bombs_cooldown;
}
void Players::SetBombs_cooldown(int bombs_cooldown) {
    this->bombs_cooldown = bombs_cooldown;
}
int Players::GetX() const {
    return this->x;
}
void Players::SetX(int x) {
    this->x = x;
}
int Players::GetY() const {
    return this->y;
}
void Players::SetY(int y) {
    this->y = y;
}
int Players::GetAlive() const {
    return this->alive;
}
void Players::SetAlive(int alive) {
    this->alive = alive;
}
bool Players::GetHuman() const {
    return this->human;
}
void Players::SetHuman(bool human) {
    this->human = human;
}
void Players::SetUp(bool Up) {
    this->movable_up = Up;
}
bool Players::GetUp() const {
    return this->movable_up;
}
void Players::SetDown(bool Down) {
    this->movable_down = Down;
}
bool Players::GetDown() const {
    return this->movable_down;
}
void Players::SetRight(bool Right) {
    this->movable_right = Right;
}
bool Players::GetRight() const {
    return this->movable_right;
}
void Players::SetLeft(bool Left) {
    this->movable_left = Left;
}
bool Players::GetLeft() const {
    return this->movable_left;
}
Players::Players(int id, bool human)
{
    SetId(id);
    SetHuman(human);
}
