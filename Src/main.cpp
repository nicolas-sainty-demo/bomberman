/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** main.cpp
*/

#include "raylib.h"
#include "stdio.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "wall.hpp"
#include "players.hpp"
#include <list>
#include "game.hpp"
#include <algorithm>
#include "updateWall.hpp"
#include "bombs.hpp"
#include <vector>
#include "explosions.hpp"
#include "models.hpp"


void DrawWall(std::vector<Wall*> wall/*, Models modelList*/)
{
    float x = 2;
    float y = 0;
    float z = 0;
    Vector3 cubePosition;
    Vector3 cubeGround;

    for (auto &list : wall) {
        int color = list->GetDestroyable();
        cubeGround = {(float)(list->GetX())*2,(float)(list->GetY()*2), -1.5};
        cubePosition = {(float)(list->GetX())*2,(float)(list->GetY()*2),0};
        if (color == 0) {
            //DrawTextureRec(sol, {0, 0, 2, 2}, test, WHITE);
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            //DrawModel(modelList.models[1], cubePosition, 1.0f, WHITE);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, BLACK);
        } else if (color == 1) {
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, GREEN);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        }
        DrawCube(cubeGround, 2.0f, 2.0f, 2.0f, BLUE);
        DrawCubeWires(cubeGround, 2.0f, 2.0f, 2.0f, MAROON);
    }
}

void setFullScreen()
{
    if (IsKeyDown(KEY_F)) {
 		int display = GetCurrentMonitor();
        if (IsWindowFullscreen()){
            SetWindowSize(1600, 1000);
        }else{
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }
 		ToggleFullscreen();
    }
}

void DrawCharacter(std::vector<Players*> playersList)
{
    for(auto player : playersList){
        Vector3 cubePosition = {(float)(player->GetX())*2,(float)(player->GetY()*2),0};
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, ORANGE);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
    }
}

void DrawExplosions(std::vector<Explosions*>* ExplosionsList)
{
    Vector3 cubePosition;

    for (auto &i : (*ExplosionsList)) {
        i->SetBombs_cooldown(i->GetBombs_cooldown() - 1);
        if (i->GetBombs_cooldown() > 0) {
            cubePosition = {(float)(i->GetX())*2,(float)(i->GetY()*2),0};
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BLACK);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        }else{
            ExplosionsList->pop_back();
            break;
        }
    }
}

void SetPlayers(Game *game)
{
    game->SetPlayersList(game->GetPlayersList());
}

void controls(Players *player)
{
    if (IsKeyDown(KEY_UP) && player->GetUp() == 1) {
        player->moveUp();
    }
    if (IsKeyDown(KEY_DOWN) && player->GetDown() == 1) {
        player->moveDown();
    }
    if (IsKeyDown(KEY_LEFT) && player->GetLeft() == 1) {
        player->moveLeft();
    }
    if (IsKeyDown(KEY_RIGHT) && player->GetRight() == 1) {
        player->moveRight();
    }
}

void move(std::vector<Players*> playersList, std::vector<Wall*> wall)
{
    for(auto players : playersList){
        updateWall(wall, players);
        if (players->GetHuman()){
            controls(players);
        }
    }
}

void loop(std::vector<Wall*> wall, Game *game)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    Camera3D camera = { 0 };
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    InitWindow(screenWidth, screenHeight, "test 0.1");
    //Models model;
    camera.position = (Vector3){ 27.0f, 27.0f, 33.0f };  // Camera position
    camera.target = (Vector3){ 27.0f, 27.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 100.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE ;             // Camera mode type
    std::vector<Bombs*> BombsList;
    std::vector<Explosions*> ExplosionsList;
    SetTargetFPS(60);
    SetPlayers(game);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        setFullScreen();
        move(game->GetPlayersList(), wall);
        createBombs(game->GetPlayersList(), &BombsList);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawWall(wall/*, model*/);
                DrawCharacter(game->GetPlayersList());
                DrawBombs(BombsList);
                Explode(&BombsList, game->GetPlayersList(), &wall, &ExplosionsList);
                DrawExplosions(&ExplosionsList);
            EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}

//opens file and saves it into a string*
std::string *readFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string *fileContent = new std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return fileContent;
}

char *load(const std::string &filename) {
    char *fileContent = LoadFileText(filename.c_str());
    if (fileContent == nullptr) {
        throw std::runtime_error("Could not open file " + filename);
    }
    return fileContent;
}

void addWall(std::vector<Wall*>* wall, int x, int y, int destroyable) {
    auto it = wall->begin();
    wall->insert(it, new Wall(x, y, destroyable));
}

void parse(std::string *fileContent, std::vector<Wall*>* wall)
{
    std::stringstream ss(*fileContent);
    std::string line;
    int heigh = 0;

    while (std::getline(ss, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '\n') {
                heigh++;
            } else {
                if (line[i] == '#') {
                    addWall(wall, i, heigh, 0);
                } else if (line[i] == '0') {
                    addWall(wall, i, heigh, 1);
                } else if (line[i] == ' ') {
                    addWall(wall, i, heigh, 2);
                }
            }
        }
        heigh++;
    }
}

int check_map(std::string *fileContent)
{
    return 0;
}

int main(void)
{
    std::string *fileContent = readFile("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/Src/Map/map.txt");
    Game game(4, 1);
    std::vector<Wall*> wall;
    parse(fileContent, &wall);
    loop(wall, &game);
    return 0;
}