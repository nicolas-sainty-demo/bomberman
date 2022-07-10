/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** models
*/

#ifndef MODELS_HPP_
#define MODELS_HPP_
#include <raylib.h>
#include <vector>

// Image checked = GenImageChecked(2, 2, 1, 1, RED, GREEN);
//     Texture2D texture = LoadTextureFromImage(checked);
//     UnloadImage(checked);

    // Model models[NUM_MODELS] = { 0 };

    // models[0] = LoadModelFromMesh(GenMeshPlane(2, 2, 5, 5));
    // models[1] = LoadModelFromMesh(GenMeshCube(2.0f, 1.0f, 2.0f));
    // models[2] = LoadModelFromMesh(GenMeshSphere(2, 32, 32));
    // models[3] = LoadModelFromMesh(GenMeshHemiSphere(2, 16, 16));
    // models[4] = LoadModelFromMesh(GenMeshCylinder(1, 2, 16));
    // models[5] = LoadModelFromMesh(GenMeshTorus(0.25f, 4.0f, 16, 32));
    // models[6] = LoadModelFromMesh(GenMeshKnot(1.0f, 2.0f, 16,
    //    for (int i = 0; i < NUM_MODELS; i++) models[i].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

class Models
{
    public:
        Models();
        ~Models();
        Model models[5];
        Texture2D wall;
        Texture2D wallD;
        Texture2D ground;
        Texture2D flames;
        Texture2D tnt;
    private:
};
#endif /* !MODELS_HPP_ */