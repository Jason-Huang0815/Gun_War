/**
 * @file GameState.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief store all the data, including struct, enum, etc.
 */

#ifndef GUNWAR_GAMESTATE_H
#define GUNWAR_GAMESTATE_H
#pragma once
#include <random>
#include<raylib.h>
#include <vector>

enum Status {
    READY, PLAYING, FAIL, VICTORY
};

enum Motion {
    STAND, JUMP, SQUAD
};

struct Obstacle{
    int layer{};
    float length = 1;
    float width = 1;
    float height = 1.0f;
};

class GameState {
public:
    struct {
        int width = GetScreenWidth();
        int height = GetScreenHeight();
    } screen;

    struct {
        Vector2 size = {.x = 100, .y = 100};
        Vector3 centre = {.x = 0, .y = 0, .z = 0};
    } space;

    struct {
        int length = 2;
        int width = 2;
        int height = 3;
    } player;


    Motion motion = STAND;
    Status status = READY;
    Camera3D camera{};
    std::vector<Obstacle> obstacles;

    void reset() {
        screen.width = GetScreenWidth();
        screen.height = GetScreenHeight();
        player.length = 2;
        player.width = 2;
        player.height = 3;
        motion = STAND;
        initObstacles();
    }

    void initCamera() {
        camera.position = {.x = 0, .y =7, .z = 10};
        camera.target = {.x = 0, .y = 3, .z = 0};
        camera.up = {.x = 0, .y = 1, .z = 0};
        camera.fovy = 60.0f;
        camera.projection = CAMERA_PERSPECTIVE;
        DisableCursor();
    }

    void initObstacles() {
        for (int i = 1; i <= 500; i++) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0, 5);
            Obstacle obstacle;
            obstacle.layer=static_cast<int>(dis(gen));
            obstacles.emplace_back(obstacle);
        }
    }
};

#endif //GUNWAR_GAMESTATE_H
