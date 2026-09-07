/**
 * @file InputSystem.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief only to read the state and input, making the corresponding responses
 */

#ifndef GUNWAR_INPUTSYSTEM_H
#define GUNWAR_INPUTSYSTEM_H
#pragma once
#include "raylib.h"

class GameState;

class InputSystem {
private:
    GameState &m_state;

public:
    explicit InputSystem(GameState &state);

    void update(float dt) const;
};


#endif //GUNWAR_INPUTSYSTEM_H
