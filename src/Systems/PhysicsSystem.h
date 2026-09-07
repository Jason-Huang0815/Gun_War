/**
 * @file PhysicsSystem.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief only to read the state and do something for real world
 */

#ifndef GUNWAR_PHYSICSSYSTEM_H
#define GUNWAR_PHYSICSSYSTEM_H
#pragma once
#include "../Core/GameState.h"

class GameState;

class PhysicsSystem {
private:
    GameState &m_state;
    float m_gravity = 18.0f;
    float m_velocity = 9.0f;
    int m_originHeight = m_state.player.height;

    void _jump(float dt);

public:
    explicit PhysicsSystem(GameState &state);

    void update(float dt);
};


#endif //GUNWAR_PHYSICSSYSTEM_H
