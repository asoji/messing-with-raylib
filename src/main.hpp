//
// Created by Aubrey on 3/22/2022.
//
#ifndef MESSING_WITH_RAYLIB_MAIN_HPP
#define MESSING_WITH_RAYLIB_MAIN_HPP

#include <raylib.h>
#include <raymath.h>

const int windowW = 1280;
const int windowH = 720;

const char* windowTitle = "raaaaaaaaaaaayliiiiiiiiiiiiiiiib";

#define G 600
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 400.0f


typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void UpdateCameraCenterSmoothFollow(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
{
    static float minSpeed = 60;
    static float minEffectLength = 10;
    static float fractionSpeed = 1.6f;

    camera->offset = (Vector2){ width/2.0f, height/2.0f };
    Vector2 diff = Vector2Subtract(player->position, camera->target);
    float length = Vector2Length(diff);

    if (length > minEffectLength)
    {
        float speed = fmaxf(fractionSpeed*length, minSpeed);
        camera->target = Vector2Add(camera->target, Vector2Scale(diff, speed*delta/length));
    }
}


#endif //MESSING_WITH_RAYLIB_MAIN_HPP
