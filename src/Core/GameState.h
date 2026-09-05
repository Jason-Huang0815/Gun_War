/**
 * @file GameState.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief store all the data, including struct, enum, etc.
 */

#ifndef GUNWAR_GAMESTATE_H
#define GUNWAR_GAMESTATE_H
#pragma once
#include<raylib.h>

enum Status {
    READY,PLAYING,FAIL,VICTORY
};

enum Motion {
    STAND,JUMP,SQUAD
};

class GameState {
public:
    struct {
        int width = GetScreenWidth();
        int height = GetScreenHeight();
    } Screen;

    struct {
        int length = 2;
        int width = 2;
        int height = 3;
    } Player;

    Motion motion=STAND;
    Camera3D camera{};

    void reset() {
        Screen.width = GetScreenWidth();
        Screen.height = GetScreenHeight();
        Player.length = 2;
        Player.width = 2;
        Player.height = 3;
        motion=STAND;
    }
    void initCamera() {
        camera.position={.x = 0,.y = 3,.z = 10};
        camera.target={.x = 0,.y = 3,.z = 0};
        camera.up={.x = 0,.y = 1,.z = 0};
        camera.fovy=60.0f;
        camera.projection=CAMERA_PERSPECTIVE;
        DisableCursor();
    }
};

#endif //GUNWAR_GAMESTATE_H
