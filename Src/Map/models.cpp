/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** models
*/

#include "models.hpp"
#include <string>
#include <iostream>


Models::Models() {
    this->wall = LoadTexture("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/ressources/Diorite.png");
    this->wallD = LoadTexture("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/ressources/dirt.png");
    this->ground = LoadTexture("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/ressources/Grass.png");
    this->flames = LoadTexture("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/ressources/flames.png");
    this->tnt = LoadTexture("/home/nicolas/B-YEP-400-BDX-4-1-indiestudio-florent.canales/ressources/tnt.jpg");
    for (int i = 0; i < 5; i++) {
        models[i] = LoadModelFromMesh(GenMeshCube(2.0f, 2.0f, 2.0f));
    }
    this->models[0].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->wall;
    this->models[1].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->wallD;
    this->models[2].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->ground;
    this->models[3].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->flames;
    this->models[4].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->tnt;
}

Models::~Models()
{
    std::cout << "destructed" << std::endl;
    UnloadTexture(this->wall);
    UnloadTexture(this->wallD);
    UnloadTexture(this->ground);
    //UnloadTexture(this->flames);
    //UnloadTexture(this->tnt);
    for (int i = 0; i < 5; i++) {
        UnloadModel(this->models[i]);
    }
}